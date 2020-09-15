#include <iostream>

using namespace std;

int calculer(int a,char sym, int b);

int main()
{
      int a(0), b(0),result(0); //Déclaration des variables utiles
      char sym;
        while(b == 0){

   cout << "Bienvenue dans le programme de calculatrice!\n" << endl;

   cout << "Donnez une valeur pour a : \n"; //On demande le premier nombre
   cin >> a;

   cout << "Entrez symbole: +,-,*,/,%\n"; //On demande symbole
   cin >> sym;

   cout << "Donnez une valeur pour b : "; //On demande le deuxième nombre
   cin >> b;
        }
   result = calculer(a,sym,b);
   cout << "le resultat est " << result;

   return 0;
}
