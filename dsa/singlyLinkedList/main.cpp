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
    reversePrint1(node4);
    printNodeF(node1);
    cout << "***************" << endl;
    printNodeFReversed(node4);

    cout << "***************" << endl;
    cout << "node to find 8 : " << find(node1, 8) << endl;
    cout << "***************" << endl;

    //cout << sizeof(node1) << endl;

    LinkedList linkedlist;
    linkedlist.print();
    cout << "taille liste : " << linkedlist.getLength() << endl;
    linkedlist.insert_end(7);
    linkedlist.insert_end(9);
    linkedlist.insert_end(10);
    linkedlist.print();
    linkedlist.insert_end(12);
    cout << "***************" << endl;
    linkedlist.print();
    cout << "taille liste : " << linkedlist.getLength() << endl;
    //linkedlist.delete_end();
    linkedlist.insert_end(11);
    linkedlist.print();
    cout << "taille liste : " << linkedlist.getLength() << endl;

    Node* nodeGetNth = linkedlist.get_nth(3);
    cout << "get nth : " << nodeGetNth->m_data << endl;
    cout << "search item : " << linkedlist.searchItem(9) << endl;
    cout << "search item : " << linkedlist.searchItem(15) << endl;
    cout << "search item improved : " << linkedlist.searchItemImproved(10) << endl;

    linkedlist.insert_value(8, 2);
    linkedlist.print();
    cout << "taille liste : " << linkedlist.getLength() << endl;
    return 0;
}
