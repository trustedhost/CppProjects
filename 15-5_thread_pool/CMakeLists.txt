cmake_minimum_required(VERSION 3.5)

project(15-5_thread_pool LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(15-5_thread_pool main.cpp
    threadpool.h threadpool.cpp)

include(GNUInstallDirs)
install(TARGETS 15-5_thread_pool
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
