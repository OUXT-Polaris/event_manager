#ifndef EVENT_BUFFER_H_INCLUDED
#define EVENT_BUFFER_H_INCLUDED

#include <event_manager/event.h>
#include <event_manager/event_id_list.h>

#include <ros/ros.h>

#include <vector>

class event_buffer
{
public:
    event_buffer(ros::Duration buffer_length);
    ~event_buffer();
private:
    void _update();
    std::vector<event> _buffer;
};

#endif  //EVENT_BUFFER_H_INCLUDED