#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    int sizeArr = 4;
    int valueToDel = 0;

    Vector v(sizeArr);

    for(int i = 0; i < sizeArr; ++i){
        v.set(i,i);
    }

    v.print();

    std::cout << "*********************************" << std::endl;

    //cout << v.find(5) << " " << v.find(55);

    v.pushBack(4);

    v.print();

    std::cout << "*********************************" << std::endl;

    v.pushBack(23);

    //v.print();

    v.pushBack(3);
    v.pushBack(9);
    v.pushBack(3);

    //v.insert(2,7);

    //v.rightRotate();

    //v.print();

    //v.leftRotate();

    //v.print();

    //v.rightRotate(2);

    cout << "get size array : " << v.getSizeArray() << endl;

    valueToDel = v.pop(2);

    cout << "value deleted : " << valueToDel << endl;

    cout << "get size array : " << v.getSizeArray() << endl;

    v.print();

    cout << "find transposition : " << v.findTransposition(3) << endl;

    v.print();

    Vector vString("crash");

    Vector vString2("tiny");

    vString.cprint();
    cout << " " << endl;
    vString2.cprint();

    vString.reverse();
    vString2.reverse();

    vString.cprint();
    cout << " " << endl;
    vString2.cprint();

    v.print();

    return 0;
}
