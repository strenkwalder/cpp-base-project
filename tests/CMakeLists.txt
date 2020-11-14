cmake_minimum_required(VERSION 3.5)

########
# Create Tests
########
#
#  complile the tests
#

enable_testing()
find_package(GTest REQUIRED)
#find_package(lcov REQUIRED)
#find_program( GCOV_PATH gcov REQUIRED)
#find_program( LCOV_PATH  NAMES lcov lcov.bat lcov.exe lcov.perl REQUIRED)
#find_program( GENHTML_PATH NAMES genhtml genhtml.perl genhtml.bat REQUIRED)

set (Test_SOURCES ${main_SOURCES} 
	${PROJECT_SOURCE_DIR}/tests/main.cpp
	${PROJECT_SOURCE_DIR}/tests/memoryleaks.cpp
	${PROJECT_SOURCE_DIR}/tests/memorytest.cpp)

add_executable(tests        	${Test_SOURCES})
add_executable(tests_coverage	${Test_SOURCES})

########################
# Setup Compiler Flags
########################
set(TEST_COMPILE_FLAGS "${TEST_COMPILE_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")   
#set(TEST_COMPILE_FLAGS "${CMAKE_CXX_FLAGS}")

if (CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    set(COVERAGE_COMPILE_FLAGS "${TEST_COMPILE_FLAGS} -fprofile-instr-generate -fcoverage-mapping")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    set(COVERAGE_COMPILE_FLAGS "${TEST_COMPILE_FLAGS}  -fprofile-arcs -ftest-coverage -fprofile-generate")
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "Intel")
  # using Intel C++
elseif (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
  # using Visual Studio C++
endif()

########################
# Targets
########################
set_target_properties(tests PROPERTIES COMPILE_FLAGS "${TEST_COMPILE_FLAGS}")
set_target_properties(tests_coverage PROPERTIES COMPILE_FLAGS "${TEST_COMPILE_FLAGS} ${COVERAGE_COMPILE_FLAGS}")

target_link_libraries(tests GTest::GTest GTest::Main)
target_link_libraries(tests_coverage GTest::GTest GTest::Main)

#target_link_libraries(tests lcov)
target_link_libraries(tests_coverage gcov)

########################
# Add Tests
########################
add_test(PlaneTests tests)
add_test(MemoryTests valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --log-file=tests_valgrind.log tests)
#add_test(CoverageTests ${PROJECT_SOURCE_DIR}/tests/main.cpp && lcov --coverage --directory . --output-file main_coverage.info && genhtml main_coverage.info --output-directory out)

