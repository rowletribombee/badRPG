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

add_executable(testMovement
test/testMovement.cpp
src/Map.cpp
src/Player.cpp
src/Stats.cpp
src/Screen.cpp
src/Potion.cpp
src/Weapon.cpp
src/Inventory.cpp
src/tiles/EmptyTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/FightTile.cpp
src/tiles/PotionTile.cpp
src/tiles/WeaponTile.cpp
src/tiles/Tile.cpp
)

add_executable(testTiles
test/testTiles.cpp 
src/tiles/EmptyTile.cpp
src/tiles/FightTile.cpp
src/tiles/PotionTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/WeaponTile.cpp
src/tiles/Tile.cpp
src/Inventory.cpp
src/Potion.cpp
src/Weapon.cpp
src/Player.cpp
src/Stats.cpp
src/Screen.cpp
src/Player.cpp
src/Map.cpp
)

add_executable(testStats
test/testStats.cpp
src/Stats.cpp
)

add_executable(testBattle
test/testStats.cpp
src/Stats.cpp
src/Player.cpp
src/Battle.cpp
src/Enemy.cpp
src/BasicBoss.cpp
src/EliteBoss1.cpp
src/FinalBoss.cpp
src/EliteBoss2.cpp
src/Inventory.cpp
src/tiles/PotionTile.cpp
src/tiles/Tile.cpp
src/Potion.cpp
)

add_executable(testPlayer
test/testPlayer.cpp
src/Stats.cpp
src/Player.cpp
src/Screen.cpp
src/Inventory.cpp
src/tiles/PotionTile.cpp
src/tiles/EmptyTile.cpp
src/tiles/FightTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/WeaponTile.cpp
src/Weapon.cpp
src/tiles/Tile.cpp
src/Potion.cpp
src/Map.cpp
)

add_executable(testScreens
test/testScreens.cpp
src/Screen.cpp
src/Stats.cpp
src/Map.cpp
src/Potion.cpp
src/Weapon.cpp
src/Player.cpp
src/Inventory.cpp
src/tiles/EmptyTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/FightTile.cpp
src/tiles/PotionTile.cpp
src/tiles/WeaponTile.cpp
src/tiles/Tile.cpp
)

add_executable(testItems
test/testItems.cpp
src/Potion.cpp
src/Weapon.cpp 
src/Player.cpp 
src/Screen.cpp
src/Stats.cpp
src/tiles/PotionTile.cpp
src/tiles/EmptyTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/FightTile.cpp
src/tiles/WeaponTile.cpp
src/tiles/Tile.cpp
src/Inventory.cpp
src/Map.cpp
)

add_executable(testInventory
test/testInventory.cpp 
src/Potion.cpp 
src/Weapon.cpp
src/Player.cpp
src/Screen.cpp
src/Stats.cpp
src/Inventory.cpp
src/tiles/PotionTile.cpp
src/tiles/EmptyTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/FightTile.cpp
src/tiles/WeaponTile.cpp
src/tiles/Tile.cpp
src/Map.cpp
)

add_executable(testWeapons
test/testInventory.cpp 
src/Potion.cpp 
src/Weapon.cpp
src/Player.cpp
src/Screen.cpp
src/Stats.cpp
src/Inventory.cpp
src/tiles/PotionTile.cpp
src/tiles/EmptyTile.cpp
src/tiles/SpawnTile.cpp
src/tiles/FightTile.cpp
src/tiles/WeaponTile.cpp
src/tiles/Tile.cpp
src/Map.cpp
)


TARGET_LINK_LIBRARIES(testTiles gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(testTiles PRIVATE gtest_disable_pthreads=ON)
TARGET_LINK_LIBRARIES(testMovement gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(testMovement PRIVATE gtest_disable_pthreads=ON)
TARGET_LINK_LIBRARIES(testStats gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(testStats PRIVATE gtest_disable_pthreads=ON)
TARGET_LINK_LIBRARIES(testItems gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(testStats PRIVATE gtest_disable_pthreads=ON)
TARGET_LINK_LIBRARIES(testPlayer gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(testItems PRIVATE gtest_disable_pthreads=ON)
TARGET_LINK_LIBRARIES(testInventory gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(testInventory PRIVATE gtest_disable_pthreads=ON)
TARGET_LINK_LIBRARIES(testWeapons gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(testWeapons PRIVATE gtest_disable_pthreads=ON)
TARGET_LINK_LIBRARIES(testBattle gtest gtest_main)
TARGET_COMPILE_DEFINITIONS(testWeapons PRIVATE gtest_disable_pthreads=ON)
