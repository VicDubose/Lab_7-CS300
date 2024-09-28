#include "user.h"
#include <iostream>

User::User(const std::string& userName, const std::string& email)
    : userName(userName), email(email) {}

void User::setUserName(const std::string& userName) {
    this->userName = userName;
}

void User::setEmail(const std::string& email) {
    this->email = email;
}

std::string User::getUserName() const {
    return userName;
}

std::string User::getEmail() const {
    return email;
}

void User::addFriend(User* friendUser) {
    if (friendList.size() >= 100) {
        std::cout << "Friend list is full. Cannot add more friends.\n";
        return;
    }
    for (const auto& friendPtr : friendList) {
        if (friendPtr == friendUser) {
            std::cout << friendUser->getUserName() << " is already in the friend list.\n";
            return;
        }
    }
    friendList.push_back(friendUser);
    std::cout << friendUser->getUserName() << " added as a friend.\n";
}

void User::removeFriend(User* friendUser) {
    for (auto it = friendList.begin(); it != friendList.end(); ++it) {
        if (*it == friendUser) {
            friendList.erase(it);
            std::cout << friendUser->getUserName() << " removed from friend list.\n";
            return;
        }
    }
    std::cout << friendUser->getUserName() << " not found in friend list.\n";
}

int User::numFriends() const {
    return friendList.size();
}

User* User::getFriendAt(int index) const {
    if (index < 0 || index >= numFriends()) {
        std::cout << "Index out of range. Returning nullptr.\n";
        return nullptr;
    }
    return friendList[index];
}
