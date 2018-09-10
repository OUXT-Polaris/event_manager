#ifndef EVENT_MANAGER_H_INCLUDED
#define EVENT_MANAGER_H_INCLUDED

//headers in pluginlib
#include <pluginlib/class_list_macros.h>
#include <pluginlib/class_loader.h>

//headers in event_manager
#include <event_manager/event_manager_base_plugin.h>
#include <event_manager/event_buffer.h>

//headers in boost
#include <boost/shared_ptr.hpp>

class event_manager_core
{
public:
    event_manager_core();
    ~event_manager_core();
    void run();
private:
    boost::shared_ptr<event_buffer> _buffer;
    ros::NodeHandle _nh;
    boost::shared_ptr<ros::Rate> _update_rate;
    std::vector<std::string> _plugin_names;
};

#endif  //EVENT_MANAGER_H_INCLUDED