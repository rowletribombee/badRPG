#include "gtest/gtest.h"
#include "../lib/Player.h"
#include "../lib/Map.h"
#include "../lib/tiles/EmptyTile.h"
#include "../lib/tiles/SpawnTile.h"
#include <iostream>
using namespace std;

TEST(MapMovement, MapMovementUpRightRight) {
    Player player;
    Map map;

    istringstream input("w\nd\nd\n");
    cin.rdbuf(input.rdbuf());

    player.move(map); // Reads 'w'
    player.move(map); // Reads 'd'
    player.move(map); // Reads 'd'

    EXPECT_EQ(player.getPositionX(), 2); // Check X-coordinate
    EXPECT_EQ(player.getPositionY(), 6); // Check Y-coordinate
}
