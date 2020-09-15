#include <iostream>
#include "Duree.h"

using namespace std;

int main()
{
    Duree duree1(2, 25, 28), duree2(0, 16, 33);
    Duree A(10,50,28),B(8,25,35),result;

    result = A - B;
    cout << A << " - " << B << " = " << result << endl;

    cout << duree1 << " et " << duree2 << endl;

    return 0;
}



