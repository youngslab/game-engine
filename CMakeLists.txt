
project(game-engine)

cmake_minimum_required(VERSION 3.0) 

if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake") 
  message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan") 
  file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/master/conan.cmake" "${CMAKE_BINARY_DIR}/conan.cmake") 
endif() 

include(${CMAKE_BINARY_DIR}/conan.cmake)
conan_cmake_run(CONANFILE conanfile.txt
    PROFILE default 
   BASIC_SETUP CMAKE_TARGETS
    BUILD missing)
  
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_BINARY_DIR})

find_package(sdl2 REQUIRED)

add_executable(gamex main.cpp game.cpp) 

target_link_libraries(gamex sdl2::sdl2)

set_target_properties(gamex PROPERTIES
            CXX_STANDARD 17)
