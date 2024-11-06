#include "gtest/gtest.h"
#include "../lib/tiles/EmptyTile.h"
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// All TESTS WITHIN EMPTYTILE SUITE ARE BASED ON RNG SO THE TEST CHECKS IF OUTPUT IS 1 OF 3 RANDOM VALUES
TEST(EmptyTile, EmptyTileTest1) {
    EmptyTile emptyTile;

    stringstream buffer;
    streambuf* oldCoutBuffer = cout.rdbuf(buffer.rdbuf());
    
    emptyTile.print();

    cout.rdbuf(oldCoutBuffer);
    string result = buffer.str();

    vector<string> firstPartOptions = {
        "Ah yes! Exactly what I needed! A whole lot of nothing. \n \n",
        "Great! An empty room. I always wanted a personal space for my existential dread. \n \n",
        "Well, it could be worse, I could be wandering in a cave with no memory and no way out… \n ... \n ... \n wait"
    };

    string secondPart = "Time to move along! \n \n";

    bool matches = false;
    for (const auto& firstPart : firstPartOptions) {
        if (result == firstPart + secondPart) {
            matches = true;
            break;
        }
    }
    EXPECT_TRUE(matches) << "Output was: " << result;
}
TEST(EmptyTile, EmptyTileTest2) {
    EmptyTile emptyTile;

    stringstream buffer;
    streambuf* oldCoutBuffer = cout.rdbuf(buffer.rdbuf());
    
    emptyTile.print();

    cout.rdbuf(oldCoutBuffer);
    string result = buffer.str();

    vector<string> firstPartOptions = {
        "Ah yes! Exactly what I needed! A whole lot of nothing. \n \n",
        "Great! An empty room. I always wanted a personal space for my existential dread. \n \n",
        "Well, it could be worse, I could be wandering in a cave with no memory and no way out… \n ... \n ... \n wait"
    };

    string secondPart = "Time to move along! \n \n";

    bool matches = false;
    for (const auto& firstPart : firstPartOptions) {
        if (result == firstPart + secondPart) {
            matches = true;
            break;
        }
    }
    EXPECT_TRUE(matches) << "Output was: " << result;
}
