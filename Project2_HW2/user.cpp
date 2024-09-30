// user should store all the info about users
// I check if i need a User.h file or .o file
// user.cpp
#include "Base.h"
#include <iostream>
#include <vector>
#include <string>

// Function to display the number of attendees for each event
//void displayAttendanceCount(const std::vector<Event*>& events) {
//  std::cout << "\nAttendance Count for Each Event:\n";
//  for (const auto& event : events) {
//      std::cout << event->getDetails() << std::endl;
//      std::cout << "Number of Attendees: " << event->getAttendeeCount() << std::endl;
//      std::cout << "-----------------------------------" << std::endl;
//  }
//}

// Example function for user actions
//void userActions(std::vector<Event*>& events) {
//  displayAttendanceCount(events);
//}
//      std::cout << "Number of Attendees: " << event->getAttendeeCount() << std::endl;
//      std::cout << "-----------------------------------" << std::endl;
//  }
//}

// Example function for user actions
//void userActions(std::vector<Event*>& events) {
//  displayAttendanceCount(events);
//}

// Function to display the number of attendees for each event
void displayAttendanceCount(const std::vector<Event*>& events) {
    std::cout << "\nAttendance Count for Each Event:\n";
    for (const auto& event : events) {
        std::cout << event->getDetails() << std::endl;
        std::cout << "Number of Attendees: " << event->getAttendeeCount() << std::endl;
        std::cout << "-----------------------------------" << std::endl;
    }
}

// Example function for user actions
void userActions(std::vector<Event*>& events) {
    int choice;

    while (true) {
        std::cout << "\nUser Actions Menu:\n";
        std::cout << "1. Display attendance count\n";
        std::cout << "2. RSVP to an event\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // Clear newline character from the buffer

        if (choice == 1) {
            displayAttendanceCount(events);
        } else if (choice == 2) {
            std::string eventName, userName;
            std::cout << "Enter your name: ";
            std::getline(std::cin, userName);

            std::cout << "Enter event name to RSVP: ";
            std::getline(std::cin, eventName);

            for (auto& event : events) {
                if (event->getDetails().find(eventName) != std::string::npos) {
                    event->rsvp(userName);
                    std::cout << "RSVP'd to " << eventName << " successfully!\n";
                    break;
                }
            }
        } else if (choice == 3) {
            return; // Exit the menu
        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}
