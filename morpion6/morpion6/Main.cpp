/*
 * Fichier de base pour ouvrir une fenetre SDL, si l'utilisateur appuie sur 'q', on quitte le programme
 */
#include "Main.h"
#include "Moteur.h"
Moteur moteur;

using namespace std;

int main(int argc, char **argv)
{
	SDL_Event event;
	SDL_Surface *screen;
	int done = 0;

	//Initialisation
	if(SDL_Init(SDL_INIT_VIDEO)!=0) {
		cout << "Probleme pour initialiser SDL: " << SDL_GetError() << endl;
		return 1;
	}

    //Mettre un titre à la fenêtre
    SDL_WM_SetCaption("Morpion Version 1.0", NULL);

	//Ouvrir une fenetre
	screen = SDL_SetVideoMode(WIDTH,HEIGHT, 32,
			SDL_DOUBLEBUF | SDL_HWSURFACE);
    if(screen==NULL)
      	done = 1;



    //Initialiser le jeu
    if(!moteur.init())
            return 1;

    cout << "Here" << endl;
    //Boucle generale
    while(!done)
    {
        //Traiter les evenements
	while(SDL_PollEvent(&event))
	{
		switch(event.type)
		{
			case SDL_QUIT:
				done=1;
				break;
			case SDL_KEYUP:
				if(event.key.keysym.sym==SDLK_q)
					moteur.fin();
				else if(event.key.keysym.sym==SDLK_ESCAPE)
					moteur.echangeFonctions();
				break;
			case SDL_MOUSEBUTTONUP:
				moteur.clic(event.button.x, event.button.y);
				break;
			default:
				break;
		}
	}

    moteur.aff(screen);
    moteur.verif();
    SDL_Flip(screen);
    }

	SDL_Quit();

    (void) argc;
    (void) argv;
	return 0;
}
