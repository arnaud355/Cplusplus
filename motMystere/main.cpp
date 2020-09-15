#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <vector>
#include "fonctions.h"

using namespace std;


int main()
{
    string motMelanger, motMystere,motAtrouver,motAmelanger;
    int tailleMot(0),essais(0),somme(0),scoreMoyen(0),nbMotsDico(0),nbAlea(0);
    unsigned int i(0);
    srand(time(0));
    char continuer = 'o';


    vector<int>tabScores;
    ifstream dico("dictionnaire/dico.txt");

    if(dico)
        {
            string ligne; //Une variable pour stocker les lignes lues


            while(getline(dico, ligne)) //Tant qu'on n'est pas � la fin, on lit
                {

                    nbMotsDico += 1; //Compte nombre de mots dans le dico

                }

        do{
            essais = 5;
            nbAlea = rand() % nbMotsDico;//Selectionne un mot aleatoire

            /*Recup d'un mot dans le fichier, le fichier est lu dans
            la fonction, comme �a le booleen du EOF est remis � z�ro
            � la fin de la fonction, jai cherch� d'autre moyen comme
            dico.clear(), mais sans succ�s
            */
            ligne = recupMot(nbAlea);
            motMystere = ligne;



        std::cout << std::endl; /*insertion de plusieurs sauts de lignes
                                pour ne pas que J2 vot le mot choisi */
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;


        tailleMot = motMystere.size();

        motAmelanger = motMystere;//mot mystere est mis dans mot � m�langer

        /*envoi de mot � melanger, et de taille de mot, m�mme si pas n�cessaire
        en c++, mais beson de conserver la taille original par rapport aux besoins
        dans la fonction*/
      motMelanger = melangerLettres(motAmelanger,tailleMot);


        while(motAtrouver != motMystere && essais > 0){
            cout << "Joueur essayer de trouver mot mystere" << endl;
            cout << "Il vous reste " << essais << " essais!" << endl;
            cout << motMelanger << endl;
            cin >> motAtrouver;
            essais -= 1;
        }


            tabScores.push_back(essais);
            for(i = 0; i < tabScores.size(); i++){
                somme += tabScores[i];
                scoreMoyen = somme / tabScores.size();
            }


        if(motAtrouver == motMystere){
            cout << "Bravo vous avez trouvez en " << essais << " essais!" << endl;
            cout << "Votre score moyen est " << scoreMoyen << endl;
            cout << "Le mot mystere etait " << motMystere << endl;
            cout << "Voulez-vous refaire une partie ? o/n" << endl;
            cin >> continuer;
            cin.ignore();
        }
        else if(essais <= 0){
            cout << "Dommage!" << endl;
            cout << "Votre score moyen est " << scoreMoyen << endl;
            cout << "Le mot mystere etait " << motMystere << endl;
            cout << "Voulez-vous refaire une partie ? o/n" << endl;
            cin >> continuer;
            cin.ignore();
        }
        else
        {

        }

        }while(continuer != 'n');
    }
    else
    {
      cout << "ERREUR: Impossible d'ouvrir le fichier en lecture." << endl;
    }
    return 0;
}

