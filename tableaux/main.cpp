#include <iostream>
#include <vector>

using namespace std;

int main()
{

    int somme(0), moyenne(0), tailleTab(0);
    vector<int>tab;

    tab.push_back(12);
    tab.push_back(19);
    tab.push_back(14);
    tab.push_back(12);

    tailleTab = tab.size();

    for(int i(0); i<tailleTab; i++){
        somme += tab[i];
    }

    moyenne = somme / tailleTab;

    cout << moyenne << endl;

    return 0;
}
