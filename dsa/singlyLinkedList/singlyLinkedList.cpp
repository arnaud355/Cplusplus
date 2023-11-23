#include <iostream>
#include "struct.h"

void print(){
    Node* temp_head = head;
    while(temp_head != nullptr){
        std::cout << temp_head->m_data << std::endl;
        temp_head = temp_head->next;
    }
}

void insert_end(int value){
    if(head == nullptr){

    }
}

void print1(Node* head){

    /*for (head != nullptr, head->next ) {
        node->m_data;
    }*/
    while(head != nullptr){
        std::cout << head->m_data << std::endl;
        head = head->next;
    }
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
