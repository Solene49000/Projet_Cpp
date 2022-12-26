// PROJET : TOURS DE HANOI - - A.ALLOUIS & S.GUILLAUME

//LIBRAIRIES
#include "librairies.h"
#define SCRX 640
#define SCRY 480
// Structure anneau
class Anneau
{

	public:
	int numeroanneau;
	int anneauhauteur=35;
	int anneaulargeur;
	int positionanneauintour;
	ALLEGRO_COLOR color = al_map_rgb(rand() % 256,rand() % 256, rand() % 256);
	public: void display_anneau(std::vector<int> tour1_tab,std::vector<int> tour2_tab,std::vector<int> tour3_tab, Tour tour);
	public:
	Anneau(int num){numeroanneau=num;}
};
