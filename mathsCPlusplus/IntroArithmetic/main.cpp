#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    //round arrondi vers le plus proche
    cout << "round of 6.283 : " << round(6.283) << endl; //6

    //floor arrondi vers le plus bas
    cout << "floor of 6.283 : " << floor(6.283) << endl; //6

    //ceil arrondi vers le plus haut
    cout << "ceil of 6.283 : " << ceil(6.283)  << endl; //7

    //pas d effet sur un int passé en parametre
    cout << "round of 1 : " << round(1) << endl; //1
    cout << "floor of 1 : " << floor(1) << endl; //1
    cout << "ceil of 1 : " << ceil(1) << endl; //1

    cout << "round of 2 : " << round(2) << endl; //2
    cout << "floor of 2 : " << floor(2) << endl; //2
    cout << "ceil of 2 : " << ceil(2) << endl; //2

    //modulo
    cout << "modulo  : 84 % 30 : " << 84 % 30 << endl; //24
    cout << "modulo  : 5 % 5 : " << 5 % 5 << endl; //0
    cout << "modulo  : 5 % 10 : " << 5 % 10 << endl; //lui-meme : 5, le premier de l operation


    return 0;
}
