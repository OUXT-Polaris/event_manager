#include <ros/ros.h>
#include <event_manager/event_manager.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "event_manager_node");
  boost::shared_ptr<boost::mutex> event_buf_mtx_ptr = boost::make_shared<boost::mutex>();
  event_manager manager;
  manager.run(ros::Duration(10.0), event_buf_mtx_ptr);
  ros::spin();
  return 0;
}