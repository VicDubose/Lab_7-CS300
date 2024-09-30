// Base case we need to put Base Class:
//o Define a base class Event with common attributes and methods for all
//events. Attributes might include eventName, eventDate, location, and
//methods like getDetails() and isUpcoming().

// Base.cpp

// redone base to not have duplicates with user
#include "Base.h"
#include <iostream>
#include <vector>
#include <string>

void displayEvents(const std::vector<Event*>& events, int currentDay, int currentMonth) {
    for (const auto& event : events) {
        std::cout << event->getDetails() << std::endl;
        std::cout << "Is upcoming? " << (event->isUpcoming(currentDay, currentMonth) ? "Yes" : "No") << std::endl;
        event->displayAttendees(); // Display attendees for each event
        std::cout << "-----------------------------------" << std::endl;
    }
}

void menu(std::vector<Event*>& events) {
    int choice;
    int currentDay, currentMonth;

    // Get current date from user
    std::cout << "Enter current day (1-31): ";
    std::cin >> currentDay;
    std::cout << "Enter current month (1-12): ";
    std::cin >> currentMonth;

    // Validate the current date
    if (currentDay < 1 || currentDay > 31 || currentMonth < 1 || currentMonth > 12) {
        std::cout << "Invalid current date input. Please restart the program.\n";
        return;
    }

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a new event\n";
        std::cout << "2. Display events\n";
        std::cout << "3. RSVP for an event\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character from the buffer

        if (choice == 1) {
            std::string name, location;
            int day, month;
            std::cout << "Enter event name: ";
            std::getline(std::cin, name);
            std::cout << "Enter event day (1-31): ";
            std::cin >> day;
            std::cout << "Enter event month (1-12): ";
            std::cin >> month;
            std::cin.ignore(); // Clear newline character

            // Validate the event date
            if (day < 1 || day > 31 || month < 1 || month > 12) {
                std::cout << "Invalid event date input. Please try again.\n";
                continue;
            }

            std::cout << "Enter event location: ";
            std::getline(std::cin, location);
            
            // Create new event
            events.push_back(new Event(name, day, month, location));
            std::cout << "Event added successfully!\n";

        } else if (choice == 2) {
            displayEvents(events, currentDay, currentMonth);

        } else if (choice == 3) {
            // Call user actions here if needed
            // userActions(events);  // Uncomment if userActions should be invoked here

        } else if (choice == 4) {
            return; // Exit the menu

        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}

// The main function to initialize everything.
int main() {
    std::vector<Event*> events; 
    menu(events);
    for (auto& event : events) {
        delete event; // Clean up dynamic memory
    }

    return 0;
}

