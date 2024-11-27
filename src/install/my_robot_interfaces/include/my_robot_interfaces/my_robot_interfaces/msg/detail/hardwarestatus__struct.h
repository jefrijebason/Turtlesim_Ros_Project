// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_robot_interfaces:msg/Hardwarestatus.idl
// generated code does not contain a copyright notice

#ifndef MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARESTATUS__STRUCT_H_
#define MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARESTATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'debug_message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/Hardwarestatus in the package my_robot_interfaces.
typedef struct my_robot_interfaces__msg__Hardwarestatus
{
  int64_t temperature;
  bool are_motors_ready;
  rosidl_runtime_c__String debug_message;
} my_robot_interfaces__msg__Hardwarestatus;

// Struct for a sequence of my_robot_interfaces__msg__Hardwarestatus.
typedef struct my_robot_interfaces__msg__Hardwarestatus__Sequence
{
  my_robot_interfaces__msg__Hardwarestatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_robot_interfaces__msg__Hardwarestatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_ROBOT_INTERFACES__MSG__DETAIL__HARDWARESTATUS__STRUCT_H_
