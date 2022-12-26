// PROJET TOURS DE HANOI - - ALLOUIS GUILLAUME

//libraries
#include "variables.h"
using namespace std;
using std::vector;


void Tour::display_tours()
	{
		//Rectangles représentant les tours
		al_draw_filled_rectangle(tour1posx, tourposy, tour1posx+tourlargeur, tourposy+tourhauteur,al_map_rgb(0,0,0));
		al_draw_filled_rectangle(tour2posx, tourposy, tour2posx+tourlargeur, tourposy+tourhauteur,al_map_rgb(0,0,0));
		al_draw_filled_rectangle(tour3posx, tourposy, tour3posx+tourlargeur, tourposy+tourhauteur,al_map_rgb(0,0,0));
		//Rectangle représentant la base 
		al_draw_filled_rectangle(tour1posx-100, tourposy+tourhauteur, tour3posx+tourlargeur+100, tourposy+tourhauteur+30,al_map_rgb(0,0,0));
};

void Anneau::display_anneau(std::vector<int> tour1_tab,std::vector<int> tour2_tab,std::vector<int> tour3_tab,Tour tour)
	{
		int tourposx;
		int tourlargeur=tour.tourlargeur;
		int tourposy=tour.tourposy;
		int tourhauteur=tour.tourhauteur; 
		unsigned long int j;
		for(int i=0; i<=5; i++){
			if(numeroanneau==i)
			{
				//Calcul taille anneau
				anneaulargeur=35+numeroanneau*25;
				//Affiche rectangle à la bonne position
				for(j=0; j<=tour1_tab.size(); j++)
				{
					if(tour1_tab[j]==numeroanneau)
					{
						tourposx=tour.tour1posx;
						positionanneauintour=j+1;
					}
				}
				for(j=0; j<=tour2_tab.size(); j++)
				{
					if(tour2_tab[j]==numeroanneau)
					{
						tourposx=tour.tour2posx;
						positionanneauintour=j+1;
					}
				}
				for(j=0; j<=tour3_tab.size(); j++)
				{
					if(tour3_tab[j]==numeroanneau)
					{
						tourposx=tour.tour3posx;
						positionanneauintour=j+1;
					}
				}
		                al_draw_filled_rectangle(tourposx+tourlargeur/2-anneaulargeur/2, tourposy+tourhauteur-positionanneauintour*anneauhauteur,tourposx+tourlargeur/2+anneaulargeur/2,tourposy+tourhauteur-(positionanneauintour-1)*anneauhauteur,color);
			}
		}
	};

//DEMMARAGE
void rungame(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, int * difficulty) {

	//Initialisation des variables
	int x = 0, y = 0;
	bool loop1 = true;
	//Booléen de souris
	bool * isintour1 = (bool*)malloc(sizeof(bool));
	bool * isintour2 = (bool*)malloc(sizeof(bool));
	bool * isintour3 = (bool*)malloc(sizeof(bool));
	*isintour1=false;
	*isintour2=false;
	*isintour3=false;
	bool selection = false; //Selection prend la valeur TRUE si un disque est selectionné
	bool jeton = true; //securité pour clics souris
	//Ordre des anneaux par tour
	std::vector<int> tour1_tab;
	if(*difficulty==3){
		tour1_tab={5,4,3,2,1};
	}
	else if(*difficulty==2){
		tour1_tab={4,3,2,1,0};
	}
	else{
		tour1_tab={3,2,1,0,0};
	}
	std::vector<int> tour2_tab={0,0,0,0,0};
	std::vector<int> tour3_tab={0,0,0,0,0};
	//Declaration des tours
	Tour tour;
	//Declaration des anneaux
	Anneau anneau1{1};
	Anneau anneau2{2};
	Anneau anneau3{3};
	Anneau anneau4{4};
	Anneau anneau5{5};
	//Anneau en jeu
	int* anneau = (int*)malloc(sizeof(int));
	*anneau=0;
	//Gestionnaire des evenements
	    while (loop1){

		al_clear_to_color(BLUE);
		tour.display_tours();
		display_anneaux(anneau1, anneau2, anneau3, anneau4, anneau5, difficulty, tour1_tab, tour2_tab, tour3_tab, tour);
		is_success(display, event_queue, tour3_tab, difficulty);
		ALLEGRO_EVENT events;
		al_wait_for_event(event_queue, &events);
		//Si appui sur croix rouge : fermer fenêtre
		if(events.type == ALLEGRO_EVENT_DISPLAY_CLOSE){
	            loop1=false;
		}

	        // si mouvement de souris : enregistrer la position
	        if (events.type == ALLEGRO_EVENT_MOUSE_AXES ){
	            x=events.mouse.x;
	            y=events.mouse.y;
	        }

		is_mouse_in_tour(x,y,isintour1,isintour2,isintour3, tour);

		//si clic sur tour pour selectionner un disque : Appel fonction supprimer disque
		if (selection==false && (*isintour1 == true || *isintour2 == true || *isintour3 == true)&&jeton==true)
		{
			if(events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && events.mouse.button & 1)
			{	
				*anneau=0;		
				//Appel prog pour supprimer le disque de la tour concernée
				delete_anneau(isintour1,isintour2, isintour3, tour1_tab, tour2_tab, tour3_tab, anneau);
				selection = true;	
				jeton = false;		
			}
		}
		//si clic sur tour pour poser disque : Appel fonction pose disque
		if(selection==true && (*isintour1 == true || *isintour2 == true || *isintour3 == true)&&jeton==true)
		{
			if(events.type==ALLEGRO_EVENT_MOUSE_BUTTON_DOWN && events.mouse.button & 1)
			{
			add_anneau(isintour1,isintour2, isintour3, tour1_tab, tour2_tab, tour3_tab, anneau);
				selection = false;	
				jeton = false;
				
			}
		}
		//Afficher nouvel écran
	        al_flip_display();
	        jeton = true;
	}//Fin gestionnaire des evenements
	return;

}

