#ifndef BASE_H
#define BASE_H

#include <string>
#include <vector>
#include <iostream>

class Event {
private:
    std::string eventName;
    int eventDay;  // Day of the event
    int eventMonth; // Month of the event
    std::string location;
    std::vector<std::string> attendees; // List of attendees

public:
    Event(const std::string &name, int day, int month, const std::string &loc)
        : eventName(name), eventDay(day), eventMonth(month), location(loc) {}

    std::string getDetails() const {
        return "Event: " + eventName + "\nDate: " + std::to_string(eventDay) + "/" + std::to_string(eventMonth) + "\nLocation: " + location;
    }

    bool isUpcoming(int currentDay, int currentMonth) const {
        if (eventMonth > currentMonth) {
            return true; // Event is in a future month
        } else if (eventMonth == currentMonth) {
            return eventDay > currentDay; // Event is later in the current month
        }
        return false; // Event is in the past
    }

    void rsvp(const std::string &attendee) {
        attendees.push_back(attendee);
    }
    void displayAttendees() const {
        std::cout << "Attendees for " << eventName << ":\n";
        for (const auto& attendee : attendees) {
            std::cout << "- " << attendee << std::endl;
        }
    }

    // Method to get the number of attendees
    size_t getAttendeeCount() const {
        return attendees.size();
    }
};

#endif // BASE_H

