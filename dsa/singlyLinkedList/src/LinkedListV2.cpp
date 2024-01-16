#include "../LinkedListV2.h"
#include "../struct.h"
#include <iostream>
#include <list>
#include <limits.h>
#include <cmath>

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

void LinkedListV2::insertElement(int value, int pos){

    Node* newNode = new Node(value);
    int sizeList = this->getLength();

    if(head == nullptr){
        head = newNode;
        head->next = nullptr;
        this->setLength(1);
    }
    else {

        if(pos <= 0 || pos > sizeList + 1){
            std::cout << "impossible to insert element" << std::endl;
        }
        else {
                Node* lastNode = nullptr;
                Node* previousNode = nullptr;
                Node* nextNode = nullptr;

                if(pos == 1){
                    newNode->next = head;
                    head = newNode;
                    this->setLength(1);
                }
                else if(pos == sizeList){
                    lastNode = this->getTail();
                    previousNode = this->get_nth(pos - 1);

                    newNode->next =lastNode;
                    previousNode->next = newNode;
                    this->setLength(1);
                }
                else if(pos == sizeList + 1){
                    lastNode = this->getTail();
                    lastNode->next = newNode;
                    newNode->next = nullptr;
                    this->setLength(1);
                }
                else{
                    previousNode = this->get_nth(pos - 1);
                    nextNode = this->get_nth(pos);

                    newNode->next = nextNode;
                    previousNode->next = newNode;
                    this->setLength(1);
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

Node* LinkedListV2::getHead() const {
    return head;
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
//remove the values accordingly with the key, except one value
void LinkedListV2::removeLastOccurence(int key = 1){

    int counter = 0;
    int i = 1;
    std::list<int> listIdx{};

    for(Node* cur = head; cur; cur = cur->next){
        if(key == cur->m_data){
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
}
//move all the values of the key at the end
void LinkedListV2::moveBack(int key = 1){
    int counter = 0;
    int i = 1;
    std::list<int> listIdx{};
    Node* previousNode = nullptr;
    Node* curNode = nullptr;
    Node* lastNode = nullptr;
    Node* secondNode = nullptr;
    bool firstPassage = true;

    for(Node* cur = head; cur; cur = cur->next){
        if(key == cur->m_data){
            counter++;
            listIdx.push_back(i);
        }
        i++;
    }

    if(counter > 1){
        auto it = listIdx.begin();

        while (it != listIdx.end()) {

            if(*it == 1){
                lastNode = this->getTail();
                secondNode = this->get_nth(2);

                lastNode->next = head;
                head->next = nullptr;
                head = secondNode;
                firstPassage = false;
            }
            else{
                if(*it != this->getLength() && firstPassage){
                    curNode = this->get_nth(*it);
                    previousNode = this->get_nth(*it - 1);
                    lastNode = this->getTail();

                    previousNode->next = previousNode->next->next;
                    lastNode->next = curNode;
                    curNode->next = nullptr;
                    firstPassage = false;
                }
                else{
                    curNode = this->get_nth(*it - 1);

                    if(curNode == head){
                        lastNode = this->getTail();
                        secondNode = this->get_nth(2);

                        lastNode->next = head;
                        head->next = nullptr;
                        head = secondNode;
                    }
                    else{
                        previousNode = this->get_nth(*it - 1);

                        if(previousNode == head){
                            lastNode = this->getTail();

                            previousNode->next = previousNode->next->next;
                            lastNode->next = curNode;
                            curNode->next = nullptr;
                        }
                        else{
                            previousNode = this->get_nth(*it - 2);
                            lastNode = this->getTail();

                            previousNode->next = previousNode->next->next;
                            lastNode->next = curNode;
                            curNode->next = nullptr;
                        }
                    }
                }
            }

            ++it; // Move to the next element
        }
    }
    listIdx.clear();
}

//recursive function
int LinkedListV2::maxValue(Node* head = nullptr){

    if(head == nullptr){
        //INT_MIN le minimun que stocke un int : –2147483648   (for 32-bit Integers)
        return INT_MIN;
    }

    return std::max(head->m_data, maxValue(head->next));
}
/*
//recursive function
int LinkedListV2::maxValue(Node* head = nullptr, bool firstCall = true){
    if(firstCall){
        return maxValue(head, false);
    }

    if(head == nullptr){
        //INT_MIN le minimun que stocke un int : –2147483648   (for 32-bit Integers)
        return INT_MIN;
    }

    return std::max(head->m_data, maxValue(head->next, false));
}*/
/*
int LinkedListV2::maxValue(){
    int maxVal = 0;

    if(head == nullptr)
        return -1;

    Node* cur = head;
    maxVal = cur->m_data;

    if(maxVal < cur->next->m_data){
        maxVal = maxValue();
    }

    return maxVal;

}*/
/*
int LinkedListV2::maxValue(Node* head = nullptr, bool firstCall = true) {
    if (firstCall) {
        if (head == nullptr) {
            // Handle empty list scenario
            return INT_MIN;
        }
        // Initial call to the function without firstCall flag
        return maxValue(head, false);
    }

    if (head == nullptr) {
        // Reached the end of the list
        return INT_MIN;
    }

    // Recursively get the maximum value from the rest of the list
    int maxRest = maxValue(head->next, false);

    // Compare current node value with the maximum of the rest of the list
    return std::max(head->m_data, maxRest);
}
*/
//valeurs index impaires rangées en premier
void LinkedListV2::arrangeOddAndEven(){

    int i = 1;
    int j = 0;
    int v = 1;
    Node* betweenNodeMax = nullptr;
    Node* betweenNodeMin = nullptr;
    Node* beforeLastNode = nullptr;
    Node* cur = head;
    if(cur != nullptr){
            while(i <= this->getLength()){

                if(i % 2 != 0 && i > 1){

                    j++;
                    v++;
                    cur = this->get_nth(i);
                    betweenNodeMax = this->get_nth(i - j);
                    betweenNodeMin = this->get_nth(i - v);
                    std::cout << "i : " << i << "j : " << j << "v : " << v << std::endl;
                    std::cout << "cur data : " << cur->m_data << std::endl;
                    if(cur->next == nullptr){
                        beforeLastNode = this->get_nth(i - 1);

                        cur->next = betweenNodeMax;
                        beforeLastNode->next = nullptr;
                        betweenNodeMin->next = cur;
                    }
                    else{
                        betweenNodeMax->next = betweenNodeMax->next->next;
                        cur->next = betweenNodeMax;
                        betweenNodeMin->next = cur;
                    }
                }
                i++;
            }

    }

}

void LinkedListV2::insertAlternate(const LinkedListV2& other){
    if (this->getHead() == nullptr) {
        std::cout << "No values in the list object" << std::endl;
    }
    else if(other.getHead() == nullptr){
        std::cout << "No values in the list pass in reference" << std::endl;
    }
    else {
        Node* otherNode = nullptr;
        int i = 1;
        int j = 2;
        int v = 0;

        if(this->getLength() > other.getLength()){

            while(i <= other.getLength()){
                otherNode = other.get_nth(i);
                this->insertElement(otherNode->m_data, j);
                j = j + 2;
                i++;
            }
        }
        else if(this->getLength() < other.getLength())
        {
            otherNode = other.get_nth(i);

            while(otherNode != nullptr){

                if(j <= this->getLength()){
                    this->insertElement(otherNode->m_data, j);
                }
                else {
                    this->insertElement(otherNode->m_data, v);
                    v++;
                }
                j = j + 2;
                i++;
                v = this->getLength() + 1;
                otherNode = other.get_nth(i);
            }
        }
        else {
            for(Node* cur = head; cur; cur = cur->next){
                otherNode = other.get_nth(i);

                if(otherNode != nullptr){
                     this->insertElement(otherNode->m_data, j);
                }
                i++;
                j = j + 2;
            }
        }
    }

}
//addition of inversion list : 123 represent 321, 453 represent 354, = 675 (576 in the list)
void LinkedListV2::addNumber(const LinkedListV2& other){

    if (this->getHead() == nullptr) {
        std::cout << "No values in the list object" << std::endl;
    }
    else if(other.getHead() == nullptr){
        std::cout << "No values in the list pass in reference" << std::endl;
    }

    int i, v = 0;
    Node* otherNode = nullptr;

    if(this->getLength() > other.getLength()){
        i = other.getLength();
        v = this->getLength();

        while(i >= 1){
            otherNode = other.get_nth(i);
            this->changeValueOfNode(otherNode->m_data, v);
            v--;
            i--;
        }
    }
    else if(this->getLength() < other.getLength()){
        i = other.getLength();
        v = this->getLength();

        while(i >= 1){
            otherNode = other.get_nth(i);

            if(v >= 1){
                this->changeValueOfNode(otherNode->m_data, v);
            }
            else{
                this->insertElement(otherNode->m_data, 1);
            }
            v--;
            i--;
        }
    }
    else{
        i = other.getLength();

        while(i >= 1){
            otherNode = other.get_nth(i);
            this->changeValueOfNode(otherNode->m_data, i);
            i--;
        }
    }
}
//addition value to current node value
void LinkedListV2::changeValueOfNode(int value, int idx){
    int i = 1;

    for(Node* cur = head; cur; cur = cur->next){
        if(i == idx){
            cur->m_data = cur->m_data + value;
        }
        i++;
    }
}
//replace current node value with a new value
void LinkedListV2::replaceValueOfNode(int value, int idx){
    int i = 1;

    for(Node* cur = head; cur; cur = cur->next){
        if(i == idx){
            cur->m_data = value;
        }
        i++;
    }
}

int LinkedListV2::getData(int idx) const {
    int i = 1;

    for(Node* cur = head; cur; cur = cur->next){
        if(i == idx){
            return cur->m_data;
        }
        i++;
    }
}
//keep nodes never repeated : 1,1,2,3,5,2 => 3,5
void LinkedListV2::removeAllRepeated(){
    int i = 1;
    int val = 0;
    int counter = 0;
    std::list<int> listIdx{};
    LinkedListV2 linkedListExistingValues;

    for(Node* cur = head; cur; cur = cur->next){
        val = cur->m_data;

        for(Node* cur2 = head; cur2; cur2 = cur2->next){
            if(cur2->m_data == val){
                counter++;
            }
        }

        if(counter == 1){
            linkedListExistingValues.addElement(val);
        }
        counter = 0;
    }

    while(i <= linkedListExistingValues.getLength()){
        this->replaceValueOfNode(linkedListExistingValues.getData(i), i);
        i++;
    }

    std::cout << "++++++++++++++++++++++++++++++" << std::endl;
    std::cout << linkedListExistingValues.getLength() << std::endl;
    std::cout << this->getLength() << std::endl;
    std::cout << "++++++++++++++++++++++++++++++" << std::endl;

    this->purgeListNodeFromTo(linkedListExistingValues.getLength() + 1, this->getLength());//3 ; 7
;
    //std::cout << "++++++++++++++++++++++++++++++" << std::endl;
    //linkedListExistingValues.print();
    //std::cout << "++++++++++++++++++++++++++++++" << std::endl;
}

int LinkedListV2::getValueFromNode(int value){

    if(head == nullptr)
        return INT_MIN;

    for(Node* cur = head; cur; cur = cur->next){
        if(cur->m_data == value){
            return cur->m_data;
        }
    }

    return INT_MAX;
}

void LinkedListV2::purgeListNodeFromTo(int idxStart, int idxEnd){

    Node* previousNode = nullptr;
    Node* currentNode = nullptr;
    Node* nextNode = nullptr;

    if(head != nullptr){
        if(idxEnd > idxStart){
             while(idxStart <= idxEnd){

                if(idxStart == 1){
                    nextNode = this->get_nth(2);
                    currentNode = this->getHead();
                    head = nextNode;

                    delete currentNode;
                    currentNode = nullptr;
                    this->setLength(-1);
                }
                else if(idxStart == idxEnd){
                    previousNode = this->get_nth(this->getLength() - 1);
                    currentNode = this->getTail();
                    previousNode->next = nullptr;

                    delete currentNode;
                    currentNode = nullptr;
                    this->setLength(-1);
                }
                else{
                    previousNode = this->get_nth(idxStart - 1);
                    currentNode = this->get_nth(idxStart);
                    nextNode = this->get_nth(idxStart + 1);

                    previousNode->next = nextNode;

                    delete currentNode;
                    currentNode = nullptr;
                    this->setLength(-1);
                }

                idxEnd = this->getLength();
            }
        }
        else if(idxEnd == idxStart){
            std::cout << "Please, use delete function for delete one node" << std::endl;
        }
        else{
            std::cout << "invalid" << std::endl;
        }
    }
}
//1,2,3,4,5,6 with k = 6 : 6,5,4,3,2,1  ; 1,2,3,4,5,6 with k = 3 : 3,2,1,6,5,4
//1,2,3,4,5,6,7 with k = 2 : 2,1,4,3,6,5,7
void LinkedListV2::reverseChain(int k){

    if(k == this->getLength()){
        Node* lastNode = nullptr;
        Node* nextNode = nullptr;
        lastNode = getTail();
        int i = 0;
        i = this->getLength() - 1;

        while(i >= 2){
            nextNode = get_nth(i);

            if(i == this->getLength() - 1){
                lastNode->next = nextNode;
                nextNode->next = get_nth(i - 1);
            }
            else if(i == 2){
                nextNode->next = get_nth(i - 1);
                nextNode->next->next = nullptr;
            }
            else{
                nextNode->next = get_nth(i - 1);
            }
            i--;
        }
        head = lastNode;
    }
    else if(k <= 1){
        std::cout << "No actions available" << std::endl;
    }
    else{
        int round = std::round(this->getLength() / k);
        bool firstRound = true;
        bool lastRound = false;
        Node* curNode = nullptr;
        Node* nextNode = nullptr;
        Node* curHead = nullptr;
        Node* nodeToRelink = nullptr;
        Node* remainNodes = nullptr;
        int v = 1;
        int borneMin = 0;
        int borneMax = 0;
        int start = 0;

        while(round > 0){
            if(firstRound){

                nodeToRelink = get_nth(k * v + 1);
                curHead = get_nth(k);
                start = k * v + 1;

                for(int i = k; i >= 2; i--){
                    curNode = get_nth(i);
                    nextNode = get_nth(i - 1);

                    if(nextNode == head){
                        curNode->next = nextNode;
                        nextNode->next = nodeToRelink;

                        for(int j = start; j <= this->getLength(); j++){
                            if(j == start){
                                nodeToRelink->next = get_nth(j + 1);
                            }
                            else{
                                remainNodes = get_nth(j);
                                if(remainNodes->next == nullptr){
                                    remainNodes->next = nullptr;
                                }
                                else{
                                    remainNodes->next = get_nth(j + 1);
                                }
                            }
                        }
                    }
                    else{
                        curNode->next = nextNode;
                    }
                }

                //std::cout << "3 :" << curHead->m_data << std::endl;
                head = curHead;
                firstRound = false;

                for(Node* cur = head; cur; cur = cur->next){
                    std::cout << "+++++++++++lala+++++++++++++++" << std::endl;
                    std::cout << cur->m_data << std::endl;
                    std::cout << "++++++++++++++++++++++++++" << std::endl;
                }
            }
            else{

                if(lastRound){

                    borneMin = k * v - k + 1;
                    borneMax = k * v;
                    int RemainNodes = this->getLength() - borneMax;
                    int j = this->getLength();
                    int a = 1;

                    for(int i = borneMax; i >= borneMin; i--){
                        curNode = get_nth(i);
                        nextNode = get_nth(i - 1);

                        if(i == borneMin && RemainNodes == 0){
                            curNode->next = nullptr;
                        }
                        else if(i == borneMin && RemainNodes > 0){

                            while(j > borneMax){

                                if((borneMax + a) <= this->getLength()){
                                    nextNode = get_nth(borneMax + a);
                                    curNode->next = nextNode;
                                }

                                curNode = get_nth(borneMax + a);

                                if(curNode->next != nullptr){
                                    curNode->next = nullptr;
                                }

                                j--;
                                a++;
                            }

                        }
                        else{
                            curNode->next = nextNode;
                        }
                    }

                }
                else{
                    // to do
                    nodeToRelink = get_nth(k * v + 1);
                    borneMin = k * v - k + 1;
                    borneMax = k * v;
                    start = k * v + 1;

                    for(int i = borneMax; i >= borneMin; i--){
                        curNode = get_nth(i);
                        nextNode = get_nth(i - 1);

                        if(i == borneMin){
                            curNode->next = nextNode;
                            nextNode->next = nodeToRelink;

                            for(int j = start; j <= this->getLength(); j++){
                                if(j == start){
                                    nodeToRelink->next = get_nth(j + 1);
                                }
                                else{
                                    remainNodes = get_nth(j);
                                    if(remainNodes->next == nullptr){
                                        remainNodes->next = nullptr;
                                    }
                                    else{
                                        remainNodes->next = get_nth(j + 1);
                                    }
                                }
                            }
                        }
                        else{
                            curNode->next = nextNode;
                        }
                    }
                }
            }
            round--;
            v++;
            if(round == 1){
                lastRound = true;
            }
        }
    }
}
