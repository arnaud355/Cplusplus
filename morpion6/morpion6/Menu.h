#ifndef H_MENU
#define H_MENU

class Menu;

#include "Define.h"
#include "Moteur.h"

class Menu
{
	private:
		//Surfaces pour le menu
		SDL_Surface *images[4];
		
		//Position et taille des boutons nouveau et quitter
		SDL_Rect nouveau,
			 quitter,
			 titre;

		//Informations pour le type de joueur
		//Positions et surfaces du texte des joueurs 
		SDL_Rect postxtj1, postxtj2;
		SDL_Surface* txtj[2];

		//Positions et surfaces des types des joueurs
		SDL_Rect postypej1, postypej2;
		SDL_Surface* typejoueur[4];
		//Type des joueurs
		int typej1, typej2;
		
	public:
		//Constructeur
		Menu();
		//Destructeur
		~Menu();

		//Fonction d'initialisation
		bool init(std::string file);
		
		//Gestion du clic
		void clic(int x, int y);

		//Fonction d'affichage
		void aff(SDL_Surface *screen);

		//Fonction qui retourne le type du joueur
		int getType(int i);
};

#endif
