#include <event_manager/event_buffer.h>
#include <event_manager/event.h>

event_buffer::event_buffer(ros::Duration buffer_length)
{
    _buffer_length = buffer_length;
}

event_buffer::~event_buffer()
{

}

void event_buffer::add_event(event event_)
{
    boost::mutex::scoped_lock lock(_event_buf_mtx);
    boost::shared_ptr<event> event_ptr = boost::make_shared<event>(event_);
    _buffer.push_back(event_ptr);
    bool is_exist = false;
    for(auto itr = _all_event_keys.begin(); itr != _all_event_keys.end(); ++itr)
    {
        if(*itr != event_.key)
        {
            is_exist = true;
        }
    }
    if(is_exist == false)
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
    for(auto itr = _buffer.begin(); itr != _buffer.end(); ++itr)
    {
        boost::shared_ptr<event> event_ptr(*itr);
        /*
        if(event_ptr->stamp > min_timestamp && event_ptr->stamp < max_timestamp)
        {
            fillterd_event_list.push_back(event_ptr);
        }
        */
    }
    return ret;
}

void event_buffer::_update_buffer()
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