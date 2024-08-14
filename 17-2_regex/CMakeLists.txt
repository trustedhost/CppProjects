cmake_minimum_required(VERSION 3.5)

project(17-2_regex LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(17-2_regex main.cpp)

include(GNUInstallDirs)
install(TARGETS 17-2_regex
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
