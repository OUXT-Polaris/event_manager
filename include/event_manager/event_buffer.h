#ifndef EVENT_BUFFER_H_INCLUDED
#define EVENT_BUFFER_H_INCLUDED

//headers in this package
#include <event_manager/event.h>
#include <event_manager/QueryKey.h>
#include <event_manager/QueryResult.h>
#include <event_manager/EventStateArray.h>

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
    void add_events(std::vector<event> events_);
    std::vector<event> get_events();
    event_manager::QueryResult query_event(event_manager::QueryKey key);
    event_manager::EventStateArray query_event_states(ros::Time min_timestamp, ros::Time max_timestamp);
    void update();
private:
    std::vector<boost::shared_ptr<event> > _buffer;
    ros::Duration _buffer_length;
    boost::mutex _event_buf_mtx;
    std::vector<std::string> _all_event_keys;
};

#endif  //EVENT_BUFFER_H_INCLUDED