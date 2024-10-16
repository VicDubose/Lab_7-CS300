#include "Labyrinth.h"
#include <iostream>
#include <string>

bool isPathToFreedom(MazeCell* start, const std::string& moves) {
    MazeCell* current = start;
    bool hasSpellbook = false;
    bool hasWand = false;
    bool hasPotion = false;

    for (char move : moves) {
        if (current == nullptr) return false;

        switch (move) {
            case 'N': current = current->north; break;
            case 'S': current = current->south; break;
            case 'E': current = current->east; break;
            case 'W': current = current->west; break;
            default: return false; // Illegal move
        }

        if (current != nullptr) {
            if (current->whatsHere == Item::SPELLBOOK) hasSpellbook = true;
            else if (current->whatsHere == Item::WAND) hasWand = true;
            else if (current->whatsHere == Item::POTION) hasPotion = true;
        } else {
            return false; // Moved out of bounds
        }
    }

    return hasSpellbook && hasWand && hasPotion;
}

MazeCell* initializeNormalMaze() {
    // Create maze cells
    MazeCell* cellA = new MazeCell{Item::SPELLBOOK, nullptr, nullptr, nullptr, nullptr};
    MazeCell* cellB = new MazeCell{Item::POTION, nullptr, nullptr, nullptr, cellA};
    cellA->south = cellB; // Connect A to B

    MazeCell* cellC = new MazeCell{Item::WAND, nullptr, nullptr, cellB, nullptr};
    cellB->east = cellC; // Connect B to C

    return cellA; // Start at cell A
}
