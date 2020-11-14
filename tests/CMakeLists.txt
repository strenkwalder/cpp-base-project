cmake_minimum_required(VERSION 3.5)

########
# Create Tests
########

enable_testing()

find_package(GTest REQUIRED)
#find_package(lcov REQUIRED)
#find_program( GCOV_PATH gcov REQUIRED)
#find_program( LCOV_PATH  NAMES lcov lcov.bat lcov.exe lcov.perl REQUIRED)
#find_program( GENHTML_PATH NAMES genhtml genhtml.perl genhtml.bat REQUIRED)

set (TEST_SOURCES ${main_SOURCES}
	${PROJECT_SOURCE_DIR}/tests/main.cpp
	${PROJECT_SOURCE_DIR}/tests/memoryleaks.cpp
	${PROJECT_SOURCE_DIR}/tests/memorytest.cpp)



########################
# Setup Compiler Flags
########################
set(TEST_COMPILE_FLAGS "${TEST_COMPILE_FLAGS} ${CMAKE_CXX_FLAGS_DEBUG}")

if ("${CMAKE_CXX_COMPILER_ID}" MATCHES "Clang")
    target_compile_options(coverage_config INTERFACE
            -Og        # no optimization
            -g3         # generate debug info
            --coverage # sets all required flags
            )

    target_link_options(coverage_config INTERFACE --coverage)

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
    target_compile_options(coverage_config INTERFACE
            -Og        # no optimization
            -g3         # generate debug info
            --coverage # sets all required flags
            )
    target_link_options(coverage_config INTERFACE --coverage)

elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Intel")
elseif ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
endif()


########################
# Targets
########################

add_executable(tests        	${TEST_SOURCES})
add_executable(tests_coverage	${TEST_SOURCES})

set_target_properties(tests PROPERTIES COMPILE_FLAGS "${TEST_COMPILE_FLAGS}")
target_link_libraries(tests GTest::GTest GTest::Main)

set_target_properties(tests_coverage PROPERTIES COMPILE_FLAGS "${TEST_COMPILE_FLAGS} ${COVERAGE_COMPILE_FLAGS}")
target_link_libraries(tests_coverage PRIVATE coverage_config GTest::GTest GTest::Main)


#target_link_libraries(tests_coverage GTest::GTest GTest::Main)

#target_link_libraries(tests lcov)
#target_link_libraries(tests_coverage gcov)

########################
# Add Tests
########################
add_test(PlaneTests ./tests)
add_test(MemoryTests valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck ./tests > tests_valgrind.log 2>&1)
add_test(CoverageTests lcov --coverage --directory . --output-file main_coverage.info && genhtml main_coverage.info --output-directory out)

