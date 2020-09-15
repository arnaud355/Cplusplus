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

//Permet à une classe d'être reconnu par lo'bjet cout de la class ostream
std::ostream& operator<<(std::ostream& flux, Zfraction const& fraction);

//Opérateurs arithmétique
Zfraction operator+(Zfraction const& a, Zfraction const& b);
Zfraction operator*(Zfraction const& a, Zfraction const& b);

/*Opérateurs de comparaison, c'est en dehors de la classe
et comme on fait appel à des variables de la classe qui sont
protégé, on appel une méthode à l'intérieur
*/
bool operator==(Zfraction const &a, Zfraction const &b);
bool operator<(Zfraction const &a, Zfraction const &b);
bool operator>(Zfraction const &a, Zfraction const &b);

#endif


