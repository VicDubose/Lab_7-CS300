#include "MazeGenerator.h"
#include "Labyrinth.h"
#include <iostream>
#include <string>

/* Change this constant to contain your name. */
const std::string kYourName = "Victor Dubose Alaura Buzbee.";

/* Change these constants to contain the paths out of your mazes. */
const std::string kPathOutOfNormalMaze = "SES";  // Updated path
const std::string kPathOutOfTwistyMaze = "WSSW";      // Updated path

int main() {
    /* Generate the maze. */
    MazeCell* startLocation = mazeFor(kYourName);
    
    /* Set a breakpoint here to explore your maze! */
    if (isPathToFreedom(startLocation, kPathOutOfNormalMaze)) {
        std::cout << "Congratulations! You've found a way out of your labyrinth." << std::endl;
    } else {
        std::cout << "Sorry, but you're still stuck in your labyrinth." << std::endl;
    }
    
    /* Generate the twisty maze. */
    MazeCell* twistyStartLocation = twistyMazeFor(kYourName);
    
    /* Set a breakpoint here to explore your twisty maze! */
    if (isPathToFreedom(twistyStartLocation, kPathOutOfTwistyMaze)) {
        std::cout << "Congratulations! You've found a way out of your twisty labyrinth." << std::endl;
    } else {
        std::cout << "Sorry, but you're still stuck in your twisty labyrinth." << std::endl;
    }
    
    return 0;
}
