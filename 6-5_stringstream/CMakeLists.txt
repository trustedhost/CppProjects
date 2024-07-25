cmake_minimum_required(VERSION 3.5)

project(6-5_stringstream LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(6-5_stringstream main.cpp)

include(GNUInstallDirs)
install(TARGETS 6-5_stringstream
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
