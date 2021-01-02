cmake_minimum_required(VERSION 3.5)

project(PONG VERSION 0.0.1)

set(SOURCES
        sources/main.cpp
        sources/Paddle.cpp
        sources/Ball.cpp
        )


find_package(SFML 2.5.1 COMPONENTS graphics audio REQUIRED)

add_executable(game ${SOURCES})

set_target_properties(
        game PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED ON
)


target_include_directories(game
        PRIVATE
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(game sfml-graphics sfml-audio)


