#include <iostream>
#include "struct.h"
#include <cassert>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>

LinkedList::LinkedList(): head(nullptr), tail(nullptr) {
    // Constructor implementation
    // Initialize variables or perform necessary setup
}

LinkedList::~LinkedList() {
    // Destructor implementation
    // Perform cleanup, delete allocated memory, etc
    while(head){
        //Parcourir les noeuds et supprimer tete
        // adresse suivante sera la tete, à la fin head = nullptr
        Node* current = head->next;
        delete head;
        head = current;
    }

    delete tail;
    tail = nullptr;
}

void LinkedList::print(){
    // common mistake : corrupt the head node
    Node* tempNode = head;
    if(tempNode == nullptr){
        std::cout << "Pas d elements" << std::endl;
    }
    else {
          while(tempNode != nullptr){
            std::cout << tempNode->m_data << std::endl;
            tempNode = tempNode->next;
        }
    }
}

void LinkedList::insert_end(int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = newNode;
        tail = newNode;
        head->next = tail;
        tail->prev = head;
        length++;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        length++;
    }
}

void LinkedList::insert_front(int value){
    Node* newNode = new Node(value);
    if(head != nullptr){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        length++;
    }
    else{
        head = newNode;
        tail = newNode;
        length++;
    }

}

void LinkedList::insert_value(int value, int pos){
    Node* newNode = new Node(value);
    int idx = 0;
    for(Node* cur = head; cur; cur = cur->next){
        idx++;
        if(pos == idx){
            newNode->next = cur;
            newNode->prev = cur->prev;
            cur->prev->next = newNode;
            length++;
        }
    }
}

void LinkedList::delete_end(){
    Node* tempNode = head;
    while(tempNode != nullptr){
        if(tempNode->next == tail){
            tail->next = nullptr;
            delete tail;
            tail = nullptr;
            tempNode->next = nullptr;
            tail = tempNode;
            length--;
            break;
        }
        tempNode = tempNode->next;
    }
}

void LinkedList::delete_front(){
    if(head != nullptr){
        if(head == tail){
            delete head;
            head = nullptr;
            delete tail;
            tail = nullptr;
            length--;
        }
        else{
            head->next->prev = nullptr;
            delete head;
            head = nullptr;
            head = head->next;
            length--;
        }
    }
}
//If getHead() is a member function that is not declared as const, it cannot be called
//on a const object (like the other parameter, which is a const LinkedList&).
Node* LinkedList::getHead() const {
    return head;
}

Node* LinkedList::getTail() const {
    return tail;
}

int LinkedList::getLength () const {
    return length;
}

Node* LinkedList::get_nth(int n) const {
    int pos = 0;
    for(Node* cur = head; cur; cur = cur->next){
        pos++;
        if(pos == n){
            return cur;
        }
    }
    return nullptr;
}
Node* LinkedList::get_nth_back(int n) const {
    int idx = length - n;
    int pos = length + 1;

    for(Node* cur = tail; cur; cur = cur->prev){
        pos--;
        if(pos == idx){
            return cur;
        }
    }
    return nullptr;
}

int LinkedList::searchItem(int value){
    int pos = 0;
    for(Node* cur = head; cur; cur = cur->next){
        pos++;
        if(value == cur->m_data){
            return pos;
        }
    }
    return -1;
}

int LinkedList::searchItemImproved(int value){
    int pos = 0;
    int temp = 0;

    for(Node* cur = tail; cur; cur = cur->prev){
        pos++;
        if(value == cur->m_data){
            if(cur->prev != nullptr){
                temp = cur->m_data;
                cur->m_data = cur->prev->m_data;
                cur->prev->m_data = temp;
            }

            return pos;
        }
    }
    return -1;
}

/*
// Another way with keeping the previous
int LinkedList::searchItemImproved(int value){
    int pos = 0;
    Node* previous = nullptr;

    for(Node* cur = head; cur; cur = cur->next){
        pos++;
        if(value == cur->m_data){
            if(previous != nullptr){
                return pos;
            swap(previous->m_data, cur->m_data);
            return pos - 1;
            }

            previous = cur;
        }
    }
    return -1;
}
*/

bool LinkedList::isSame(const LinkedList& other){
    // Adresse n as pas d intelligence, il faut une fleche pour pointer depuis l adresse.
    // Avec une reference sur l adresse on peut utiliser le point.
    if (this->getHead() == nullptr || other.getHead() == nullptr) {
            return false;
        }
    bool same = true;
    Node* nodeIndex = other.getHead();

    for(Node* cur = this->getHead(); cur; cur = cur->next){
        for(Node* cur2 = nodeIndex; cur2; cur2 = cur2->next){
            if(cur->m_data != cur2->m_data){
                same = false;
                std::cout << "les 2 chaines ne sont pas les memes" << std::endl;
                return false;
            }
            else{
                nodeIndex = nodeIndex->next;
                break;
            }
        }
    }

    if(same){
        std::cout << "les 2 chaines sont les memes" << std::endl;
        return true;
    }

    std::cout << "les 2 chaines ne sont pas les memes" << std::endl;
    return false;
    /* other way
    Node* h1 = head, *h2 = other.head;

    while(h1 && h2){
        if(h1->m_data != h2->m_data)
            return false;
        h1 = h1->next, h2 = h2->next;
    }
    //make sure both ends together
    //h1 et h2 sont à nullptr, leurs contraire doit être vrai
    return !h1 && !h2;
    */
}

