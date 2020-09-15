#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "fonctions.h"

using namespace std;

string melangerLettres(string motAmelanger,int tailleMot){
    int posAlea(0);
    int i(0);

    string motMelanger;
    bool NonMelanger(1);

    while(NonMelanger){

          posAlea = rand() % motAmelanger.size();

            motMelanger += motAmelanger[posAlea];
            //motMelanger[i] = motAmelanger[posAlea]; n'ai pas renvoyé, considéré comme type char je suppose et non comme string
            motAmelanger.erase(posAlea,1);
            i += 1;
            if(i >= tailleMot){

                NonMelanger = 0;
            }

    }

    return motMelanger;

}

string recupMot(int nbAlea){
     ifstream dico("dictionnaire/dico.txt");
        string ligne = "khhd";
        int j(0);
        bool motNonTrouve = 1;
       while(getline(dico, ligne) && motNonTrouve) //Tant qu'on n'est pas à la fin, on lit
      {

         if(j == nbAlea){
            motNonTrouve = 0;
         }
         j += 1;
        }
        return ligne;
}



