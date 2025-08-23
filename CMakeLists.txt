cmake_minimum_required(VERSION 3.16)
project(RayTracing VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

add_executable(RayTracing main.cpp "sdl_setup.h"  "vec3.h" "color.h" "ray.h" "hittable.h" "sphere.h" "hittable_list.h" "rtweekend.h" "interval.h" "camera.h" "material.h")

# Include SDL2 headers
include_directories("C:/Users/hp/sdl/SDL2-2.30.11/include")

# Link SDL2 library
target_link_libraries(RayTracing "C:/Users/hp/sdl/SDL2-2.30.11/lib/x64/SDL2.lib")
target_link_libraries(RayTracing "C:/Users/hp/sdl/SDL2-2.30.11/lib/x64/SDL2main.lib")
