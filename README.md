# Projet_Cpp
##Tours de Hanoi
-

ATTENTION : Pour executer le projet changer le chemin de l'image (ligne 31 dans runmenu.cpp)
Voici le projet des tours de Hanoi en C++.
Pour jouer : 
-

- cliquer la souris sur une tour pour selectionner un disque.
- Cliquer la souris sur une deuxième tour pour déplacer le disque.

Les fonctions :
-

- void main()
  Ouvre une fenetre et appelle le jeu (run())
- void run()
  Le jeu tourne. La foncion gère tous les évenements s'y produisant. Notamment les clics de souris.
  
Les bibliothèques et les structures :
-

- Toutes les bibliothèques utilisées sont dans le fichier librairies.h
- Chaque structure a son propre fichier :
  - tour.h contient la structure pour la gestion et la création des tours
  - anneau.h contient la structure pour la gestion et la création des anneaux pour chaque tours
  - variables.h contient toutes les variables globales prédéfinies
  - bouton.h contient la structure pour la gestion  et la création des boutons dans le menu
 
  Le fichier Run_IA :
  -
  
- Le code utilise la fonction al_init_primitives_addon pour dessiner des formes géométriques et la fonction al_install_keyboard pour gérer les entrées clavier.
- Le code génère aléatoirement la configuration de départ du jeu, en plaçant un certain nombre de disques sur la première tour. Le joueur peut alors appuyer sur la touche ESPACE pour déplacer le disque du dessus de la tour sélectionnée vers la tour suivante. Le code vérifie si le mouvement est valide selon les règles du jeu (un disque ne peut être placé que sur un autre disque plus grand) et met à jour l'affichage en conséquence.
- Le code utilise également une fonction récursive pour trouver et afficher une solution automatique au jeu, en utilisant l'algorithme des tours d'Hanoï classique.
- Le code n'est pas implémenté au projet par manque de temps.
