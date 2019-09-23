cmake_minimum_required(VERSION 3.10)

project(freetype-test)

find_package(PkgConfig REQUIRED)
pkg_check_modules(FREETYPE2 REQUIRED freetype2)

add_executable(${PROJECT_NAME} src/main.c)

target_link_libraries(${PROJECT_NAME} ${FREETYPE2_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${FREETYPE2_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${FREETYPE2_CFLAGS_OTHER})
