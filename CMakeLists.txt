cmake_minimum_required(VERSION 3.11)

set(PROJECT_NAME "catch_ut")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CXX_GNU_COMPILE_FLAGS "-Wall -pedantic -Wextra -Werror")
set(CXX_CLANG_COMPILE_FLAGS "-Wall -pedantic -Wextra -Werror")

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
  list(APPEND CMAKE_CXX_FLAGS  ${CXX_GNU_COMPILE_FLAGS})
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  list(APPEND CMAKE_CXX_FLAGS  ${CXX_CLANG_COMPILE_FLAGS})
endif()

add_executable(catch_ut src/ut/main.cpp src/ut/Gcd.cpp src/ut/Vector.cpp)

target_include_directories(catch_ut PRIVATE
  $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
  $<INSTALL_INTERFACE:include>)
