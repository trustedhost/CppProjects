cmake_minimum_required(VERSION 3.5)

project(12-2_move_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(12-2_move_2 main.cpp)

include(GNUInstallDirs)
install(TARGETS 12-2_move_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
