
CMAKE_MINIMUM_REQUIRED (VERSION 2.8)

PROJECT (TTTT CXX)

# Declare semantic versioning for FILVAL
SET(FILVAL_VERSION_MAJOR 0)
SET(FILVAL_VERSION_MINOR 1)
SET(FILVAL_VERSION_PATCH 0)
SET(CMAKE_BUILD_TYPE "Release")

CONFIGURE_FILE (
  "${PROJECT_SOURCE_DIR}/filval/filval.hpp"
  "${PROJECT_BINARY_DIR}/filval/filval.hpp"
  )


SET( TTTT_SOURCE_DIR ${CMAKE_CURRENT_SOURCE_DIR} )
SET( TTTT_BINARY_DIR ${CMAKE_CURRENT_BINARY_DIR} )

# Setup clang as the project compiler
SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
SET (CMAKE_CXX_FLAGS                "-Wall")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O3 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_AR      "/usr/bin/llvm-ar")
SET (CMAKE_LINKER  "/usr/bin/llvm-ld")
SET (CMAKE_NM      "/usr/bin/llvm-nm")
SET (CMAKE_OBJDUMP "/usr/bin/llvm-objdump")
SET (CMAKE_RANLIB  "/usr/bin/llvm-ranlib")

LIST( APPEND CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake )

FIND_PACKAGE(Jupyter)
IF(NBCONVERT_FOUND)
    ADD_CUSTOM_TARGET(notebook-docs
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/convert_nb ${NBCONVERT_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/docs
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Converting Jupyter Notebooks to HTML" VERBATIM
    )

    ADD_CUSTOM_TARGET(notebooks
        ${CMAKE_CURRENT_SOURCE_DIR}/cmake/convert_nb ${NBCONVERT_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/docs --update
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Re-Running notebooks and converting to HTML" VERBATIM
    )
ENDIF(NBCONVERT_FOUND)

# add a target to generate API documentation with Doxygen
FIND_PACKAGE(Doxygen)
IF(DOXYGEN_FOUND)
    CONFIGURE_FILE(
        ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in
        ${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile @ONLY
        )
    ADD_CUSTOM_TARGET(docs
        ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_BINARY_DIR}/docs/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs
        COMMENT "Generating API documentation with Doxygen" VERBATIM
        DEPENDS notebook-docs
    )
ENDIF(DOXYGEN_FOUND)


FIND_PACKAGE(ROOT REQUIRED)
INCLUDE_DIRECTORIES( SYSTEM ${ROOT_INCLUDE_DIR} ${CMAKE_CURRENT_SOURCE_DIR})

# Adds the dictionary library for addiitonal type serialization
SET( CLINGDICTFILE ${CMAKE_CURRENT_BINARY_DIR}/clingdict.cpp )
ROOT_GENERATE_DICTIONARY( "" ${CMAKE_CURRENT_SOURCE_DIR}/filval_root/LinkDef.hpp ${CLINGDICTFILE} "" )
ADD_LIBRARY( filval SHARED ${CLINGDICTFILE} )


ADD_EXECUTABLE(main ${CMAKE_CURRENT_SOURCE_DIR}/analysis/TTTT_Analysis.cpp)
TARGET_LINK_LIBRARIES( main filval ${ROOT_LIBRARIES} )

ADD_EXECUTABLE(mva ${CMAKE_CURRENT_SOURCE_DIR}/analysis/MVA_Creation.cpp)
TARGET_LINK_LIBRARIES( mva filval ${ROOT_LIBRARIES} )

ADD_CUSTOM_TARGET(examples
    COMMENT "Building Examples"
)
FILE(GLOB ExampleSources ${CMAKE_CURRENT_SOURCE_DIR}/filval/examples/example*.cpp)
FOREACH(ex_full_name IN LISTS ExampleSources)
    GET_FILENAME_COMPONENT(ex_name ${ex_full_name} NAME_WE)
    ADD_EXECUTABLE(${ex_name} EXCLUDE_FROM_ALL ${ex_full_name})
    ADD_DEPENDENCIES(examples ${ex_name})
    TARGET_LINK_LIBRARIES(${ex_name} filval ${ROOT_LIBRARIES} )
ENDFOREACH(ex_full_name)

