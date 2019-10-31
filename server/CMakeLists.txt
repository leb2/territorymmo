cmake_minimum_required(VERSION 3.13)
project(server)

set(CMAKE_CXX_STANDARD 17)
find_package(Boost 1.71.0 COMPONENTS system filesystem REQUIRED)
include_directories(${Boost_INCLUDE_DIRS})

add_executable(server src/main.cpp src/networking/tcp_server.cpp src/networking/tcp_server.h src/networking/tcp_connection.cpp src/networking/tcp_connection.h src/game/game.cpp src/game/game.h src/game/notifier/notifier.h src/game/map/tile.cpp src/game/map/tile.h src/game/entity/entity.cpp src/game/entity/entity.h src/game/player/player.cpp src/game/player/player.h src/game/notifier/notifier_factory.h src/game/map/tile_map.cpp src/game/map/tile_map.h src/game/map/tile_map_interface.h src/game/player/player_set_interface.h src/game/entity/unit.cpp src/game/entity/unit.h src/game/player/player_set.cpp src/game/player/player_set.h src/networking/client.h src/clientinteraction/game_client.cpp src/clientinteraction/game_client.h src/networking/client_factory.h src/clientinteraction/game_client_factory.cpp src/clientinteraction/game_client_factory.h src/game/map/tile_data.h)
add_executable(test test/test.cpp)
target_link_libraries(test ${Boost_LIBRARIES})
target_link_libraries(server ${Boost_LIBRARIES})
