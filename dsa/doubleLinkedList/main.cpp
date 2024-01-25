#include <iostream>
#include "DoubleLinkedList.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    DoubleLinkedList listDouble;
    listDouble.insertEnd(1);
    listDouble.insertEnd(2);
    listDouble.insertEnd(3);
    listDouble.insertEnd(4);
    listDouble.insertEnd(5);

    listDouble.print();
    listDouble.printReversed();

    cout << "**************************" << endl;

    DoubleLinkedList listDouble2;
    listDouble2.insertEnd(1);
    listDouble2.insertEnd(2);
    listDouble2.insertEnd(5);
    listDouble2.insertEnd(4);
    listDouble2.insertEnd(5);
    listDouble2.insertEnd(4);
    listDouble2.insertEnd(4);

    listDouble2.print();
    cout << "************deleteAllNodesWithKey**************" << endl;
    listDouble2.deleteAllNodesWithKey(5);
    listDouble2.print();

    cout << "************deleteEvenPositions**************" << endl;
    DoubleLinkedList listDouble3;

    listDouble3.insertEnd(1);
    listDouble3.insertEnd(2);
    listDouble3.insertEnd(3);
    listDouble3.insertEnd(4);
    listDouble3.insertEnd(10);
    listDouble3.print();
    cout << "**************************" << endl;
    listDouble3.deleteEvenPositions();
    listDouble3.print();

    cout << "************deleteOddPositions**************" << endl;
    DoubleLinkedList listDouble4;
    listDouble4.insertEnd(1);
    listDouble4.insertEnd(2);
    listDouble4.insertEnd(3);
    listDouble4.insertEnd(4);
    listDouble4.insertEnd(10);
    listDouble4.print();

    listDouble4.deleteOddPositions();
    listDouble4.print();

    cout << "************IsPalindrome**************" << endl;
    DoubleLinkedList listDouble5;
    listDouble5.insertEnd(1);
    listDouble5.insertEnd(2);
    listDouble5.insertEnd(3);
    listDouble5.insertEnd(2);
    listDouble5.insertEnd(1);
    listDouble5.print();
    cout << "**************************" << endl;
    cout << listDouble5.isPalindrome() << endl;
    cout << listDouble5.findMiddle() << endl;

    cout << "***********swap***************" << endl;
    DoubleLinkedList listDouble6;
    listDouble6.insertEnd(6);
    listDouble6.insertEnd(10);
    listDouble6.insertEnd(8);
    listDouble6.insertEnd(15);
    listDouble6.print();
    cout << "**************************" << endl;
    listDouble6.swapForwardWithBackward(2);
    listDouble6.print();

    cout << "***********reverse***************" << endl;
    DoubleLinkedList listDouble7;
    listDouble7.insertEnd(1);
    listDouble7.insertEnd(2);
    listDouble7.insertEnd(3);
    listDouble7.insertEnd(4);
    listDouble7.insertEnd(5);
    listDouble7.print();
    cout << "**************************" << endl;
    listDouble7.reverseAllNodesAddresses();
    listDouble7.print();

    return 0;
}
