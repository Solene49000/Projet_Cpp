//PROJET TOURS HANOI - - ALLOUIS GUILLAUME
#include "runlib.h"
#include "variables.h"

//DEMMARAGE
void rungame(ALLEGRO_DISPLAY * display) {
	//Initialisation librairies
	al_init_primitives_addon();
	//Initialisation gestionnaire des events
	ALLEGRO_EVENT_QUEUE * event_queue = al_create_event_queue();
	al_register_event_source(event_queue, al_get_display_event_source(display));
	al_register_event_source(event_queue, al_get_mouse_event_source());
	//Initialisation des variables
	int x = 0, y = 0;
	bool loop = true;
	bool * isintour1 = (bool*)malloc(sizeof(bool));
	bool * isintour2 = (bool*)malloc(sizeof(bool));
	bool * isintour3 = (bool*)malloc(sizeof(bool));
	*isintour1=false;
	*isintour2=false;
	*isintour3=false;
	bool selection = false; //Selection prend la valeur TRUE si un disque est selectionné
	
	//Gestionnaire des evenements
	al_create_event_queue();
	    while (loop){
		display_tours();
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		//Si appui sur croix rouge : fermer fenêtre
		if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
	            loop=false;
	        }

	        // si mouvement de souris : enregistrer la position
	        if (events.type == ALLEGRO_EVENT_MOUSE_AXES ){
	            x=events.mouse.x;
	            y=events.mouse.y;
	        }

		is_mouse_in_tour(x,y,isintour1,isintour2,isintour3);

		//si clic sur tour pour selectionner un disque : Appel fonction supprimer disque
		if (events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && selection==false && (*isintour1 == true || *isintour2 == true || *isintour3 == true))
		{
			if(events.mouse.button & 1)
			{
				selection = false;
				al_clear_to_color(al_map_rgb(rand() % 256,rand() % 256, rand() % 256));
			//Appel prog pour supprimer le disque de la tour concernée
			}
		}
		//si clic sur tour pour poser disque : Appel fonction pose disque
		if(events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && selection==true && (*isintour1 == true || *isintour2 == true || *isintour3 == true))
		{
			if(events.mouse.button & 1)
			{
				selection = false;
				al_clear_to_color(al_map_rgb(0,0,0));
			}
		}
		//Afficher nouvel écran
	        al_flip_display();
	}//Fin gestionnaire des evenements
	//Destructeur
	al_destroy_event_queue(event_queue);
}

void is_mouse_in_tour(int x, int y, bool *isintour1, bool *isintour2, bool *isintour3 ){
//Variables position tour (A METTRE EN VAR GLOBALES)
	int tour1posx=100;
	int tour2posx=320;
	int tour3posx=440;
	int tourposy=80;
	int tourlargeur=100;
	int tourhauteur=300;
	//Position dans une tour ?
	if(tour1posx < x && x < (tour1posx + tourlargeur) && tourposy < y && y < (tourposy + tourhauteur))
	{
		*isintour1 = true;
	}
	else if(tour2posx < x && x < (tour2posx + tourlargeur) && tourposy < y && y < (tourposy + tourhauteur))
	{
		*isintour2 = true;
	}
	else if(tour3posx < x && x < (tour3posx + tourlargeur) && tourposy < y && y < (tourposy + tourhauteur))
	{
		*isintour3 = true;
	}
	else{
		*isintour1 = false;
		*isintour2=false;
		*isintour3=false;
	}
}
void display_tours(){

	int tour1posx=100;
	int tour2posx=320;
	int tour3posx=440;
	int tourposy=80;
	int tourlargeur=100;
	int tourhauteur=300;

	//Rectangles représentant les tours
	al_draw_filled_rectangle(tour1posx, tourposy, tour1posx+tourlargeur, tourposy+tourhauteur,al_map_rgb(0,0,0));
	al_draw_filled_rectangle(tour2posx, tourposy, tour2posx+tourlargeur, tourposy+tourhauteur,al_map_rgb(0,0,0));
	al_draw_filled_rectangle(tour3posx, tourposy, tour3posx+tourlargeur, tourposy+tourhauteur,al_map_rgb(0,0,0));
}
