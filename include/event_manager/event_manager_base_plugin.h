#ifndef EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED
#define EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED

namespace event_manager_plugins
{
    class base_plugin
    {
        virtual void initialize(){};
        virtual void update_event(){};
    };
}
#endif  //EVENT_MANAGER_BASE_PLUGIN_H_INCLUDED