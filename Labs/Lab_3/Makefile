CXX = g++
EXEC = trip_calculator

# Default target
all: $(EXEC)

$(EXEC): main.o trip.o
	$(CXX) -Wall -Werror -o $(EXEC) main.o trip.o

main.o: main.cpp
	$(CXX) -Wall -Werror -c main.cpp

trip.o: trip.cpp
	$(CXX) -Wall -Werror -c trip.cpp
run: all
	./$(EXEC)
