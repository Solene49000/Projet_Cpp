CC = g++
CXXFLAGS = -g -Wall 
CXXFLAGS += `pkg-config --libs allegro-5 allegro_font-5 allegro_ttf-5 allegro_primitives-5 allegro_image-5`
LDFLAGS = -lm 
EXEC = executable_projet
SRC = $(wildcard *.cpp)
OBJ  = $(SRC:.cpp=.o) 
H = tour.h anneau.h variables.h bouton.h librairies.h

all: $(EXEC)

$(EXEC):$(OBJ)
	$(CC) $^ -o $@ $(CXXFLAGS)

%.cpp.o: $(SRC)
	$(CC) $(CXXFLAGS) -o $@ -c $<

main.o: $(H)

clean:
	rm -rf *.o

clean_all: clean
	rm -rf $(EXEC)
