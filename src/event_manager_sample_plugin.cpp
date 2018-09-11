#include <event_manager/event_manager_sample_plugin.h>

namespace event_manager_plugins
{
    event_manager_sample_plugin::event_manager_sample_plugin()
    {
        
    }

    event_manager_sample_plugin::~event_manager_sample_plugin()
    {

    }

    void event_manager_sample_plugin::initialize(XmlRpc::XmlRpcValue parameters)
    {
        std::string topic_name = ros::this_node::getName() + "/" + std::string(parameters["name"]);
        _topic_sub = _nh.subscribe(topic_name, 1, &event_manager_sample_plugin::_callback, this);
        return;
    }

    void event_manager_sample_plugin::_callback(std_msgs::Empty msg)
    {
        return;
    }
}