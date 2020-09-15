#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <vector>

using namespace std;

string ScrambleWord(string mot)
{
    int Position;

    string scrambled;

    while(mot.size()>0)
    {
        Position = rand() % mot.size();
        scrambled += mot[Position];
        mot.erase(Position,1);
    }

    return scrambled;

}


int main()
{

    // déclaration et initialisation des variables

    srand(time(0));
    string mystery, scrambled, guess, answer, w;
    int AttemptsLeft, WordCount(0);
    double WordPosition(0);
    ifstream Dico("dico.txt");

    if (Dico)
    {
        vector<string> WordList(0);

        while(getline(Dico, w))
        {
            WordCount++;
            WordList.push_back(w);
        }
        Dico.ignore();



        do
        {
            // 1: choix du mot

            WordPosition = rand() % WordCount;

            mystery = WordList[WordPosition];

            // 2: on mélange les lettres du mot

            scrambled = ScrambleWord(mystery);

            // 3: on demande le mot mystère

            AttemptsLeft = 5; //on réinitialise le compteur à chaque nouvelle partie

            cout << "Mystery word: " << mystery << endl;

            do
            {
                cout << "Il vous reste " << AttemptsLeft << " essais" << endl;
                cout << "Quel est ce mot? : " << endl;
                cout << scrambled << endl;
                cin >> guess;
                AttemptsLeft--; // le compteur est décrémenté à chaque essai
            }while (guess != mystery && AttemptsLeft > 0);

            /* au cas où la personne serait arrivée au bout des cinq essais,
            il faut tester la dernière réponse pour décider du message à afficher*/

            if (guess == mystery)
            {
                cout << "Vous avez gagné!" << endl;
            }
            else
            {
                cout << "Vous avez perdu. Le mot était " << mystery << endl;
            }
            cout << "Voulez-vous rejouer? (y/n)" << endl;
            cin >> answer;
        }while(answer=="y");
    }
    else
    {
        cout << "Error opening dico.txt" << endl;
    }

    return 0;
}
