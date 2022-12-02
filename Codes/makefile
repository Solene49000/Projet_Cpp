CC = g++
ALLEGRO = $(pkg-config --libs allegro-5 allegro_font-5 allegro_ttf-5)
CFLAGS = -Wall
LDFLAGS = -lm
EXEC = executable_projet
SRC = $(wildcard *.cpp)
OBJ  = $(SRC:.cpp=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) $(ALLEGRO)

%.o: $(SRC) *.hpp
	$(CC) -o $@ -c $< $(CFLAGS) $(ALLEGRO)

clean:
	rm -rf *.o

clean_all: clean
	rm -rf $(EXEC)