void is_mouse_in_tour(int x, int y, bool *isintour1, bool *isintour2, bool *isintour3, Tour tour){
//Variables position tour (A METTRE EN VAR GLOBALES)
	int tour1posx=tour.tour1posx;
	int tour2posx=tour.tour2posx;
	int tour3posx=tour.tour3posx;
	int tourposy=tour.tourposy;
	int tourlargeur=tour.tourlargeur;
	int tourhauteur=tour.tourhauteur;
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

void display_anneaux(Anneau anneau1, Anneau anneau2, Anneau anneau3, Anneau anneau4, Anneau anneau5, int * difficulty, std::vector<int> tour1_tab,std::vector<int> tour2_tab, std::vector<int> tour3_tab, Tour tour)
{
	anneau1.display_anneau(tour1_tab, tour2_tab, tour3_tab, tour);
	anneau2.display_anneau(tour1_tab, tour2_tab, tour3_tab, tour);
	anneau3.display_anneau(tour1_tab, tour2_tab, tour3_tab, tour);
	if(*difficulty>=2){
		anneau4.display_anneau(tour1_tab, tour2_tab, tour3_tab, tour);
	}
	if(*difficulty==3){
		anneau5.display_anneau(tour1_tab, tour2_tab, tour3_tab, tour);
	}
}
void delete_anneau(bool *isintour1, bool *isintour2, bool *isintour3,std::vector<int>& tour1_tab, std::vector<int>& tour2_tab, std::vector<int>& tour3_tab, int* anneau){
	//On supprime l'anneau le plus haut de la tour et on retient son id dans *anneau
	if(*isintour1==true){
		for(int i=0; i<=4;i++){
			if(tour1_tab[i]!=0){
				*anneau=tour1_tab[i];
			}
		}
		for(int i=0; i<=4;i++){
			if(tour1_tab[i]==*anneau){
				tour1_tab[i]=0;
			}
		}
	}
	if(*isintour2==true){
		for(int i=0; i<=4;i++){
			if(tour2_tab[i]!=0){
				*anneau=tour2_tab[i];
			}
		}
		for(int i=0; i<=4;i++){
			if(tour2_tab[i]==*anneau){
				tour2_tab[i]=0;
			}
		}
	}
		if(*isintour3==true){
		for(int i=0; i<=4;i++){
			if(tour3_tab[i]!=0){
				*anneau=tour3_tab[i];
			}
		}
		for(int i=0; i<=4;i++){
			if(tour3_tab[i]==*anneau){
				tour3_tab[i]=0;
			}
		}
	}
}
void add_anneau(bool *isintour1, bool *isintour2, bool *isintour3,std::vector<int>& tour1_tab, std::vector<int>& tour2_tab, std::vector<int>& tour3_tab, int* anneau){
	//On ajoute l'anneau au sommet de la tour
	if(*isintour1==true){
		for(int i=0; i<=4;i++){	
			if(tour1_tab[i]==0){
				tour1_tab[i]=*anneau;
				return;
			}
		}
	}
	if(*isintour2==true){
		for(int i=0; i<=4;i++){
			if(tour2_tab[i]==0){
				tour2_tab[i]=*anneau;
				return;
			}
		}
	}
	if(*isintour3==true){
		for(int i=0; i<=4;i++){
			if(tour3_tab[i]==0){
				tour3_tab[i]=*anneau;
				return;
			}
		}
	}
}
void is_success(ALLEGRO_DISPLAY * display, ALLEGRO_EVENT_QUEUE * event_queue, std::vector<int> tour3_tab, int * difficulty){
	std::vector<int> easy = {3,2,1,0,0};
	std::vector<int> medium = {4,3,2,1,0}; 
	std::vector<int> hard = {5,4,3,2,1};
	if(*difficulty == 1){
		if(tour3_tab==easy){
			sleep(2);
			runmenu(display, event_queue);
		}
	}
	if(*difficulty == 2){
		if(tour3_tab==medium){
			sleep(2);
			runmenu(display, event_queue);
		}
	}
	if(*difficulty == 3){
		if(tour3_tab==hard){
			sleep(2);
			runmenu(display, event_queue);
		}
	}
	else{
	return;
	}

}




















