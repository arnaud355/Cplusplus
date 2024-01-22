#include "DoubleLinkedList.h"
#include <list>
#include <cmath>

DoubleLinkedList::DoubleLinkedList()
{
    //ctor
}

// Below 2 deletes prevent copy and assign to avoid this mistake
//DoubleLinkedList::DoubleLinkedList(const DoubleLinkedList&) = delete;
//DoubleLinkedList::DoubleLinkedList &operator=(const DoubleLinkedList &another) = delete;

DoubleLinkedList::~DoubleLinkedList()
{
    //dtor
}

void DoubleLinkedList::print() {
    for (Node* cur = head; cur; cur = cur->next)
        std::cout << cur->m_data << " ";
    std::cout << "\n";
}

Node* DoubleLinkedList::get_nth(int n) const {
    int pos = 0;
    for(Node* cur = head; cur; cur = cur->next){
        pos++;
        if(pos == n){
            return cur;
        }
    }
    return nullptr;
}

int DoubleLinkedList::getLength () const {
    return length;
}

int DoubleLinkedList::getData(int idx) const {
    int i = 1;

    for(Node* cur = head; cur; cur = cur->next){
        if(i == idx){
            return cur->m_data;
        }
        i++;
    }
}

void DoubleLinkedList::printReversed(){
    for(Node* cur = tail; cur; cur = cur->prev){
        std::cout << cur->m_data << " ";
    }
}


void DoubleLinkedList::addNode(Node* node) {
    debug_add_node(node);
    ++length;
}

void DoubleLinkedList::deleteNode(Node* node) {
    this->debug_remove_node(node);
    --length;
    delete node;
}

void DoubleLinkedList::insertFront(int value) {
    Node* item = new Node(value);
    this->addNode(item);

    if (!head)
        head = tail = item;
    else {
        link(item, head);
        head = item;
    }
    this->debug_verify_data_integrity();
}

void DoubleLinkedList::insertEnd(int value){
    Node* item = new Node(value);
    this->addNode(item);

    if(!head)
        head = tail = item;
    else{
        link(tail, item);
        tail = item;
    }

    this->debug_verify_data_integrity();
}

void DoubleLinkedList::link(Node* first, Node* second){
    if(first)
        first->next = second;
    if(second)
        second->prev = first;
}

void DoubleLinkedList::embedAfter(Node* node_before, int value) {
    // Add a node with value between node and its next
    Node* middle= new Node(value);
    ++length;
    this->debug_add_node(middle);

    Node* node_after = node_before->next;
    link(node_before, middle);
    link(middle, node_after);
}

void DoubleLinkedList::insertSorted(int value) {		// O(n) time - O(1) memory
    // 3 special cases for simplicity
    if (!length || value <= head->m_data)
        this->insertFront(value);
    else if (tail->m_data <= value)
        this->insertEnd(value);
    else {
        // Find the node I am less than. Then I am before it
        for (Node *cur = head; cur; cur = cur->next) {
            if (value <= cur->m_data) {
                this->embedAfter(cur->prev, value);
                break;
            }
        }
    }
    this->debug_verify_data_integrity();

    // This idea is used in Insertion Sort Algorithm
}

void DoubleLinkedList::delete_front() {
    if(!head)
        return;
    Node* cur = head->next;
    this->deleteNode(head);
    head = cur;

    // Integrity change
    if(head)
        head->prev = nullptr;
    else if(!length)
        tail = nullptr;

    this->debug_verify_data_integrity();
}

void DoubleLinkedList::delete_end() {
    if(!head)
        return;
    Node* cur = tail->prev;
    this->deleteNode(tail);
    tail = cur;

    // Integrity change
    if(tail)
        tail->next = nullptr;
    else if(!length)
        head = nullptr;

    this->debug_verify_data_integrity();
}
//delete a node and link his prev and next
Node* DoubleLinkedList::delete_and_link(Node* cur) {
    // remove this node, but connect its neighbors
    Node* ret = cur->prev;
    this->link(cur->prev, cur->next);
    this->deleteNode(cur);

    return ret;
}

