#include <event_manager/event_manager.h>

event_manager::event_manager()
{
    
}

event_manager::~event_manager()
{

}

void event_manager::run()
{
    double buffer_length_time;
    _nh.param<double>(ros::this_node::getName()+"/buffer_length", buffer_length_time, 10.0);
    ros::Duration buffer_length(buffer_length_time);
    double update_rate;
    _nh.param<double>(ros::this_node::getName()+"/update_rate", update_rate, 10.0);
    _update_rate = boost::make_shared<ros::Rate>(update_rate);
    buffer = boost::make_shared<event_buffer>(buffer_length);
    while(ros::ok())
    {
        _update_rate->sleep();
    }
    return;
}