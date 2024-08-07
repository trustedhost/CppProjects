cmake_minimum_required(VERSION 3.5)

project(16-2_if_constexpr LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(16-2_if_constexpr main.cpp)

include(GNUInstallDirs)
install(TARGETS 16-2_if_constexpr
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
