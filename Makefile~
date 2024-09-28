# Compiler
CXX = g++
TARGETS = deque_example user_example

MAIN_SRC = main.cpp
DEQUE_SRC = deque.cpp
USER_SRC = user.cpp

MAIN_OBJ = $(MAIN_SRC:.cpp =.o)
DEQUE_OBJ = $(DEQUE_SRC:.cpp=.o)
USER_OBJ = $(USER_SRC:.cpp=.o)
all: $(TARGETS)

deque_example: $(MAIN_OBJ) $(DEQUE_OBJ) $(USER_OBJ)
	$(CXX) $(MAIN_OBJ) $(DEQUE_OBJ) -o $@

user_example: $(MAIN_OBJ) $(USER_OBJ)
	$(CXX) $(MAIN_OBJ) $(USER_OBJ) -o $@

# Compile object files
$(MAIN_OBJ): $(MAIN_SRC) deque.h user.h
	$(CXX) -c $(MAIN_SRC)

$(DEQUE_OBJ): $(DEQUE_SRC) deque.h
	$(CXX) -c $(DEQUE_SRC)

$(USER_OBJ): $(USER_SRC) user.h
	$(CXX) -c $(USER_SRC)

# Run target
run: deque_example
	./deque_example 

clean:
	rm -f $(DEQUE_OBJ) $(USER_OBJ) $(TARGETS)

