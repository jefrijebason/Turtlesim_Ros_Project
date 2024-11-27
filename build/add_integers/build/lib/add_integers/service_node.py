import rclpy
from rclpy.node import Node
from custom_interfaces.srv import AddTwoInt  # Ensure your custom interface is properly generated

class AdditionService(Node):
    def __init__(self):
        super().__init__("add_int_service")
        
        # Create the service with the type AddTwoInt and the name "add_two_ints"
        self.service = self.create_service(
            AddTwoInt, "add_two_ints", self.add_two_ints_callback
        )

    def add_two_ints_callback(self, request, response):
        # Perform the addition and log the request details
        response.sum = request.a + request.b
        self.get_logger().info(f"Incoming request\n a: {request.a} b: {request.b} \nSending back response: {response.sum}")
        return response

def main(args=None):
    # Initialize ROS2 Python client library
    rclpy.init(args=args)
    
    # Create an instance of the AdditionService node
    addition_service = AdditionService()
    
    # Spin the node so it can process incoming requests
    rclpy.spin(addition_service)
    
    # Clean up by destroying the node and shutting down rclpy
    addition_service.destroy_node()
    rclpy.shutdown()

