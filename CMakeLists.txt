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
    control.hpp control.cpp
    button.hpp button.cpp
    field.hpp field.cpp
    electric_field.hpp electric_field.cpp
    repelling_field.hpp repelling_field.cpp
    vec_utils.hpp
    input.hpp input.cpp
    logger.hpp logger.cpp
    globals.hpp
)

list(TRANSFORM SRC_FILES PREPEND "src/")

add_executable(${PROJECT_NAME} ${SRC_FILES})

set_target_properties(${PROJECT_NAME} PROPERTIES DEBUG_POSTFIX -d)

### Add link directories here ###

### Add include directories here ###
target_include_directories(${PROJECT_NAME} PRIVATE external)

### Uncomment this line if you want the standard libraries to be linked statically ###
#target_link_options(${PROJECT_NAME} PRIVATE -static-libgcc -static-libstdc++)

add_compile_definitions(SFML_STATIC)

### Use this line to link external libraries
if(WIN32)
    target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external/lib/debug/win ${CMAKE_SOURCE_DIR}/external/lib/release/win)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_link_libraries(${PROJECT_NAME} sfml-graphics-s-d sfml-window-s-d sfml-system-s-d freetype opengl32 winmm gdi32)
    else()
        message(${CMAKE_BUILD_TYPE})
        target_link_libraries(${PROJECT_NAME} sfml-graphics-s sfml-window-s sfml-system-s freetype opengl32 winmm gdi32)
    endif()
elseif(UNIX)
    target_link_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/external/lib/debug/linux ${CMAKE_SOURCE_DIR}/external/lib/release/linux)
    if(CMAKE_BUILD_TYPE STREQUAL "Debug")
        target_link_libraries(${PROJECT_NAME} sfml-graphics-s-d sfml-window-s-d sfml-system-s-d freetype GL X11 Xcursor Xrandr udev)
    else()
        target_link_libraries(${PROJECT_NAME} sfml-graphics-s sfml-window-s sfml-system-s freetype GL X11 Xcursor Xrandr udev)
    endif()
endif()
