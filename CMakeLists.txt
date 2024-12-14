cmake_minimum_required(VERSION 3.10)
project(cxx_utils VERSION 0.1.0 LANGUAGES C CXX)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories("inc")

# file(GLOB_RECURSE cxx_utils_SRC CONFIGURE_DEPENDS "src/*.cpp")
# add_library(cxx_utils ${cxx_utils_SRC})
# target_include_directories(cxx_utils PRIVATE "inc")

enable_testing()
add_subdirectory("tests")
