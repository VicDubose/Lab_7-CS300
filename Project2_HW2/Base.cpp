// Base.cpp
// redone base to not have duplicates with user
//make a submenu to utilize your location Variable to its fullest
// Strategy Pattern is mainly utilized in option 2 
#include "Base.h"
#include "Events.h"
#include <iostream>
#include <vector>
#include <string>
#include <limits>

bool isValidDate(int day, int month) {
    if (month < 1 || month > 12 || day < 1 || day > 31) return false;

    // Validate days in each month
    if (month == 2) {
        return day <= 29;
    }
    if (month == 4 || month == 6 || month == 9 || month == 11) {
        return day <= 30;
    }
    return true;
}

void displayEvents(const std::vector<Base*>& events) {
    std::cout << "-----------------------------------" << std::endl;
    for (const auto& event : events) {
        std::cout << event->getDetails() << std::endl;
        event->displayAttendees();
        std::cout << "-----------------------------------" << std::endl;
    }
}

void displayAttendanceCount(const std::vector<Base*>& events) {
    std::cout << "Attendance Count for Events:\n";
    for (const auto& event : events) {
        std::cout << event->getDetails() << " - Attendees: " << event->getAttendeeCount() << std::endl;
    }
}

void displayUI(std::vector<Base*>& events) {
    int choice;
    int currentDay, currentMonth;

    // Get current date from user
    std::cout << "\nWelcome to the Event Planner\n";
    std::cout << "What is today's date?\n";
    std::cout << "Enter the current day (1-31): ";
    std::cin >> currentDay;
    std::cout << "Enter current month (1-12): ";
    std::cin >> currentMonth;

    // Validate time
    if (!isValidDate(currentDay, currentMonth)) {
        std::cout << "Invalid current date input. Please restart the program.\n";
        return;
    }
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the input buffer

    while (true) {
        std::cout << "\n** Event Planner **:\n";
        std::cout << "1. Add a new event\n";
        std::cout << "2. Display events\n";
        std::cout << "3. RSVP for an event\n";
        std::cout << "4. Display Attendance count\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::string input;
        std::getline(std::cin, input);

        // Convert input to integer
        choice = std::stoi(input);

        if (choice == 1) { // option 1 
            std::string name, location, genre, bandName;
            int day, month, totalHeadcount;
            std::vector<std::string> speakers, topics;
            int eventType;

            std::cout << "Choose event type (1: Concert, 2: Conference): ";
            std::getline(std::cin, input);
            eventType = std::stoi(input);

            std::cout << "Enter event name: ";
            std::getline(std::cin, name);
            std::cout << "Enter event day (1-31): ";
            std::getline(std::cin, input);
            day = std::stoi(input);
            std::cout << "Enter event month (1-12): ";
            std::getline(std::cin, input);
            month = std::stoi(input);
            std::cout << "Enter event location: ";
            std::getline(std::cin, location);

            if (!isValidDate(day, month)) {
                std::cout << "Invalid event date. Please try again.\n";
                continue;
            }

            if (eventType == 1) { // Concert
                std::cout << "Enter genre: ";
                std::getline(std::cin, genre);
                std::cout << "Enter band name: ";
                std::getline(std::cin, bandName);
                std::cout << "Enter total headcount: ";
                std::getline(std::cin, input);
                totalHeadcount = std::stoi(input);
                events.push_back(new Concerts(name, day, month, location, genre, bandName, totalHeadcount));
            } else if (eventType == 2) { // Conference
                std::string speaker, topic;
                std::cout << "Enter number of speakers: ";
                std::getline(std::cin, input);
                int numSpeakers = std::stoi(input);
                for (int i = 0; i < numSpeakers; ++i) {
                    std::cout << "Enter speaker name: ";
                    std::getline(std::cin, speaker);
                    speakers.push_back(speaker);
                }
                std::cout << "Enter number of topics: ";
                std::getline(std::cin, input);
                int numTopics = std::stoi(input);
                for (int i = 0; i < numTopics; ++i) {
                    std::cout << "Enter topic: ";
                    std::getline(std::cin, topic);
                    topics.push_back(topic);
                }
                events.push_back(new Conferences(name, day, month, location, speakers, topics));
            } else {
                std::cout << "Invalid event type. Please choose 1 or 2.\n";
            }
        } else if (choice == 2) { // Option 2 in base menu
            int subChoice;
            while (true) {
                std::cout << "\n** Display Events Menu **:\n";
                std::cout << "1. Display All Events\n";
                std::cout << "2. Search by Location\n";
                std::cout << "3. Search by Date\n";
                std::cout << "4. Search by Event Type\n";
                std::cout << "5. Back\n";
                std::cout << "Enter your choice: ";
                std::getline(std::cin, input);
                subChoice = std::stoi(input);

                if (subChoice == 1) {
                    displayEvents(events);
                } else if (subChoice == 2) {
                    std::string location;
                    std::cout << "Enter location to search: ";
                    std::getline(std::cin, location);
                    std::vector<Base*> filteredEvents;
                    for (const auto& event : events) {
                        if (event->getLocation() == location) { 
                            filteredEvents.push_back(event);
                        }
                    }
                    displayEvents(filteredEvents);
                } else if (subChoice == 3) {
                    int day, month;
                    std::cout << "Enter event day (1-31): ";
                    std::cin >> day;
                    std::cout << "Enter event month (1-12): ";
                    std::cin >> month;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                    std::vector<Base*> filteredEvents;
                    for (const auto& event : events) {
                        if (event->getDay() == day && event->getMonth() == month) {
                            filteredEvents.push_back(event);
                        }
                    }
                    displayEvents(filteredEvents);
                } else if (subChoice == 4) {
                    int eventType;
                    std::cout << "Choose event type (1: Concert, 2: Conference): ";
                    std::cin >> eventType;
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer

                    std::vector<Base*> filteredEvents;
                    for (const auto& event : events) {
                        if ((eventType == 1 && dynamic_cast<Concerts*>(event)) ||
                            (eventType == 2 && dynamic_cast<Conferences*>(event))) {
                            filteredEvents.push_back(event);
                        }
                    }
                    displayEvents(filteredEvents);
                } else if (subChoice == 5) {
                    break; // Go back to main menu
                } else {
                    std::cout << "Invalid option. Please try again.\n";
                }
            }
        } else if (choice == 3) { // Option 3 in menu RSVP function (needs the UserName variable
            std::string userName, eventName;
            std::cout << "Enter your name: ";
            std::getline(std::cin, userName);
            std::cout << "Enter event name to RSVP: ";
            std::getline(std::cin, eventName);
            bool found = false;
            for (auto& event : events) {
                if (event->getDetails().find(eventName) != std::string::npos) {
                    event->rsvp(userName);
                    std::cout << "RSVP'd to " << eventName << " successfully!\n";
                    found = true;
                    break;
                }
            }
            if (!found) {
                std::cout << "Event not found.\n";
            }
        } else if (choice == 4) { // Shows whos going to all events helps if search is to much
            displayAttendanceCount(events);
        } else if (choice == 5) {
            for (auto& event : events) {
                delete event;
            }
            events.clear();
            return; // Exit the menu
        } else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}
