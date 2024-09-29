//deque.h

#ifndef DEQUE_H
#define DEQUE_H
class Deque {
private:
    int* data;          
    int front;          
    int back;           
    int capacity;      
    int size;           // Current number of elements in the deque
public:
    Deque();            // Constructor
    ~Deque();           // Destructor
    void push_front(int value);
    void push_back(int value);
    int pop_front();
    int pop_back();
    int peak_front() const;
    int peak_back() const;
    void remove_all();
    bool is_empty() const;
    int get_size() const;
};
#endif // DEQUE_H

