set(PACKAGE_NAME "IBM XACC Accelerator")
set(PACKAGE_DESCIPTION "IBM XACC Accelerator Framework")
set(LIBRARY_NAME xacc-ibm-accelerator)
if(NOT WIN32)
  string(ASCII 27 Esc)
  set(ColorReset "${Esc}[m")
  set(BoldYellow "${Esc}[1;33m")
  set(BoldGreen "${Esc}[1;32m")
endif()

file(GLOB SRC
          IBMAccelerator.cpp
          IBMAcceleratorActivator.cpp
          IBMIRTransformation.cpp)

find_package(LAPACK)
if(LAPACK_FOUND)
  message(
    STATUS "${BoldGreen}Building local IBM Accelerator simulator.${ColorReset}")
  list(APPEND SRC LocalIBMAccelerator.cpp)
  include_directories(qiskit-terra/src/qasm-simulator-cpp/src)
  include_directories(qiskit-terra/src/qasm-simulator-cpp/src/backends)
  include_directories(qiskit-terra/src/qasm-simulator-cpp/src/engines)
  include_directories(qiskit-terra/src/qasm-simulator-cpp/src/utilities)
  include_directories(
    qiskit-terra/src/qasm-simulator-cpp/src/third-party/headers)
else()
  message(
    STATUS
      "${BoldYellow}Could not find Blas or Lapack, skipping local IBM simulator build.${ColorReset}"
    )
endif()

usfunctiongetresourcesource(TARGET ${LIBRARY_NAME} OUT SRC)
usfunctiongeneratebundleinit(TARGET ${LIBRARY_NAME} OUT SRC)

add_library(${LIBRARY_NAME} SHARED ${SRC})

set(_bundle_name xacc_ibm_accelerator)

set_target_properties(${LIBRARY_NAME}
                      PROPERTIES COMPILE_DEFINITIONS
                                 US_BUNDLE_NAME=${_bundle_name}
                                 US_BUNDLE_NAME
                                 ${_bundle_name})

usfunctionembedresources(TARGET
                         ${LIBRARY_NAME}
                         WORKING_DIRECTORY
                         ${CMAKE_CURRENT_SOURCE_DIR}
                         FILES
                         manifest.json)

if(LAPACK_FOUND)
  target_link_libraries(${LIBRARY_NAME} ${XACC_LIBRARIES} blas lapack)
else()
  target_link_libraries(${LIBRARY_NAME} ${XACC_LIBRARIES})
endif()

if(APPLE)
  set_target_properties(${LIBRARY_NAME}
                        PROPERTIES INSTALL_RPATH "@loader_path/../lib")
  set_target_properties(${LIBRARY_NAME}
                        PROPERTIES LINK_FLAGS "-undefined dynamic_lookup")
else()
  set_target_properties(${LIBRARY_NAME}
                        PROPERTIES INSTALL_RPATH "$ORIGIN/../lib")
  set_target_properties(${LIBRARY_NAME} PROPERTIES LINK_FLAGS "-shared")
endif()

install(TARGETS ${LIBRARY_NAME} DESTINATION ${CMAKE_INSTALL_PREFIX}/plugins)
