//User.cpp (Main) now that the duplicate user interface has been removed (Combined in Base.cpp).
// User.Cpp
#include "Base.h"
#include "Events.h"
#include <iostream>
#include <vector>
#include <string>

// Main function
int main() {
    std::vector<Base*> events;

    // Display the main menu to add events
    displayUI(events); // Ensure this function is defined to handle event creation

    // Handle user actions
    // userActions(events);

    // Cleanup: Free allocated memory for events
    for (auto& event : events) {
        delete event; 
    }

    return 0;
}

