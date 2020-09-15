#ifndef DEF_PERSONNAGES
#define DEF_PERSONNAGES
#include "armes.h"

#include <iostream>
#include <string>



class Personnage
{
    public:

    Personnage();
    Personnage(std::string nomArme, int degatsArme);
    ~Personnage();
    void recevoirDegats(int nbDegats);
    void attaquer(Personnage &cible);
    void boirePotionDeVie(int quantitePotion);
    void changerArme(std::string nomNouvelleArme, int degatsNouvelleArme);
    bool estVivant() const;
    void afficherEtat() const;
    void afficherVie () const;
    private:

    int m_vie;
    int m_mana;
    Arme m_arme; //Notre perso posssède une arme, un objet arme de type Arme
};

#endif
