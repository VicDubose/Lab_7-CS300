** Currently the code seems to work but im having a major issue trying to test the code without a main.cpp file and my clean command in my makefile doesnt seem to be operational ** 


wsl@Ghost:~/CS-300-Tyr1jr1/Labs/Lab_4$ make
make: Circular main.cpp <- main.cpp dependency dropped.
make: Nothing to be done for 'all'.
wsl@Ghost:~/CS-300-Tyr1jr1/Labs/Lab_4$ ./deque_example
Hello, World!
wsl@Ghost:~/CS-300-Tyr1jr1/Labs/Lab_4$ ^C
wsl@Ghost:~/CS-300-Tyr1jr1/Labs/Lab_4$ make run
make: Circular main.cpp <- main.cpp dependency dropped.
./deque_example
Hello, World!
