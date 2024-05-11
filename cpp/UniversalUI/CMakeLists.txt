
cmake_minimum_required(VERSION 3.5)

project(UniversalUI)

set(GSPCORE_INCLUDE ${CMAKE_CURRENT_SOURCE_DIR}/../../../GSPCore/include)
set(GSPCORE_LIB ${CMAKE_CURRENT_SOURCE_DIR}/../../../GSPCore/build/libGSPCore.so)


set(UNIVERSALUI_SRC
    src/UApplication.cpp
)

add_library(UniversalUI STATIC ${UNIVERSALUI_SRC})
target_include_directories(UniversalUI PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${GSPCORE_INCLUDE})
target_link_libraries(UniversalUI ${GSPCORE_LIB})



set(UNIVERSALUI_TEST_SRC
    test/main.cpp
)

add_executable(UniversalUITest ${UNIVERSALUI_TEST_SRC})
target_include_directories(UniversalUITest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include ${GSPCORE_INCLUDE})
target_link_libraries(UniversalUITest UniversalUI)

