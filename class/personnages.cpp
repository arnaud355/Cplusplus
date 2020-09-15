
#include "personnages.h"


using namespace std;

Personnage::Personnage() : m_vie(100), m_mana(100)
{

}
Personnage::Personnage(string nomArme, int degatsArme) : m_vie(100), m_mana(100),m_arme(nomArme, degatsArme)
{

}
Personnage::~Personnage()
{

}
void Personnage::recevoirDegats(int nbDegats)
{
    m_vie -= nbDegats;
    //On enl�ve le nombre de d�g�ts re�us � la vie du personnage

    if (m_vie < 0) //Pour �viter d'avoir une vie n�gative
    {
        m_vie = 0; //On met la vie � 0 (cela veut dire mort)
    }
}

void Personnage::attaquer(Personnage &cible)
{
    cible.recevoirDegats(m_arme.getDegats());
    //On inflige � la cible les d�g�ts que cause notre arme
}

void Personnage::boirePotionDeVie(int quantitePotion)
{
    m_vie += quantitePotion;

    if (m_vie > 100) //Interdiction de d�passer 100 de vie
    {
        m_vie = 100;
    }
}

void Personnage::changerArme(string nomNouvelleArme, int degatsNouvelleArme)
{
    m_arme.changer(nomNouvelleArme, degatsNouvelleArme);
}
void Personnage::afficherEtat() const
{
    cout << "niveau de vie : " << m_vie << endl;
    cout << "niveau de magie : " << m_mana << endl;
    m_arme.afficher();
}
void Personnage::afficherVie () const
{
    cout << "niveau de vie : " << m_vie << endl;

}
bool Personnage::estVivant() const
{
    if (m_vie > 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
