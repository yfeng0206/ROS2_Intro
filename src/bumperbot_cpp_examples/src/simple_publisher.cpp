#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

#include <chrono>

using namespace std::chrono_literals;

class SimplePublisher: public rclcpp::Node 
{
public:
//this is the constructor
    SimplePublisher() : Node("Mega_Death_Star_Node"), counter_(0)
    {
        /*creates the publisher by calling the partent function of create publisher*/
        pub_ = create_publisher<std_msgs::msg::String>("chatter_Topic", 10);
        /*Here we use the bind to know what function to call. And we use the timerCallback and this
        because it belongs to an object. If it is a free function you can just do bind(function1()).
        It also create a callable object with bind*/
        timer_ = create_wall_timer(1s, std::bind(&SimplePublisher::timerCallback,this));

        RCLCPP_INFO(get_logger(),"publishing at 1 Hz");
    }

private:
    unsigned int counter_;
    /*
    std::shared_ptr<rclcpp::Publisher <std_msgs::msg::String>> pub_;
    We use shared pointers here because we don't want the publisher and timers to be deleted
    if you don't pass them as publisher and timer here and keep them in this variable they will die
    when the scope ends
    */
    rclcpp::Publisher <std_msgs::msg::String> :: SharedPtr pub_;
    rclcpp::TimerBase:: SharedPtr timer_;

    void timerCallback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello ROS 2 - counter : " + std::to_string(counter_++);

        pub_->publish(message);
    }
};

int main(int argc, char* argv[])
{
    rclcpp::init(argc,argv);
    auto node = std::make_shared<SimplePublisher>();
    rclcpp::spin(node);
    rclcpp::shutdown();

    return 0;
}