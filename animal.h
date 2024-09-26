#ifndef _animal_h
#define _animal_h

#include <string>

class Animal {

 public:
  //constructor
  Animal(std::string cName, int cAge, std::string cType);

  //prints animal's details
  virtual void displayInfo();

  //returns animal's type
  std::string getType();

  std::string getName();

 protected:

  std::string name;
  int age;
  std::string type;

};

class Dog : public Animal {

 public:

  //constructor (no need for type as a parameter)
  Dog(std::string cName, int cAge, std::string cBreed);

  //additionally includes breed information
  void displayInfo() override;

 private:

  std::string breed;

};

class Cat : public Animal {

 public:

  //constructor (no need for type as a parameter)
  Cat(std::string cName, int cAge, std::string cBreed);

  //additionally includes breed information
  void displayInfo() override;

 private:

  std::string breed;

};
  
  
#endif
