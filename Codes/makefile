CC = g++
ALLEGRO = $(pkg-config --libs allegro-5 allegro_font-5 allegro_ttf-5)
CFLAGS = -Wall
LDFLAGS = -lm
EXEC = executable_projet
SRC = $(wildcard *.cpp)
SRTUCT = $(SRC:.cpp=.hpp 
OBJ  = $(SRC:.cpp=.o)

all: $(EXEC)

executable_projet : $(OBJ)
    $(CC) -o $@ $^ $(LDFLAGS) $(ALLEGRO)

%.o: $(SRC) $(STRUCT) 
	$(CC) -o $@ -c $< $(CFLAGS) $(ALLEGRO)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
