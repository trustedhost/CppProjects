cmake_minimum_required(VERSION 3.5)

project(16-1_uniform_initialization LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(16-1_uniform_initialization main.cpp)

include(GNUInstallDirs)
install(TARGETS 16-1_uniform_initialization
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
