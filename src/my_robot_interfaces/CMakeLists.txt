cmake_minimum_required(VERSION 3.8)
project(my_robot_interfaces)

# Optional: add compiler flags if using GCC or Clang
if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Find dependencies
find_package(ament_cmake REQUIRED)
find_package(rosidl_default_generators REQUIRED)
find_package(std_msgs REQUIRED)  # Ensure std_msgs is found

# Generate interfaces (messages, services, actions)
rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Hardwarestatus.msg"  # Ensure this message file exists
  "msg/Turtle.msg"          # Ensure this message file exists
  "msg/TurtleArray.msg"
  "srv/CatchTurtle.srv"     # Ensure this message file exists
  DEPENDENCIES std_msgs     # std_msgs should be available now
)

# Export runtime dependencies (ensures other packages can find the generated code)
ament_export_dependencies(rosidl_default_runtime)

# Test dependencies (optional, for linting)
if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # Skip the linter checking for copyrights
  set(ament_cmake_copyright_FOUND TRUE)
  # Skip cpplint if not in a git repo
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

# Declare the package to ament
ament_package()
