#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String    
    
class SendNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("publisher")
        
        self.publisher_=self.create_publisher(String,"robot_new",10)
        self.timer_=self.create_timer(0.5,self.publish_news)
        self.get_logger().info("Robot News Station has started ")

    def publish_news(self):
        msg=String()
        msg.data = "Hello"
        self.publisher_.publish(msg) 


def main(args=None):
    rclpy.init(args=args)
    node = SendNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
    
# if __name__ == "__main__":
#     main()