cmake_minimum_required(VERSION 3.5)

project(9-1_Template LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(9-1_Template main.cpp

)

include(GNUInstallDirs)
install(TARGETS 9-1_Template
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
