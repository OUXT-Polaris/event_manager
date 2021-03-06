#ifndef EVENT_MANAGER_SAMPLE_PLUGIN_H_INCLUDED
#define EVENT_MANAGER_SAMPLE_PLUGIN_H_INCLUDED

#include <pluginlib/class_list_macros.h>
#include <event_manager/event_manager_base_plugin.h>

#include <std_msgs/Empty.h>

namespace event_manager_plugins
{
    class event_manager_sample_plugin : public event_manager_base_plugin::base_plugin
    {
        public:
            event_manager_sample_plugin();
            ~event_manager_sample_plugin();
            void initialize(XmlRpc::XmlRpcValue parameters);
        private:
            ros::NodeHandle _nh;
            ros::Subscriber _topic_sub;
            void _callback(std_msgs::Empty msg);
    };
}

#endif  //EVENT_MANAGER_SAMPLE_PLUGIN_H_INCLUDED