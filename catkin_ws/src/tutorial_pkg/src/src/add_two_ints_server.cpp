# include "ros/ros.h"
# include "tutorial_pkg/AddTwoInts.h"

bool add(tutorial_pkg::AddTwoInts::Request &req, tutorial_pkg::AddTwoInts::Response &res)
{
    res.sum = req.a + req.b;
    ROS_INFO("request: x=%1d, y=%1d", (long int)req.a, (long int)req.b);
    ROS_INFO("sending back response: [%1d]", (long int)res.sum);
    return true;
}


int main (int argc, char **argv)
{
    ros::init(argc, argv, "add_two_ints_server");
    ros::NodeHandle n;

    ros::ServiceServer service = n.advertiseService("add_two_ints", add);
    ROS_INFO("Ready to add two ints.");
    ros::spin();
    return 0;
}
