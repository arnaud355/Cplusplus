#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <fstream>

using namespace std;

void litMotMystere(string& mot);                               // Lit un mot mystere au hasard dans le fichier dico.txt
void melangeMot(string& motMel,string const& motMys);         // Melange les lettres du mot mystere
void saisieMotPropose(string& motPro,string const& motMel);   // Saisie du mot propose par le joueur
bool compareMots(string& motPro,string const& motMys);        // Comparaison du mot propose et du mot mystere

int main()
    {
     string motMystere(" "), motMelange("aaaa "), motPropose(" ");  // mot a trouver, mot melange, mot propose par le joueur
     bool trouve(false);                                            // booleen solution trouve ou non
     char reponse('O');                                             // Reponse a la question une autre partie
     int const nombreCoupMaxi(5);                                   // nombre de coup maximum fixe a 5
     int coupEnCours(0);                                            // numero de la tentative en cours

     srand(time(0));                                                // initialisation de la generation des nombres aleatoires

     while(reponse == 'o' || reponse == 'O')
        {
         litMotMystere(motMystere);                              // on lit un mot au hasard dans le fichier dico
         melangeMot(motMelange, motMystere);                    // On mélange les lettres du mot mystere

    // On demande à l'utilisateur quel est le mot mystère jusqu'a ce qu il trouve

        trouve = false;
        coupEnCours = 0;

        while ((!trouve) && (coupEnCours < nombreCoupMaxi))
            {
             saisieMotPropose(motPropose,motMelange);                // Saisie de la proposition du joueur

             trouve = compareMots(motPropose,motMystere);            // Comparaison de motPropose et motMystere on affecte le booleen

             if (!trouve)                                            // le mot n a pas ete trouve
                {
                coupEnCours++;                                           // On incremente le nombre d'essai
                cout << "Non ce n'est pas le bon mot !!! il vous reste "<< (nombreCoupMaxi - coupEnCours) << " essais" << endl << endl;
                }
            }                                                       // le mot a ete trouve donc on sort car trouve est a vrai

        if (trouve)
        {
        cout << "BRAVO VOUS AVEZ TROUVE !" << endl <<endl;          // Le mot a ete trouve
        }
        else                                                        // Le nombre maxi d essais a ete atteind
        {
        cout << "DESOLE MAIS VOUS AVEZ PERDU : LE MOT A TROUVER ETAIT : " << motMystere << endl << endl;
        }

        cout << "UNE AUTRE PARTIE ? O/N : ";
        cin >> reponse;
        cin.ignore();
        cout << endl << endl;
        }

     return 0;
    }

void litMotMystere(string& mot)
    {
     ifstream monFichier("dico.txt");                      // Creation d un flux sur dico.txt
     int nombreDeMots(0), positionMotChoisi(0);            // Taille du fichier en mots et position du mot choisi dans le fichier
     string ligne(" ");                                    // Variable pour lecture du fichier

     if(monFichier)
        {                                                               // ouverture du fichier OK
         while(getline(monFichier, ligne))                               // on compte le nombre de mots dans le fichier
            {
            nombreDeMots++;
            }

        positionMotChoisi = rand() % nombreDeMots;                      // on genere un nombre aléatoire en fonction du nombre de mots

        monFichier.clear();                                             // je remet les flags fichiers à 0
        monFichier.seekg(0, ios::beg);                                  // ON se replace au debut du fichier

        for (int i(0); i < positionMotChoisi; i++)                     // on lit le fichier jusqu'au mot choisi
            {
            getline(monFichier, mot);
            }
        monFichier.close();                                             // Comme on va ouvrir le fichier a chaque appel de la fonction
                                                                        // il est necessaire de le fermer manuellement
        }
     else                                                               // probleme d ouverture
        {
        cout << "ERREUR: Impossible d'ouvrir le fichier" << endl;
        }
    }

void melangeMot(string& motMel,string const& motMys)
    {
    string mot(motMys);                              // motMys est une constante on ne pourra pas lui enlever de lettres
    int position(0);

    motMel = motMys;                                // initialisation de la longueur de motMel

    for (int i(0); i < motMys.size(); i++)
        {
         position = rand() % mot.size();
         motMel[i] = mot[position];
         mot.erase(position, 1);
        }
    }

void saisieMotPropose(string& motPro,string const& motMel)
    {
    cout << "Quel est ce mot ? " << motMel << endl;     // Affichage de la demande avec le mot melange
    getline(cin, motPro);                               // Saisie du mot propose

    for (int i(0) ; motPro[i] != '\0' ; i++)            // Mise en majuscules du mot propose car le dico ne contient que des majuscules
        {
        motPro[i] = toupper(motPro[i]);
        }

    cout << endl;
    }

bool compareMots(string& motPro,string const& motMys)
    {
     bool resultat(true);

     if (motPro.size() == motMys.size())              // Le mot propose fait il la meme longueur que la mot mystere ?
            {
            for (int i(0); i < motPro.size(); i++)    // On test lettre par lettre
                {
                if (motPro[i] != motMys[i])           // Si il y a une difference
                    {
                    resultat = false;                 // alors le resultat est faux
                    }
                }
            }
       else                                           // Pas la meme longueur
            {
            resultat = false;                           // donc faux
            }

     return resultat;
    }
