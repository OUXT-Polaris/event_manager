#ifndef EVENT_MANAGER_H_INCLUDED
#define EVENT_MANAGER_H_INCLUDED

#include <pluginlib/class_list_macros.h>

#include <event_manager/event_manager_base_plugin.h>
#include <event_manager/event_buffer.h>

class event_manager
{
public:
    event_manager();
    ~event_manager();
    void run();
    boost::shared_ptr<event_buffer> buffer;
private:
    ros::NodeHandle _nh;
    boost::shared_ptr<ros::Rate> _update_rate;
};

#endif  //EVENT_MANAGER_H_INCLUDED