#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from example_interfaces.msg import String    
    
class ReceiveNode(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("subscribe")
        
        self.subscribe_=self.create_subscription(String,"robot_new",self.callback_robot_news,10)
        self.get_logger().info("subscribe Station has started ")

    def callback_robot_news(self,msg):
        self.get_logger().info(msg.data)


def main(args=None):
    rclpy.init(args=args)
    node = ReceiveNode()
    rclpy.spin(node)
    rclpy.shutdown()
    
    
# if __name__ == "__main__":
#     main()