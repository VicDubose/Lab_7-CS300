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