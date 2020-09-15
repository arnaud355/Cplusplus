#include <iostream>
#include <fstream>
#include <string>
#include <limits>  // pour utiliser numeric_limits<int>::max()
using namespace std;

int main()
{
   //ifstream fichier("C:/Users/arnaud/Desktop/projetsC++/fichier/dico.txt");
   ifstream dico("../fichier/dico.txt");
    int i(0),nbLignes(-1),v(0);
    //bool motNonTrouve = 1;
    //bool tourne = 1;
   if(dico)
   {
      //L'ouverture s'est bien passée, on peut donc lire


      string ligne; //Une variable pour stocker les lignes lues


string mot;
 while(dico.ignore(numeric_limits<int>::max(), '\n'))
                        nbLignes++;


                cout << "Le fichier contient " << nbLignes << " lignes." << endl;
do{
      while(getline(dico, ligne) /*&& motNonTrouve*/) //Tant qu'on n'est pas à la fin, on lit
      {

         if(i == 3){
            cout << ligne << endl;

            //motNonTrouve = 0;
         }

         i += 1;
         //Et on l'affiche dans la console
         //Ou alors on fait quelque chose avec cette ligne
         //À vous de voir
      }

    //cin.ignore();
    // dico.clear();
    // dico.seekg(0, ios::beg);

    //dico.open("../fichier/dico.txt");
   /*  tourne = dico.eof();
     tourne = 0;*/
//cout << tourne << endl;
//ifstream dico("../fichier/dico.txt");

   //cout << ligne << endl;
    v += 1;
   }while(v < 3);
   }
   else
   {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
   }


   return 0;
}

