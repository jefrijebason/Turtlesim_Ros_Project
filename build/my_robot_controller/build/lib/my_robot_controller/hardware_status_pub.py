#!/usr/bin/env python3
import rclpy
from rclpy.node import Node
from my_robot_interfaces.msg import Hardwarestatus
    
class Hardware_status_Node(Node): # MODIFY NAME
    def __init__(self):
        super().__init__("Hardware_status_pub")
        
        
        self.get_logger().info("Robot News Station has started ")


def main(args=None):
    rclpy.init(args=args)
    node = Hardware_status_Node()
    rclpy.spin(node)
    rclpy.shutdown()
    
    
# if __name__ == "__main__":
#     main()