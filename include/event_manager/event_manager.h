#ifndef EVENT_MANAGER_H_INCLUDED
#define EVENT_MANAGER_H_INCLUDED

//headers in pluginlib
#include <pluginlib/class_list_macros.h>

#include <event_manager/plugins/event_manager_base_plugin.h>
#include <event_manager/event_buffer.h>

class event_manager_core
{
public:
    event_manager_core();
    ~event_manager_core();
    void run();
    boost::shared_ptr<event_buffer> buffer;
private:
    ros::NodeHandle _nh;
    boost::shared_ptr<ros::Rate> _update_rate;
    std::vector<std::string> _plugin_names;
};

#endif  //EVENT_MANAGER_H_INCLUDED