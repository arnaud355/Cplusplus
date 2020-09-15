#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>


using namespace std;
string recupMot(int nbAlea);

int main()
{

    int nbMotsDico(0),nbAlea(0);

    srand(time(0));
    char continuer = 'o';



    ifstream dico("dictionnaire/dico.txt");


    if(dico)
        {
             string ligne; //Une variable pour stocker les lignes lues


        while(getline(dico, ligne)) //Tant qu'on n'est pas à la fin, on lit
        {

         nbMotsDico += 1; //Compte nombre de mots dans le dico

        }

        do{


      //L'ouverture s'est bien passée, on peut donc lire




        nbAlea = rand() % nbMotsDico;//Selectionne un mot aleatoire


        ligne = recupMot(nbAlea);
        cout << ligne << endl;

        // ifstream dico("dictionnaire/dico.txt");


         cout << "continuer o/n" << endl;
         cin >>continuer;
        //cin.ignore;
        }while(continuer != 'n');
    }
    else
    {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return 0;
}

string recupMot(int nbAlea){
     ifstream dico("dictionnaire/dico.txt");
        string ligne;
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

