#include <iostream>
#include "struct.h"

using namespace std;

int main()
{
    cout << "Hello linked list!" << endl;

    //create 4 objects and set data
    Node* node1 = new Node(6);
    Node* node2 = new Node(10);
    Node* node3 = new Node(8);
    Node* node4 = new Node(15);


    //set 4 links
    node1->next = node2; //1-2 link
    node2->next = node3; //2-3 link
    node3->next = node4; //3-4 link
    node4->next = nullptr; //4-E link

    //set 4 links for prev
    node4->prev = node3; //1-2 link
    node3->prev = node2; //2-3 link
    node2->prev = node1; //3-4 link
    node1->prev = nullptr; //3-4 link

    print1(node1);
    printNodeF(node1);
    cout << "***************" << endl;
    printNodeFReversed(node4);

    cout << "***************" << endl;
    cout << "node to find 8 : " << find(node1, 8) << endl;
    cout << "***************" << endl;

    //cout << sizeof(node1) << endl;

    return 0;
}
