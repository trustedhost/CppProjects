cmake_minimum_required(VERSION 3.5)

project(14_Callable LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(14_Callable main.cpp)

include(GNUInstallDirs)
install(TARGETS 14_Callable
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
