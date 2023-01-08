#include <allegro5/allegro.h>
#include <allegro5/allegro_primitives.h>
#include <iostream>
#include <stack>
#include <cstdlib>

// Largeur et hauteur de chaque disque
const int DISK_WIDTH = 100;
const int DISK_HEIGHT = 20;

// Nombre de tours
const int NUM_PEGS = 3;

// Structure représentant un disque
struct Disk
{
    int size;          // Taille du disque (1 = petit, 2 = moyen, 3 = grand)
    int x;             // Coordonnée x de la forme graphique du disque
    int y;             // Coordonnée y de la forme graphique du disque
    ALLEGRO_COLOR color;  // Couleur de la forme graphique du disque

    // Constructeur
    Disk(int size, int x, int y) : size(size), x(x), y(y)
    {
        color = al_map_rgb(100 + size * 50, 100 + size * 50, 100 + size * 50);
    }
};

// Structure représentant une tour
struct Peg
{
    std::stack<Disk> disks;  // Pile de disques sur la tour
    int x;             // Coordonnée x de la forme graphique de la tour
    int y;             // Coordonnée y de la forme graphique de la tour

    // Constructeur
    Peg(int x, int y) : x(x), y(y) {}
};

int main()
{
    // Initialisation d'Allegro
    al_init();
    al_init_primitives_addon();
    al_install_keyboard();

    // Création de la fenêtre
    const int WINDOW_WIDTH = 600;
    const int WINDOW_HEIGHT = 400;
    ALLEGRO_DISPLAY* display = al_create_display(WINDOW_WIDTH, WINDOW_HEIGHT);
  // Initialisation des tours
Peg pegs[NUM_PEGS];
for (int i = 0; i < NUM_PEGS; i++)
{
    pegs[i] = Peg(200 + i * 200, 0);
}

// Génération aléatoire de la configuration de départ
int numDisks = 4;  // On place un certain nombre de disques sur la première tour
for (int i = numDisks; i > 0; i--)
{
    Disk disk(i, pegs[0].x, WINDOW_HEIGHT - DISK_HEIGHT * 1.5f - (numDisks - i) * (DISK_HEIGHT + 5));
    pegs[0].disks.push(disk);
}

// Variables de jeu
int selectedPeg = -1;  // Tour sélectionnée (-1 = aucune)
bool autoSolve = false;  // Indique si on affiche la solution automatique

while (true)
{
    // Gestion des évènements
    ALLEGRO_EVENT event;
    al_wait_for_event(al_get_keyboard_event_source(), &event);

    if (event.type == ALLEGRO_EVENT_KEY_DOWN)
    {
        if (event.keyboard.keycode == ALLEGRO_KEY_ESCAPE)
        {
            break;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_LEFT && selectedPeg > 0)
        {
            selectedPeg--;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_RIGHT && selectedPeg < NUM_PEGS - 1)
        {
            selectedPeg++;
        }
        else if (event.keyboard.keycode == ALLEGRO_KEY_SPACE && selectedPeg >= 0)
        {
            // On vérifie si le mouvement est valide et on déplace le disque s'il l'est
            if (!pegs[selectedPeg].disks.empty() && (pegs[(selectedPeg + 1) % NUM_PEGS].disks.empty() || pegs[selectedPeg].disks.top().size < pegs[(selectedPeg + 1) % NUM_PEGS].disks.top().size))
            {
                Disk disk = pegs[selectedPeg].disks.top();
                pegs[selectedPeg].disks.pop();
                disk.x = pegs[(selectedPeg + 1) % NUM_PEGS].x;
                disk.y = pegs[(selectedPeg + 1) % NUM_PEGS].disks.empty() ? WINDOW_HEIGHT - DISK_HEIGHT : pegs[(selectedPeg + 1) % NUM_PEGS].disks.top().y - (DISK_HEIGHT + 5);
                pegs[(selectedPeg + 1) % NUM_PEGS].disks.push(disk);
            }
         }
         else if (event.keyboard.keycode == ALLEGRO_KEY_S)
         {
              // On bascule l'affichage de la solution automatique
              autoSolve = !autoSolve;
         }
     }               
    // Effacement de l'écran
    al_clear_to_color(al_map_rgb(255, 255, 255));

    // Dessin des tours
    for (int i = 0; i < NUM_PEGS; i++)
    {
        al_draw_rectangle(pegs[i].x - DISK_WIDTH / 2, pegs[i].y, pegs[i].x + DISK_WIDTH / 2, pegs[i].y + 400, al_map_rgb(0, 0, 0), 2.0f);
    }

    // Dessin des disques
    for (int i = 0; i < NUM_PEGS; i++)
    {
        for (int j = 0; j < pegs[i].disks.size(); j++)
        {
            al_draw_filled_rectangle(pegs[i].disks[j].x - DISK_WIDTH / 2, pegs[i].disks[j].y, pegs[i].disks[j].x + DISK_WIDTH / 2, pegs[i].disks[j].y + DISK_HEIGHT, pegs[i].disks[j].color);
        }
    }

    al_flip_display();
}

al_destroy_display(display);

return 0;

