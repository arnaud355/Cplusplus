#include "ZFraction.h"
using namespace std;

//Constructeurs
ZFraction::ZFraction(int num, int den)
    :m_numerateur(num), m_denominateur(den)
{
    simplifie();
}

ZFraction::ZFraction(int entier)
    :m_numerateur(entier), m_denominateur(1)
{
}

ZFraction::ZFraction()
    :m_numerateur(0), m_denominateur(1)
{
}

//Affichage
void ZFraction::affiche(ostream& flux) const
{
    if(m_denominateur == 1)
    {
        flux << m_numerateur;
    }
    else
    {
        flux << m_numerateur << '/' << m_denominateur;
    }
}

//Opérateur d'injection dans un flux
ostream& operator<<(ostream& flux, ZFraction const& fraction)
{
    fraction.affiche(flux);
    return flux;
}

//Opérateurs arithmétiques
ZFraction& ZFraction::operator+=(ZFraction const& autre)
{
    m_numerateur = autre.m_denominateur * m_numerateur + m_denominateur * autre.m_numerateur;
    m_denominateur = m_denominateur * autre.m_denominateur;

    simplifie();
    return *this;
}

ZFraction& ZFraction::operator*=(ZFraction const& autre)
{
    m_numerateur *= autre.m_numerateur;
    m_denominateur *= autre.m_denominateur;

    simplifie();
    return *this;
}

//Méthodes de comparaison
bool ZFraction::estEgal(ZFraction const& autre) const
{
    if(m_numerateur == autre.m_numerateur && m_denominateur == autre.m_denominateur)
        return true;
    else
        return false;
}

bool ZFraction::estPlusPetitQue(ZFraction const& autre) const
{
    if(m_numerateur * autre.m_denominateur < m_denominateur * autre.m_numerateur)
        return true;
    else
        return false;
}

//Simplification
void ZFraction::simplifie()
{
    int nombre=pgcd(m_numerateur, m_denominateur); //Calcul du pgcd

    m_numerateur /= nombre;     //Et on simplifie
    m_denominateur /= nombre;
}

//Opérateurs externes
ZFraction operator+(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie+=b;
    return copie;
}

ZFraction operator*(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie*=b;
    return copie;
}

bool operator==(ZFraction const& a, ZFraction const& b)
{
    if(a.estEgal(b))
        return true;
    else
        return false;
}

bool operator!=(ZFraction const& a, ZFraction const& b)
{
    if(a.estEgal(b))
        return false;
    else
        return true;
}

bool operator<(ZFraction const& a, ZFraction const& b) //Vrai si a<b donc si a est plus petit que a
{
    if(a.estPlusPetitQue(b))
        return true;
    else
        return false;
}

bool operator>(ZFraction const& a, ZFraction const& b) //Vrai si a>b donc si b est plus petit que a
{
    if(b.estPlusPetitQue(a))
        return true;
    else
        return false;
}

bool operator<=(ZFraction const& a, ZFraction const& b) //Vrai si a<=b donc si b n'est pas plus petit que a
{
    if(b.estPlusPetitQue(a))
        return false;
    else
        return true;
}

bool operator>=(ZFraction const& a, ZFraction const& b) //Vrai si a>=b donc si a n'est pas plus petit que b
{
    if(a.estPlusPetitQue(b))
        return false;
    else
        return true;
}

//Calcul du pgcd
int pgcd(int a, int b)
{
    while(a != b)
    {
        if(a > b)
        {
            a -= b;
        }
        else
        {
            b -= a;
        }
    }
    return a;
}