bool LinkedList::isSameAndLength(const LinkedList& other){
    // Adresse n as pas d intelligence, il faut une fleche pour pointer depuis l adresse.
    // Avec une reference sur l adresse on peut utiliser le point.
    if (this->getHead() == nullptr || other.getHead() == nullptr) {
            return false;
        }

    if(this->getLength() == other.getLength()){
        bool same = true;

        Node* nodeIndex = other.getHead();

        for(Node* cur = this->getHead(); cur; cur = cur->next){
            for(Node* cur2 = nodeIndex; cur2; cur2 = cur2->next){
                if(cur->m_data != cur2->m_data){
                    same = false;
                    std::cout << "les 2 chaines ne sont pas les memes" << std::endl;
                    return false;
                }
                else{
                    nodeIndex = nodeIndex->next;
                    break;
                }
            }
        }

         if(same){
            std::cout << "les 2 chaines sont les memes" << std::endl;
            return true;
        }
    }
    else{
        std::cout << "Pas la meme longueur de liste" << std::endl;
        return false;
    }

    return false;
}

void print1(Node* head){
    std::cout << "with for loop : " << std::endl;
    for (Node* cur = head; cur; cur = cur->next ) {
        std::cout << cur->m_data << std::endl;
    }
     std::cout << "*****************" << std::endl;
    /*
    Node* cur = head;
    while(cur != nullptr){
        std::cout << cur->m_data << std::endl;
        cur = cur->next;
    }*/
}

void reversePrint1(Node* tail){

    if(tail == nullptr || tail->prev == nullptr){
        std::cout << "Vous etes au premier noeud " << std::endl;
    }
    else {
        std::cout << "with reverse for loop : " << std::endl;
        for (Node* cur = tail; cur; cur = cur->prev ) {
            std::cout << cur->m_data << std::endl;
        }
    }

     std::cout << "*****************" << std::endl;
    /*
    Node* cur = head;
    while(cur != nullptr){
        std::cout << cur->m_data << std::endl;
        cur = cur->next;
    }*/
}

int find(Node* startNode, int value){

     while(startNode != nullptr){
         if(startNode->m_data == value){
             break;
        }

        startNode = startNode->next;
    }

    return startNode->m_data;

}

void print3(Node* head){
    if(head == nullptr)
        return;
    //en appelant la fonction elle même avant l'affichage les variables sont copiées à la suite
    print3(head->next);
    std::cout << head->m_data << std::endl;
}


//with a factorial function it s O(n) and not O(!n)
Node* printNodeF(Node* head){
    if(head == nullptr)
        return nullptr;

     std::cout << head->m_data << std::endl;
     head = printNodeF(head->next);
     return head;
}

Node* printNodeFReversed(Node* tail){
    if(tail == nullptr)
        return nullptr;

     std::cout << tail->m_data << std::endl;
     tail = printNodeFReversed(tail->prev);
     return tail;
}

/*
void LinkedList::debugVerifyDataIntegrity(){
    if(length == 0){
        //avec assert si expression est fausse arret programme et message alerte
        assert(head == nullptr);
        assert(tail == nullptr);
    }else{
        assert(head != nullptr);
        assert(tail != nullptr);
        if(length == 1)
            assert(head == tail);
        else
            assert(head != tail);
        assert(!tail->next);
    }
    int len = 0;
    for(Node* cur = head; cur; cur = cur->next, len++){
        assert(len < 10000); // avoid circle list
    }
    assert(length == len);
    //assert(length == (int)debug_data.size());
}

std::string LinkedList::debugToString(){
    if(length == 0)
        return "";
    std::ostringstream oss;
    for(Node* cur = head; cur; cur = cur->next){
        oss << cur->m_data;
        if(cur->next)
            oss << " ";
    }
    return oss.str();
}

void test1(){
    std::cout << "\ntest1\n";
    LinkedList listTest;
    listTest.insert_end(1);
    listTest.insert_end(2);
    listTest.insert_end(3);
    listTest.insert_end(4);

    listTest.print();

    std::string expected = "1 2 3 4";
    std::string result = listTest.debugToString();
    if(expected != result){
        std::cout << "no match: expected : " << expected << "\nresult : " << result << "\n";
        assert(false);
    }
    //listTest.debugPrintList("***********");
}

void LinkedList::debugPrintList(std::string msg = ""){
    if(msg != "")
        std::cout << msg << "\n";
    for(int i = 0; i < (int)m_debug_data.size(); ++i)
        //debugPrintNode(m_debug_data[i]);
    std::cout << "*************\n" << std::flush;
}
void LinkedList::debugPrintNode(Node* node, bool isSeparate = false){
    if(isSeparate)
        std::cout << "Sep: ";
    if(node == nullptr){
        std::cout << "nullptr\n";
        return;
    }

    std::cout << node->m_data << " ";
    if(node->next == nullptr)
        std::cout << "X ";
    else
        std::cout << node->next->m_data << " ";

    if(node == head)
        std::cout << "head\n";
    else if(node == tail)
        std::cout << "tail\n";
    else
        std::cout << "\n";
}

void LinkedList::debug_add_node(Node* node){
    m_debug_data.push_back(node);
}


void LinkedList::debug_remove_node(Node* node){
    auto it = std::find(m_debug_data.begin(), m_debug_data.end(), node);
    if(it == m_debug_data.end())
        std::cout << "Node does not exists\n";
    else
        m_debug_data.erase(it);
}
*/
Node* f(Node* cur) {
	if (cur && cur->next) {
		Node* rem = f(cur->next);
		rem->next = cur;
		cur->next = nullptr;
	}
	std::cout << cur->m_data << std::endl;
	return cur;
}
void factorial(Node* head, Node* tail) {
    f(head);
	std::swap(head, tail);
}
