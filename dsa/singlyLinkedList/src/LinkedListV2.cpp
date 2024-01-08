#include "../LinkedListV2.h"
#include "../struct.h"
#include <iostream>
#include <list>

LinkedListV2::LinkedListV2(): head(nullptr), tail(nullptr)
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

    delete tail;
    tail = nullptr;

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
                newNode->next = nullptr;
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

    return nullptr;
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
//delete the first node meet with the value
void LinkedListV2::delete_node_with_key(int value){
    bool oneVal = false;
    int pos = 0;

    if(head != nullptr){
        for(Node* cur = head; cur; cur = cur->next){
                pos++;
                if(cur->m_data == value && !oneVal){
                    if(pos == 1){
                        this->delete_front();
                        oneVal = true;
                    }
                    else if (pos == this->getLength()){
                        this->delete_end();
                        oneVal = true;
                    }
                    else{
                        this->delete_value(value);
                        oneVal = true;
                    }
                }
        }
    }
}

void LinkedListV2::swap_pairs(){
    int temp = 0;
    int index = 1;

    if(this->getLength() > 1){
        for(Node* cur = head; cur; cur = cur->next){
            if(index % 2 != 0 && cur != nullptr && cur->next != nullptr){
                temp = cur->m_data;
                cur->m_data = cur->next->m_data;
                cur->next->m_data = temp;
            }
            index++;
        }
    }
}

void LinkedListV2::printNodesAddresses(){
    if(head == nullptr){
        std::cout << "Pas d elements" << std::endl;
    }
    else{
        for(Node* cur = head; cur; cur = cur->next){
            std::cout << "addresse du noeud :" << cur << std::endl;
        }
    }
}

void LinkedListV2::reverseListNodes(){
    //int i = 1;
    int j = this->getLength();
    Node* previous = nullptr;
    Node* cur = nullptr;

    Node* lastNode = this->getTail();
    //Attention de ne pas appeler de maniere circulaire les noeuds
    while(j >= 2){
        cur = this->get_nth(j);

        previous = this->get_nth(j - 1);
        cur->next = previous;
        previous->next = nullptr;
        j--;
    }

    head = lastNode;
     /*if(this->getLength() > 1){
            while(i < j){

                curLast = this->get_nth(j);

                tempNode = curFirst;
                curFirst = curLast;
                curLast = tempNode;

                curFirst =  curFirst->next;

                i++;
                j--;
            }
    }*/
}
//delete valeur aux positions paires (pas les valeurs)
void LinkedListV2::deleteEvenPos(){
    int i = 1;

    for(Node* cur = head; cur; cur = cur->next){
            std::cout << "index outside : " << i << std::endl;
        if(i % 2 == 0){
            if(cur->next != nullptr){
                std::cout << "index : " << i << std::endl;
                this->delete_nth(i);
            }
            else{
                std::cout << "index end: " << i << std::endl;
                this->delete_end();
            }
        }
        i++;
    }
}
//liste déjà triée
void LinkedListV2::insertSorted(int value){

    Node* newNode = new Node(value);

    Node* previousNode = nullptr;
    int i = 1;

    if(head == nullptr){
        head = newNode;
        head->next = nullptr;
        this->setLength(1);
    }
    else{
        for(Node* cur = head; cur; cur = cur->next){
            if(newNode->m_data <= cur->m_data && cur == head){
                newNode->next = head;
                head = newNode;
                this->setLength(1);
            }
            else if(newNode->m_data >= cur->m_data && cur->next == nullptr){
                cur->next = newNode;
                newNode->next = nullptr;
                this->setLength(1);
            }
            else if(newNode->m_data < cur->m_data && cur->next == nullptr){
                newNode->next = cur;
                previousNode = this->get_nth(i - 1);
                previousNode->next = newNode;
                cur->next = nullptr;
                this->setLength(1);
            }//au dessus bon
            /*
            else if(newNode->m_data > cur->m_data && newNode->m_data < cur->next->m_data && cur->next != nullptr){
                newNode->next = cur->next;
                cur->next = newNode;
                this->setLength(1);
            }*/
            i++;
        }
    }

}

void LinkedListV2::swapHeadAndTail(){
    Node* lastNode = this->getTail();
    Node* beforeLastNode = this->get_nth(this->getLength() - 1);
    Node* secondNode = this->get_nth(2);

    beforeLastNode->next = head;

    lastNode->next = secondNode;

    head->next = nullptr;
    head = lastNode;

}

void LinkedListV2::leftRotate(int k = 1){
    Node* lastNode = this->getTail();
    Node* secondNode = this->get_nth(2);

    while(k > 0){
        lastNode = this->getTail();
        secondNode = this->get_nth(2);
        lastNode->next = head;
        head->next = nullptr;
        head = secondNode;
        k--;
    }
}

//remove duplicate and keep the first met
void LinkedListV2::removeDuplicates(){
    int num = 0;
    int counter = 0;
    int i = 1;
    std::list<int> listIdx{};

    for(Node* cur = head; cur; cur = cur->next){
        num = cur->m_data;
        for(Node* cur2 = head; cur2; cur2 = cur2->next){
            if(num == cur2->m_data){
                counter++;
                listIdx.push_back(i);
            }
            i++;
        }

        if(counter > 1){
            auto it = listIdx.begin();
            ++it; // Move the iterator to the second element
            while (it != listIdx.end()) {
                if(*it == this->getLength()){
                    this->delete_end();
                }
                else {
                    this->delete_nth(*it);
                }

                ++it; // Move to the next element
            }
        }
        listIdx.clear();
        counter = 0;
        i = 1;
    }

    /*for(Node* cur = head; cur; cur = cur->next){
        num = cur->m_data;
        idxToLock = i;
        std::cout << "idx : " << idxToLock << std::endl;
        for(Node* cur2 = head; cur2; cur2 = cur2->next){
            if(cur2->m_data == num && j != idxToLock){
                if(cur2->next == nullptr){
                    this->delete_end();
                }
                else{
                    std::cout << "data : " << cur2->m_data << std::endl;
                    std::cout << "j : " << j << std::endl;
                    this->delete_value(cur2->m_data);
                }
            }
            j++;
        }
        j = 1;
        i++;
    }*/
}
