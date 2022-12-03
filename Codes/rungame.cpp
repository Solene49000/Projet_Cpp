//PROJET TOURS HANOI - - ALLOUIS GUILLAUME
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include "runlib.h"
#include "variables.h"

//VARIABLES GLOBALES A SUPP DES QUE LIBS TOURS ET ANNEAUX FAITS

void rungame(void) {

ALLEGRO_MOUSE_STATE mouse; //Souris simple
int oldx = 0, oldy = 0;
bool fin = false, isintour1 = false, isintour2 = false, isintour3 = false;
int tour1posx=100;
int tour2posx=320;
int tour3posx=440;
int tourposy=80;
int tourlargeur=100;
int tourhauteur=300;
bool selection = false; //Selection prend la valeur TRUE si un disque est selectionné

    while (!fin){

        // récupération de l'état de la souris
        al_get_mouse_state(&mouse);

        // si mouvement enregistrer la position
        if (oldx != mouse.x || oldy != mouse.y){
            oldx = mouse.x;
            oldy = mouse.y;
            //printf("%d-%d\n", mouse.x, mouse.y);
        }

	//Position dans une tour ?
	if(tour1posx < oldx && oldx < (tour1posx + tourlargeur) && tourposy < oldy && oldy < (tourposy + tourhauteur))
	{
		isintour1 = true;
	}
	else if(tour2posx < oldx && oldx < (tour2posx + tourlargeur) && tourposy < oldy && oldy < (tourposy + tourhauteur))
	{
		isintour2 = true;
	}
	else if(tour3posx < oldx && oldx < (tour3posx + tourlargeur) && tourposy < oldy && oldy < (tourposy + tourhauteur))
	{
		isintour3 = true;
	}
	else{
		isintour1 = false;
		isintour2=false;
		isintour3=false;
	}
	//si clic sur tour pour selectionner un disque
	if (mouse.buttons & 1 && selection==false && (isintour1 == true || isintour2 == true || isintour3 == true))
	{
		selection = false;
		al_clear_to_color(al_map_rgb(rand() % 256,rand() % 256, rand() % 256));
		//Appel prog pour supprimer le disque de la tour concernée
	}
	//si clic sur tour pour poser disque
	if(mouse.buttons & 1 && selection==true && (isintour1 == true || isintour2 == true || isintour3 == true))
	{
		selection = false;
		al_clear_to_color(al_map_rgb(0,0,0));
	}
	// si clic droit quitter
        if (mouse.buttons & 2)
            fin = true;

        al_flip_display();
    }

}
