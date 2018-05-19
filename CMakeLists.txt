cmake_minimum_required (VERSION 2.8.12)

project(Game)

set(SOURCE_FILES main.cpp)

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/ext/sfml")

# add c++11 standard to compiler
add_compile_options(-std=c++11)

include_directories(${SFML_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

file(GLOB_RECURSE HS_FILES	
	GLOB_CPP_PATTERNS src/*.cpp */states/*.cpp
	GLOB_H_PATTERNS include/*.h */states/*.h RECURSE GROUP
)

add_executable(game ${HS_FILES})

# link with SFML library dependiences
target_link_libraries(game sfml-system sfml-window sfml-graphics sfml-audio)

target_include_directories(game PRIVATE
    "${CMAKE_CURRENT_SOURCE_DIR}/ext/sfml/include"
 #   "${CMAKE_CURRENT_SOURCE_DIR}/ext"
 #   "${CMAKE_CURRENT_SOURCE_DIR}/include"
)
