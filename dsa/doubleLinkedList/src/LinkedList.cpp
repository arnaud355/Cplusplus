#include "LinkedList.h"

LinkedList::LinkedList()
{
    //ctor
}

LinkedList::LinkedList(int cols): m_cols(cols)
{
    //ctor
    // dummy node of col = -1
    /*In computer programming, a sentinel node is a specifically designated node used with linked lists
    and trees as a traversal path terminator. This type of node does not hold or reference
     any data managed by the data structure.

     Sentinels are used as an alternative over using NULL as the path terminator in order to get
      one or more of the following benefits:

     Marginally increased speed of operations
     Increased data structure robustness (arguably)

     */
    tail = head = new ColumnNode(0, -1);
    ++length;
}

LinkedList::~LinkedList()
{
    //dtor
     while(head){
        //Parcourir les noeuds et supprimer tete.
        //Adresse suivante sera la tete, à la fin head = nullptr
        ColumnNode* current = head->next;
        delete head;
        head = current;
    }

    delete tail;
    tail = nullptr;
}

void LinkedList::printRow(){
    ColumnNode* cur = head->next;

    for(int c = 0; c < m_cols; ++c){
        if(cur && cur->m_column == c){
            std::cout << cur->m_data << " ";
            cur = cur->next;
        }
        else
            std::cout << "0 ";
    }
    std::cout << "\n";
}

void LinkedList::printRowNonZero(){
    for(ColumnNode* cur = head->next; cur; cur = cur->next)
        std::cout << cur->m_data << " ";
    std::cout << "\n";
}

void LinkedList::setValue(int data, int col){
    getCol(col, true)->m_data = data;
}

int LinkedList::getValue(int col){
    ColumnNode* node = getCol(col, false);
    if(!node)
        return 0;
    return node->m_data;
}

void LinkedList::add(LinkedList& other){
    assert(m_cols == other.m_cols);

    //iterate on the other first, and add it to the current one
    for(ColumnNode* otherCur = other.head->next; otherCur; otherCur = otherCur->next){
        ColumnNode* thisCol = getCol(otherCur->m_column, true);
        thisCol->m_data = thisCol->m_data + otherCur->m_data;
    }
}
