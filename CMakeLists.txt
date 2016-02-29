# CMakeLists.txt --- CMake project settings
##############################################################################

# CMake minimum version
cmake_minimum_required(VERSION 2.4)

# project name and language
project(TypicalConsoleApp CXX)

# set program information
set(PROGRAM_MAJOR 0)
set(PROGRAM_MINOR 1)
set(PROGRAM_BUILD 0)
set(PROGRAM_NAME "TypicalGtkmmApp")
set(PROGRAM_AUTHORS "Katayama Hirofumi MZ")
set(PROGRAM_YEARS "2016")
set(VERSION_STRING "${PROGRAM_MAJOR}.${PROGRAM_MINOR}.${PROGRAM_BUILD}")
set(VERSION_INFO_STRING "${PROGRAM_NAME} ${VERSION_STRING} by ${PROGRAM_AUTHORS}")

# check build type
if (NOT CMAKE_BUILD_TYPE)
    message(STATUS "No build type selected, default to Debug")
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# make uppercase string of build type
string(TOUPPER "${CMAKE_BUILD_TYPE}" uppercase_CMAKE_BUILD_TYPE)

# check build type again
if (NOT uppercase_CMAKE_BUILD_TYPE MATCHES "^(DEBUG|RELEASE|RELWITHDEBINFO|MINSIZEREL)$")
    message(FATAL_ERROR "Invalid value for CMAKE_BUILD_TYPE: ${CMAKE_BUILD_TYPE}")
endif()

# define _DEBUG on Debug version
if (uppercase_CMAKE_BUILD_TYPE STREQUAL "DEBUG")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -D_DEBUG")
endif()

# set output directory (build/)
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/build)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})

# gtkmm-related
include(FindPkgConfig)
find_package(GTK2 2.4 REQUIRED gtkmm)
pkg_check_modules(GTKMM REQUIRED gtkmm-2.4)
include_directories(${GTKMM_INCLUDE_DIRS})
link_directories(${GTKMM_LIBRARY_DIRS})

# Win32 or not?
if (CMAKE_HOST_WIN32)
    # enable Win32 resource
    ENABLE_LANGUAGE(RC)

    # Win32
    add_executable(TypicalGtkmmApp TypicalGtkmmApp.cpp MainWindow.cpp TypicalGtkmmApp_res.rc)
else()
    # non-Win32
    add_executable(TypicalGtkmmApp TypicalGtkmmApp.cpp MainWindow.cpp)
endif()

# C++11
set_property(TARGET TypicalGtkmmApp PROPERTY CXX_STANDARD 11)

# gtkmm-related
target_link_libraries(TypicalGtkmmApp ${GTKMM_LIBRARIES})

# configuration files
configure_file(config.h.in config.h)
configure_file(TypicalGtkmmApp_res.rc.in TypicalGtkmmApp_res.rc)

##############################################################################
