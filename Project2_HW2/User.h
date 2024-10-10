// User.h
#ifndef USER_H
#define USER_H

#include <vector>
#include <string>
#include "Base.h" 
#include "Events.h" 

void displayAttendanceCount(const std::vector<Base*>& events);
void userActions(std::vector<Base*>& events);

#endif // USER_H
