cmake_minimum_required(VERSION 3.5)

project(12-1_rvalue_move_constructor LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(12-1_rvalue_move_constructor main.cpp)

include(GNUInstallDirs)
install(TARGETS 12-1_rvalue_move_constructor
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
