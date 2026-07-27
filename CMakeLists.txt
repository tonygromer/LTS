cmake_minimum_required(VERSION 3.10)
project(LaptimeSim)
add_executable(LTS)
target_sources(LTS
               PRIVATE
               src/laptimesim.cpp)
               