
import rclpy

from std_msgs.msg import String 
def main(args=None):
    rclpy.init(args=args)
    node=rclpy.create_node('number_publisher')
    publ=node.create_publisher(String,'count',10)
    msg=String()
    i=0
    ###########
    def timer_callback():
        nonlocal i
        msg.data='/the count is :%d'%i
        i+=1
        node.get_logger().info(f'Publishing: {msg.data}')
        publ.publish(msg)

    timer=node.create_timer (0.5,timer_callback)
    rclpy.spin(node)
    node.destroy_node()
    rclpy.shutdown()
    #############

if __name__=='__main__':    main()







    # node = rclpy.create_node('my_first_publisher')
    # publisher = node.create_publisher(String, 'my_first_topic', 10)
    # msg = String()
    # msg.data = 'Hello, ROS2!'
    # while rclpy.ok():
    #     publisher.publish(msg)
    #     node.get_logger().info(f'Published: {msg.data}')
    #     rclpy.spin_once(node, timeout_sec=1.0)