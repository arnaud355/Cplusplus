#include "Rand.h"

//Mis en place du compteur
int Rand::cnt=0;

//V�rification du compteur
void Rand::checkSeed()
{
        //Si on a trop appel� le g�n�rateur de nombres, on remet le tout � z�ro
        if((!cnt)||(cnt>10000))
                {
                srand(time(NULL));
                cnt=0;
                }
}

//G�n�rer une nouvelle s�quence...
void Rand::newSeed(int s)
{
        srand(s);
}

//G�n�rer un nombre al�atoire
int Rand::randi()
{
        checkSeed();
        return rand();
}

//G�n�rer un nombre al�atoire entre [0,max-1]
int Rand::randi(int max)
{
        checkSeed();
        if(max)
                return rand()%max;
        return 0;
}

//G�n�rer un nombre al�atoire entre [0,1]
double Rand::randf()
{
	checkSeed();
	return rand()/((double) RAND_MAX);
}

//G�n�rer un nombre al�atoire entre [a,b]
double Rand::randf(double a, double b)
{
	checkSeed();
	if(a>b)
		return randf(b,a);
	return (randf()*(b-a)+a);
}
