cmake_minimum_required(VERSION 3.13)
project(server)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(server src/main.cpp src/networking/tcp_server.cpp src/networking/tcp_server.h src/networking/tcp_connection.cpp src/networking/tcp_connection.h src/game/game.cpp src/game/game.h src/game/notifier.h src/game/tile.cpp src/game/tile.h src/game/entity.cpp src/game/entity.h src/game/player.cpp src/game/player.h src/game/notifier_factory.h src/game/tile_map.cpp src/game/tile_map.h src/game/tile_map_interface.h src/game/player_set_interface.h)
add_executable(test test/test.cpp)
target_link_libraries(test ${Boost_LIBRARIES})
target_link_libraries(server ${Boost_LIBRARIES})
