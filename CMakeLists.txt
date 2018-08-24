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

set(RPG_TOWN_TITLE "Rpg Town")
set(RPG_TOWN_VERSION_MAJOR 0)
set(RPG_TOWN_VERSION_MINOR 2)
set(RPG_TOWN_VERSION_RELEASE pre-alpha)

configure_file(
	"${SRCDIR}/config.h.in"
	"${BINDIR}/config.h"
)
include_directories("${BINDIR}")

file(GLOB_RECURSE HS_FILES	
	GLOB_CPP_PATTERNS src/*.cpp */states/*.cpp
	GLOB_H_PATTERNS include/*.h */states/*.h RECURSE GROUP
)
set(EXECUTABLE_NAME "rpg-town")
add_executable(${EXECUTABLE_NAME} ${HS_FILES})

set(GESFML_INCLUDE_DIR & ${CMAKE_CURRENT_SOURCE_DIR}/include/GESFML)

include_directories(${GESFML_INCLUDE_DIR})

include_directories(${SFML_DIR}/include)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

if(UNIX)
# SFML
set(CMAKE_MODULE_PATH "${SRCDIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
if(SFML_FOUND)
	target_link_libraries(${EXECUTABLE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)
endif()
endif(UNIX)

if(WIN32 OR MSVC OR MINGW)
add_subdirectory("${PROJECT_SOURCE_DIR}/ext/sfml")

# link with SFML library dependiences
target_link_libraries(${EXECUTABLE_NAME} sfml-system sfml-window sfml-graphics sfml-audio)

target_include_directories(${EXECUTABLE_NAME} PRIVATE
    "${PROJECT_SOURCE_DIR}/ext/sfml/include"
)
endif(WIN32 OR MSVC OR MINGW)

# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)

# CPack packaging
include(InstallRequiredSystemLibraries)
set(CPACK_RESOURCE_FILE_LICENSE "${SRCDIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${RPG_TOWN_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${RPG_TOWN_VERSION_MINOR}")
include(CPack)
