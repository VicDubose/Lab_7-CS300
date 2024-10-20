#include "Labyrinth.h"
#include <iostream>
#include <vector> // Include vector header

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    MazeCell* current = start;
    std::vector<size_t> itemLocations; // To store the locations of magical items

    for (char move : moves) {
        // Move according to the direction specified by `move`
        if (move == 'N' && current->north) {
            current = current->north;
        } else if (move == 'S' && current->south) {
            current = current->south;
        } else if (move == 'E' && current->east) {
            current = current->east;
        } else if (move == 'W' && current->west) {
            current = current->west;
        } else {
            return false; // Invalid move, out of bounds
        }

        // Check for items
        if (current->whatsHere != Item::NOTHING) {
            itemLocations.push_back(reinterpret_cast<size_t>(current)); // Store the address of the current cell
            current->whatsHere = Item::NOTHING; // Assume you take the item
        }
    }

    // Display the locations of the items collected
    std::cout << "Item locations: ";
    for (size_t loc : itemLocations) {
        std::cout << loc << " "; // Print addresses (or you can convert them to indices if needed)
    }
    std::cout << std::endl;

    return true; // Assume path leads to freedom if no invalid moves were made
}
