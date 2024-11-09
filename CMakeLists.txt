cmake_minimum_required(VERSION 3.10)
project(IWokeUpInACaveAndAllIWantIsWifi)

ADD_SUBDIRECTORY(googletest)

add_executable(startGame
src/main.cpp
src/Game.cpp
src/Map.cpp
src/tiles/EmptyTile.cpp
src/tiles/FightTile.cpp
src/tiles/ItemTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/WeaponTile.cpp
src/tiles/Tile.cpp
)

add_executable(testTiles
test/testTiles.cpp 
src/tiles/EmptyTile.cpp
src/tiles/FightTile.cpp
src/tiles/ItemTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/WeaponTile.cpp
src/tiles/Tile.cpp
)

TARGET_LINK_LIBRARIES(testTiles gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(testTiles PRIVATE gtest_disable_pthreads=ON)