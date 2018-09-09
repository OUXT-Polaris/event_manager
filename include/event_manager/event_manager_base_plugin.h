#ifndef EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED
#define EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED

//headers in event_manager
#include <event_manager/event.h>
#include <event_manager/QueryKey.h>
#include <event_manager/QueryResult.h>
#include <event_manager/EventStateArray.h>
#include <event_manager/event_buffer.h>

//headers in boost
#include <boost/optional.hpp>
#include <boost/shared_ptr.hpp>

namespace event_manager_plugins
{
    class base_plugin
    {
    public:
        base_plugin(){};
        ~base_plugin(){};
        virtual void initialize(XmlRpc::XmlRpcValue parameters){};
        virtual boost::optional<std::vector<event> > add_events(){};
        //virtual event_manager::QueryResult query_event(event_manager::QueryKey key){};
        //virtual event_manager::EventStateArray query_event_states(){};
    private:
        boost::shared_ptr<event_buffer> _buffer;
    };
}
#endif  //EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED