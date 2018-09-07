#include <event_manager/event_manager.h>

event_manager::event_manager()
{
    
}

event_manager::~event_manager()
{

}

void event_manager::run(ros::Duration buffer_length)
{
    buffer = boost::make_shared<event_buffer>(buffer_length);
    return;
}