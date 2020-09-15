#include <iostream>
#include <fstream>
#include <string>
using namespace std;


int main()
{
    string const monFichier("dico.txt");
    ofstream monFlux(monFichier.c_str());

    if(monFlux)
    {
        monFlux << "souris" << endl;
        monFlux << "moto" << endl;
        monFlux << "raylle" << endl;
        monFlux << "poisson" << endl;

    }
    else
    {
        cout << "ERREUR: Impossible d'ouvrir le fichier." << endl;
    }

    return 0;
}

