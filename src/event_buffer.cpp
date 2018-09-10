//headers in event_manager
#include <event_manager/event_buffer.h>
#include <event_manager/event.h>

//headers in STL
#include <algorithm>

event_buffer::event_buffer(ros::Duration buffer_length)
{
    _buffer_length = buffer_length;
}

event_buffer::~event_buffer()
{

}

std::vector<event> event_buffer::get_events()
{
    boost::mutex::scoped_lock lock(_event_buf_mtx);
    std::vector<event> ret;
    for(auto event_itr = _buffer.begin(); event_itr != _buffer.end(); event_itr++)
    {
        ret.push_back(*event_itr->get());
    }
    return ret;
}

void event_buffer::add_event(event event_)
{
    boost::mutex::scoped_lock lock(_event_buf_mtx);
    boost::shared_ptr<event> event_ptr = boost::make_shared<event>(event_);
    for(int i=0; i<_buffer.size(); i++)
    {
        if(_buffer[i]->key == event_.key && _buffer[i]->stamp == event_.stamp)
        {
            return;
        }
    }
    _buffer.push_back(event_ptr);
    bool key_is_exist = false;
    for(auto itr = _all_event_keys.begin(); itr != _all_event_keys.end(); ++itr)
    {
        if(*itr != event_.key)
        {
            key_is_exist = true;
        }
    }
    if(key_is_exist == false)
    {
        _all_event_keys.push_back(event_.key);
    }
    return;
}

event_manager::QueryResult event_buffer::query_event(event_manager::QueryKey key)
{
    boost::mutex::scoped_lock lock(_event_buf_mtx);
    ros::Time min_timestamp = ros::Time::now() - key.target_duration;
    event_manager::QueryResult ret;
    for(auto itr = _buffer.begin(); itr != _buffer.end(); ++itr)
    {
        boost::shared_ptr<event> event_ptr(*itr);
        if(event_ptr->stamp > min_timestamp)
        {
            ret.stamp.push_back(event_ptr->stamp);
        }
    }
    return ret;
}

event_manager::EventStateArray event_buffer::query_event_states(ros::Time min_timestamp, ros::Time max_timestamp)
{
    boost::mutex::scoped_lock lock(_event_buf_mtx);
    event_manager::EventStateArray ret;
    std::vector<std::string> triggerd_events;
    for(auto itr = _buffer.begin(); itr != _buffer.end(); ++itr)
    {
        boost::shared_ptr<event> event_ptr(*itr);
        if(event_ptr->stamp > min_timestamp && event_ptr->stamp < max_timestamp)
        {
            if(std::find(triggerd_events.begin(), triggerd_events.end(), event_ptr->key) != triggerd_events.end())
            {
                continue;
            }
            else
            {
                triggerd_events.push_back(event_ptr->key);
            }
        }
    }
    for(auto event_key_itr = _all_event_keys.begin(); event_key_itr != _all_event_keys.end(); ++event_key_itr)
    {
        if(std::find(triggerd_events.begin(), triggerd_events.end(), *event_key_itr) != triggerd_events.end())
        {
            event_manager::EventState state;
            state.event.event_key = *event_key_itr;
            state.is_triggerd = true;
            ret.event_states.push_back(state);
        }
        else
        {
            event_manager::EventState state;
            state.event.event_key = *event_key_itr;
            state.is_triggerd = false;
            ret.event_states.push_back(state);     
        }
    }
    return ret;
}

void event_buffer::update()
{
    boost::mutex::scoped_lock lock(_event_buf_mtx);
    ros::Time min_timestamp = ros::Time::now() - _buffer_length;
    std::vector<boost::shared_ptr<event> > buf;
    for(auto itr = _buffer.begin(); itr != _buffer.end(); ++itr)
    {
        boost::shared_ptr<event> event_ptr(*itr);
        if(event_ptr->stamp > min_timestamp)
        {
            buf.push_back(event_ptr);
        }
    }
    _buffer = buf;
    return;
}