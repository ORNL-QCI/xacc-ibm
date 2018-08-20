cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(xacc-ibm LANGUAGES CXX)

set(CMAKE_STANDARD_REQUIRED ON)
set(CMAKE_CXX_STANDARD 11)
message(STATUS "C++ version ${CXX_STANDARD} configured.")

option(IBM_BUILD_TESTS "Build test programs" OFF)

if (FROM_SETUP_PY AND NOT APPLE)
   message(STATUS "Running build from setup.py, linking to static libstdc++")
   set (CMAKE_SHARED_LINKER_FLAGS "-static-libstdc++" CACHE INTERNAL "" FORCE)
endif()

# Make sure all build libraries have reference to their dependents
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

find_package(XACC REQUIRED)

if (CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set (CMAKE_INSTALL_PREFIX "${XACC_ROOT}" CACHE PATH "default install path" FORCE )
endif()

set(CppMicroServicesConfig_DIR "${XACC_ROOT}/share/cppmicroservices4/cmake")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${XACC_ROOT}/share/xacc")
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CppMicroServicesConfig_DIR}")
include(tests)
include(CppMicroServicesConfig)

configure_file("${CMAKE_SOURCE_DIR}/cmake/xacc-ibm-config.hpp.in" "${CMAKE_BINARY_DIR}/xacc-ibm-config.hpp")

include_directories(${CMAKE_BINARY_DIR})

include_directories(${XACC_INCLUDE_DIRS})
include_directories(${CMAKE_SOURCE_DIR}/utils)

link_directories(${XACC_LIBRARY_DIR})

if(${XACC_HAS_ANTLR})
   add_subdirectory(compiler)
endif()
add_subdirectory(accelerator)
if(PYTHON_INCLUDE_DIR)
   add_subdirectory(python)
endif()

if(IBM_BUILD_TESTS)
   include_directories(${CMAKE_SOURCE_DIR}/accelerator)
   include_directories(${CMAKE_SOURCE_DIR}/utils)
   add_subdirectory(examples)
   add_subdirectory(tests)
endif()

