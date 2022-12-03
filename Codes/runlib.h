
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include "variables.h"

void rungame(ALLEGRO_DISPLAY * display);
void is_mouse_in_tour(int x, int y, bool *isintour1, bool *isintour2, bool *isintour3);
void display_tours();
