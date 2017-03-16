cmake_minimum_required(VERSION 3.6)
project(get_next_line)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")

set(SOURCE_FILES get_next_line.c get_next_line.h libft/libft.h main.c)
add_executable(get_next_line ${SOURCE_FILES})
target_link_libraries(get_next_line ${CMAKE_SOURCE_DIR}/libft.a)