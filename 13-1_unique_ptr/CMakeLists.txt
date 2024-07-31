cmake_minimum_required(VERSION 3.5)

project(13-1_unique_ptr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(13-1_unique_ptr main.cpp)

include(GNUInstallDirs)
install(TARGETS 13-1_unique_ptr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
