CC = g++
CFLAGS = -Wall
LDFLAGS = -lm
EXEC = executable_projet
SRC = $(wildcard *.cpp)
SRTUCT = $(SRC:.cpp=.hpp 
OBJ  = $(SRC:.cpp=.o)

all: $(EXEC)

executable_projet : $(OBJ)
    $(CC) -o $@ $^ $(LDFLAGS)

%.o: $(SRC) $(STRUCT) 
        $(CC) -o $@ -c $< $(CFLAGS)

clean:
        rm -rf *.o

mrproper: clean
        rm -rf $(EXEC)
