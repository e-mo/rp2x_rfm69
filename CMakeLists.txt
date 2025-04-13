cmake_minimum_required(VERSION 3.13)

project(rp2x_rfm69_lib C CXX ASM)

add_library(rp2x_rfm69_lib INTERFACE)

target_sources(rp2x_rfm69_lib INTERFACE
	src/rp2x_rfm69_interface.c
)

target_include_directories(rp2x_rfm69_lib INTERFACE
	src
)

target_link_libraries(rp2x_rfm69_lib INTERFACE
	hardware_gpio
	hardware_spi
)
