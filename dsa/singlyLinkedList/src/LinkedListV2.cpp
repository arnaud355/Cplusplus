#include "../LinkedListV2.h"
#include <iostream>

LinkedListV2::LinkedListV2(): head(nullptr)
{
    //ctor
}

LinkedListV2::~LinkedListV2()
{
    //dtor
    delete head;
    head = nullptr;
}

void LinkedListV2::addElement(int value){

    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        head->next = nullptr;
    }
    else{
        for(Node* cur = head; cur; cur = cur->next){
            if(cur->next == nullptr){
                cur->next = newNode;
                break;
            }
        }
    }
}

void LinkedListV2::print(){

    if(head == nullptr){
        std::cout << "Pas d elements" << std::endl;
    }
    else{
        for(Node* cur = head; cur; cur = cur->next){
            std::cout << cur->m_data << std::endl;
        }
    }
}

Node* LinkedListV2::getTail(){
    for(Node* cur = head; cur; cur = cur->next){
            if(cur->next == nullptr){
                return cur;
            }
    }
}
