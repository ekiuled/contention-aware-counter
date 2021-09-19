project(counter)

set(CMAKE_CXX_STANDARD 17)

add_executable(test counter.cpp test.cpp)
target_link_libraries(test pthread)