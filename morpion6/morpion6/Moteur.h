#ifndef H_MOTEUR
#define H_MOTEUR

class Moteur;

#include <fstream>

#include "Define.h"
#include "Jeu.h"
#include "Menu.h"
#include "IA.h"

class Moteur
{
	private:
		//Pointeur de jeu
		Jeu *jeu;
		//Pointeur de menu
		Menu *menu;
        //Module d'IA
        IA *ia;		

		//booléen qui sert à savoir dans le menu
		bool dansMenu;
	public:
		//Constructeur/Destructeur
		Moteur();
		~Moteur();

		//Fonction qui gére le clic
		void clic(int , int);
		//Fonction qui gére l'affichage
		void aff(SDL_Surface *screen);

		//Fonction d'initialisation
		bool init();

		//Fonction qui initialise le jeu et le remet à zéro
		void initJeu();
		//Fonction qui demande de passer en mode Jeu
		void setFonctionsJeu();
		//Fonction qui demande de passer en mode Menu 
		void setFonctionsMenu();
		//Fonction qui change d'état de jeu
		void echangeFonctions();
		
		//Fonction de fin (servira pour les sauvegardes)
		void fin();

		void misAJourTypeJoueurs();
		void verif();
};

#endif
