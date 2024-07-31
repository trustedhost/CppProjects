cmake_minimum_required(VERSION 3.5)

project(11_Exception LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(11_Exception main.cpp)

include(GNUInstallDirs)
install(TARGETS 11_Exception
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
