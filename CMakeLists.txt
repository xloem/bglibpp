project(bglib)

add_library(bglib++ bglib++/bglib.cpp)

add_executable(scan_example scan_example++/main.cpp)

target_link_libraries(scan_example bglib++)
add_dependencies(scan_example bglib++)
