CC = g++
CXXFLAGS = -g -Wall $(pkg-config --libs allegro-5 allegro_font-5 allegro_ttf-5)
LDFLAGS = -lm $(pkg-config --libs allegro-5 allegro_font-5 allegro_ttf-5)
EXEC = executable_projet
SRC = $(wildcard *.cpp)
OBJ  = $(SRC:.cpp=.o) 
H = tour.h anneau.h

all: $(EXEC)

$(EXEC): $(OBJ)
        $(CC) $^ $(LDFLAGS) -o $@

%.o: $(SRC)
        $(CC) $(CFLAGS) -o $@ -c $^

main.o: $(H)

clean:
        rm -rf *.o

clean_all: clean
        rm -rf $(EXEC)
