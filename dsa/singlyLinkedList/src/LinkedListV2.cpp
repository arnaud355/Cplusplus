#include "../LinkedListV2.h"
#include "../struct.h"
#include <iostream>

LinkedListV2::LinkedListV2(): head(nullptr)
{
    //ctor
}

LinkedListV2::~LinkedListV2()
{
    //dtor
    while(head){
        //Parcourir les noeuds et supprimer tete.
        //Adresse suivante sera la tete, à la fin head = nullptr
        Node* current = head->next;
        delete head;
        head = current;
    }

    this->setLength(0);

}

void LinkedListV2::addElement(int value){

    Node* newNode = new Node(value);
    if(head == nullptr){
        head = newNode;
        head->next = nullptr;
        this->setLength(1);
    }
    else{
        for(Node* cur = head; cur; cur = cur->next){
            if(cur->next == nullptr){
                cur->next = newNode;
                this->setLength(1);
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

Node* LinkedListV2::getTail() const {
    for(Node* cur = head; cur; cur = cur->next){
            if(cur->next == nullptr){
                return cur;
            }
    }
}

int LinkedListV2::getLength() const {
    return length;
}

void LinkedListV2::setLength(int value){

    length = length + value;

    if(length < 0){
        length = 0;
    }
    if(value == 0)
        length = 0;
}

void LinkedListV2::delete_end(){
    if(head != nullptr){
        if(head == this->getTail()){
            delete head;
            head = nullptr;
            this->setLength(0);
        }
        else{
            Node* previous = get_nth(this->getLength() - 1);
            delete previous->next;
            previous->next = nullptr;
            this->setLength(-1);
        }
    }
}

void LinkedListV2::delete_front(){
    if(head != nullptr){
        if(head == this->getTail()){
            delete head;
            head = nullptr;
            this->setLength(0);
        }
        else{
            Node* tempNode = head;
            delete head;
            head = nullptr;
            head = tempNode->next;
            this->setLength(-1);
        }
    }
}

void LinkedListV2::delete_nth(int index){

    if(index > 0 && index <= this->getLength()){
            if(index == 1){
                this->delete_front();
            }
            else if(index == this->getLength()){
                this->delete_end();
            }
            else{
                //hypothese : code sans le prev
                Node* previousNode = get_nth(index - 1);
                Node* tempNode = previousNode->next->next;

                delete previousNode->next;
                previousNode->next = nullptr;

                previousNode->next = tempNode;

                this->setLength(-1);
            }
    }

}

void LinkedListV2::delete_value(int value){

    Node* tempNode = nullptr;

    for(Node* cur = head; cur; cur = cur->next){
        if(cur->next->m_data == value){
            tempNode = cur->next->next;
            delete cur->next;
            cur->next = nullptr;
            cur->next = tempNode;
            this->setLength(-1);
            break;
        }
    }
}

Node* LinkedListV2::get_nth(int n) const {
    int pos = 0;
    for(Node* cur = head; cur; cur = cur->next){
        pos++;
        if(pos == n){
            return cur;
        }
    }
    return nullptr;
}
