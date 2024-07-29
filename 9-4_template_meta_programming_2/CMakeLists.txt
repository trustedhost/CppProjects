cmake_minimum_required(VERSION 3.5)

project(9-4_template_meta_programming_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9-4_template_meta_programming_2 main.cpp)

include(GNUInstallDirs)
install(TARGETS 9-4_template_meta_programming_2
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
