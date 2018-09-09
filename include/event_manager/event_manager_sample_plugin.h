#ifndef EVENT_MANAGER_SAMPLE_PLUGIN_H_INCLUDED
#define EVENT_MANAGER_SAMPLE_PLUGIN_H_INCLUDED

#include <pluginlib/class_list_macros.h>
#include <event_manager/event_manager_base_plugin.h>

namespace event_manager_plugins
{
    class event_manager_sample_plugin : public base_plugin
    {
        public:
            event_manager_sample_plugin(){};
            ~event_manager_sample_plugin(){};
            void initialize(XmlRpc::XmlRpcValue parameters){};
            boost::optional<std::vector<event> > add_events(){return boost::none;};
    };
}

PLUGINLIB_EXPORT_CLASS(event_manager_plugins::event_manager_sample_plugin, event_manager_plugins::base_plugin)

#endif  //EVENT_MANAGER_SAMPLE_PLUGIN_H_INCLUDED