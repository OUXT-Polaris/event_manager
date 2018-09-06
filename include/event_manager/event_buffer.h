#ifndef EVENT_BUFFER_H_INCLUDED
#define EVENT_BUFFER_H_INCLUDED

#include <ros/ros.h>

class event_buffer
{
public:
    event_buffer(ros::Duration buffer_length);
    ~event_buffer();
private:
    void _update();
};

#endif  //EVENT_BUFFER_H_INCLUDED