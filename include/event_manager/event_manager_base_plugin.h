#ifndef EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED
#define EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED

//headers in event_manager
#include <event_manager/event.h>
#include <event_manager/QueryKey.h>
#include <event_manager/QueryResult.h>
#include <event_manager/EventStateArray.h>

#include <boost/optional.hpp> 

namespace event_manager_plugins
{
    class base_plugin
    {
    public:
        base_plugin();
        ~base_plugin();
        virtual void initialize(XmlRpc::XmlRpcValue parameters);
        virtual boost::optional<event> set_recent_event();
        virtual event_manager::QueryResult query_event(event_manager::QueryKey key);
        virtual event_manager::EventStateArray query_event_states();
    };
}
#endif  //EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED