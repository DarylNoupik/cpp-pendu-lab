# Jeu du Pendu en C++

Ce jeu du pendu en C++ est une petite application console permettant de jouer au jeu classique du pendu. Le jeu est simple : le programme choisit un mot aléatoire parmi une liste, et le joueur doit deviner les lettres du mot en proposant des lettres.

## Comment jouer

1. Exécutez le programme.
2. Le programme choisit un mot aléatoire parmi une liste de mots.
3. Le mot est affiché partiellement caché, avec seulement les 2 premières et les 2 dernières lettres révélées.
4. Le joueur propose une lettre en entrant une lettre minuscule.
5. Si la lettre proposée est dans le mot, elle est révélée dans le mot partiellement caché.
6. Si la lettre proposée n'est pas dans le mot, un essai est déduit.
7. Le joueur a un maximum de 6 essais pour deviner le mot.
8. Le joueur gagne s'il devine le mot ou perd s'il épuise tous ses essais.

## Fonctionnalités

- Choix aléatoire d'un mot parmi une liste prédéfinie.
- Affichage du mot partiellement caché avec des lettres révélées.
- Gestion des essais et affichage du dessin du pendu.
- Validation des propositions du joueur.

## Comment exécuter

1. Assurez-vous d'avoir un environnement C++ configuré sur votre système.
2. Compilez le code source en utilisant un compilateur C++ (par exemple, g++).
3. Exécutez le programme généré.

```bash
g++ pendu.cpp -o pendu
./pendu
