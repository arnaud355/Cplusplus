#include "IA.h"

using namespace std;

IA::IA()
{}

IA::~IA()
{}

int IA::calcScore(int cntpion, int cntjoueur)
{
//On regarde le nombre de pions
switch(cntpion)
    {
    case 1:
        return 10*cntjoueur;
    case 2:
        return 30*cntjoueur;
    default:
        return 0;
    }
}

int IA::evalue(Jeu *jeu)
{
    int score=0;

    int cntjoueur, cntpion;
    int i,j;

    //Si le jeu est fini
    if(jeu->getFini())
        {
	    //Si l'IA a gagné, on retourn 1000 - le nombre de pions
        if(jeu->getTypeGagne() == joueurCourant)
            {
            return 1000-comptePions(jeu);
            }
        else if(jeu->getTypeGagne() == Vide)
		    {
		    //Egalite -> on retourne 0
		    return 0;
		    }
	    else
		    {
		    //Si l'IA a perdu, on retourne -1000 + le nombre de pions
	        return -1000+comptePions(jeu);
		    }
        }

    //Diagonale 1
    cntpion=0;
    cntjoueur=0;
    //On regarde chaque case
    for(i=0;i<3; i++)
        {
	    //Si la case n'est pas vide
        if(!jeu->estVide(i,i))
	        {
	        //On incrémente d'un pion
	        cntpion++;
            //Si c'est le même type du joueur courant
            if(jeu->getCase(i,i)==joueurCourant)
      		    //On incrémente le compteur
                cntjoueur++;
            else
       	        //On décrémente le compteur
                cntjoueur--;
            }
        }

    //On ajoute au score cette nouvelle participation
    score += calcScore(cntpion,cntjoueur);

    //Diagonale 2
    cntpion=0;
    cntjoueur=0;
    for(i=0;i<3; i++)
        {
        if(!jeu->estVide(i,2-i))
	    {
            cntpion++;
            if(jeu->getCase(i,2-i)==joueurCourant)
                cntjoueur++;
            else
                cntjoueur--;
            }
        }

    score += calcScore(cntpion,cntjoueur);

    //Lignes
    for(i=0;i<3;i++)
        {
        cntpion = 0;
        cntjoueur = 0;
        for(j=0;j<3;j++)
            {
            if(jeu->getCase(i,j)!=Vide)
                {
                cntpion++;
                if(jeu->getCase(i,j)==joueurCourant)
                    cntjoueur++;
                else
                    cntjoueur--;
                }
            }

        score += calcScore(cntpion,cntjoueur);
        }

    //Colonnes
    for(i=0;i<3;i++)
        {
        cntpion = 0;
        cntjoueur = 0;
        for(j=0;j<3;j++)
            {
            if(jeu->getCase(j,i)!=Vide)
                {
                cntpion++;
                if(jeu->getCase(j,i)==joueurCourant)
                    cntjoueur++;
                else
                    cntjoueur--;
                }
            }

        score += calcScore(cntpion,cntjoueur);
        }

    return score;
}

int IA::comptePions(Jeu *jeu)
{
    int i,j,cnt=0;
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            {
            if(jeu->getCase(i,j)!=Vide)
                cnt++;
            }
    return cnt;
}

void IA::calcIA(Jeu *jeu, int prof)
{
    int i,j,tmp;
    int max = MINEVAL;
    int maxi=-1,maxj=-1;

    //On met en place le joueur courant
    joueurCourant = jeu->getTour();

    //Si la profondeur est nulle ou la partie est finie,
    //on ne fait pas le calcul
    if((prof!=0)||(!jeu->getFini()))
        {
        //On parcourt les cases du morpion
        for(i=0;i<3; i++)
            for(j=0;j<3;j++)
                {
                //Si la case est vide
                if(jeu->estVide(i,j))
                    {
                    //On simule qu'on joue cette case
                    jeu->joue(i,j);
                    //On appelle la fonction calcMin pour lancer l'IA
                    tmp = calcMin(jeu, prof-1);
                    //Si ce score est plus grand
                    if((tmp>max)||((tmp==max)&&(Rand::randi(2))))
                        {
                        //On le choisit
                        max = tmp;
                        maxi = i;
                        maxj = j;
                        }
                    //On annule le coup
                    jeu->annuleCoup(i,j);
                    }
                }
        }
    //On jouera le coup maximal
    jeu->joue(maxi,maxj);
}

int IA::calcMin(Jeu *jeu, int prof)
{
    int i,j,tmp;
    int min = MAXEVAL;

    //Si on est à la profondeur voulue, on retourne l'évaluation
    if(prof==0)
        return evalue(jeu);

    //Si la partie est finie, on retourne l'évaluation de jeu
    if(jeu->getFini())
        return evalue(jeu);

    //On parcourt le plateau de jeu et on le joue si la case est vide
    for(i=0;i<3; i++)
        for(j=0;j<3;j++)
            {
            if(jeu->estVide(i,j))
                {
                //On joue le coup
                jeu->joue(i,j);
                tmp = calcMax(jeu, prof-1);
                if(tmp<min)
                    {
                    min = tmp;
                    }
                //On annule le coup
                jeu->annuleCoup(i,j);
                }
            }
    return min;
}

int IA::calcMax(Jeu *jeu, int prof)
{
    int i,j,tmp;
    int max = MINEVAL;

    //Si on est à la profondeur voulue, on retourne l'évaluation
    if(prof==0)
        return evalue(jeu);

    //Si la partie est finie, on retourne l'évaluation de jeu
    if(jeu->getFini())
        return evalue(jeu);

    //On parcourt le plateau de jeu et on le joue si la case est vide
    for(i=0;i<3; i++)
        for(j=0;j<3;j++)
            {
            if(jeu->estVide(i,j))
                {
                //On joue le coup
                jeu->joue(i,j);
                tmp = calcMin(jeu, prof-1);
                if(tmp>max)
                    {
                    max = tmp;
                    }
                //On annule le coup
                jeu->annuleCoup(i,j);
                }
            }
    return max;
}
