cmake_minimum_required(VERSION 3.5)

project(9-2_Variadic_template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9-2_Variadic_template main.cpp)

include(GNUInstallDirs)
install(TARGETS 9-2_Variadic_template
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
