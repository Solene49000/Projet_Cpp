//PROJET TOURS HANOI - - ALLOUIS GUILLAUME
#include <iostream>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_color.h>
#include "runlib.h"
#include "variables.h"

void rungame(void) {

ALLEGRO_MOUSE_STATE mouse; //Souris simple
int fin = 0, oldx = 0, oldy = 0;
int moitie_gauche = scrx/2;
int selection = 1; //Selection prend la valeur 0 si un disque est selectionné

    while (!fin){

        // récupération de l'état de la souris
        al_get_mouse_state(&mouse);

        // si mouvement enregistrer la position
        if (oldx != mouse.x || oldy != mouse.y){
            oldx = mouse.x;
            oldy = mouse.y;
            //printf("%d-%d\n", mouse.x, mouse.y);
        }

        // si clic gauche à gauche changer couleur fenêtre
        if (mouse.buttons & 1 && oldx <= moitie_gauche)
            al_clear_to_color(al_map_rgb(rand() % 256,
            rand() % 256,
            rand() % 256));
	//Position dans une tour ou non ?
	//if(<oldx<
	//si clic sur tour pour selectionner un disque
	//if (mouse.buttons & 1 && selection=1 && oldx <= tour)
        // si clic droit quitter
        if (mouse.buttons & 2)
            fin = 1;

        al_flip_display();
    }

}
