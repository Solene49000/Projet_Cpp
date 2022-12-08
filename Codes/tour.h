// PROJET : TOURS DE HANOI - - A.ALLOUIS & S.GUILLAUME

//LIBRAIRIES
#include "librairies.h"

// DECLARATION DE LA STRUCTURE TOUR_STRUCTURE
struct tour_structure {
	int numero_tour;
	int nombre_etage;
	int position_x;
	int position_y;
	int position_milieu_x;
	int tab_etage_anneau[];
};
