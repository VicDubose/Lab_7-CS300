#include <iostream>
#include <string>
#include <vector>

class Animal;
class Dog;
class Cat;
class Shelter;

int displayMenu();
void addAnimal(Shelter &shelter);
void removeAnimal(Shelter &shelter);
void displayAnimals(Shelter &shelter);

int main() {
    Shelter shelter;
    int choice;

    do {
        choice = displayMenu();

        switch (choice) {
            case 1:
                addAnimal(shelter);
                break;
            case 2:
                removeAnimal(shelter);
                break;
            case 3:
                displayAnimals(shelter);
                break;
            case 4:
                std::cout << "Exiting the program" << std::endl;
                break;
            default:
                std::cout << "Invalid option. Please try again." << std::endl;
                break;
        }
    } while (choice != 4);

    return 0;
}

int displayMenu() {
    int choice;
    std::cout << "\n--- Animal Shelter Management System ---\n";
    std::cout << "1. Add an Animal\n";
    std::cout << "2. Remove an Animal\n";
    std::cout << "3. Display All Animals\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

void addAnimal(Shelter &shelter) {
    int typeChoice;
    std::string name, breed;
    int age;

    std::cout << "Select animal type:\n";
    std::cout << "1. Dog\n";
    std::cout << "2. Cat\n";
    std::cout << "Enter your choice: ";
    std::cin >> typeChoice;

    std::cout << "Enter animal's name: ";
    std::cin >> name;
    std::cout << "Enter animal's age: ";
    std::cin >> age;
    std::cout << "Enter breed: ";
    std::cin >> breed;

    if (typeChoice == 1) {
        Dog *dog = new Dog(name, age, breed);
        shelter.addAnimal(dog);
    } else if (typeChoice == 2) {
        Cat *cat = new Cat(name, age, breed);
        shelter.addAnimal(cat);
    } else {
        std::cout << "Invalid animal type." << std::endl;
    }
}

void removeAnimal(Shelter &shelter) {
    std::string name;
    std::cout << "Enter the name of the animal to remove: ";
    std::cin >> name;
    shelter.removeAnimal(name);
}

void displayAnimals(Shelter &shelter) {
    shelter.displayAnimals();
}