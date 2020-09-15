#include <iostream>
#include <string>
#include "personnages.h" //Ne pas oublier


using namespace std;

int main()
{
    Personnage david, goliath("epee aiguis�e",20), spartacus("glaive",15);
    //Cr�ation de 2 objets de type Personnage : david et goliath
    do{
        goliath.attaquer(david); //goliath attaque david
        david.boirePotionDeVie(20); //david r�cup�re 20 de vie en buvant une potion
        goliath.attaquer(david); //goliath r�attaque david
        spartacus.attaquer(goliath);
        david.attaquer(goliath); //david contre-attaque... c'est assez clair non ?
        goliath.changerArme("Double hache tranchante v�n�neuse de la mort", 40);
        goliath.attaquer(spartacus);
        goliath.attaquer(david);
        spartacus.boirePotionDeVie(20);
        spartacus.changerArme("Double glaive de la mort",35);
        spartacus.attaquer(goliath);

        cout << "David" << endl;
        david.afficherEtat();
         cout << "Spartacus" << endl;
         spartacus.afficherEtat();
        cout << "Goliath" << endl;
        goliath.afficherEtat();
    }while(goliath.estVivant() && (david.estVivant() || spartacus.estVivant()));

    cout << "David : ";
     david.afficherVie();
    std::cout << std::endl;

    cout << "Spartacus : ";
    spartacus.afficherVie();
    std::cout << std::endl;

    cout << "Goliath : ";
    goliath.afficherVie();
    std::cout << std::endl;

    return 0;
}
