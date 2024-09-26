#include <iostream>
#include <vector>
#include <string>
#include <algorithm> 


class Animal {
public:
    Animal(const std::string& name) : name(name) {}
    virtual ~Animal() = default;

    std::string getName() const { return name; }
    virtual void display() const = 0;

protected:
    std::string name;
};

// Example derived class
class Dog : public Animal {
public:
    Dog(const std::string& name) : Animal(name) {}
    void display() const override {
        std::cout << "Dog: " << name << std::endl;
    }
};

class Cat : public Animal {
public:
    Cat(const std::string& name) : Animal(name) {}
    void display() const override {
        std::cout << "Cat: " << name << std::endl;
    }
};

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
            animal->display();
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

int main() {
    Shelter shelter;
    //std::cout << "Enter your choice: ";
    // std::getline(std::cin, choice);
    // Adding animals to the shelter
    shelter.addAnimal(new Dog("Buddy"));
    shelter.addAnimal(new Cat("Whiskers"));
    shelter.addAnimal(new Dog("Max"));

    // Display all animals
    shelter.displayAnimals();

    shelter.removeAnimal("Buddy");
    std::cout << "\nAfter removing Buddy:" << std::endl;
    shelter.displayAnimals();

    return 0;
}
