cmake_minimum_required(VERSION 3.5)
project(wserver LANGUAGES CXX)

set(CMAKE_COMPILE_WARNING_AS_ERROR ON)
set(CMAKE_CXX_STANDARD 20)

add_subdirectory(third_party)

add_library(${PROJECT_NAME} STATIC
    src/wserver/wserverext/wserverhttp/wserverhttp.cpp
    src/wserver/types/wsocket.cpp
)
target_include_directories(${PROJECT_NAME} PRIVATE
    include
    third_party/spdlog/include/
    third_party/nettools/xsocket/include/
)
target_link_libraries(${PROJECT_NAME}
    spdlog::spdlog
    xsocket
)
if (!WIN32)
target_compile_options(${PROJECT_NAME} PRIVATE
    -Wall
)
endif()
