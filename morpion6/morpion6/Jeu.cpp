#include "Jeu.h"

using namespace std;

Jeu::Jeu()
{
    //Vider le Jeu
    videJeu();

    //Valeur par défaut pour les surfaces
    o=NULL;
    x=NULL;
    gagneo=NULL;
    gagnex=NULL;
    bg=NULL;
    vide=NULL;

    //Type des joueurs
    j2 = Humain;
    j1 = Difficile;
}

Jeu::~Jeu()
{
    //On libére les surfaces
    SDL_FreeSurface(o);
    SDL_FreeSurface(bg);
    SDL_FreeSurface(x);
    SDL_FreeSurface(gagneo);
    SDL_FreeSurface(gagnex);
}

bool Jeu::init(string file)
{
    SDL_Rect r;
    int i,j;
    ifstream inputfile;
    string s;

    //Ouverture du fichier de paramétrage
    inputfile.open(file.data());

    //Test sur l'ouverture de la fonction
    if(inputfile.fail())
        {
        cout << "Erreur dans l'ouverture de " << file << endl;
        return false;
        }

    //Vérification de l'allocation des surfaces
    if(vide!=NULL)
	{
	    SDL_FreeSurface(vide), vide = NULL;
	}
    if(o!=NULL)
        {
            SDL_FreeSurface(o), o = NULL;
        }
    if(x!=NULL)
        {
            SDL_FreeSurface(x), x = NULL;
        }
    if(bg!=NULL)
        {
            SDL_FreeSurface(bg), bg = NULL;
        }
    if(gagneo!=NULL)
        {
	    SDL_FreeSurface(gagneo), gagneo = NULL;
	}
    if(gagnex!=NULL)
    	{
	    SDL_FreeSurface(gagnex), gagnex = NULL;
	}

    //On charge toutes les images dans les surfaces associées
    inputfile >> s;
    bg = SDL_LoadBMP(s.data());
    inputfile >> s;
    vide = SDL_LoadBMP(s.data());
    inputfile >> s;
    o = SDL_LoadBMP(s.data());
    inputfile >> s;
    x = SDL_LoadBMP(s.data());
    inputfile >> s;
    gagneo = SDL_LoadBMP(s.data());
    inputfile >> s;
    gagnex = SDL_LoadBMP(s.data());

    //On teste le retour du chargement
    if( (vide==NULL) || (o==NULL) || (x==NULL) || (bg==NULL) || (gagneo==NULL)|| (gagnex==NULL))
    	{
    	cout << "Probleme de chargement de la case vide, du O, du X, de l'image de fond et des surfaces gagnees" << endl;
    	return false;
    	}

    //On initialise le premier tour: ce sera Rond qui commencera
    tour = Rond;

    //Mis en place de la transparence
    if(SDL_SetAlpha(vide,SDL_SRCALPHA,180)==-1)
       cout << "Erreur avec la transparence de la case vide" << endl;

    //Mis en place de la transparence
    if(SDL_SetColorKey(o,SDL_SRCCOLORKEY,0)==-1)
       cout << "Erreur avec la transparence du rond" << endl;

    if(SDL_SetColorKey(x,SDL_SRCCOLORKEY,0)==-1)
       cout << "Erreur avec la transparence de la croix" << endl;

    if(SDL_SetColorKey(gagneo,SDL_SRCCOLORKEY,0)==-1)
       cout << "Erreur avec la transparence du rond" << endl;

    if(SDL_SetColorKey(gagnex,SDL_SRCCOLORKEY,0)==-1)
        cout << "Erreur avec la transparence du rond" << endl;

    /* Début du code d'initialisation */
    /* Mettre en place la largeur et l'hauteur d'une case */
    inputfile >> r.w >> r.h;

    //Initialisation de chaque case
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
	{
		inputfile >> r.x >> r.y;
		//On initialise les positions de chaque case
		plateau[i][j].setPos(&r);
		//On initialise les images de chaque case
		plateau[i][j].setImage(vide,o,x,gagneo,gagnex);
	}
    return true;
}

void Jeu::videJeu()
{
    int i,j;

    //On met toutes les cases à Vide
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            plateau[i][j].init();

    //On commence par Rond
    tour = Rond;

    //On met fini à false
    fini = false;
}

