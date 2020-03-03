#include "ros/ros.h"
#include <string>
#include "system_msgs/joke.h"
#include "system_msgs/jokeRequest.h"
#include "system_msgs/jokeResponse.h"
#include "system_msgs/square.h"
#include "system_msgs/squareRequest.h"
#include "system_msgs/squareResponse.h"

class ServerHandling
{
public:
    ServerHandling() {}

    bool GetJoke(system_msgs::jokeRequest &request,
                 system_msgs::jokeResponse &response)
    {
        std::string custom_req = request.custom_request;
        std::transform(custom_req.begin(), custom_req.end(), custom_req.begin(), ::tolower);
        ROS_INFO("Get Joke called for %s", request.custom_request.c_str());
        if (custom_req == "tell me a joke")
        {
            response.custom_response = "I am not funny";
        }
        else if (custom_req == "")
        {
            response.custom_response = "Okay, will think a joke for you";
        }
        else
        {
            response.custom_response = "Will handle this later";
        }
        ROS_INFO("Sending back response %s", response.custom_response.c_str());
        return true;
    }

    bool GetSquare(system_msgs::squareRequest &request,
                   system_msgs::squareResponse &response)
    {
        ROS_INFO("Get Square for [%ld]", (long int)request.a);
        return true;
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "server");
    ros::NodeHandle nh;

    ServerHandling serverHandling;

    ros::ServiceServer get_joke = nh.advertiseService(
        "get_joke", &ServerHandling::GetJoke, &serverHandling);
    ros::ServiceServer get_square = nh.advertiseService(
        "get_square", &ServerHandling::GetSquare, &serverHandling);
    ros::spin();
    return 0;
}