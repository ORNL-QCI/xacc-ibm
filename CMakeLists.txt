cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(xacc-rigetti LANGUAGES CXX)

set(CMAKE_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
message(STATUS "C++ version ${CXX_STANDARD} configured.")

# Make sure all build libraries have reference to their dependents
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(XACC REQUIRED)

set(CppMicroServicesConfig_DIR "${XACC_ROOT}/share/cppmicroservices3/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${XACC_ROOT}/share/xacc")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CppMicroServicesConfig_DIR}")
include(tests)
include(CppMicroServicesConfig)

find_package(Boost COMPONENTS system program_options filesystem chrono thread REQUIRED)

configure_file("${CMAKE_SOURCE_DIR}/cmake/xacc-ibm-config.hpp.in" "${CMAKE_BINARY_DIR}/xacc-ibm-config.hpp")

include_directories(${CMAKE_BINARY_DIR})

include_directories(${XACC_INCLUDE_DIRS})
include_directories(${Boost_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/utils)

link_directories(${XACC_LIBRARY_DIR})

add_subdirectory(accelerator)
add_subdirectory(examples)

