#!/usr/bin/env python

import rospy
import system_msgs.srv


def main():
    rospy.init_node("client")

    get_joke = rospy.ServiceProxy('get_joke', system_msgs.srv.joke)
    req = system_msgs.srv.jokeRequest()
    req.custom_request = "Tell me a Joke"
    resp = get_joke(req)
    print(resp.custom_response)

    get_square = rospy.ServiceProxy('get_square', system_msgs.srv.square)
    req = system_msgs.srv.squareRequest()
    req.a = 25
    resp = get_square(req)
    print(resp.b)


if __name__ == "__main__":
    main()
