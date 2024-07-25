cmake_minimum_required(VERSION 3.5)

project(6-5_ifstream_ofstream_stringstream LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(6-5_ifstream_ofstream_stringstream main.cpp
    test.txt)

include(GNUInstallDirs)
install(TARGETS 6-5_ifstream_ofstream_stringstream
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
