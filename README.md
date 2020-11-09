C++ Project Base
================
[![Build Status](https://gitlab.com/Trenkwalder/cpp-project-base/badges/master/pipeline.svg)](https://gitlab.com/Trenkwalder/cpp-project-base/-/commits/master)

https://gitlab.com/Trenkwalder/-/commits/master

This repo contains a small C++ project (main.cpp + src/dummy.cpp).
It is setup with **CMAKE** and is used to test the Google Test (GTest environment).
Note that the tests are so designed that each test is checked for memory leaks under the condition that the tests are called with Valgrind.
Finally, a GitLab CI integration is done, which runs the pipeline.

Dependencies
------------

This project depends on:
 - CMAKE (cmake)
 - Google Tests (gtest)
 - GNU Coverage (gcov)
 - Valgrind (valgrind)
 
 To install these packages in an Debian/Ubuntu Linux, use the following command 
```sh
sudo apt install build-essential cmake libgtest-dev gcovr valgrind
```


How to use it?
--------------

Simply run a common CMAKE build with:
```sh
mkdir build/
cd build/
cmake ..
```

Then you can build the project with:
```sh
make all
```
This command builds the main executable, called `build/application`, and the Google Tests, `build/tests/tests`.

You can run the 
 - application with `> build/application`
 - tests with `> build/tests/tests`
 
 
 To run the tests and check each individual test for memory leaks, simply run 
```sh
valgrind --leak-check=full --show-leak-kinds=all --tool=memcheck --log-file="build/tests_valgrind.log" build/tests/tests
```


Where can I fund stuff?
-----------------------

This project is organisied in the following way:
 - `./main.cpp` is the root file which starts the applicaiton
 - `src/` and subfolders contain all source files  that are needed to compile the application
 - `tests/` and subfolders contain all tests and a `tests/main.cpp` which starts all tests.
 
 
