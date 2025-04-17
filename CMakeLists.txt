cmake_minimum_required(VERSION 3.10)

# Set project name and C++ standard
project(hello_world VERSION 1.0 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# Add executable
add_executable(hello_world src/hello_world.cpp include/hello_world.h)

# Include directories
target_include_directories(hello_world PUBLIC include)

# ------------- DOXYGEN_SECTION ------------- 

# Find Doxygen
find_package(Doxygen REQUIRED)

# Doxygen target, or you can just edit then inside the Doxyfile too
set(DOXYGEN_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/docs)
set(DOXYGEN_GENERATE_HTML YES)
set(DOXYGEN_EXTRACT_ALL YES)
set(DOXYGEN_EXTRACT_PRIVATE YES)
set(DOXYGEN_EXTRACT_STATIC YES)

doxygen_add_docs(doxygen-docs
    ${CMAKE_SOURCE_DIR}/include
    ${CMAKE_SOURCE_DIR}/src
    COMMENT "Generating API documentation with Doxygen"
)

# Documentation target
add_custom_target(docs
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
)

# ...A different documentation target
add_custom_target(different_docs
    COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.different
    WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
    COMMENT "Generating API documentation with Doxygen"
    VERBATIM
)