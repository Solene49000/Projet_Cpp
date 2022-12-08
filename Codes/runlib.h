#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include "variables.h"

//Structures
class Rectangle
{
	public:
		int posx;
		int posy;
		ALLEGRO_COLOR color;
	//ADD CONSTRUCTOR
	Rectangle(int position_x,int position_y, ALLEGRO_COLOR couleur){
		posx = position_x;
		posy = position_y;
		color = couleur;
	}
};

class GrandRectangle : public Rectangle
{
	public:
		int largeur = 400;
		int hauteur = 80;
//ADD CONSTRUCTOR
	GrandRectangle(int position_x, int position_y, ALLEGRO_COLOR couleur)
	        : Rectangle(position_x, position_y, couleur) //Cal rectangle constructor
	    {
	    }
};

class MoyenRectangle : public Rectangle
{
	public:
		int largeur = 120;
		int hauteur = 50;
//ADD CONSTRUCTOR
	MoyenRectangle(int position_x, int position_y, ALLEGRO_COLOR couleur)
	        : Rectangle(position_x, position_y, couleur) //Cal rectangle constructor
	    {
	    }
};


//Declaration des fonctions
void rungame(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, int * difficulty);
void runmenu(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue);
void is_mouse_in_tour(int x, int y, bool *isintour1, bool *isintour2, bool *isintour3);
void is_mouse_in_button(int x, int y, bool *isinplay, bool *isinIAplay, bool *isineasy, bool *isinmedium, bool *isinhard, GrandRectangle rect_play, GrandRectangle rect_IA_play, MoyenRectangle rect_easy, MoyenRectangle rect_medium, MoyenRectangle rect_hard);
void display_tours();
void display_buttons(GrandRectangle rect_play, GrandRectangle rect_IA_play, MoyenRectangle rect_easy, MoyenRectangle rect_medium, MoyenRectangle rect_hard, bool * isinplay, bool * isinIAplay, bool * isineasy, bool * isinmedium, bool * isinhard, ALLEGRO_FONT * font, ALLEGRO_FONT * medium_font, int * difficulty);
void difficulties(int * difficulty, bool* isineasy, bool* isinmedium, bool * isinhard);



