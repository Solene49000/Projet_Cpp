// PROJET TOURS DE HANOI - - ALLOUIS GUILLAUME

//libraries

#include "variables.h"


int main()
{
//Initialisation
al_init();
al_init_font_addon();
al_init_ttf_addon();
al_install_mouse(); //Left button is #1
al_init_primitives_addon();
al_init_image_addon();
//Ouverture fenetre
ALLEGRO_DISPLAY * display = al_create_display(SCRX, SCRY);
al_set_window_title(display, "Tours Hanoi");
//Initialisation gestionnaire des events
ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
al_register_event_source(event_queue, al_get_display_event_source(display));
al_register_event_source(event_queue, al_get_mouse_event_source());
//Gestionnaire des evenements
al_create_event_queue();
//Run menu
runmenu(display, event_queue);
//Destructeurs
al_destroy_display(display);
al_destroy_event_queue(event_queue);
return 0;
}
