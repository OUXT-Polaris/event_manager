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
    void run(ros::Duration buffer_length, boost::shared_ptr<boost::mutex> event_buf_mtx);
private:
};

#endif  //EVENT_MANAGER_H_INCLUDED