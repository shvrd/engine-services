CMAKE_MINIMUM_REQUIRED(VERSION 3.12)
PROJECT(enginito)

SET(CMAKE_CXX_STANDARD 17)

ADD_COMPILE_DEFINITIONS(BUILD_DEBUG)

IF(NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
ENDIF()

SET(CMAKE_CXX_FLAGS "-Wall -Wextra -Wno-unused-variable -Wno-unused-parameter")
SET(CMAKE_CXX_FLAGS_DEBUG "-g")
SET(CMAKE_CXX_FLAGS_RELEASE "-O3")

# define preprocessor variables and build flags for different operating systems
IF(MINGW)
    MESSAGE("Building for Windows using MinGW")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")
    ADD_COMPILE_DEFINITIONS(BUILD_WINDOWS)
ELSEIF(APPLE)
    MESSAGE("Building for MacOS")
    ADD_COMPILE_DEFINITIONS(BUILD_MACOS)
ELSEIF(UNIX)
    MESSAGE("Building for Linux / Unixlike")
    ADD_COMPILE_DEFINITIONS(BUILD_LINUX)

    # set opengl preference to glvnd
    SET(OpenGL_GL_PREFERENCE GLVND)
ENDIF()

# define filepaths
SET(DEPENDENCIES ${CMAKE_HOME_DIRECTORY}/dependencies)
SET(LIBRARY_INCLUDE_DIRS ${CMAKE_HOME_DIRECTORY}/src)

# load necessary libraries
FIND_PACKAGE(PkgConfig REQUIRED)

# pkgconfig packages
# PKG_CHECK_MODULES(VULKAN REQUIRED vulkan)

# other packages
INCLUDE(${DEPENDENCIES}/FindGLFW.cmake)
INCLUDE(${DEPENDENCIES}/FindGLM.cmake)
INCLUDE(FindOpenGL)
INCLUDE(FindGLEW)
INCLUDE(FindFreetype)

INCLUDE(FindOpenAL)

# check if necessary libraries were loaded
IF(NOT ${GLFW_FOUND} OR NOT ${OPENGL_FOUND} OR NOT ${GLEW_FOUND} OR NOT ${GLM_FOUND} OR NOT ${FREETYPE_FOUND} OR NOT ${OPENAL_FOUND})
    MESSAGE("FAILED TO FIND A NECESSARY LIBRARY")
    RETURN()
ENDIF()

# define subdirectories
ADD_SUBDIRECTORY(src)
ADD_SUBDIRECTORY(test)
