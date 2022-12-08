// PROJET : TOURS DE HANOI - - A.ALLOUIS & S.GUILLAUME

// BIBLIOTHEQUES
#include <iostream>

// VARIABLES GLOBALES
int N_tour = 3;
int N_etage = 4;
int hauteur_etage = 20;
int Largeur_tour = 80;
int Hauteur_tour = N_etage * hauteur_etage;
int Epaisseur_tour = 4;
define scrx 640
define scry 480

// DECLARATION DE LA STRUCTURE TOUR_STRUCTURE
struct tour_structure (
	int numero_tour;
	int nombre_etage;
	int position_x;
	int position_y;
	int position_milieu_x;
	int tab_etage_anneau[nombre_etage];
) tour_structure;
