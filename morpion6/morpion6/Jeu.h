#ifndef H_JEU
#define H_JEU

#include <fstream>

#include "Define.h"
#include "Objet.h"

enum TypeJoueur {Humain, Facile, Moyen, Difficile};

//Classe du jeu
class Jeu
{
    private:
    	//Le plateau jeu
    	Objet plateau[3][3];

    	//Surfaces de la case vide, d'un rond, d'une croix, d'un fond et les surfaces gagnantes
    	SDL_Surface *vide, *o, *x, *bg, *gagneo, *gagnex;

    	//Variable pour un tour et pour savoir qui a gagné
    	Case tour, typegagne;

    	//Variable pour savoir si la partie est terminée
    	bool fini;

    	//Fonction pour vérifier si la partie est terminée
        void verifFini();

    	//Type des joueurs (humain/ordi)
    	TypeJoueur j1, j2;

    public:
    	//Créateur/Destructeur
    	Jeu();
    	~Jeu();

        //Fonction d'initialisation (chargement des surfaces)
        bool init(std::string file);

    	//Gestion du jeu lors d'un clic
    	void clic(int , int);

    	//Fonction d'affichage
    	void aff(SDL_Surface *screen);

    	//Fonction qui vider le plateau de jeu
    	void videJeu();

    	//Fonction qui retourne la valeur de fini
    	bool getFini();

        //Fonction qui retourne le joueur courant
        Case getTour();

        //Fonction qui retourne qui a gagné
        Case getTypeGagne();

        //Fonction qui retourne le type de la case
        Case getCase(int i, int j);

        //Fonction qui retourne si le joueur courant est un humain
        bool estHumain();

        //Fonction qui retourne le type du joueur courant
        TypeJoueur getTypeJoueur();

        //Fonction qui retourne l'état de la case
        bool estVide(int i, int j);

        //Fonction qui joue la case (i,j)
        void joue(int i,int j);

        //Fonction qui annule le dernier coup
        void annuleCoup(int a, int b);

	//Fonction qui met en place le type des joueurs
	void setTypeJoueur(int i, int type);
};
#endif
