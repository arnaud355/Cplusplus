#include <iostream>
#include "Stack.h"

using namespace std;

int main()
{
    Stack stk(3);
    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << stk.isFull() << endl;
    cout << stk.peek() << endl;
    stk.pop();
    cout << stk.isFull() << endl;

    return 0;
}
