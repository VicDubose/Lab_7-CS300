### This Program is Called Event_Planner ###

The Event Planner program can be executed using the command ./Event_Planner. My name is Vic Tyrone Dubose, and I hope this information provides clarity on the project's structure.
While I recognize the need for a README page to explain my code, I'm uncertain about what additional information to include.

In this implementation, I utilized friend classes to minimize the use of extensive setters and getters, as I'm not very proficient in their implementation.
This approach serves as my workaround. The program features four menus, including one main menu and three sub-menus, all of which are implemented in the Base.cpp file.
The design concept I chose for this project is the Strategy Pattern, which is prominently displayed in Menu Option 2. This menu allows users to search for events based on different criteria,
including date, location, and type, as well as to display all events. Additionally, the use of friend classes allows for adherence to the open-closed principle,enabling me to add more friend classes to the program without altering the base code found in Base.h. this allows me to make small edits to the Base.cpp file to add an additional menu option in the various Sub-menus to avoid opening and altering major parts of the code.


references used :
(https://www.geeksforgeeks.org/dynamic-_cast-in-cpp/ ) = Dynamic_Cast to classes.
(https://cplusplus.com/reference/string/stoi/)(https://www.geeksforgeeks.org/stdstoi-function-in-cpp/) = Stoi conversion methods used.
(https://www.geeksforgeeks.org/friend-class-function-cpp/) = Friend class implementations for base understanding.
(https://www.geeksforgeeks.org/write-getter-and-setter-methods-in-cpp/)(https://www.geeksforgeeks.org/cpp-getters-and-setters/) = Setter & getter understanding.
(https://www.softwaretestinghelp.com/cpp-makefile-tutorial/) = Makefile help + older notes

### to answer the questions in HW2 ### :
Write documentation explaining your design choices, including:

**  How inheritance was utilized in your design ** :
In the Event Planner project, inheritance was employed to create a hierarchical structure that facilitates code reuse and organization. The base class serves as the foundation for the event management system, encapsulating common functionality. Inheritance was utilized through my friend classes implemented in my Base.h, they allowed my class Concert and Conference to inherit the private variables in my Base class so that if i needed to implement more types of events in the future I could layer more friend classses over my Base class without changing the Base class to gain those private variables and also implement new funtions without the use of extensive rework or extensive setters and getters.


** Why use of a vector of pointers ** :
Utilizing a vector of pointers provides flexibility in managing dynamic event objects. This approach allows for the storage of heterogeneous event types, as each pointer can point to different derived class instances. It also aids in efficient memory management, enabling us to easily add, remove, or manipulate events without needing to copy entire objects. Moreover, using pointers helps to avoid slicing issues, ensuring that derived class features are preserved. This understanding was put to full use in my Base.cpp where I used : std::vector<Base*> events; which is a vector pointer that points at the base object, i also utilized this in menu option 2 When adding new events (either Concerts or Conferences), I use new to create instances and store their pointers in the events vector. Theres even a temporary vector when searching for events by location, date, or type, I created the temporary vector (filteredEvents) that also hold pointers to Base objects, this was all possible only by utilizing vectors and pointers.

** Why using design patterns is beneficial ** :
Implementing design patterns, such as the Strategy Pattern in Menu Option 2, brings several advantages:
    Modularity: By encapsulating different search strategies, we can easily add/modify functionality without affecting the overall system.
    Flexibility: Users can choose their preferred search method (date, location, type) at runtime, enhancing usability.
    Maintenance: Isolating algorithms from the context allows for easier updates&debugging, promoting cleaner code&reducing potential errors.
    
** Any challenges encountered during development **:
During the development of the Event Planner, I faced several challenges:
    Understanding Friend Classes: While friend classes simplify access control, grasping their implications required additional research. I relied on resources to better understand their usage and benefits.
    Implementing the Strategy Pattern: Designing a flexible system that adhered to the Strategy Pattern was initially daunting, particularly in ensuring that the interface was intuitive for users.
    Creating a README: I struggled with determining what essential information to include in the README. I aim to provide clear guidance on the project structure and functionality, as well as instructions for usage.
    Creation and use of multiple pages: during this project I struggled to understand the reason for .h, .o and .cpp files and how they all function to make a cohesive program, originally my User.cpp  and Base.cpp both had user interfaces that duplicated information and i threw all problems to the user input. after visiting with Dr.Wagner i learned that I needed significant revisions to make a final product. I originally reused a makefile form a earlier project blindly making pages i didnt quite need which still presists through my code currently all in an attempt to force complexity. 
