cmake_minimum_required (VERSION 3.20)
project (sample VERSION 1.0)

include_directories(include)

set(SOURCE
  src/chap06.c)

set(TESTS 
  tests/test_chap06.cpp)

# These tests can use the Catch2-provided main

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.3.2 # or a later release
)
FetchContent_MakeAvailable(Catch2)

# Create a static library and tests
add_library(thareja STATIC ${SOURCE})
add_executable(tests ${TESTS})
target_link_libraries(tests PRIVATE thareja Catch2::Catch2WithMain)
