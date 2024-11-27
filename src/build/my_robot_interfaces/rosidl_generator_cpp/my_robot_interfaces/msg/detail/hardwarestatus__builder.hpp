// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_robot_interfaces:msg/Hardwarestatus.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARESTATUS__BUILDER_HPP_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARESTATUS__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_robot_interfaces/msg/detail/hardwarestatus__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_robot_interfaces
{

namespace msg
{

namespace builder
{

class Init_Hardwarestatus_debug_message
{
public:
  explicit Init_Hardwarestatus_debug_message(::my_robot_interfaces::msg::Hardwarestatus & msg)
  : msg_(msg)
  {}
  ::my_robot_interfaces::msg::Hardwarestatus debug_message(::my_robot_interfaces::msg::Hardwarestatus::_debug_message_type arg)
  {
    msg_.debug_message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_robot_interfaces::msg::Hardwarestatus msg_;
};

class Init_Hardwarestatus_are_motors_ready
{
public:
  explicit Init_Hardwarestatus_are_motors_ready(::my_robot_interfaces::msg::Hardwarestatus & msg)
  : msg_(msg)
  {}
  Init_Hardwarestatus_debug_message are_motors_ready(::my_robot_interfaces::msg::Hardwarestatus::_are_motors_ready_type arg)
  {
    msg_.are_motors_ready = std::move(arg);
    return Init_Hardwarestatus_debug_message(msg_);
  }

private:
  ::my_robot_interfaces::msg::Hardwarestatus msg_;
};

class Init_Hardwarestatus_temperature
{
public:
  Init_Hardwarestatus_temperature()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Hardwarestatus_are_motors_ready temperature(::my_robot_interfaces::msg::Hardwarestatus::_temperature_type arg)
  {
    msg_.temperature = std::move(arg);
    return Init_Hardwarestatus_are_motors_ready(msg_);
  }

private:
  ::my_robot_interfaces::msg::Hardwarestatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_robot_interfaces::msg::Hardwarestatus>()
{
  return my_robot_interfaces::msg::builder::Init_Hardwarestatus_temperature();
}

}  // namespace my_robot_interfaces

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARESTATUS__BUILDER_HPP_
