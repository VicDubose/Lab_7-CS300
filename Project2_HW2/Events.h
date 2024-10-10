// Events.h Links Private variables to other classes (Works around setting and getting)
#ifndef EVENTS_H
#define EVENTS_H

#include "Base.h"
#include <vector>
#include <iostream>

// declaration of the displayUI function
void displayUI(std::vector<Base*>& events);

class Concerts : public Base {
private:
    std::string genre;
    std::string bandName;
    int totalHeadcount;

public:
    Concerts(const std::string &name, int day, int month, const std::string &loc, const std::string &gen, const std::string &band, int headcount)
        : Base(name, day, month, loc), genre(gen), bandName(band), totalHeadcount(headcount) {}

    void displayDetails() const {
        std::cout << getDetails() << "\nGenre: " << genre << "\nBand: " << bandName << "\nTotal Headcount: " << totalHeadcount << std::endl;
    }
};

class Conferences : public Base {
private:
    std::vector<std::string> speakers;
    std::vector<std::string> topics;

public:
    Conferences(const std::string &name, int day, int month, const std::string &loc, const std::vector<std::string> &speak, const std::vector<std::string> &top)
        : Base(name, day, month, loc), speakers(speak), topics(top) {}

    void displayDetails() const {
        std::cout << getDetails() << "\nSpeakers: ";
        for (const auto& speaker : speakers) {
            std::cout << speaker << " ";
        }
        std::cout << "\nTopics: ";
        for (const auto& topic : topics) {
            std::cout << topic << " ";
        }
        std::cout << std::endl;
    }
};

#endif

