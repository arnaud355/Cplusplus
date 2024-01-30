#include "ArrayLinkedList.h"
#include "DoubleLinkedList.h"

ArrayLinkedList::ArrayLinkedList(int length): m_length(length)
{
    //ctor
    for(int i = 0; i < m_length; i++){
        this->initValue(0);
    }
}

ArrayLinkedList::~ArrayLinkedList()
{
    //dtor
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

void ArrayLinkedList::initValue(int value){
    Node* newNode = new Node(value);

    if(head == nullptr){
        head = newNode;
        tail = head;

        head->next = nullptr;
        head->prev = nullptr;
    }
    else{
        Node* previousNode = this->getTail();
        previousNode->next = newNode;
        newNode->prev = previousNode;
        tail = newNode;
        tail->next = nullptr;
    }
}

void ArrayLinkedList::setValue(int value, int pos){
   int i = 0;
   if(head != nullptr){
        if(pos > -1 && pos < this->getLength()){
            for(Node* cur = head; cur; cur = cur->next){
                if(i == pos){
                    cur->m_data = cur->m_data + value;
                }
                i++;
            }
        }
   }
}

Node* ArrayLinkedList::getHead() const {
    return head;
}

Node* ArrayLinkedList::getTail() const {
    return tail;
}

int ArrayLinkedList::getLength() const {
    return m_length;
}

void ArrayLinkedList::setLength(int value){

    m_length = m_length + value;

    if(value == 0){
        m_length = 0;
    }

    if(m_length < 0){
        m_length = 0;
    }
}

Node* ArrayLinkedList::getNth(int n) const {
    int pos = 0;
    for(Node* cur = head; cur; cur = cur->next){
        if(pos == n){
            return cur;
        }
        pos++;
    }
    return nullptr;
}

void ArrayLinkedList::printArray(){
     for(Node* cur = head; cur; cur = cur->next){
        std::cout << cur->m_data << " ";
    }
    std::cout << "\n";
}

void ArrayLinkedList::printArrayNonZero(){
    for(Node* cur = head; cur; cur = cur->next){
        if(cur->m_data != 0)
            std::cout << cur->m_data << " ";
    }
    std::cout << "\n";
}
// get the value with the index in parameter
int ArrayLinkedList::getValue(int idx) const {
    int i = 0;
    for(Node* cur = head; cur; cur = cur->next){
        if(i == idx){
            return cur->m_data;
        }
        i++;
    }
    return -1;
}

void ArrayLinkedList::addition(ArrayLinkedList& other){
    Node* node = nullptr;

    if(this->getHead() != nullptr && other.getHead() != nullptr){
        for(Node* cur = other.getHead(); cur; cur = cur->next){
            if(cur->m_data != 0){
                node = this->getNth(other.getIdx(cur));
                node->m_data = node->m_data + cur->m_data;
            }
        }
    }
}

int ArrayLinkedList::getIdx(Node* nodeOfIdx) const {
    int i = 0;
    for(Node* cur = head; cur; cur = cur->next){
        if(cur == nodeOfIdx){
            return i;
        }
        i++;
    }

    return -1;
}
