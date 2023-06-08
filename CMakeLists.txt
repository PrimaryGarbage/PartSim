cmake_minimum_required(VERSION 3.22)
project(Partsim VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

### Put the names of your source files here ###
set(SRC_FILES 
    main.cpp
    app.hpp app.cpp
    prim_exception.hpp
    timer.hpp
    types.hpp
    particle.hpp
    particle_master.hpp particle_master.cpp particle_master.tpp
    ui.hpp ui.cpp
)

list(TRANSFORM SRC_FILES PREPEND "src/")

add_executable(${PROJECT_NAME} ${SRC_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -d)

### Add link directories here ###
target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external/lib/win ${CMAKE_SOURCE_DIR}/external/lib/linux)

### Add include directories here ###
target_include_directories(${PROJECT_NAME} PRIVATE external)

### Uncomment this line if you want the standard libraries to be linked statically ###
#target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)

add_compile_definitions(SFML_STATIC)

### Use this line to link external libraries
target_link_libraries(${PROJECT_NAME} sfml-graphics-s-d sfml-window-s-d sfml-system-s-d freetype opengl32 winmm gdi32)
