#include "ros/ros.h"
#include "first_task/Navigator.h"
#include <cstdlib>

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "Navigator_client");

  if(argc!=2)
  {
    ROS_INFO("Client");
    return 1;
  }

  ros::NodeHandle n;
  ros::ServiceClient client = n.serviceClient<first_task::Navigator>("find_fibonacci");

  first_task::Navigator srv;
  srv.request.x = atoll(argv[1]);

  if(client.call(srv))
  {
    ROS_INFO("Fibonacci Number : %ld", (long int)srv.response.fibo);
  }
  else
  {
    ROS_ERROR("Failed");
    return 1;
  }

  return 0;
}
