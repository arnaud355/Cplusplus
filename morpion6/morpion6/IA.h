#ifndef H_IA
#define H_IA

#include "Jeu.h"
#include "Rand.h"

const int MINEVAL=-100000;
const int MAXEVAL=100000;

//Classe qui gére l'intelligence artificielle
class IA
{
    private:
        Case joueurCourant;

    public:
        IA();
        ~IA();

        //Fonction qui calcule le prochain coup*/
		void calcIA(Jeu *j, int prof);

        //Fonctions pour le calcul
        int calcMin(Jeu *j, int prof);
        int calcMax(Jeu *j, int prof);
        
        //Fonction qui évalue le jeu
        int calcScore(int, int);
        int evalue(Jeu *j);
	int comptePions(Jeu *j);
};

#endif
