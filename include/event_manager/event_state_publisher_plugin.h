#ifndef EVENT_STATE_PUBLISHER_PLUGIN_H_INCLUDED
#define EVENT_STATE_PUBLISHER_PLUGIN_H_INCLUDED

#include <pluginlib/class_list_macros.h>
#include <event_manager/event_manager_base_plugin.h>

namespace event_manager_plugins
{
    class event_state_publisher : public base_plugin
    {

    };
}

PLUGINLIB_EXPORT_CLASS(event_manager_plugins::event_state_publisher, event_manager_plugins::base_plugin)

#endif  //EVENT_STATE_PUBLISHER_PLUGIN_H_INCLUDED