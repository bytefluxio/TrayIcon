cmake_minimum_required(VERSION 3.5)

project(TrayIcon VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR})

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_BINARY_DIR}/conanbuildinfo.cmake)
conan_basic_setup(TARGETS)
conan_set_vs_runtime()
conan_set_libcxx()
conan_output_dirs_setup()

find_package(Qt6 REQUIRED CONFIG)

set(PROJECT_SOURCES
        main.cpp
        resources.qrc)

add_executable(${PROJECT_NAME} ${PROJECT_SOURCES})

target_link_libraries(${PROJECT_NAME} CONAN_PKG::qt Qt6::Core Qt6::Widgets)

file(
        COPY
        ${CMAKE_BINARY_DIR}/qt.conf
        DESTINATION
        ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
