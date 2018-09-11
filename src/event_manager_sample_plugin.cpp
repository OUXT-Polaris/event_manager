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

    }

    void event_manager_sample_plugin::_callback(std_msgs::Empty msg)
    {
        return;
    }
}

PLUGINLIB_EXPORT_CLASS(event_manager_plugins::event_manager_sample_plugin, event_manager_base_plugin::base_plugin)