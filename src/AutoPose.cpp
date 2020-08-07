#include "ros/ros.h"
#include "first_task/Num.h"
#include "first_task/Navigator.h"
#include <cstdlib>

class Listener
{
  public:
  ros::NodeHandle n;
  void callback(const first_task::Num::ConstPtr &y);
};

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "AutoPose");

  Listener list;
  ros::Subscriber sub = list.n.subscribe("tused", 1000, &Listener::callback, &list);

  ros::spin();

  return 0;
}

void Listener::callback(const first_task::Num::ConstPtr &y)
{
  ros::ServiceClient client = n.serviceClient<first_task::Navigator>("find_fibonacci");

  first_task::Navigator srv;
  srv.request.x = y->num;

  if(client.call(srv))
  {
    ROS_INFO("Fibonacci Number : %ld", (long int)srv.response.fibo);
  }
  else
  {
    ROS_ERROR("Failed");
    return ;
  }
}
