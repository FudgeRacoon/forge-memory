cmake_minimum_required(VERSION 3.30)

set(CMAKE_CXX_STANDARD 17)

project(forge_memory VERSION 0.1.0 LANGUAGES CXX)

include(FetchContent)

if(NOT TARGET forge_base)
	FetchContent_Declare(
		forge_base
		GIT_REPOSITORY https://github.com/FudgeRacoon/forge-base.git
		GIT_TAG        origin/master
	)
	FetchContent_MakeAvailable(forge_base)
endif()

add_library(forge_memory INTERFACE)
target_link_libraries(forge_memory INTERFACE forge_base)
target_include_directories(forge_memory INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/Source/Public)