
cmake_minimum_required(VERSION 3.5)

project(UniversalUITest)

set(GSPCORE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../../../GSPCore/include)
set(GSPCORE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/../../../GSPCore/build/libGSPCore.so)


set(UNIVERSALUI_TEST_SRC
    test/main.cpp
)

add_executable(UniversalUITest ${UNIVERSALUI_TEST_SRC})
target_include_directories(UniversalUITest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${GSPCORE_INCLUDE})
target_link_libraries(UniversalUITest ${GSPCORE_LIB})

