#include <ros/ros.h>
#include <event_manager/event_manager.h>

int main(int argc, char *argv[]) {
  ros::init(argc, argv, "event_manager_node");
  event_manager_core manager_core;
  manager_core.run();
  ros::spin();
  return 0;
}