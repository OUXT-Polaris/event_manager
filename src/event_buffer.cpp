#include <event_manager/event_buffer.h>
#include <event_manager/event.h>

event_buffer::event_buffer(ros::Duration buffer_length)
{
    _buffer_length = buffer_length;
    _event_buf_mtx = boost::make_shared<boost::mutex>();
    //_event_buf_mtx = event_buf_mtx;
}

event_buffer::~event_buffer()
{

}

void event_buffer::add_event(event event_)
{
    boost::shared_ptr<event> event_ptr = boost::make_shared<event>(event_);
    _buffer.push_back(event_ptr);
    return;
}

void event_buffer::_update()
{
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
    //_buffer = buf;
    //_buffer.resize(buf.size());
    return;
}