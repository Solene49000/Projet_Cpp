// Projet : TOURS D'HANOÏ - Ambre ALLOUIS & Solène GUILLAUME

#include <SFML/Graphics.hpp>
#include <iostream>
#include <stack>

// Largeur et hauteur de chaque disque
const int DISK_WIDTH = 100;
const int DISK_HEIGHT = 20;

// Nombre de tours
const int NUM_PEGS = 3;

// Structure représentant un disque
struct Disk
{
    int size;          // Taille du disque (1 = petit, 2 = moyen, 3 = grand)
    sf::RectangleShape shape;  // Forme graphique du disque

    // Constructeur
    Disk(int size) : size(size)
    {
        shape.setSize(sf::Vector2f(DISK_WIDTH, DISK_HEIGHT));
        shape.setFillColor(sf::Color(100 + size * 50, 100 + size * 50, 100 + size * 50));
    }
};

// Structure représentant une tour
struct Peg
{
    std::stack<Disk> disks;  // Pile de disques sur la tour
    sf::RectangleShape shape;  // Forme graphique de la tour

    // Constructeur
    Peg()
    {
        shape.setSize(sf::Vector2f(DISK_WIDTH, 400));
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineColor(sf::Color::Black);
        shape.setOutlineThickness(2.0f);
    }
};

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 400), "Tours d'Hanoï");
    window.setFramerateLimit(60);

    // Initialisation des tours
    Peg pegs[NUM_PEGS];
    for (int i = 0; i < NUM_PEGS; i++)
    {
        pegs[i].shape.setPosition(200 + i * 200, 0);
    }

    // Génération aléatoire de la configuration de départ
    int numDisks = 4; 
// On place un certain nombre de disques sur la première tour
for (int i = numDisks; i > 0; i--)
{
Disk disk(i);
disk.shape.setPosition(100 - DISK_WIDTH / 2, 400 - DISK_HEIGHT * 1.5f - (numDisks - i) * (DISK_HEIGHT + 5));
pegs[0].disks.push(disk);
}
// Variables de jeu
int selectedPeg = -1;  // Tour sélectionnée (-1 = aucune)
bool autoSolve = false;  // Indique si on affiche la solution automatique

while (window.isOpen())
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();

        // Sélection d'une tour avec la souris
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left)
        {
            // On vérifie si le clic a été fait sur une tour
            for (int i = 0; i < NUM_PEGS; i++)
            {
                if (pegs[i].shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
                {
                    selectedPeg = i;
                    break;
                }
            }
        }

        // Déplacement d'un disque avec les touches fléchées
        if (event.type == sf::Event::KeyPressed)
        {
            if (event.key.code == sf::Keyboard::Left && selectedPeg > 0)
            {
                selectedPeg--;
            }
            else if (event.key.code == sf::Keyboard::Right && selectedPeg < NUM_PEGS - 1)
            {
                selectedPeg++;
            }
            else if (event.key.code == sf::Keyboard::Space && selectedPeg >= 0)
            {
                // On vérifie si le mouvement est valide et on déplace le disque s'il l'est
                if (!pegs[selectedPeg].disks.empty() && (pegs[(selectedPeg + 1) % NUM_PEGS].disks.empty() || pegs[selectedPeg].disks.top().size < pegs[(selectedPeg + 1) % NUM_PEGS].disks.top().size))
                {
                    Disk disk = pegs[selectedPeg].disks.top();
                    pegs[selectedPeg].disks.pop();
                    disk.shape.setPosition(pegs[(selectedPeg + 1) % NUM_PEGS].shape.getPosition().x + DISK_WIDTH / 2, pegs[(selectedPeg + 1) % NUM_PEGS].disks.empty() ? 400 - DISK_HEIGHT : pegs[(selectedPeg + 1) % NUM_PEGS].disks.top().shape.getPosition().y -(DISK_HEIGHT + 5));
pegs[(selectedPeg + 1) % NUM_PEGS].disks.push(disk);
}
}
else if (event.key.code == sf::Keyboard::S)
{
// On bascule l'affichage de la solution automatique
autoSolve = !autoSolve;
}
}
}
    window.clear();

    // Dessin des tours
    for (int i = 0; i < NUM_PEGS; i++)
    {
        window.draw(pegs[i].shape);
    }

    // Dessin des disques
    for (int i = 0; i < NUM_PEGS; i++)
    {
        for (int j = 0; j < pegs[i].disks.size(); j++)
        {
            window.draw(pegs[i].disks[j].shape);
        }
    }

    window.display();
}

return 0;
 
