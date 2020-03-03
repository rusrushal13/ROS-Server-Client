# ROS Server and Client

Build a system of two ROS Nodes where one ROS Node runs in Python3(working as a Client) and another ROS Node runs in C++(Working as a server)

## Running the Application

> Assuming the installation been done for ROS, if not please go [here](http://wiki.ros.org/melodic/Installation)

- Run the roscore master

```bash
roscore
```

- Run the server

```bash
rosrun server server
```

- Run the Client

```bash
rosrun client client.py
```

## Running the Application using Docker

```docker
docker-compose up
```

## Resources Used

- [ROS Tutorials](http://wiki.ros.org/ROS/Tutorials)

- [ROS in Docker container](https://answers.ros.org/question/312577/catkin_make-command-not-found-executing-by-a-dockerfile/)

- [Justin Huang Youtube Channel](https://www.youtube.com/channel/UC1NUHtM57Ge5qai4s0AaBEg)

- [Christian Henkel ROS Industrial Conference talk on running the ROS nodes inside Docker containers](https://www.youtube.com/watch?v=Ubdc96GkO3M)

- [ROS and Docker Paper](https://www.researchgate.net/publication/317751755_ROS_and_Docker)

- [Ruffsl ROS Docker Demos](https://github.com/ruffsl/ros_docker_demos)
