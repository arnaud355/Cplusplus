#ifndef DEF_ZFRACTIONS
#define DEF_ZFRACTIONS

#include <iostream>

class Zfraction
{

public:

Zfraction(int nb1,int nb2);
Zfraction(int nb);
Zfraction();


Zfraction& operator+=(Zfraction const  &b);
Zfraction& operator*=(Zfraction const &b);

void afficher(std::ostream &flux) const;

bool estEgal(Zfraction const& b) const;
bool estPlusPetitQue(Zfraction const& b) const;
bool estPlusGrandQue(Zfraction const& b) const;


private:

int m_num;
int m_deno;
};

//Permet � une classe d'�tre reconnu par lo'bjet cout de la class ostream
std::ostream& operator<<(std::ostream& flux, Zfraction const& fraction);

//Op�rateurs arithm�tique
Zfraction operator+(Zfraction const& a, Zfraction const& b);
Zfraction operator*(Zfraction const& a, Zfraction const& b);

/*Op�rateurs de comparaison, c'est en dehors de la classe
et comme on fait appel � des variables de la classe qui sont
prot�g�, on appel une m�thode � l'int�rieur
*/
bool operator==(Zfraction const &a, Zfraction const &b);
bool operator<(Zfraction const &a, Zfraction const &b);
bool operator>(Zfraction const &a, Zfraction const &b);

#endif


