/***
 *  Jeu le pendu realisee par Daryl NOUPIK V0.1
 *  Date : 20/10/2023
 *  Heure: 01:14
 *  Extrait de solution du lab des  X2028 -- Module C++
*/


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

// Fonction pour choisir un mot aléatoire parmi une liste
std::string choisirMotAleatoire(const std::vector<std::string>& motsPossibles) {
    int indexMot = std::rand() % motsPossibles.size(); // Choix d'un indice de mot aléatoire
    return motsPossibles[indexMot]; // Renvoie le mot correspondant à l'indice choisi
}

// Fonction pour initialiser le mot caché en masquant toutes les lettres sauf les 2 premières et les 2 dernières
std::string initialiserMotCache(const std::string& motADeviner) {
    std::string motCache = motADeviner; // Copie du mot à deviner
    for (int i = 2; i < motCache.length() - 2; i++) {
        motCache[i] = '_'; // Remplace les lettres du mot par des underscores
    }
    return motCache; // Renvoie le mot partiellement caché
}

// Fonction pour afficher l'état actuel du jeu (mot caché, lettres déjà devinées, dessin du pendu)
void afficherEtatJeu(const std::string& motCache, const std::vector<char>& lettresDejaDevinees, int essais) {
    std::cout << "Mot actuel : " << motCache << std::endl; // Affiche le mot partiellement caché
    std::cout << "Lettres déjà devinées : ";
    for (char lettre : lettresDejaDevinees) {
        std::cout << lettre << " "; // Affiche les lettres déjà devinées
    }
    std::cout << std::endl;

    if (essais > 0) { // Si des essais ont été faits
        std::cout << " _______" << std::endl; // Dessine la structure du pendu
        std::cout << " |     |" << std::endl;
        if (essais >= 2)
            std::cout << " |     O" << std::endl;
        if (essais >= 3)
            std::cout << " |    /";
        if (essais == 4)
            std::cout << "|";
        if (essais >= 5)
            std::cout << " \\";
        std::cout << std::endl;
        if (essais >= 6)
            std::cout << " |    /";
        if (essais == 6)
            std::cout << " \\" << std::endl;
        else
            std::cout << std::endl;
        std::cout << " |" << std::endl;
        std::cout << " |___" << std::endl;
    }
}

// Fonction pour vérifier si le jeu est gagné (le mot a été entièrement deviné)
bool estJeuGagne(const std::string& motCache, const std::string& motADeviner) {
    return motCache == motADeviner; // Renvoie vrai si le mot partiellement caché est identique au mot à deviner
}

int main() {
    const int MAX_ESSAIS = 6; // Nombre maximum d'essais autorisés
    const std::vector<std::string> motsPossibles = {
        "programme", "informatique", "developpement", "pendu", "challenge", "ordinateur",
        "algorithm", "variable", "condition", "boucle", "fonction", "interface", "compilation",
        "code", "langage", "exercice", "apprentissage", "simulation", "structure", "prototype",
        "bibliothèque", "héritage", "polymorphisme", "encapsulation"
    }; // Liste de mots possibles

    std::srand(static_cast<unsigned>(std::time(nullptr))); // Initialisation du générateur de nombres aléatoires
    std::string motADeviner = choisirMotAleatoire(motsPossibles); // Choix aléatoire d'un mot à deviner
    std::string motCache = initialiserMotCache(motADeviner); // Initialisation du mot partiellement caché
    std::vector<char> lettresDejaDevinees; // Liste des lettres déjà devinées
    int essais = 0; // Compteur d'essais

    std::cout << "Bienvenue au jeu du pendu !" << std::endl;
    std::cout << "Le mot à deviner a " << motADeviner.length() << " lettres." << std::endl;

    while (essais < MAX_ESSAIS) { // Boucle principale du jeu
        afficherEtatJeu(motCache, lettresDejaDevinees, essais); // Affiche l'état actuel du jeu

        char proposition;
        std::cout << "Proposez une lettre : ";
        std::cin >> proposition; // Demande au joueur de proposer une lettre

        if (proposition < 'a' || proposition > 'z') {
            std::cout << "Veuillez entrer une lettre minuscule." << std::endl; // Vérifie que la proposition est une lettre minuscule
            continue;
        }

        bool dejaDevinee = false; // Indique si la lettre a déjà été devinée
        for (char lettre : lettresDejaDevinees) {
            if (lettre == proposition) {
                dejaDevinee = true;
                break;
            }
        }

        if (dejaDevinee) {
            std::cout << "Vous avez déjà proposé cette lettre." << std::endl; // Affiche un message si la lettre a déjà été devinée
        } else {
            lettresDejaDevinees.push_back(proposition); // Ajoute la lettre aux lettres déjà devinées

            bool lettreTrouvee = false; // Indique si la lettre proposée est présente dans le mot à deviner
            for (int i = 0; i < motADeviner.length(); i++) {
                if (motADeviner[i] == proposition) {
                    motCache[i] = proposition; // Révèle la lettre dans le mot partiellement caché
                    lettreTrouvee = true;
                }
            }

            if (lettreTrouvee) {
                std::cout << "Bonne proposition !" << std::endl; // Affiche un message si la lettre est trouvée
            } else {
                std::cout << "Mauvaise proposition." << std::endl; // Affiche un message si la lettre est incorrecte
                essais++;
            }
        }

        if (estJeuGagne(motCache, motADeviner)) {
            std::cout << "Bravo ! Vous avez deviné le mot : " << motADeviner << std::endl; // Vérifie si le jeu est gagné
            break;
        }
    }

    if (essais == MAX_ESSAIS) {
        std::cout << "Désolé, vous avez épuisé tous vos essais. Le mot était : " << motADeviner << std::endl; // Affiche un message si tous les essais sont épuisés
    }

    return 0;
}
