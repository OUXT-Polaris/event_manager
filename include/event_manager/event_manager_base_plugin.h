#ifndef EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED
#define EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED

#define DEFAULT_BUFFER_LENGTH 10.0

//headers in event_manager
#include <event_manager/event.h>
#include <event_manager/QueryKey.h>
#include <event_manager/QueryResult.h>
#include <event_manager/EventStateArray.h>
#include <event_manager/event_buffer.h>

//headers in boost
#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>

namespace event_manager_base_plugin
{
    class base_plugin
    {
    public:
        base_plugin(){};
        ~base_plugin(){};
        virtual void initialize(XmlRpc::XmlRpcValue parameters, ros::Duration buffer_length)
        {
            _buffer = boost::make_shared<event_buffer>(buffer_length);
            return;
        };
        virtual std::vector<event> get_events()
        {
            std::vector<event> ret = _buffer->get_events();
            return ret;
        };
        virtual void add_event(event event_)
        {
            _buffer->add_event(event_);
            return;
        };
        virtual void add_events(std::vector<event> events_)
        {
            _buffer->add_events(events_);
            return;
        };
    private:
        boost::shared_ptr<event_buffer> _buffer;
    };
}
#endif  //EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED