cmake_minimum_required(VERSION 3.23)

project(Pufferfish C)  # Specify C language at project level

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)  # Fixed typo: was CMAKE_C_REQUIRED
set(CMAKE_C_EXTENSIONS OFF)  # Optional: disable GNU extensions for portability

# Set debug build type if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# Add flags - these are good!
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g3 -Wall -Wextra -Wpedantic -Werror")

add_executable(Pufferfish 
    main.c
    board.c
)