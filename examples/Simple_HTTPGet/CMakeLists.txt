cmake_minimum_required(VERSION 3.5)
project(Simple_HTTPGet LANGUAGES CXX)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(../../ wserver/build)

add_executable(${PROJECT_NAME}
    main.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE
    ../../include
    ../../third_party/nettools/xsocket/include/
)
target_link_libraries(${PROJECT_NAME}
    wserver
)
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
)