void Jeu::clic(int x, int y)
{
    int i,j;
    bool trouve=false;

    if(!fini)
        {
        for(i=0;(i<3)&&(!trouve);i++)
            for(j=0;(j<3)&&(!trouve);j++)
                {
                if(plateau[i][j].estDedans(x,y))
                    {
                    if((plateau[i][j].estVide()))
                        {
                        plateau[i][j].setType(tour);
                        tour = (tour==Rond)?Croix:Rond;
                        }
                    trouve = true;
                    }
                }
	}
    if(trouve)
        verifFini();
}

void Jeu::aff(SDL_Surface *screen)
{
    int k,l;

    //Dessiner le fond d'ecran
    SDL_BlitSurface(bg,NULL,screen,NULL);

    //Dessiner chaque case
    for(k=0;k<3;k++)
        for(l=0;l<3;l++)
            {
            plateau[k][l].affiche(screen);
            }
}

//Fonction qui retourne le joueur courant
Case Jeu::getTypeGagne()
{return typegagne;}

Case Jeu::getTour()
{return tour;}

bool Jeu::getFini()
{return fini;}

void Jeu::verifFini()
{
	bool casevide = false;
	int i;

    //Remet cette variable à zéro
    typegagne = Vide;
    fini = false;

	//Lignes
	for(i=0;i<3;i++)
	{
		if(!plateau[i][0].estVide())
 			{
			if((plateau[i][0].memeType(plateau[i][1])) && (plateau[i][0].memeType(plateau[i][2])))
				{
				fini = true;
				typegagne = plateau[i][0].getType();
				plateau[i][0].setType(Gagne);
				plateau[i][1].setType(Gagne);
				plateau[i][2].setType(Gagne);
				}
			}
		else
			casevide = true;
	}

	//Colonnes
	for(i=0;i<3;i++)
	{
		if(!plateau[0][i].estVide())
 			{
			if((plateau[0][i].memeType(plateau[1][i])) && (plateau[0][i].memeType(plateau[2][i])))
				{
				fini = true;
				typegagne = plateau[0][i].getType();
				plateau[0][i].setType(Gagne);
				plateau[1][i].setType(Gagne);
				plateau[2][i].setType(Gagne);
				}
			}
		else
			casevide = true;
	}

	//Diagonales
	if( !plateau[0][0].estVide() )
		{
			if((plateau[0][0].memeType(plateau[1][1]))&&(plateau[0][0].memeType(plateau[2][2])))
			{
				fini = true;
				typegagne = plateau[0][0].getType();
				plateau[0][0].setType(Gagne);
				plateau[1][1].setType(Gagne);
				plateau[2][2].setType(Gagne);
			}
		}
	else
		casevide = true;

	if( !plateau[2][0].estVide() )
		{
			if((plateau[2][0].memeType(plateau[1][1]))&&(plateau[2][0].memeType(plateau[0][2])))
			{
				fini = true;
				typegagne = plateau[2][0].getType();
				plateau[2][0].setType(Gagne);
				plateau[1][1].setType(Gagne);
				plateau[0][2].setType(Gagne);
			}
		}
	else
		casevide = true;

	//Dernières cases à vérifier pour le booléen casevide
	if( (plateau[1][1].estVide())||(plateau[1][2].estVide())||
		(plateau[2][1].estVide())||(plateau[2][2].estVide()))
		casevide = true;

	fini = !casevide || fini;
}

//Fonctions pour l'IA
//Est-ce que le joueur courant est humain
bool Jeu::estHumain()
{
    if(tour==Rond)
        return j1==Humain;
    else
        return j2==Humain;
}

//Fonction qui retourne le type du joueur
TypeJoueur Jeu::getTypeJoueur()
{
	if(tour==Rond)
		return j1;
	else
		return j2;
}

//Fonction qui retourne l'état de la case
bool Jeu::estVide(int i, int j)
{
    return plateau[i][j].estVide();
}

Case Jeu::getCase(int i, int j)
{
    return plateau[i][j].getType();
}

//Fonction qui joue la case (i,j)
void Jeu::joue(int i,int j)
{
    plateau[i][j].setType(tour);
    tour = (tour==Rond)?Croix:Rond;
    verifFini();
}

void Jeu::annuleCoup(int a, int b)
{
   int i,j;

   plateau[a][b].setType(Vide);
   for(i=0;i<3;i++)
        for(j=0;j<3;j++)
        {
        plateau[i][j].setType(plateau[i][j].getType());
        }

    tour = (tour==Rond)?Croix:Rond;
    verifFini();
}

//Fonction qui met en place le type des joueurs
void Jeu::setTypeJoueur(int i, int type)
{
	if(i==1)
		{
		j1 = (TypeJoueur) type;
		}
	else
		{
		j2 = (TypeJoueur) type;
		}
}