void DoubleLinkedList::delete_node_with_key(int value) {
    if (!length)
        return;
    if (head->m_data == value)
        this->delete_front();
    else {
        for (Node *cur = head; cur; cur = cur->next) {
            if (cur->m_data == value) {
                cur = this->delete_and_link(cur);
                if (!cur->next)	// we removed last node!
                    tail = cur;
                break;
            }
        }
    }
    this->debug_verify_data_integrity();
}

void DoubleLinkedList::delete_nth(int index){

    if(index > 0 && index <= this->getLength()){
            if(index == 1){
                this->delete_front();
            }
            else if(index == this->getLength()){
                this->delete_end();
            }
            else{
                //avec le prev
                Node* previousNode = get_nth(index - 1);
                Node* nextNode = get_nth(index + 1);
                //Node* tempNode = previousNode->next->next;

                delete previousNode->next;
                previousNode->next = nullptr;

                previousNode->next = nextNode;
                nextNode->prev = previousNode;

                length--;
            }
    }

}

void DoubleLinkedList::deleteAllNodesWithKey(int value){
    int counter = 0;
    if(head != nullptr){
        Node* cur = head;
        while(cur != nullptr){
            if(cur->m_data == value){
                //this->delete_node_with_key(cur->m_data);
                counter++;
            }
            cur = cur->next;
        }
    }

    for(int j = 0; j < counter; j++){
        this->delete_node_with_key(value);
    }
}

void DoubleLinkedList::deleteEvenPositions(){

    std::list<int> listIdx{};
    int i = 1;

    for(Node* cur = head; cur; cur = cur->next){
        if(i % 2 == 0){
            listIdx.push_back(cur->m_data);
        }
        i++;
    }

    auto it = listIdx.begin();
    while (it != listIdx.end()) {
       this->delete_node_with_key(*it);
        ++it; // Move to the next element
    }
}

void DoubleLinkedList::deleteOddPositions(){
    std::list<int> listIdx{};
    int i = 1;

    for(Node* cur = head; cur; cur = cur->next){
        if(i % 2 != 0){
            listIdx.push_back(cur->m_data);
        }
        i++;
    }

    auto it = listIdx.begin();
    while (it != listIdx.end()) {
       this->delete_node_with_key(*it);
        ++it; // Move to the next element
    }
}

bool DoubleLinkedList::isPalindrome(){
    int middle = 0;
    bool isPalin = true;
    Node* nodeInf = nullptr;
    Node* nodeSup = nullptr;
    int j = this->getLength();

    if(this->getLength() % 2 == 0){
        middle = this->getLength() / 2;
    }
    else{
        middle = std::ceil(this->getLength() / 2);
    }

    for(int i = 1; i <= middle; i++){
        nodeInf = get_nth(i);
        nodeSup = get_nth(j);

        if(nodeInf->m_data != nodeSup->m_data )
            return false;

        j--;
    }

    return isPalin;
}
//Don t use length of the list, one iteration
int DoubleLinkedList::findMiddle(){
    int counter = 0;
    int middle = 0;

    for(Node* cur = head; cur; cur = cur->next){
        counter++;
    }

    if(counter % 2 == 0){
        middle = counter / 2;
        middle++;
    }
    else{
        middle = std::ceil(counter / 2);
        middle++;
    }

    return this->getData(middle);

}
//swap; for example if k = 1, swap first and last, k = 2, swap second and before last
void DoubleLinkedList::swapForwardWithBackward(int k){
    if(k >= this->getLength()){
        std::cout << "no available" << std::endl;
    }
    else{

    }
}
//************test************************************************************
void DoubleLinkedList::debug_add_node(Node* node) {
    debug_data.push_back(node);
}

void DoubleLinkedList::debug_remove_node(Node* node) {
    auto it = std::find(debug_data.begin(), debug_data.end(), node);
    if (it == debug_data.end())
        std::cout << "Node does not exist\n";
    else
        debug_data.erase(it);
}

void DoubleLinkedList::debug_print_address() {
    for (Node* cur = head; cur; cur = cur->next)
        std::cout << cur << "," << cur->m_data << "\t";
    std::cout << "\n";
}

