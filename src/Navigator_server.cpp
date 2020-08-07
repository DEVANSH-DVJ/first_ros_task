#include "ros/ros.h"
#include "first_task/Navigator.h"

long int fib(long int x)
{
  if(x==1 || x==2)
    return 1;
  else return fib(x-1) + fib(x-2);
}

bool fibonacci(first_task::Navigator::Request &req,
                first_task::Navigator::Response &res)
{
  res.fibo = fib(req.x);
  ROS_INFO("request: x=%ld", (long int)req.x);
  ROS_INFO("sending back response: [%ld]", (long int)res.fibo);
  return true;
}

int main(int argc, char *argv[])
{
  ros::init(argc, argv, "Navigator_server");

  ros::NodeHandle n;

  ros::Rate loop_rate(0.2);

  ros::ServiceServer service = n.advertiseService("find_fibonacci", fibonacci);

  while(ros::ok())
  {
    ROS_INFO("Working");
    ros::spinOnce();
    loop_rate.sleep();
  }

  return 0;
}
