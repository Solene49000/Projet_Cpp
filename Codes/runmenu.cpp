//PROJET TOURS HANOI - - ALLOUIS GUILLAUME
#include "runlib.h"
#include "variables.h"

//DEMMARAGE
void runmenu(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue) {
	//Initialisation des variables
	int x = 0, y = 0;
	bool loop = true;
	bool * isinplay = (bool*)malloc(sizeof(bool));
	bool * isinIAplay = (bool*)malloc(sizeof(bool));
	bool * isineasy = (bool*)malloc(sizeof(bool));
	bool * isinmedium = (bool*)malloc(sizeof(bool));
	bool * isinhard = (bool*)malloc(sizeof(bool));
	*isinplay=false;
	*isinIAplay=false;
	*isineasy=false;
	*isinmedium=false;
	*isinhard=false;
	//Initialisation des boutons
	GrandRectangle rect_play(120 ,120, BLUE);
	GrandRectangle rect_IA_play(120,220,BLUE);
	MoyenRectangle rect_easy(120, 320, BLUE);
	MoyenRectangle rect_medium(260, 320, LIGHT_BLUE);
	MoyenRectangle rect_hard(400, 320, BLUE);
	//Initialisation polices
	ALLEGRO_FONT * font = al_load_ttf_font("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 64,0);
	ALLEGRO_FONT * medium_font = al_load_ttf_font("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf", 25,0);

	//Gestionnaire des evenements
	while (loop){
		display_buttons(rect_play, rect_IA_play, rect_easy, rect_medium, rect_hard, isinplay, isinIAplay, isineasy, isinmedium, isinhard, font, medium_font);
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		//Si appui sur croix rouge : fermer fenêtre
		if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
	            loop=false;
	        }

	        // si mouvement de souris : enregistrer la position
	        if (events.type == ALLEGRO_EVENT_MOUSE_AXES){
	            x=events.mouse.x;
	            y=events.mouse.y;
	        }
		//determine si souris sur un bouton
		is_mouse_in_button(x,y,isinplay,isinIAplay,isineasy, isinmedium, isinhard, rect_play, rect_IA_play, rect_easy, rect_medium, rect_hard);

		//si clic sur bouton play : Appel fonction rungame();
		if (*isinplay == true)
		{
			display_buttons(rect_play, rect_IA_play, rect_easy, rect_medium, rect_hard, isinplay, isinIAplay, isineasy, isinmedium, isinhard, font, medium_font);
			if(events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && events.mouse.button & 1)
			{
				rungame(display, event_queue);
				loop = false;
			}
		}
		//si clic sur IA PLAY : Appel fonction runIA
		if (*isinIAplay == true )
		{
			display_buttons(rect_play, rect_IA_play, rect_easy, rect_medium, rect_hard, isinplay, isinIAplay, isineasy, isinmedium, isinhard, font, medium_font);
			if(events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && events.mouse.button & 1)
			{
				al_clear_to_color(al_map_rgb(rand() % 256,rand() % 256, rand() % 256));
				display_buttons(rect_play, rect_IA_play, rect_easy, rect_medium, rect_hard, isinplay, isinIAplay, isineasy, isinmedium, isinhard, font, medium_font);
			}
		}
		//si clic sur easy or medium or hard : Appel fonction color_rect
		if(*isineasy==true ||*isinmedium==true||*isinhard==true)
		{
			if(events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && events.mouse.button & 1)
			{
				al_clear_to_color(al_map_rgb(0,0,0));
			}
		}
		//Afficher nouvel écran
	        al_flip_display();
	}//Fin gestionnaire des evenements
	//Destructeur
	al_destroy_event_queue(event_queue);
	al_destroy_font(font);
	al_destroy_font(medium_font);
	free(isinplay);
	free(isinIAplay);
	free(isineasy);
	free(isinmedium);
	free(isinhard);
}

