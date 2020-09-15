
#include "Zfractions.h"

using namespace std;

Zfraction::Zfraction(int nb1,int nb2)
    :m_num(nb1),m_deno(nb2)
{

}
Zfraction::Zfraction(int nb)
    :m_num(nb),m_deno(1)
{

}
Zfraction::Zfraction()
    :m_num(0),m_deno(1)
{

}



Zfraction & Zfraction::operator+=(Zfraction const &b)
{

	bool divisible = true;
	if(m_deno == b.m_deno){
		m_num += b.m_num;
		do{
			if(m_num % 2 != 0 && m_deno % 2 != 0){
				m_num /= 2;
				m_deno /= 2;
			}
			else {
			divisible = false;
			}
		}while(divisible);

		return *this;
	}
	else if(m_deno != b.m_deno){

		m_num = (m_num * b.m_deno) + (b.m_num * m_deno);
		m_deno = b.m_deno * m_deno;
		do{
			if(m_num % 2 != 0 && m_deno % 2 != 0){
				m_num /= 2;
				m_deno /= 2;
			}
			else {
			divisible = false;
			}
		}while(divisible);

		return *this;
	}
}
Zfraction & Zfraction::operator*=(Zfraction const &b)
{

	bool divisible = true;
	if(m_deno == b.m_deno){
		m_num = m_num * b.m_num;
		do{
			if(m_num % 2 != 0 && m_deno % 2 != 0){
				m_num /= 2;
				m_deno /= 2;
			}
			else {
			divisible = false;
			}
		}while(divisible);

		return *this;
	}
	else if(m_deno != b.m_deno){

		m_num = (m_num * b.m_num) + (b.m_deno * m_deno);
		m_deno = b.m_deno * m_deno;
		do{
			if(m_num % 2 != 0 && m_deno % 2 != 0){
				m_num /= 2;
				m_deno /= 2;
			}
			else {
			divisible = false;
			}
		}while(divisible);

		return *this;
	}
}
bool Zfraction::estEgal(Zfraction const& b) const
{
    int r1(0),r2(0);
    r1 = m_num / m_deno;
    r2 = b.m_num / b.m_deno;

    if (r1 == r2)
        return true;
    else
        return false;
}
bool Zfraction::estPlusPetitQue(Zfraction const& b) const
{
    int r1(0),r2(0);
    r1 = m_num / m_deno;
    r2 = b.m_num / b.m_deno;

    if (r1 < r2)
        return true;
    else
        return false;
}
bool Zfraction::estPlusGrandQue(Zfraction const& b) const
{
    int r1(0),r2(0);
    r1 = m_num / m_deno;
    r2 = b.m_num / b.m_deno;

    if (r1 > r2)
        return true;
    else
        return false;
}
void Zfraction::afficher(ostream &flux) const
{
    flux << m_num << '/' << m_deno;
}

//***************************************************************
//Cette zone n'est plus la zone des méthodes de la class Zfraction
Zfraction operator+(Zfraction const& a, Zfraction const& b)
{
    /*va faire l'opération dans la methode += inclu dans la class,
    garanti la cohérence et semantique*/
    Zfraction copie(a);
    copie += b;
    return copie;
}
Zfraction operator*(Zfraction const& a, Zfraction const& b)
{
    Zfraction copie(a);
    copie *= b;
    return copie;
}
bool operator==(Zfraction const &a, Zfraction const &b)
{
    return a.estEgal(b);
}
bool operator<(Zfraction const &a, Zfraction const &b)
{
    if(a.estPlusPetitQue(b))
        return true;
    else
        return false;
}
bool operator>(Zfraction const &a, Zfraction const &b)
{
    if(a.estPlusGrandQue(b))
        return true;
    else
        return false;
}
ostream &operator<<(ostream& flux, Zfraction const& fraction)
{
    fraction.afficher(flux) ;
    return flux;
}

