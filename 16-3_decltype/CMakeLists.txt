cmake_minimum_required(VERSION 3.5)

project(16-3_decltype LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(16-3_decltype main.cpp)

include(GNUInstallDirs)
install(TARGETS 16-3_decltype
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
