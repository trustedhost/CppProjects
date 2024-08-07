cmake_minimum_required(VERSION 3.5)

project(16-2_constexpr_class_define LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(16-2_constexpr_class_define main.cpp)

include(GNUInstallDirs)
install(TARGETS 16-2_constexpr_class_define
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
