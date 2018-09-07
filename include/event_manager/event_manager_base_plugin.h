#ifndef EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED
#define EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED

#include <event_manager/event.h>

#include <boost/optional.hpp> 

namespace event_manager_plugins
{
    class base_plugin
    {
    public:
        base_plugin(){};
        ~base_plugin(){};
        virtual void initialize(){};
        virtual boost::optional<event> get_recent_event(){};
    };
}
#endif  //EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED