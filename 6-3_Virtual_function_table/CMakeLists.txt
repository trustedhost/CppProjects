cmake_minimum_required(VERSION 3.5)

project(6-3_Virtual_function_table LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(6-3_Virtual_function_table main.cpp)

include(GNUInstallDirs)
install(TARGETS 6-3_Virtual_function_table
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
