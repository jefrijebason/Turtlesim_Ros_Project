#!/usr/bin/env python3
import rclpy
import math
from rclpy.node import Node
from turtlesim.srv import Kill
from turtlesim.msg import Pose
from geometry_msgs.msg import Twist
from my_robot_interfaces.srv import CatchTurtle
from my_robot_interfaces.msg import TurtleArray
from functools import partial


class Turtle_Controller_Node(Node):
    def __init__(self):
        super().__init__("turtle_controller")
        self.pose_ = None
        self.turtle_to_catch_ = None
        self.target_x = 4.1
        self.target_y = 8.5
        self.cmd_vel_publisher_ = self.create_publisher(Twist, "turtle1/cmd_vel", 10)
        self.pose_subscriber_ = self.create_subscription(Pose, "turtle1/pose", self.callback_turtle_pose, 10)
        self.alive_turtles_subscriber_ = self.create_subscription(TurtleArray, "alive_turtle", self.callback_alive_turtles, 10)
        self.control_loop_timer_ = self.create_timer(0.01, self.control_loop)

    def callback_turtle_pose(self, msg):
        self.pose_ = msg

    def callback_alive_turtles(self, msg):
        # When the list of alive turtles is updated, choose the closest one
        if msg.turtles:
            closest_turtle = self.get_closest_turtle(msg.turtles)
            self.turtle_to_catch_ = closest_turtle

    def get_closest_turtle(self, turtles):
        min_dist = float("inf")
        closest_turtle = None
        for turtle in turtles:
            dist = math.sqrt((self.pose_.x - turtle.x) ** 2 + (self.pose_.y - turtle.y) ** 2)
            if dist < min_dist:
                min_dist = dist
                closest_turtle = turtle
        return closest_turtle

    def control_loop(self):
        if self.pose_ is None or self.turtle_to_catch_ is None:
            return

        dist_x = self.turtle_to_catch_.x - self.pose_.x
        dist_y = self.turtle_to_catch_.y - self.pose_.y
        distance = math.sqrt(dist_x * dist_x + dist_y * dist_y)

        msg = Twist()

        # Move towards the target if the turtle is far enough
        if distance > 0.5:
            msg.linear.x = 2 * distance

            goal_theta = math.atan2(dist_y, dist_x)
            diff = goal_theta - self.pose_.theta
            if diff > math.pi:
                diff -= 2 * math.pi
            elif diff < -math.pi:
                diff += 2 * math.pi

            msg.angular.z = 6 * diff
        else:
            msg.linear.x = 0.0
            msg.angular.z = 0.0

            # Catch the target turtle if within reach
            if self.turtle_to_catch_ is not None:
                self.call_catch_turtle_server(self.turtle_to_catch_.name)
                self.turtle_to_catch_ = None  # Reset after catching

        self.cmd_vel_publisher_.publish(msg)

    def call_catch_turtle_server(self, turtle_name):
        client = self.create_client(CatchTurtle, "catch_turtle")
        while not client.wait_for_service(timeout_sec=1.0):
            self.get_logger().warn("Waiting for catch turtle service...")

        request = CatchTurtle.Request()
        request.name = turtle_name

        future = client.call_async(request)
        future.add_done_callback(partial(self.callback_call_catch_turtle, turtle_name=turtle_name))

    def callback_call_catch_turtle(self, future, turtle_name):
        try:
            response = future.result()
            if response.success:
                self.get_logger().info(f"Turtle {turtle_name} was successfully caught.")
            else:
                self.get_logger().error(f"Failed to catch turtle {turtle_name}.")
        except Exception as e:
            self.get_logger().error(f"Service call failed: {e}")


def main(args=None):
    rclpy.init(args=args)
    node = Turtle_Controller_Node()
    rclpy.spin(node)
    rclpy.shutdown()


if __name__ == "__main__":
    main()
