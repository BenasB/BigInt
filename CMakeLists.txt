cmake_minimum_required(VERSION "3.12")

project("BigInt")

if (CMAKE_COMPILER_IS_GNUCC)
	option(ENABLE_COVERAGE "Enable coverage reporting for gcc/clang" FALSE)
	
	if (ENABLE_COVERAGE)
		add_compile_options(--coverage -O0)
	endif()
endif()

set (CMAKE_CXX_STANDARD 11)
add_executable("${PROJECT_NAME}" "testing/append.cpp" 
								 "testing/construct.cpp" 
								 "BigInt.cpp")
								 
target_link_libraries("${PROJECT_NAME}" --coverage)