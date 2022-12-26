// PROJET : TOURS DE HANOI - - A.ALLOUIS & S.GUILLAUME

//LIBRAIRIES
#include "librairies.h"
#define SCRX 640
#define SCRY 480

// DECLARATION DE LA STRUCTURE TOUR
class Tour
{
	public:
	int tourposy=80;
	int tourlargeur=20;
	int tourhauteur=200;
	int tour1posx=SCRX/2-180-tourlargeur;
	int tour2posx=SCRX/2-tourlargeur/2;
	int tour3posx=SCRX/2+180;
	public: void display_tours();
};
