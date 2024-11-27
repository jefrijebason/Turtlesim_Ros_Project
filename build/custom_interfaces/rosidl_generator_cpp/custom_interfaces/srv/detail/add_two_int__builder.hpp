// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:srv/AddTwoInt.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__ADD_TWO_INT__BUILDER_HPP_
#define CUSTOM_INTERFACES__SRV__DETAIL__ADD_TWO_INT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/srv/detail/add_two_int__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddTwoInt_Request_b
{
public:
  explicit Init_AddTwoInt_Request_b(::custom_interfaces::srv::AddTwoInt_Request & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::srv::AddTwoInt_Request b(::custom_interfaces::srv::AddTwoInt_Request::_b_type arg)
  {
    msg_.b = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::AddTwoInt_Request msg_;
};

class Init_AddTwoInt_Request_a
{
public:
  Init_AddTwoInt_Request_a()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_AddTwoInt_Request_b a(::custom_interfaces::srv::AddTwoInt_Request::_a_type arg)
  {
    msg_.a = std::move(arg);
    return Init_AddTwoInt_Request_b(msg_);
  }

private:
  ::custom_interfaces::srv::AddTwoInt_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::AddTwoInt_Request>()
{
  return custom_interfaces::srv::builder::Init_AddTwoInt_Request_a();
}

}  // namespace custom_interfaces


namespace custom_interfaces
{

namespace srv
{

namespace builder
{

class Init_AddTwoInt_Response_sum
{
public:
  Init_AddTwoInt_Response_sum()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::custom_interfaces::srv::AddTwoInt_Response sum(::custom_interfaces::srv::AddTwoInt_Response::_sum_type arg)
  {
    msg_.sum = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::srv::AddTwoInt_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::srv::AddTwoInt_Response>()
{
  return custom_interfaces::srv::builder::Init_AddTwoInt_Response_sum();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__ADD_TWO_INT__BUILDER_HPP_
