#ifndef EVENT_H_INCLUDED
#define EVENT_H_INCLUDED

#include <ros/ros.h>

struct event
{
    const ros::Time stamp;
    const std::string key;
    event(ros::Time stamp_, std::string key_) : stamp(stamp_), key(key_){};
};
#endif  //EVENT_H_INCLUDED