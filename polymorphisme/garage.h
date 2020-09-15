#ifndef DEF_GARAGE
#define DEF_GARAGE

#include "polymorphisme.h"
#include <iostream>
#include <vector>
#include <string>

class Garage
{
    public:
    Garage();
    void ajouterVehicules(std::vector<Vehicule*> &listeVehicules,std::string vehicule,std::string modele,int prix,int annee,int nbroues,int nbportes = 0,int vitesse = 0,int poids = 0);
    void supprimerVehicules(std::vector<Vehicule*> &listeVehicules, int pos);
    void afficherTousLesModelesDeVehicules(std::vector<Vehicule*> &listeVehicules) const;
    virtual ~Garage();          //Remarquez le 'virtual' ici

    protected:
    std::vector<Vehicule*> listeVehicules;
};

#endif
