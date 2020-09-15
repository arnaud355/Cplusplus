#include <iostream>
#include <vector>
#include <string>
#include "polymorphisme.h"
#include "garage.h"

using namespace std;

Garage::Garage()
{

}

Vehicule::Vehicule(string modele,int prix,int annee,int nbRoues)
    : m_modele(modele),m_prix(prix),m_anneeFabrication(annee),m_nbRoues(nbRoues)
{}

void Vehicule::affiche() const
//J'en profite pour modifier un peu les fonctions d'affichage
{
    cout << "Ceci est un vehicule coutant " << m_prix << " euros." << endl;
}

void Vehicule::anneeSortie() const
{
    cout << "C est un vehicule sortie l annee " << m_anneeFabrication << endl;
}



Vehicule::~Vehicule() //Même si le destructeur ne fait rien, on doit le mettre !
{}


void Garage::ajouterVehicules(vector<Vehicule*> &listeVehicules,string vehicule,string modele,int prix,int annee,int nbroues,int nbportes,int vitesse,int poids)
{
    if(vehicule == "voiture"){
        listeVehicules.push_back(new Voiture(modele,prix,annee,nbroues,nbportes));
    }
    else if(vehicule == "moto"){
        listeVehicules.push_back(new Moto(modele,prix,annee,nbroues,vitesse));
    }
    else if(vehicule == "camion"){
        listeVehicules.push_back(new Camion(modele,prix,annee,nbroues,poids));
    }
    else
    {
        cout << "Vous n avez pas entré un type de véhicule correct!" << endl;
    }
}
void Garage::supprimerVehicules(vector<Vehicule*> &listeVehicules, int pos)
{
        listeVehicules.erase(listeVehicules.begin() + pos);

}
void Garage::afficherTousLesModelesDeVehicules(vector<Vehicule*> &listeVehicules) const
{
    int tailleTab(0);
    tailleTab = listeVehicules.size();
    cout << "Modele au garage: " << endl;
    for(int i(0); i<tailleTab; ++i)
    {
        cout << "Modele: " <<  listeVehicules[i]->retourneModele() << endl;
    }
}
string Voiture::retourneModele() const
{
    return m_modele;
}
string Moto::retourneModele() const
{
    return m_modele;
}
string Camion::retourneModele() const
{
    return m_modele;
}
Garage::~Garage()
{

}

Voiture::Voiture(string modele,int prix,int annee,int nbRoues, int portes)
    :Vehicule(modele,prix,annee,nbRoues), m_portes(portes)
{}

void Voiture::affiche() const
{
    cout << "Ceci est une voiture avec " << m_portes << " portes et coutant " << m_prix << " euros." << endl;
}

void Voiture::anneeSortie() const
{
    cout << "C est une voiture sortie l annee " << m_anneeFabrication << endl;
}

void Voiture::afficheNbRoues() const
{
    cout << "C est une voiture ayant " << m_nbRoues <<  " roues " << endl;
}

Voiture::~Voiture()
{}

Moto::Moto(string modele,int prix,int annee,int nbRoues, double vitesseMax)
    :Vehicule(modele,prix,annee,nbRoues), m_vitesse(vitesseMax)
{}

void Moto::affiche() const
{
    cout << "Ceci est une moto allant a " << m_vitesse << " km/h et coutant " << m_prix << " euros." << endl;
}

void Moto::anneeSortie() const
{
    cout << "C est une moto sortie l annee " << m_anneeFabrication << endl;
}

void Moto::afficheNbRoues() const
{
    cout << "C est une moto ayant " << m_nbRoues << " roues " << endl;
}

Moto::~Moto()
{}

Camion::Camion(string modele,int prix,int annee,int nbRoues, double poids)
    :Vehicule(modele,prix,annee,nbRoues), m_poids(poids)
{}

void Camion::affiche() const
{
    cout << "Ceci est un camion pesant " << m_poids << " tonnes et coutant " << m_prix << " euros." << endl;
}

void Camion::anneeSortie() const
{
    cout << "C est un camion sortie l annee " << m_anneeFabrication << endl;
}

void Camion::afficheNbRoues() const
{
    cout << "C est un camion ayant " << m_nbRoues << " roues " << endl;
}

Camion::~Camion()
{}
