#include <iostream>
#include <vector>
#include <string>
#include "polymorphisme.h"
#include "garage.h"

using namespace std;

int main()
{
    vector<Vehicule*> listeVehicules;
    Garage garage;
    bool changer = true, continuer = true;
    char reponse, rep;
    string vehicule,modele;
    int prix(0),annee(0),nbroues(0),nbportes(0),vitesse(0),poids(0), tailleTab(0),pos(0);

    listeVehicules.push_back(new Voiture("ford mondeo",15000,1998,4,5));
    listeVehicules.push_back(new Voiture("alpha",12000,2002,4,3));
    listeVehicules.push_back(new Moto("honda repsol",2000,2015,2,212.5));
    listeVehicules.push_back(new Camion("mercedes benz",30000,1986,6,5.6));

    listeVehicules[0]->affiche();
    //On affiche les informations de la première voiture
    listeVehicules[0]->anneeSortie();
     listeVehicules[0]->afficheNbRoues();
     std::cout << std::endl;

    listeVehicules[2]->affiche();
    //Et celles de la moto
     listeVehicules[2]->anneeSortie();
     listeVehicules[2]->afficheNbRoues();

    listeVehicules[3]->affiche();
    //Et celles de la camion
     listeVehicules[3]->anneeSortie();
     listeVehicules[3]->afficheNbRoues();

     do{

            cout << "Voulez-vous renseigner un nouveau véhicule ? y/n :" << endl;
            cin >> reponse;
            if(reponse == 'n'){
                changer = false;
            }
            else{
                cout << "Type de véhicule: voiture, moto, camion:" << endl;
                cin >> vehicule;
                cout << "nom du modele:" << endl;
                cin >> modele;
                 cout << "prix:" << endl;
                cin >> prix;
                 cout << "annee:" << endl;
                cin >> annee;
                 cout << "nombre de roues:" << endl;
                cin >> nbroues;
            }

                    if(vehicule == "voiture" && reponse != 'n'){
                        cout << "nombre de portes (pour les voitures uniquement):" << endl;
                        cin >> nbportes;
                    }
                    else if(vehicule == "moto" && reponse != 'n'){
                        cout << "vitesse maximale (pour les motos uniquement):" << endl;
                        cin >> vitesse;
                    }
                    else if(vehicule == "camion" && reponse != 'n'){
                        cout << "poids (pour les camions uniquement):" << endl;
                        cin >> poids;
                    }
                    else
                    {
                        changer = false;
                    }

                garage.ajouterVehicules(listeVehicules,vehicule,modele,prix,annee,nbroues,nbportes,vitesse,poids);

     }while(changer);

      garage.afficherTousLesModelesDeVehicules(listeVehicules);

      do{
          cout << "Voulez-vous supprimer un modele: y/n" << endl;
          cin >> rep;
          if(rep == 'y'){
                cout << "Le modele à quelle position voulez-vous supprimer ?" << endl;
                cin >> pos;
                pos = pos - 1;
                garage.supprimerVehicules(listeVehicules,pos);
          }

          if(rep != 'y')
             continuer = false;

      }while(continuer);

    garage.afficherTousLesModelesDeVehicules(listeVehicules);

    tailleTab = listeVehicules.size();

    for(int i(0); i<tailleTab; ++i)
    {
        delete listeVehicules[i];  //On libère la i-ème case mémoire allouée
        listeVehicules[i] = 0;  //On met le pointeur à 0 pour éviter les soucis
    }

    return 0;
}
