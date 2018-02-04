#include <ros/ros.h>
#include <std_msgs/String.h>

#include <sstream>

int main(int argc, char **argv)
{
  ros::init(argc, argv, "talker");

  ros::NodeHandle n;
  ros::Publisher chatter_pub = n.advertise<std_msgs::String>("/chatter", 1);

  ros::Rate loop_rate(1);  // Set 1 Hz

  while (ros::ok()) {
    std_msgs::String msg;
    std::stringstream ss;
    ss << "hello world";
    mcos_debug_printf("%s\n", ss.str().c_str());
    msg.data = ss.str();
    
    chatter_pub.publish(msg);
    loop_rate.sleep();
  }

  return 0;
}
