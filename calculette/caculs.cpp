#include <iostream>

using namespace std;

int calculer(int a,char sym, int b){

        int result(0);

        switch(sym){
            case '+' : result = a + b;
            break;

            case '-': result = a - b;
            break;

            case '*' : result = a * b;
            break;

            case '/': result = a / b;
            break;

            case '%': result = a % b;
            break;

            default:
                cout << "il n y a rien!";
            break;
        }

        return result;
 }
