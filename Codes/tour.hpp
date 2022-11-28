#include <iostream>

// Variables globales :
int N_tour;
int N_etage;
int Hauteur_etage;
int Largeur_tour;
int Hauteur_tour = N_etage * Hauteur_etage;
int Epaisseur_tour = 8;

// Structure tour_structure
struct tour_structure (
        int numero_tour;
        int nombre_etage;
        int position_x;
        int position_y;
        int position_milieu_x;
        int tab_etage_anneau[];
);
