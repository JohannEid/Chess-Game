cmake_minimum_required(VERSION 3.6)
project(Chess_Game_)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(SOURCE_FILES main.cpp object.cpp object.h Header.h Board.cpp Board.h Player.cpp Player.h common.cpp common.h engine.cpp engine.h)
add_executable(Chess_Game_ ${SOURCE_FILES})


set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake_modules")
find_package(SFML REQUIRED system window graphics network audio)
if (SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(Chess_Game_ ${SFML_LIBRARIES})
endif()






