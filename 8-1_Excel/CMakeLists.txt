cmake_minimum_required(VERSION 3.5)

project(8-1_Excel LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(8-1_Excel main.cpp
    utils.h
    utils.cpp)

include(GNUInstallDirs)
install(TARGETS 8-1_Excel
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
