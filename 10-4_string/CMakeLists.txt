cmake_minimum_required(VERSION 3.5)

project(10-4_string LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(10-4_string main.cpp)

include(GNUInstallDirs)
install(TARGETS 10-4_string
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
