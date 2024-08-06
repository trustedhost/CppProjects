cmake_minimum_required(VERSION 3.5)

project(15-4_future_promise LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(15-4_future_promise main.cpp)

include(GNUInstallDirs)
install(TARGETS 15-4_future_promise
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
