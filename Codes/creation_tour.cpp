// PROJET TOURS DE HANOI - - ALLOUIS GUILLAUME

//libraries
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>

#include "tour.h"
#include "anneau.h"

class tour () {

	int main()
	{
		//Initialisation
		al_init();
		al_init_font_addon();
		al_init_ttf_addon();
		al_install_mouse(); //Left button is #0
		//Ouverture fenetre
		ALLEGRO_DISPLAY * display = al_create_display(scrx, scry);
		al_set_window_title(display, "Tours Hanoi");
		ALLEGRO_FONT * font = al_load_ttf_font("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 64,0);



		//al_destroy_event_queue(ui.queue);
		al_flip_display();

		//Temps d'attente en secondes
		al_rest(5.0);

		al_destroy_font(font);
		al_destroy_display(display);
		return 0;
	}
}
