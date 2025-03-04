cmake_minimum_required(VERSION 3.8)
project(bumperbot_cpp_examples)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(rcl_interfaces REQUIRED)
find_package(turtlesim REQUIRED)

include_directories(include)

# uncomment the following section in order to fill in
# further dependencies manually.
# find_package(<dependency> REQUIRED)

add_executable(simple_publisher src/simple_publisher.cpp)
ament_target_dependencies(simple_publisher rclcpp std_msgs)
add_executable(simple_subs src/simple_subs.cpp)
ament_target_dependencies(simple_subs rclcpp std_msgs)
add_executable(simple_parameter src/simple_parameter.cpp)
ament_target_dependencies(simple_parameter rclcpp std_msgs rcl_interfaces)
add_executable(simple_turtlesim_kinematics src/simple_turtlesim_kinematics.cpp)
ament_target_dependencies(simple_turtlesim_kinematics rclcpp std_msgs turtlesim)


install(
  DIRECTORY include
  DESTINATION include
)

install(TARGETS 
  simple_publisher
  simple_subs
  simple_parameter
  simple_turtlesim_kinematics
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()
