//PROJET : TOURS HANOI - - ALLOUIS & GUILLAUME

//LIBRAIRIES
#include "librairies.h"

//DECLARATION CLASSE BOUTON
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

//DECLARATION CLASSE GRANDBOUTON
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

//DECLARATION CLASSE MOYENBOUTON
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
