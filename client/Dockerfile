FROM ros:latest

RUN apt-get update && \
    apt-get install -y python-catkin-tools && \
    rm -rf /var/lib/apt/lists/*

ENV ROS_WS /opt/ros_ws

RUN mkdir -p $ROS_WS/src

WORKDIR $ROS_WS

COPY . $ROS_WS/src

RUN catkin config --extend /opt/ros/$ROS_DISTRO && \
    catkin build

RUN sed --in-place --expression \
    '$isource "$ROS_WS/devel/setup.bash"' \
    /ros_entrypoint.sh

CMD ["rosrun", "client", "client.py"]
