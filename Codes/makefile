C = g++
CXXFLAGS = -g -Wall $(pkg-config --libs allegro-5 allegro_font-5 allegro_ttf-5)
LDFLAGS = -lm $(pkg-config --libs allegro-5 allegro_font-5 allegro_ttf-5)
EXEC = executable_projet
SRC = $(wildcard *.cpp)
OBJ  = $(SRC:.cpp=.o) 
H = tour.h anneau.h
OBJ_H = $(H:.h=.o)

all: $(EXEC)

$(EXEC): $(OBJ) $(OBJ_H)
        $(CC) $^ $(LDFLAGS) -o $@

%.o: $(SRC) $(H)
        $(CC) $(CFLAGS) -o $@ -c $^

clean:
        rm -rf *.o

clean_all: clean
        rm -rf $(EXEC)
