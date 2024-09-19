#include <iostream>
#include <string>

const int MAX_BOOKS = 1000;

struct Book {
    int id; // The Library of Congress catalog number
    std::string title; // The Title
    std::string publisher; // The publisher
    std::string creator; // The Author
    int year; // The Year of publication
};

struct Library {
    Book books[MAX_BOOKS];
    int count; // Number of books currently stored
};

void displayBooks(const Library& library) {
    std::cout << "ID\tTitle\t\t\tCreator\t\tYear" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    for (int i = 0; i < library.count; ++i) {
        const Book& book = library.books[i];
        std::cout << book.id << '\t' << book.title << '\t' << book.creator << '\t' << book.year << std::endl;
    }
}

void menu(Library& library) {
    std::string choice; // Using string to read choices

    while (true) {
        std::cout << "\nMenu:\n";
        std::cout << "1. Add a new book\n";
        std::cout << "2. Display books\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::getline(std::cin, choice); // Read choice to make this work.

        if (choice == "1") {
            if (library.count >= MAX_BOOKS) {
                std::cout << "Library is full. Cannot add any more books.\n";
                continue;
            }

            Book book;
            std::cout << "Enter ID: ";
            std::cin >> book.id;
            std::cin.ignore(); 

            std::cout << "Enter Title: ";
            std::getline(std::cin, book.title);

            std::cout << "Enter Publisher: ";
            std::getline(std::cin, book.publisher);

            std::cout << "Enter Creator (Author): ";
            std::getline(std::cin, book.creator);

            std::cout << "Enter Year of Publication: ";
            std::cin >> book.year;
            std::cin.ignore(); 

            library.books[library.count] = book; 
            library.count++; 
        } 
        else if (choice == "2") {
            displayBooks(library);
        } 
        else if (choice == "3") {
            break; // Exit the loop
        } 
        else {
            std::cout << "Invalid option. Please try again.\n";
        }
    }
}

int main() {
    Library library = { {}, 0 }; // Initialize the library
    menu(library);
    return 0;
}
