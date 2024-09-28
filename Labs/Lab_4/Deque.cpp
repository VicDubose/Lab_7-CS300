
//Deque.cpp

#include "deque.h"
#include <iostream>
Deque::Deque() : front(0), back(0), capacity(1000), size(0) {
    data = new int[capacity];
}
Deque::~Deque() {
    remove_all();
}
void Deque::push_front(int value) {
    if (size >= capacity) {
        std::cout << "Deque is full. Cannot push front.\n";
        return;
    }
    front = (front - 1 + capacity) % capacity;
    data[front] = value;
    size++;
}
void Deque::push_back(int value) {
    if (size >= capacity) {
        std::cout << "Deque is full. Cannot push back.\n";
        return;
    }
    data[back] = value;
    back = (back + 1) % capacity;
    size++;
}
int Deque::pop_front() {
    if (is_empty()) {
        std::cout << "Deque is empty. Cannot pop front.\n";
        return -1; // Return a sentinel value or handle as needed
    }
    int value = data[front];
    front = (front + 1) % capacity;
    size--;
    return value;
}
int Deque::pop_back() {
    if (is_empty()) {
        std::cout << "Deque is empty. Cannot pop back.\n";
        return -1; // Return a sentinel value or handle as needed
    }
    back = (back - 1 + capacity) % capacity;
    int value = data[back];
    size--;
    return value;
}
int Deque::peak_front() const {
    if (is_empty()) {
        std::cout << "Deque is empty. Cannot peak front.\n";
        return -1; // Return a sentinel value or handle as needed
    }
    return data[front];
}
int Deque::peak_back() const {
    if (is_empty()) {
        std::cout << "Deque is empty. Cannot peak back.\n";
        return -1; // Return a sentinel value or handle as needed
    }
    return data[(back - 1 + capacity) % capacity];
}
void Deque::remove_all() {
    delete[] data;
    data = new int[capacity];
    front = 0;
    back = 0;
    size = 0;
}
bool Deque::is_empty() const {
    return size == 0;
}
int Deque::get_size() const {
    return size;
}
