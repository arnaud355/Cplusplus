#include <iostream>
#include <cmath>
#include "ZFraction.h"
using namespace std;

int main()
{
    ZFraction a(4,5);      //Déclare une fraction valant 4/5
    ZFraction b(2);        //Déclare une fraction valant 2/1 (ce qui vaut 2)
    ZFraction c,d,f,j;
    ZFractmath g,h,i;
    int n(0),e(0);          //Déclare deux fractions valant 0
    double z(0);

    c = a+b;               //Calcule 4/5 + 2/1 = 14/5

    d = a*b; //Calcule 4/5 * 2/1 = 8/5

    f = a/b;

    j = a-b;
    g.getNumberAbs(c);
    h.getNumberPow(c);
    i.getNumberSqrt(c);


    cout << a << " + " << b << " = " << c << endl;

    cout << a << " * " << b << " = " << d << endl;

    cout << a << " / " << b << " = " << f << endl;

    cout << a << " - " << b << " = " << j << endl;

    n = c.numerateur();
    e = d.denominateur();
    cout << "le numerateur est" << n << endl;
    cout << "le denominateur est" << e << endl;
    z = c.conversionDecimale();
    cout << "Pour c = " << c << endl;
    cout << z << endl;
    cout << "abs: " << endl;
    g.afficherMath();
    cout << endl;
    cout << "pow: " << endl;
     cout << endl;
    h.afficherMath();
    cout << "sqrt: " << endl;
    cout << endl;
    i.afficherMath();
    if(a > b)
        cout << "a est plus grand que b." << endl;
    else if(a==b)
        cout << "a est egal a b." << endl;
    else
        cout << "a est plus petit que b." << endl;

    return 0;
}

