

import rclpy

from std_msgs.msg import String 
node=None
def chat_callback(msg):
    node.get_logger().info(f'Received: {msg.data}')
def main(args=None):
    global node 
    rclpy.init(args=args)

    node=rclpy.create_node('number_subscriber')
    sub=node.create_subscription(String,'count',chat_callback,10)

    while rclpy.ok():
        rclpy.spin_once(node)
    node.destroy_node()
    rclpy.shutdown()
if __name__=='__main__':    main()
