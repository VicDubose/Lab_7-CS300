//Base.h
#ifndef BASE_H
#define BASE_H

#include <string>
#include <vector>
#include <iostream>

class Concerts; 
class Conferences; 

class Base {
private:
    std::string eventName;   // Important for the name of attendees to be captured
    int eventDay;            // Day of the event
    int eventMonth;          // Month of the event
    std::string location;    // Important to the search function / and Option 2 criteria
    std::vector<std::string> attendees; // List of attendees

public:
    // Constructor
    Base(const std::string &name, int day, int month, const std::string &loc)
        : eventName(name), eventDay(day), eventMonth(month), location(loc) {}

    // Getter methods
    std::string getLocation() const {
        return location;
    }
    int getDay() const {
        return eventDay;
    }
    int getMonth() const {
        return eventMonth;
    }
    std::string getDetails() const {
        return "Event: " + eventName + "\nDate: " + std::to_string(eventDay) + "/" + std::to_string(eventMonth) + "\nLocation: " + location;
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

    size_t getAttendeeCount() const {
        return attendees.size();
    }

    virtual ~Base() {} // Virtual destructor for polymorphism (new add) 

    void displayUI(std::vector<Base*>& events); // Declaration of displayUI

    friend class Concerts;  
    friend class Conferences; // Allowing friends to access private members/ Setter / Getter idea to get the private variables (Is this open closed concept or no ?
};

#endif 
