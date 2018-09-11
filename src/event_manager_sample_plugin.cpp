#include <event_manager/event_manager_sample_plugin.h>

#include <thread>

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
        ROS_ERROR_STREAM("hi");
        std::string topic_name = ros::this_node::getName() + "/" + std::string(parameters["name"]);
        _topic_sub = _nh.subscribe(topic_name, 1, &event_manager_sample_plugin::_callback, this);
        return;
    }

    void event_manager_sample_plugin::_callback(std_msgs::Empty msg)
    {
        return;
    }
}

PLUGINLIB_EXPORT_CLASS(event_manager_plugins::event_manager_sample_plugin, event_manager_base_plugin::base_plugin)