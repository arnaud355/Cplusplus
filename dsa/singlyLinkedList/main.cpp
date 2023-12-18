#include <iostream>
#include "struct.h"
#include "LinkedListV2.h"
#include <vector>

using namespace std;

int main()
{
    cout << "Hello linked list!" << endl;
/*
    //create 4 objects and set data
    Node* node1 = new Node(20);
    Node* node2 = new Node(21);
    Node* node3 = new Node(22);
    Node* node4 = new Node(23);


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
*/
    LinkedList linkedlist;
    LinkedList linkedlist2;
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
    linkedlist.insert_value(16, 3);
    linkedlist.insert_front(6);
    linkedlist.insert_front(5);

    linkedlist2.insert_front(5);
    linkedlist2.insert_end(6);
    linkedlist2.insert_end(7);
    linkedlist2.insert_end(16);
    linkedlist2.insert_end(10);
    linkedlist2.insert_end(9);
    linkedlist2.insert_end(12);
    linkedlist2.insert_end(11);

    linkedlist.print();
    cout << "taille liste : " << linkedlist.getLength() << endl;
    //linkedlist.delete_front();
    linkedlist.print();
    cout << "taille liste : " << linkedlist.getLength() << endl;

    /*
    LinkedList myNodesList;
    myNodesList.debug_add_node(node1);
    myNodesList.debug_add_node(node2);
    myNodesList.debug_add_node(node3);
    myNodesList.debug_add_node(node4);
    myNodesList.debugPrintList("Affichage de ma liste de noeuds");
    test1();

    //vector<Node*> debug_data;
    */

    Node* nodeGetNthBack = linkedlist.get_nth_back(3);
    cout << "get nth back: " << nodeGetNthBack->m_data << endl;
    linkedlist.print();
    cout << "taille liste 1: " << linkedlist.getLength() << endl;
    cout << "taille liste 2: " << linkedlist2.getLength() << endl;

    cout << "affiche liste 1 : " << endl;
    linkedlist.print();
    cout << "affiche liste 2 : " << endl;
    linkedlist2.print();
    cout << "est elle la meme tete : " << linkedlist.isSame(linkedlist2) << endl;
    cout << "est elle la meme tete et meme longueur 5 : " << linkedlist.isSameAndLength(linkedlist2) << endl;;

    LinkedListV2 linkedListv2;
    linkedListv2.addElement(30);
    linkedListv2.addElement(31);
    linkedListv2.addElement(32);
    linkedListv2.addElement(33);
    linkedListv2.addElement(34);

    linkedListv2.print();

    Node* nodeTail = linkedListv2.getTail();
    cout << "node tail : " << nodeTail->m_data << endl;

    return 0;
}
