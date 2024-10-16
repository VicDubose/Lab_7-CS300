#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>

/* Change this constant to contain your name. */
const std::string kYourName = "Tyrone Dubose Alaura Buzbee.";

/* Change this constant to contain the path out of your normal maze. */
const std::string kPathOutOfNormalMaze = "TODO: Replace this string with your path out of the normal maze.";

// Function to test paths
void testPath(MazeCell* start, const std::string& moves, const std::string& mazeName) {
    std::cout << "Testing path for " << mazeName << ": " << moves << std::endl;
    bool success = isPathToFreedom(start, moves);
    std::cout << (success ? "Path succeeded!" : "Path failed!") << std::endl;
}

int main() {
    MazeCell* normalMazeStart = mazeFor(kYourName);

    // Test predefined paths
    testPath(normalMazeStart, "ESNWWNNEWSSESWWN", "Normal Maze"); // Adjust based on your paths
    testPath(normalMazeStart, "S", "Normal Maze (Out of Bounds)");

    if (isPathToFreedom(normalMazeStart, kPathOutOfNormalMaze)) {
        std::cout << "Congratulations! You've found a way out of your labyrinth." << std::endl;
    } else {
        std::cout << "Sorry, but you're still stuck in your labyrinth." << std::endl;
    }

    // This may need to be adjusted based on how your maze is structured
    delete normalMazeStart->south->east;
    delete normalMazeStart->south;        // Delete cell B
    delete normalMazeStart;                // Delete cell A

    return 0;
}
