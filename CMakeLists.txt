cmake_minimum_required (VERSION 2.6.0)

# Enable debug symbols by default
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE STRING "Choose the type of build (Debug or Release)" FORCE)
endif()

# add c++11 standard to compiler
add_compile_options(-std=c++11)

project(Rpg-Town)

set(BINDIR ${PROJECT_BINARY_DIR})
set(SRCDIR ${PROJECT_SOURCE_DIR})

set(RPG_TOWN_VERSION_MAJOR 1)
set(RPG_TOWN_VERSION_MINOR 0)

configure_file(
	"${PROJECT_SOURCE_DIR}/config.h.in"
	"${PROJECT_BINARY_DIR}/config.h"
)
include_directories("${PROJECT_BINARY_DIR}")

file(GLOB HS_FILES	
	GLOB_CPP_PATTERNS src/*.cpp */states/*.cpp
	GLOB_H_PATTERNS include/*.h */states/*.h RECURSE GROUP
)
set(EXECUTABLE_NAME "Rpg_Town")
add_executable(${EXECUTABLE_NAME} ${HS_FILES})

# SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
	include_directories(${SFML_INCLUDE_DIR})
	target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES} ${SFML_DEPENDENCIES})
endif()

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${RPG_TOWN_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${RPG_TOWN_VERSION_MINOR}")
include(CPack)