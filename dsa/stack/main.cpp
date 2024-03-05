#include <iostream>
#include "include/Stack.h"

using namespace std;

int main()
{
    Stack stk(3);
    stk.push(10);
    stk.push(20);
    stk.push(30);

    cout << stk.isFull() << endl;
    cout << "peek : " << stk.peek() << endl;
    //stk.pop();
    cout << stk.isFull() << endl;
    cout << "**********************" << endl;
    stk.display();

    cout << stk.reverseSubwords("abc d efg xy") << endl;
    cout << stk.reverseNum(1234) << endl;

    Stack stkParentheses(1,'a');

    cout << "Is valid parenthese : " << stkParentheses.isValid("([])") << endl;
    cout << "Is valid parenthese : " << stkParentheses.isValid("([})") << endl;

    stkParentheses.removeDuplicates("abbaca");

    return 0;
}
