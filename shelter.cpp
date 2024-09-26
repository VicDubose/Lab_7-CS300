#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 
#include "animal.h"

class Shelter {
public:
    void addAnimal(Animal* animal) {
        animals.push_back(animal);
    }

    void removeAnimal(const std::string& name) {
        animals.erase(std::remove_if(animals.begin(), animals.end(),
            [&name](Animal* animal) {
                return animal->getName() == name;
            }), animals.end());
    }

    void displayAnimals() const {
        std::cout << "Animals in the shelter:" << std::endl;
        for (const auto& animal : animals) {
            animal->displayInfo();
        }
    }

    ~Shelter() {
        for (auto animal : animals) {
            delete animal;
        }
    }

private:
    std::vector<Animal*> animals; // Collection of animal pointers
};

// int main() {
//     Shelter shelter;
//     //std::cout << "Enter your choice: ";
//     // std::getline(std::cin, choice);
//     // Adding animals to the shelter
//     shelter.addAnimal(new Dog("Buddy",10,"poodle"));
//     shelter.addAnimal(new Cat("Whiskers",11,"sphynx"));
//     shelter.addAnimal(new Dog("Max",12,"retriever"));

//     // Display all animals
//     shelter.displayAnimals();

//     shelter.removeAnimal("Buddy");
//     std::cout << "\nAfter removing Buddy:" << std::endl;
//     shelter.displayAnimals();

//     return 0;
// }
