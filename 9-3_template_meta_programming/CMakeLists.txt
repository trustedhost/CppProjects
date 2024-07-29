cmake_minimum_required(VERSION 3.5)

project(9-3_template_meta_programming LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9-3_template_meta_programming main.cpp)

include(GNUInstallDirs)
install(TARGETS 9-3_template_meta_programming
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
