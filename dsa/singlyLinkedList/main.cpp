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
    linkedListv2.addElement(35);

    linkedListv2.print();

    Node* nodeTail = linkedListv2.getTail();
    cout << "node tail : " << nodeTail->m_data << endl;
    cout << "taille liste : " << linkedListv2.getLength() << endl;

    linkedListv2.delete_end();
    linkedListv2.print();
    cout << "taille liste : " << linkedListv2.getLength() << endl;

    linkedListv2.delete_front();
    linkedListv2.print();
    cout << "taille liste : " << linkedListv2.getLength() << endl;

    linkedListv2.delete_nth(3);
    linkedListv2.print();
    cout << "taille liste : " << linkedListv2.getLength() << endl;

    linkedListv2.delete_value(32);
    linkedListv2.print();
    cout << "taille liste : " << linkedListv2.getLength() << endl;


    //create 5 objects and set data
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);


    //set 4 links
    node1->next = node2; //1-2 link
    node2->next = node3; //2-3 link
    node3->next = node4; //3-4 link
    node4->next = node5; //4-E link
    node5->next = nullptr;

    factorial(node1,node5);


    LinkedListV2 linkedList3;
    linkedList3.addElement(1);
    linkedList3.addElement(2);
    linkedList3.addElement(3);
    linkedList3.addElement(4);
    linkedList3.addElement(2);
    linkedList3.addElement(6);
    cout << "*****************************" << endl;
    linkedList3.print();
    cout << "taille liste" << linkedList3.getLength() << endl;

    linkedList3.delete_node_with_key(2);
    linkedList3.print();
    cout << "taille liste : " << linkedList3.getLength() << endl;
    cout << "*****************************" << endl;
    linkedList3.swap_pairs();
    linkedList3.print();
    cout << "taille liste : " << linkedList3.getLength() << endl;
    cout << "*****************************" << endl;
    linkedList3.print();
    cout << "************Inversed addresses*****************" << endl;
    linkedList3.reverseListNodes();
    linkedList3.print();
    // 31246  -> 64213
    cout << "*****************************" << endl;
    LinkedListV2 linkedList4;
    linkedList4.addElement(1);
    linkedList4.addElement(2);
    linkedList4.addElement(3);
    linkedList4.addElement(4);
    linkedList4.addElement(5);
    linkedList4.addElement(6);
    linkedList4.print();
    cout << "taille liste " << linkedList4.getLength() << endl;
    cout << "*****************************" << endl;
    linkedList4.deleteEvenPos();
    linkedList4.print();
    cout << "taille liste " << linkedList4.getLength() << endl;

    cout << "*****************************" << endl;
    LinkedListV2 linkedList5;

    linkedList5.insertSorted(10);
    linkedList5.insertSorted(2);
    linkedList5.insertSorted(4);
    //linkedList5.print();
    //linkedList5.insertSorted(3);
    //linkedList5.insertSorted(1);

    cout << "*****************************" << endl;
    linkedList5.print();

    cout << "*****************************" << endl;
    LinkedListV2 linkedList6;
    linkedList6.addElement(6);
    linkedList6.addElement(10);
    linkedList6.addElement(8);
    linkedList6.addElement(15);
    linkedList6.print();
    linkedList6.swapHeadAndTail();
    cout << "*****************************" << endl;
    linkedList6.print();
    cout << "*****************************" << endl;
    linkedList6.leftRotate(2);
    linkedList6.print();

    cout << "*****************************" << endl;
    LinkedListV2 linkedList7;
    linkedList7.addElement(1);
    linkedList7.addElement(2);
    linkedList7.addElement(1);
    linkedList7.addElement(5);
    linkedList7.addElement(3);
    linkedList7.addElement(2);
    linkedList7.addElement(4);
    linkedList7.addElement(3);
    linkedList7.addElement(5);
    linkedList7.addElement(2);
    linkedList7.print();
    cout << "***********Remove duplicates******************" << endl;
    linkedList7.removeDuplicates();
    linkedList7.print();

    cout << "*****************************" << endl;
    LinkedListV2 linkedList8;
    linkedList8.addElement(1);
    linkedList8.addElement(2);
    linkedList8.addElement(3);
    linkedList8.addElement(4);
    linkedList8.addElement(1);
    linkedList8.print();
    cout << "*****************************" << endl;
    linkedList8.removeLastOccurence(1);
    linkedList8.print();

    cout << "*****************************" << endl;
    LinkedListV2 linkedList9;
    linkedList9.addElement(5);
    linkedList9.addElement(1);
    linkedList9.addElement(2);
    linkedList9.addElement(5);
    linkedList9.addElement(3);
    linkedList9.print();
    cout << "*****************************" << endl;
    linkedList9.moveBack(5);
    linkedList9.print();
    cout << "*************list10****************" << endl;
    LinkedListV2 linkedList10;
    linkedList10.addElement(2);
    linkedList10.addElement(7);
    linkedList10.addElement(15);
    linkedList10.addElement(1);
    linkedList10.addElement(2);
    linkedList10.moveBack(2);
    linkedList10.print();
    //cout << "max value : " << linkedList10.maxValue(linkedList10.getHead(), true) << endl;
    cout << "max value : " << linkedList10.maxValue(linkedList10.getHead()) << endl;

    cout << "*************list11****************" << endl;
    LinkedListV2 linkedList11;
    linkedList11.addElement(10);
    linkedList11.addElement(20);
    linkedList11.addElement(3);
    linkedList11.addElement(7);
    linkedList11.addElement(15);
    linkedList11.print();

    //linkedList11.arrangeOddAndEven();
    //10,3,15,20,7
    linkedList11.print();
    cout << "*************list12 and list13****************" << endl;
    LinkedListV2 linkedList12;
    LinkedListV2 linkedList13;

    linkedList12.addElement(1);
    linkedList12.addElement(3);
    //linkedList12.addElement(5);
    //linkedList12.addElement(7);

    linkedList13.addElement(2);
    linkedList13.addElement(4);
    linkedList13.addElement(6);
    linkedList13.addElement(8);

    linkedList12.print();
    cout << "*****************************" << endl;
    linkedList12.insertAlternate(linkedList13);
    linkedList12.print();

    cout << "*****************************" << endl;
    LinkedListV2 linkedList14;
    LinkedListV2 linkedList15;

    linkedList14.addElement(1);
    linkedList14.addElement(2);
    linkedList14.addElement(3);

    linkedList15.addElement(4);
    linkedList15.addElement(5);
    linkedList15.addElement(3);

    linkedList14.addNumber(linkedList15);

    return 0;
}
