//PROJET : TOURS HANOI - - ALLOUIS & GUILLAUME

#include "tour.h"
#include "anneau.h"
#include "bouton.h"
#include "librairies.h"

//Declaration des fonctions
void rungame(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, int * difficulty);
void runmenu(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue);
void is_mouse_in_tour(int x, int y, bool *isintour1, bool *isintour2, bool *isintour3, Tour tour);
void is_mouse_in_button(int x, int y, bool *isinplay, bool *isinIAplay, bool *isineasy, bool *isinmedium, bool *isinhard, GrandRectangle rect_play, GrandRectangle rect_IA_play, MoyenRectangle rect_easy, MoyenRectangle rect_medium, MoyenRectangle rect_hard);
void display_tours();
void display_buttons(GrandRectangle rect_play, GrandRectangle rect_IA_play, MoyenRectangle rect_easy, MoyenRectangle rect_medium, MoyenRectangle rect_hard, bool * isinplay, bool * isinIAplay, bool * isineasy, bool * isinmedium, bool * isinhard, ALLEGRO_FONT * font, ALLEGRO_FONT * medium_font, int * difficulty);
void difficulties(int * difficulty, bool* isineasy, bool* isinmedium, bool * isinhard);
void display_anneaux(Anneau anneau1, Anneau anneau2, Anneau anneau3, Anneau anneau4, Anneau anneau5, int * difficulty, std::vector<int> tour1_tab,std::vector<int> tour2_tab, std::vector<int> tour3_tab, Tour tour);
void delete_anneau(bool *isintour1, bool *isintour2, bool *isintour3,std::vector<int>& tour1_tab, std::vector<int>& tour2_tab, std::vector<int>& tour3_tab, int* anneau);
void add_anneau(bool *isintour1, bool *isintour2, bool *isintour3,std::vector<int>& tour1_tab, std::vector<int>& tour2_tab, std::vector<int>& tour3_tab, int* anneau);
void is_success(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, std::vector<int> tour3_tab, int * difficulty);

//VARIABLES GOBALES AFFICHAGE
#define SCRX 640
#define SCRY 480
#define BLUE al_map_rgba(10,10,150,255)
#define LIGHT_BLUE al_map_rgba(1,55,55,30)
#define WHITE al_map_rgb(255,255,255)
#define BLACK al_map_rgb(0,0,0)

// VARIABLES GLOBALES RUNGAME
#define N_TOUR = 3;
#define N_ETAGE = 4;
#define HAUREUR_ETAGE = 20;
#define Largeur_TOUR = 80;
#define HAUTEUR_TOUR = N_etage * hauteur_etage;
#define EPAISSEUR_TOUR = 4;
