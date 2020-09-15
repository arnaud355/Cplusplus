#ifndef DEF_FRACTION
#define DEF_FRACTION

#include <iostream>

class ZFraction
{
public:

    //Constructeurs
    ZFraction(int num, int den);
    ZFraction(int nombre);
    ZFraction();

    //Affichage
    void affiche(std::ostream& flux) const;

    //Opérateurs arithmétiques
    ZFraction& operator+=(ZFraction const& autre);
    ZFraction& operator*=(ZFraction const& autre);

    //Méthodes de comparaison
    bool estEgal(ZFraction const& autre) const;
    bool estPlusPetitQue(ZFraction const& autre) const;

private:

    int m_numerateur;      //Le numérateur de la fraction
    int m_denominateur;    //Le dénominateur de la fraction

    // Simplifie une fraction
    void simplifie();

};

//Opérateur d'injection dans un flux
std::ostream& operator<<(std::ostream& flux, ZFraction const& fraction);

//Opérateurs arithmétiques
ZFraction operator+(ZFraction const& a, ZFraction const& b);
ZFraction operator*(ZFraction const& a, ZFraction const& b);

//Opérateurs de comparaison
bool operator==(ZFraction const& a, ZFraction const& b);
bool operator!=(ZFraction const& a, ZFraction const& b);
bool operator<(ZFraction const& a, ZFraction const& b);
bool operator>(ZFraction const& a, ZFraction const& b);
bool operator>=(ZFraction const& a, ZFraction const& b);
bool operator<=(ZFraction const& a, ZFraction const& b);

//Calcul du pgcd
int pgcd(int a, int b);

#endif
