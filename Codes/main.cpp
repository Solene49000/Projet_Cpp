// PROJET TOURS DE HANOI - - ALLOUIS GUILLAUME

//libraries
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>


//VARIABLES GOBALES A METTRE DANS LE FICHIER ADAPTE
#define scrx 640
#define scry 480

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
//ui.background = al_color_name("White");
//ALLEGRO_TIMER *timer;
//ui.FPS = 60
//timer = al_install_timer(1.0 / ui.FPS);
//Set up the event queue
//ui.queue = al_create_event_queue();
//al_register_event_source(ui.queue, (void*)al_get_mouse_state());

//Appeler menu
//al_start_timer(timer);
//run(); /* run my application */

//al_destroy_event_queue(ui.queue);
al_flip_display();

//Temps d'attente en secondes
al_rest(5.0);

al_destroy_font(font);
al_destroy_display(display);
return 0;
}


