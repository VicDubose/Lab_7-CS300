#include <string>
#include <iostream>
#include "animal.h"

Animal::Animal(std::string cName, int cAge, std::string cType) {
  name = cName;
  age = cAge;
  type = cType;
};

void Animal::displayInfo() {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Age: " << age << std::endl;
  std::cout << "Type: " << type << std::endl;
};

std::string Animal::getType() {
  return type;
};

Dog::Dog(std::string cName, int cAge, std::string cBreed)
  : Animal(cName, cAge, "dog") {
  breed = cBreed;
};

void Dog::displayInfo () {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Age: " << age << std::endl;
  std::cout << "Breed: " << breed << std::endl;
};

Cat::Cat(std::string cName, int cAge, std::string cBreed)
  : Animal(cName, cAge, "cat") {
  breed = cBreed;
};

void Cat::displayInfo () {
  std::cout << "Name: " << name << std::endl;
  std::cout << "Age: " << age << std::endl;
  std::cout << "Breed: " << breed << std::endl;
};
