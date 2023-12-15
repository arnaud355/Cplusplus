#include <iostream>
#include "struct.h"

LinkedList::LinkedList(): head(nullptr), tail(nullptr) {
    // Constructor implementation
    // Initialize variables or perform necessary setup
}

LinkedList::~LinkedList() {
    // Destructor implementation
    // Perform cleanup, delete allocated memory, etc
    delete head;
    head = nullptr;

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
        length++;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
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
            tail = nullptr;
            tempNode->next = nullptr;
            tail = tempNode;
            length--;
            break;
        }
        tempNode = tempNode->next;
    }
}

Node* LinkedList::getHead(){
    return head;
}

Node* LinkedList::getTail(){
    return tail;
}

int LinkedList::getLength (){
    return length;
}

Node* LinkedList::get_nth(int n){
    int pos = 0;
    for(Node* cur = head; cur; cur = cur->next){
        pos++;
        if(pos == n){
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

void LinkedList::debugVerifyDataIntegrety(){
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
    assert(length == (int)debug_data.size());
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
