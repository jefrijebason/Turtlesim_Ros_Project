// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from custom_interfaces:srv/AddTwoInt.idl
// generated code does not contain a copyright notice

#ifndef CUSTOM_INTERFACES__SRV__DETAIL__ADD_TWO_INT__STRUCT_H_
#define CUSTOM_INTERFACES__SRV__DETAIL__ADD_TWO_INT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/AddTwoInt in the package custom_interfaces.
typedef struct custom_interfaces__srv__AddTwoInt_Request
{
  int64_t a;
  int64_t b;
} custom_interfaces__srv__AddTwoInt_Request;

// Struct for a sequence of custom_interfaces__srv__AddTwoInt_Request.
typedef struct custom_interfaces__srv__AddTwoInt_Request__Sequence
{
  custom_interfaces__srv__AddTwoInt_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__AddTwoInt_Request__Sequence;


// Constants defined in the message

/// Struct defined in srv/AddTwoInt in the package custom_interfaces.
typedef struct custom_interfaces__srv__AddTwoInt_Response
{
  int64_t sum;
} custom_interfaces__srv__AddTwoInt_Response;

// Struct for a sequence of custom_interfaces__srv__AddTwoInt_Response.
typedef struct custom_interfaces__srv__AddTwoInt_Response__Sequence
{
  custom_interfaces__srv__AddTwoInt_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} custom_interfaces__srv__AddTwoInt_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // CUSTOM_INTERFACES__SRV__DETAIL__ADD_TWO_INT__STRUCT_H_
