#ifndef EVENT_BUFFER_H_INCLUDED
#define EVENT_BUFFER_H_INCLUDED

//headers in this package
#include <event_manager/event.h>
#include <event_manager/event_id_list.h>
#include <event_manager/QueryKey.h>
#include <event_manager/QueryResult.h>

//headers in ROS
#include <ros/ros.h>

//headers in stl
#include <vector>

//headers in boost
#include <boost/shared_ptr.hpp>
#include <boost/thread.hpp>

class event_buffer
{
public:
    event_buffer(ros::Duration buffer_length);
    ~event_buffer();
    void add_event(event event_);
    event_manager::QueryResult query_event(event_manager::QueryKey key);
private:
    void _update_buffer();
    std::vector<boost::shared_ptr<event> > _buffer;
    ros::Duration _buffer_length;
    boost::mutex _event_buf_mtx;
};

#endif  //EVENT_BUFFER_H_INCLUDED