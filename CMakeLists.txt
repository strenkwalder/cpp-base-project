cmake_minimum_required(VERSION 3.5)

project(cpp-project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")  
	MESSAGE("Setting Clang flags:")
	SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Weverything")
	
	set(CMAKE_CXX_FLAGS_DEBUG "-g3 -Og -pg")#pg = profilig info; 
	set(CMAKE_CXX_FLAGS_RELEASE "-O2")
	
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
	MESSAGE("Setting GNU flags:")
	SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -Wshadow -Wdouble-promotion -Wcast-align -Wold-style-cast -Wundef -fno-common -Wconversion -Wpointer-arith -Wcast-qual -Wmissing-braces -Wfloat-equal -Wreturn-type -Wredundant-decls")
	set(CMAKE_CXX_FLAGS_DEBUG "-g3 -Og -pg")#pg = profilig info; 
	set(CMAKE_CXX_FLAGS_RELEASE "-O2")
	
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
	MESSAGE("Setting Intel flags:")
	SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
	
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
	MESSAGE("Setting MSVC flags:")
	SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}")
endif()


###########
# Setup Main Program as library and executable
###########
set(main_SOURCES ${PROJECT_SOURCE_DIR}/src/dummy.cpp)
include_directories(${PROJECT_SOURCE_DIR}/src)


add_library (application.lib SHARED ${main_SOURCES})
add_executable(application
                    main.cpp
                    ${main_SOURCES})

#################################
# Tests
#################################
add_subdirectory(tests)
