project(bglib++)

add_library(bglib++ bglib++/bglib.cpp)
target_include_directories(bglib++ INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/bglib++)

install(TARGETS bglib++ DESTINATION lib)
install(FILES bglib++/bglib.hpp bglib++/bglib_types.hpp DESTINATION include)

add_executable(scan_example scan_example++/main.cpp)
target_link_libraries(scan_example bglib++)
