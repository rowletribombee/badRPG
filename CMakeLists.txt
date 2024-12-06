cmake_minimum_required(VERSION 3.10)
project(IWokeUpInACaveAndAllIWantIsWifi)

ADD_SUBDIRECTORY(googletest)

# add_executable(testScreens
# src/Screen.cpp
# src/Map.cpp
# src/Player.cpp
# src/tiles/Tile.cpp
# src/tiles/EmptyTile.cpp
# src/tiles/SpawnTile.cpp 
# test/testScreens.cpp
# )

add_executable(startGame
src/main.cpp
src/LoadManager.cpp
src/Game.cpp
src/Stats.cpp
src/Player.cpp
src/Map.cpp
src/Inventory.cpp
src/Screen.cpp
src/Potion.cpp
src/tiles/EmptyTile.cpp
src/tiles/FightTile.cpp
src/tiles/PotionTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/WeaponTile.cpp
src/tiles/Tile.cpp

src/Weapon.cpp
)
