#include "ZFraction.h"
#include <cmath>
using namespace std;

//Constructeurs
/*ZFraction::ZFraction(int num , int den) : m_numerateur(num), m_denominateur(den)
{
    simplifie();
}*/

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

//methodes
int ZFraction::numerateur()
 {
    int fract(0);
    fract = m_numerateur;
    return fract;
 }
int ZFraction::denominateur()
 {
     int fract(0);
    fract = m_denominateur;
    return fract;
 }
 double ZFraction::conversionDecimale()
 {
    double zNum(0);
    double zDen(0);
    double z(0);

    zNum = static_cast<double>(m_numerateur);
    zDen = static_cast<double>(m_denominateur);

    z = zNum / zDen;
    return z;
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

int ZFraction::getZfracNum() const
{
    return m_numerateur;
}
int ZFraction::getZfracDeno() const
{
    return m_denominateur;
}
//*********************************************************
//Partie de la class Zfractmath
void ZFractmath::getNumberAbs(ZFraction const& fraction)
{
    int num(0),deno(0);
    num = getZfracMathNum(fraction);
    deno = getZfracMathDeno(fraction);

    m_matnum =  static_cast<double>(num);
    m_matdeno =  static_cast<double>(deno);

    m_matnum = abs(m_matnum);
    m_matdeno = abs(m_matdeno);
}
void ZFractmath::getNumberPow(ZFraction const& fraction)
{
    int num(0), deno(0);
    num = getZfracMathNum(fraction);
    deno = getZfracMathDeno(fraction);

    m_matnum =  static_cast<double>(num);
    m_matdeno =  static_cast<double>(deno);

    m_matnum = pow(m_matnum,2);
    m_matdeno = pow(m_matdeno,2);
}
void ZFractmath::getNumberSqrt(ZFraction const& fraction)
{
    int num(0), deno(0);
    num = getZfracMathNum(fraction);
    deno = getZfracMathDeno(fraction);

    m_matnum =  static_cast<double>(num);
    m_matdeno =  static_cast<double>(deno);

    m_matnum = sqrt(m_matnum);
    m_matdeno = sqrt(m_matdeno);
}
void ZFractmath::afficherMath() const
{
    cout << m_matnum << '/' << m_matdeno << endl;
}
int getZfracMathNum(ZFraction const& fraction){
    int result(0);
    result = fraction.getZfracNum();
    return result;
}
int getZfracMathDeno(ZFraction const& fraction){
    int result(0);
     result = fraction.getZfracDeno();
     return result;

}
//******************
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

ZFraction& ZFraction::operator/=(ZFraction const& autre)
{
    m_numerateur *= autre.m_denominateur;
    m_denominateur *= autre.m_numerateur;

    simplifie();
    return *this;
}

ZFraction& ZFraction::operator-=(ZFraction const& autre)
{
    if(m_denominateur == autre.m_denominateur){
       m_numerateur = m_numerateur - autre.m_numerateur;
       }
    else{
        m_numerateur = m_numerateur * autre.m_denominateur - m_denominateur * autre.m_numerateur;
        m_denominateur = m_denominateur * autre.m_denominateur;
    }

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
ZFraction operator/(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie/=b;
    return copie;
}
ZFraction operator-(ZFraction const& a, ZFraction const& b)
{
    ZFraction copie(a);
    copie-=b;
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
