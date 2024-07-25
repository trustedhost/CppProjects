cmake_minimum_required(VERSION 3.5)

project(6-2_Virtual_polimorphism LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(6-2_Virtual_polimorphism main.cpp)

include(GNUInstallDirs)
install(TARGETS 6-2_Virtual_polimorphism
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
