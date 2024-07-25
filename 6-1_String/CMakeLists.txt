cmake_minimum_required(VERSION 3.5)

project(6-1_String LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(6-1_String main.cpp
    employee.h employee.cpp
    employeelist.h employeelist.cpp
    manager.h manager.cpp)

include(GNUInstallDirs)
install(TARGETS 6-1_String
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
