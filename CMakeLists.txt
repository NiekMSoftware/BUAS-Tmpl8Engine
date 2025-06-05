cmake_minimum_required(VERSION 3.31)
project(buas_engine VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

# Include OpenGL
find_package(OpenGL REQUIRED)
include(FetchContent)

# GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw.git
        GIT_TAG 3.4
)
FetchContent_MakeAvailable(glfw)

# Include directories
include_directories(
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_SOURCE_DIR}/extern/glad/include
        ${PROJECT_SOURCE_DIR}/extern/json/include
)

set(GLAD_SOURCE "${PROJECT_SOURCE_DIR}/extern/glad/src/glad.c")
add_library(glad STATIC ${GLAD_SOURCE})
target_include_directories(glad PRIVATE ${PROJECT_SOURCE_DIR}/extern/glad/include)

# Disable warnings for GLAD
if(MSVC)
    target_compile_options(glad PRIVATE /W0)
else()
    target_compile_options(glad PRIVATE -w)
endif()

# Engine library source files
file(GLOB_RECURSE ENGINE_LIB_SOURCES
        "src/*.cpp"
        "src/*.h"
        "include/*.h"
        "extern/glad/src/glad.c"
)

# Remove main.cpp from the engine library sources
list(FILTER ENGINE_LIB_SOURCES EXCLUDE REGEX ".*main\\.cpp$")

# Link library dependencies
add_library(buas_engine_lib STATIC ${ENGINE_LIB_SOURCES})
target_link_libraries(buas_engine_lib
        PUBLIC
        OpenGL::GL
        glfw
        glad
)

# Create main executable
add_executable(buas_engine src/main.cpp)

# Link the executable with the engine library
target_link_libraries(buas_engine PRIVATE buas_engine_lib)

# Enable warning levels
if(MSVC)
    target_compile_options(buas_engine_lib PRIVATE /W4)
    target_compile_options(buas_engine PRIVATE /W4)
else()
    target_compile_options(buas_engine_lib PRIVATE -Wall -Wextra -Wpedantic)
    target_compile_options(buas_engine PRIVATE -Wall -Wextra -Wpedantic)
endif()

# Copy shader resources during build
add_custom_command(TARGET buas_engine POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:buas_engine>/resources
)

add_executable(example_window examples/hello_window.cpp)
target_link_libraries(example_window PRIVATE buas_engine_lib)

# Copy example resources for the example project
add_custom_command(TARGET example_window POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/resources $<TARGET_FILE_DIR:example_window>/resources
)

message(STATUS "Configured ${PROJECT_NAME} v${PROJECT_VERSION}")