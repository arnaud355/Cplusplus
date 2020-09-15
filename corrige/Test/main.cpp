#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;

string melangerLettres(string mot)
{
   string melange;
   int position(0);

   //Tant qu'on n'a pas extrait toutes les lettres du mot
   while (mot.size() != 0)
   {
      //On choisit un num�ro de lettre au hasard dans le mot
      position = rand() % mot.size();
      //On ajoute la lettre dans le mot m�lang�
      melange += mot[position];
      //On retire cette lettre du mot myst�re
      //Pour ne pas la prendre une deuxi�me fois
        mot.erase(position, 1);
    }

   //On renvoie le mot m�lang�
   return melange;
}

int main()
{
    int nouveauJeu(1), nombreCoup(5);

    ifstream monFlux("C:/Users/Aster/Desktop/C++/Test/dico_perso.txt");  //Ouverture d'un fichier en lecture



    while (nouveauJeu == 1)
   {
    int nombreEssai(0);
    string motMelange, motUtilisateur, motMystere;
    int randMot,j(0);

    randMot = rand() % 26;

    //seekg(ios::beg);

    while (j != randMot)
    {
          getline(monFlux, motMystere); //On lit une ligne compl�te
          j ++;
    }




          //Initialisation des nombres al�atoires
   srand(time(0));

   //1 : On demande de saisir un mot
   //cout << "Saisissez un mot" << endl;
   //cin >> motMystere;

   //2 : On r�cup�re le mot avec les lettres m�lang�es dans motMelange
   motMelange = melangerLettres(motMystere);

   //3 : On demande � l'utilisateur quel est le mot myst�re
   do
   {
      cout << endl << "Quel est ce mot ? " << motMelange << endl;
      cin >> motUtilisateur;

      if (motUtilisateur == motMystere)
      {
         cout << "Bravo !" << endl;
      }
      else
      {
          nombreEssai +=1;
         cout << "Ce n'est pas le mot !" << endl << "Il vous reste " << nombreCoup - nombreEssai << " essais" << endl;
      }
   }while (motUtilisateur != motMystere && nombreEssai < nombreCoup);
   //On recommence tant qu'il n'a pas trouv�

   if (nombreEssai == nombreCoup)
   {
       cout << "La solution etait " << motMystere << endl;
   }


   cout << endl << "Voulez-vous recommencer (1: oui / 2: non)? " << endl;
      cin >> nouveauJeu;
   }


    return 0;
}