void DoubleLinkedList::debug_print_node(Node* node, bool is_seperate = false) {
    if (is_seperate)
        std::cout << "Sep: ";
    if (node == nullptr) {
        std::cout << "nullptr\n";
        return;
    }
    std::cout << node->m_data << " ";
    if (node->next == nullptr)
        std::cout << "X ";
    else
        std::cout << node->next->m_data << " ";

    if (node == head)
        std::cout << "head\n";
    else if (node == tail)
        std::cout << "tail\n";
    else
        std::cout << "\n";
}
void DoubleLinkedList::debug_print_list(std::string msg = "") {
    if (msg != "")
        std::cout << msg << "\n";
    for (int i = 0; i < (int) debug_data.size(); ++i)
        debug_print_node(debug_data[i]);
    std::cout << "************\n"<<std::flush;
}

std::string DoubleLinkedList::debug_to_string() {
    if (length == 0)
        return "";
    std::ostringstream oss;
    for (Node* cur = head; cur; cur = cur->next) {
        oss << cur->m_data;
        if (cur->next)
            oss << " ";
    }
    return oss.str();
}

void DoubleLinkedList::debug_verify_data_integrity() {
    if (length == 0) {
        assert(head == nullptr);
        assert(tail == nullptr);
    } else {
        assert(head != nullptr);
        assert(tail != nullptr);
        if (length == 1)
            assert(head == tail);
        else
            assert(head != tail);
        assert(!tail->next);
    }
    int len = 0;
    for (Node* cur = head; cur; cur = cur->next, len++)
        assert(len < 10000);	// Consider infinite cycle?
    assert(length == len);
    assert(length == (int)debug_data.size());
}

void DoubleLinkedList::test1() {
	std::cout << "\n\ntest1\n";
	DoubleLinkedList listD;

	listD.insertEnd(1);
	listD.insertEnd(2);
	listD.insertEnd(3);
	listD.insertEnd(4);
	listD.insertEnd(5);

	listD.delete_nth(1);

	// some actions
	listD.print();

	std::string expected = "2 3 4 5";
	std::string result = listD.debug_to_string();
	if (expected != result) {
		std::cout << "no match:\nExpected: " <<
				expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	listD.debug_print_list("********");
}

void DoubleLinkedList::test2() {
	std::cout << "\n\ntest2\n";
	DoubleLinkedList listD;

	listD.insertEnd(1);
	listD.insertEnd(2);
	listD.insertEnd(3);
	listD.insertEnd(4);
	listD.insertEnd(5);

	listD.delete_nth(5);

	// some actions
	listD.print();

	std::string expected = "1 2 3 4";
	std::string result = listD.debug_to_string();
	if (expected != result) {
		std::cout << "no match:\nExpected: " <<
				expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	listD.debug_print_list("********");
}

void DoubleLinkedList::test3() {
	std::cout << "\n\ntest3\n";
	DoubleLinkedList listD;

	listD.insertEnd(1);
	listD.insertEnd(2);
	listD.insertEnd(3);
	listD.insertEnd(4);
	listD.insertEnd(5);

	listD.delete_nth(3);

	// some actions
	listD.print();

	std::string expected = "1 2 4 5";
	std::string result = listD.debug_to_string();
	if (expected != result) {
		std::cout << "no match:\nExpected: " <<
				expected << "\nResult  : " << result << "\n";
		assert(false);
	}
	listD.debug_print_list("********");
}

void DoubleLinkedList::test4() {
	std::cout << "\n\ntest3\n";
	DoubleLinkedList listD;

	listD.insertEnd(1);
	listD.insertEnd(2);
	listD.insertEnd(3);
	listD.insertEnd(4);
	listD.insertEnd(5);

	listD.delete_front();
	listD.delete_end();

	// some actions
	listD.print();

	std::string expected = "2 3 4";
	std::string result = listD.debug_to_string();
	if (expected != result) {
		std::cout << "no match:\nExpected: " <<
				expected << "\nResult  : " << result << "\n";
		assert(false);
	}
    listD.debug_print_list("********");
}
