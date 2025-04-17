# Doxygen Hello World

## Getting Started
- Install Doxygen to your System
- Clone repo
    ```DOS
    git clone https://github.com/royyandzakiy/doxy-helloworld    
    cd .\doxy-helloworld\
    ```
- Build repo
    ```DOS
    rmdir /s /q .\\build && cmake -S . -B .\\build -G "Visual Studio 17 2022" -A x64 && cmake --build .\\build --config Debug
    ```
- Run
    ```DOS
    .\\build\\Debug\\hello_world.exe
    ```

## Adding Doxygen to any project
- `doxy-helloworld/CMakeLists.txt` Add these lines
    ```
    ...
    find_package(Doxygen REQUIRED)

    # Documentation target
    add_custom_target(docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
    ...
    ```
- Auto-generate Template Doxyfile
    ```DOS
    doxygen -g # auto-generates a boilerplate doxyfile, will be overwritten later-on
    ```
- Generate & Open Docs
    ```DOS
    cmake --build .\build --config Debug --target docs
    start docs\html\index.html
    ```
- Modify the generated Doxyfile
    ```Doxyfile
    PROJECT_NAME           = "Doxy Hello World"
    RECURSIVE              = YES
    EXTRACT_ALL            = YES
    EXTRACT_PRIVATE        = YES
    EXTRACT_STATIC         = YES
    OUTPUT_DIRECTORY       = ./docs
    GENERATE_HTML          = YES
    GENERATE_LATEX         = NO
    ```

## Creating Custom Doxygen files for seperate documenatations
- Create new `Doxyfile.different` (name it whatever you like)
- `doxy-helloworld/CMakeLists.txt` Add these lines
    ```
    ...
    # ...A different documentation target
    add_custom_target(different_docs
        COMMAND ${DOXYGEN_EXECUTABLE} ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.different
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating API documentation with Doxygen"
        VERBATIM
    )
    ...
    ```
- Generate & Open Docs
    ```DOS
    cmake --build .\build --config Debug --target different_docs
    start different_docs\html\index.html
    ```