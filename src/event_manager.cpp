#include <event_manager/event_manager.h>

event_manager_core::event_manager_core()
{
   _event_state_pub = _nh.advertise<event_manager::EventStateArrayStamped>(ros::this_node::getName()+"/event_state", 1);
}

event_manager_core::~event_manager_core()
{

}

void event_manager_core::_publish_event_state()
{
    event_manager::EventStateArrayStamped event_state_msg;
    while(ros::ok())
    {
        event_state_msg.header.stamp = ros::Time::now();
        event_state_msg.event_states_array = _buffer->query_event_states();
        _event_state_pub.publish(event_state_msg);
        _update_rate->sleep();
    }
}

void event_manager_core::run()
{
    double buffer_length_time;
    _nh.param<double>(ros::this_node::getName()+"/buffer_length", buffer_length_time, 10.0);
    ros::Duration buffer_length(buffer_length_time);
    double update_rate;
    _nh.param<double>(ros::this_node::getName()+"/update_rate", update_rate, 10.0);
    _update_rate = boost::make_shared<ros::Rate>(update_rate);
    _buffer = boost::make_shared<event_buffer>(buffer_length);
    XmlRpc::XmlRpcValue parameters;
    _nh.getParam(ros::this_node::getName(), parameters);
    XmlRpc::XmlRpcValue plugin_params = parameters["plugins"];
    pluginlib::ClassLoader<event_manager_base_plugin::base_plugin> loader("event_manager","event_manager_base_plugin::base_plugin");
    std::vector<boost::shared_ptr<event_manager_base_plugin::base_plugin> > plugin_ptrs;

    boost::shared_ptr<event_manager_base_plugin::base_plugin> test_plugin = loader.createInstance("event_manager_plugins::event_manager_sample_plugin");
    test_plugin.get()->initialize(plugin_params, buffer_length);

    for(auto plugin_params_itr = plugin_params.begin(); plugin_params_itr != plugin_params.end(); ++plugin_params_itr)
    {
        _plugin_names.push_back(plugin_params_itr->first);
        plugin_ptrs.push_back(loader.createInstance("event_manager_plugins::"+plugin_params_itr->first));
        plugin_ptrs[plugin_ptrs.size()-1].get()->initialize(plugin_params_itr->second, buffer_length);
    }
    boost::thread pub_thread(boost::bind(&event_manager_core::_publish_event_state, this));
    while(ros::ok())
    {
        for(int i=0; i<plugin_ptrs.size(); i++)
        {
            _buffer->add_events(plugin_ptrs[i]->get_events());
        }
        _buffer->update();
        ros::spinOnce();
    }
    return;
}