void is_mouse_in_button(int x, int y, bool *isinplay, bool *isinIAplay, bool *isineasy, bool *isinmedium, bool *isinhard, GrandRectangle rect_play, GrandRectangle rect_IA_play, MoyenRectangle rect_easy, MoyenRectangle rect_medium, MoyenRectangle rect_hard){

	if(rect_play.posx < x && x < (rect_play.posx + rect_play.largeur) && rect_play.posy < y && y < (rect_play.posy + rect_play.hauteur))
	{
		*isinplay = true;
	}
	else if(rect_IA_play.posx < x && x < (rect_IA_play.posx + rect_IA_play.largeur) && rect_IA_play.posy < y && y < (rect_IA_play.posy + rect_IA_play.hauteur))
	{
		*isinIAplay = true;
	}
	else if(rect_easy.posx < x && x < (rect_easy.posx + rect_easy.largeur) && rect_easy.posy < y && y < (rect_easy.posy + rect_easy.hauteur))
	{
		*isineasy = true;
	}
	else if(rect_medium.posx < x && x < (rect_medium.posx + rect_medium.largeur) && rect_medium.posy < y && y < (rect_medium.posy + rect_medium.hauteur))
	{
		*isinmedium = true;
	}
	else if(rect_hard.posx < x && x < (rect_hard.posx + rect_hard.largeur) && rect_hard.posy < y && y < (rect_hard.posy + rect_hard.hauteur))
	{
		*isinhard = true;
	}
	else{
		*isinplay = false;
		*isinIAplay=false;
		*isineasy=false;
		*isinmedium=false;
		*isinhard=false;
	}
}
void display_buttons(GrandRectangle rect_play, GrandRectangle rect_IA_play, MoyenRectangle rect_easy, MoyenRectangle rect_medium, MoyenRectangle rect_hard, bool * isinplay, bool * isinIAplay, bool* isineasy, bool* isinmedium, bool * isinhard, ALLEGRO_FONT * font, ALLEGRO_FONT * medium_font){

	//Couleur des rectangles
	rect_play.color = BLUE;
	rect_IA_play.color = BLUE;
	rect_easy.color = BLUE;
	rect_medium.color = BLUE;
	rect_hard.color = BLUE;
	if(*isinplay==true)
	{
		rect_play.color = LIGHT_BLUE;
	}
	else if(*isinIAplay==true)
	{
		rect_IA_play.color = LIGHT_BLUE;
	}
	else if(*isineasy==true)
	{
		rect_easy.color = LIGHT_BLUE;
	}
	else if(*isinmedium==true)
	{
		rect_medium.color = LIGHT_BLUE;
	}
	else if(*isinhard==true)
	{
		rect_hard.color = LIGHT_BLUE;
	}
	//Dessin des rectangles
	al_draw_filled_rectangle(rect_play.posx,rect_play.posy, rect_play.posx+rect_play.largeur, rect_play.posy+rect_play.hauteur,rect_play.color);
	al_draw_filled_rectangle(rect_IA_play.posx,rect_IA_play.posy, rect_IA_play.posx+rect_IA_play.largeur, rect_IA_play.posy+rect_IA_play.hauteur,rect_IA_play.color);
	al_draw_filled_rectangle(rect_easy.posx,rect_easy.posy, rect_easy.posx+rect_easy.largeur, rect_easy.posy+rect_easy.hauteur,rect_easy.color);
	al_draw_filled_rectangle(rect_medium.posx,rect_medium.posy, rect_medium.posx+rect_medium.largeur, rect_medium.posy+rect_medium.hauteur,rect_medium.color);
	al_draw_filled_rectangle(rect_hard.posx,rect_hard.posy, rect_hard.posx+rect_hard.largeur, rect_hard.posy+rect_hard.hauteur,rect_hard.color);

	//Texte
	al_draw_text(font, WHITE, rect_play.posx+rect_play.largeur/2, rect_play.posy, ALLEGRO_ALIGN_CENTRE, "PLAY");
	al_draw_text(font, WHITE, rect_IA_play.posx+rect_IA_play.largeur/2, rect_IA_play.posy, ALLEGRO_ALIGN_CENTRE, "IA PLAY");
	al_draw_text(medium_font, WHITE, rect_easy.posx+rect_easy.largeur/2, rect_easy.posy+rect_easy.hauteur/3, ALLEGRO_ALIGN_CENTRE, "EASY");
	al_draw_text(medium_font, WHITE, rect_medium.posx+rect_medium.largeur/2, rect_medium.posy+rect_medium.hauteur/3, ALLEGRO_ALIGN_CENTRE, "MEDIUM");
	al_draw_text(medium_font, WHITE, rect_hard.posx+rect_hard.largeur/2, rect_hard.posy+rect_hard.hauteur/3, ALLEGRO_ALIGN_CENTRE, "HARD");

}
