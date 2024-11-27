#!/usr/bin/env python3
import rclpy
from rclpy.node import Node

from example_interfaces.srv import AddTwoInts

class AddTwoIntsServerNode(Node):
    def __init__(self):
        super().__init__("add_int_server")
        self.server_ =self.create_service(AddTwoInts,"add_int_server",self.call_back_two_init)
        self.get_logger().info("Add ints server has started ")


    def call_back_two_init(self,request,response):
        response.sum=request.a + request.b
        self.get_logger().info(str(request.a)+" + "+ str(request.b)+" = "+str(response.sum))
        return response   


def main(args=None):
    rclpy.init(args=args)
    node =AddTwoIntsServerNode()
    rclpy.spin(node)
    rclpy.shutdown()
