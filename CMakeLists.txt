cmake_minimum_required(VERSION 3.20)

set(PROJECT_NAME "SouperDesSages")

project(${PROJECT_NAME} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE_FILE "${PROJECT_SOURCE_DIR}/SouperDesSages/src/*.cpp")
file(GLOB_RECURSE INCLUDE_FILE "${PROJECT_SOURCE_DIR}/SouperDesSages/include/*.h")

add_executable(${PROJECT_NAME}
			${SOURCE_FILE}
			${INCLUDE_FILE})

target_include_directories(${PROJECT_NAME} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/SouperDesSages/include")

source_group("Source Files" FILES ${SOURCE_FILE})
source_group("Header Files" FILES ${INCLUDE_FILE})


set_property(TARGET ${PROJECT_NAME} PROPERTY
VS_DEBUGGER_WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}")