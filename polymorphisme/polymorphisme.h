#ifndef DEF_POLYMORPHISME
#define DEF_POLYMORPHISME

//#include "garage.h"
#include <iostream>
#include <vector>
#include <string>



class Vehicule
{
    public:
    Vehicule(std::string modele,int prix,int annee,int nbRoues); //Construit un véhicule d'un certain prix
    Vehicule();
    virtual void affiche() const;
    virtual void anneeSortie() const;
    virtual void afficheNbRoues() const = 0;
    virtual std::string retourneModele() const = 0;
    virtual ~Vehicule();          //Remarquez le 'virtual' ici

    protected:
    std::string m_modele;
    int m_prix;
    int m_anneeFabrication;
    int m_nbRoues;
};


class Voiture: public Vehicule
{
    public:
    Voiture(std::string modele,int prix,int annee,int nbRoues, int portes);
    //Construit une voiture dont on fournit le prix et le nombre de portes
    virtual void affiche() const;
    virtual void anneeSortie() const;
    virtual void afficheNbRoues() const;
    virtual std::string retourneModele() const;
    virtual ~Voiture();

    private:
    int m_portes;
};

class Moto : public Vehicule
{
    public:
    Moto(std::string modele,int prix,int annee,int nbRoues, double vitesseMax);
    //Construit une moto d'un prix donné et ayant une certaine vitesse maximale
    virtual void affiche() const;
    virtual void anneeSortie() const;
    virtual void afficheNbRoues() const;
    virtual std::string retourneModele() const;
    virtual ~Moto();

    private:
    double m_vitesse;
};

class Camion : public Vehicule
{
    public:
    Camion(std::string modele,int prix,int annee,int nbRoues, double poids);
    //Construit une moto d'un prix donné et ayant une certaine vitesse maximale
    virtual void affiche() const;
    virtual void anneeSortie() const;
    virtual void afficheNbRoues() const;
    virtual std::string retourneModele() const;
    virtual ~Camion();

    private:
    double m_poids;
};
#endif
