# CMake 最低版本要求
cmake_minimum_required(VERSION 3.10.2)

# 支持 gnu++11
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

add_library( # Sets the name of the library.
        exp82464

        # Sets the library as a shared library.
        SHARED

        # Provides a relative path to your source file(s).
        ruin.c
        )

target_link_libraries(
        # 指定目标库
        exp82464
)
