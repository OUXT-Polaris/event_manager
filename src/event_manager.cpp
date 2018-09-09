#include <event_manager/event_manager.h>

event_manager_core::event_manager_core()
{
    
}

event_manager_core::~event_manager_core()
{

}

void event_manager_core::run()
{
    double buffer_length_time;
    _nh.param<double>(ros::this_node::getName()+"/buffer_length", buffer_length_time, 10.0);
    ros::Duration buffer_length(buffer_length_time);
    double update_rate;
    _nh.param<double>(ros::this_node::getName()+"/update_rate", update_rate, 10.0);
    _update_rate = boost::make_shared<ros::Rate>(update_rate);
    buffer = boost::make_shared<event_buffer>(buffer_length);
    XmlRpc::XmlRpcValue parameters;
    _nh.getParam(ros::this_node::getName(), parameters);
    XmlRpc::XmlRpcValue plugin_params = parameters["plugins"];
    for(auto plugin_params_itr = plugin_params.begin(); plugin_params_itr != plugin_params.end(); ++plugin_params_itr)
    {
        _plugin_names.push_back(plugin_params_itr->first);
        pluginlib::ClassLoader<event_manager_plugins::base_plugin> loader("event_manager","event_manager_plugins::base_plugin");
        boost::shared_ptr<event_manager_plugins::base_plugin> plugin = loader.createInstance("event_manager_plugins::"+plugin_params_itr->first);
        plugin->initialize(plugin_params_itr->second);
        _plugin_ptrs.push_back(plugin);
    }
    while(ros::ok())
    {
        _update_rate->sleep();
    }
    return;
}