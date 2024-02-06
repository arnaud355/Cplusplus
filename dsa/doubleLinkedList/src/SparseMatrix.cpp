#include "SparseMatrix.h"
#include <assert.h>     /* assert */

SparseMatrix::SparseMatrix(int rows, int cols): m_rows(rows),m_cols(cols)
{
    //ctor
    // dummy node
    tail = head = new RowNode(-1, cols);
    ++length;
}

SparseMatrix::~SparseMatrix()
{
    //dtor
     while(head){
        //Parcourir les noeuds et supprimer tete.
        //Adresse suivante sera la tete, à la fin head = nullptr
        RowNode* current = head->next;
        delete head;
        head = current;
    }

    delete tail;
    tail = nullptr;

}

void SparseMatrix::setValue(int data, int row, int col){
    assert(0 <= row && row < m_rows);
    assert(0 <= col && col < m_cols);

    RowNode* node = getRow(row, true);
    node->colList.setValue(data, col);
}

int SparseMatrix::getValue(int row, int col){
    assert(0 <= row && row < m_rows);
    assert(0 <= col && col < m_cols);

    RowNode* node = getRow(row, false);
    // no such row
    if(!node)
        return 0;
    return node->colList.getValue(col);
}

void SparseMatrix::printMatrix(){
    std::cout << "Print matrix : " << m_rows << " x " << m_cols << "\n";
    RowNode* cur = head->next;
    for(int r = 0; r < m_rows; ++r){
        if(cur && cur->m_row == r){
            cur->colList.printRow();
            cur = cur->next;
        }
        else{
            for(int j = 0; j < m_cols; ++j)
                std::cout << "0 ";
            std::cout << "\n";
        }
    }
}

void SparseMatrix::printMatrixNonZero(){
    std::cout << "Print matrix : " << m_rows << " x " << m_cols << "\n";
    for(RowNode* cur = head->next; cur; cur = cur->next)
        cur->colList.printRowNonZero();
}

void SparseMatrix::add(SparseMatrix& other){
    //assert(m_rows == other.m_rows && m_cols = other.m_cols);
    // iterate on the other first, and add it to the current one
    for(RowNode* otherCur = other.head->next; otherCur; otherCur = otherCur->next){
        RowNode* thisRow = getRow(otherCur->m_row, true);
        thisRow->colList.add(otherCur->colList);
    }
}

void SparseMatrix::testCol(){
    LinkedList collst(12);
    collst.setValue(10,10);
    collst.setValue(5,5);
    collst.setValue(2,2);
    collst.setValue(7,7);
    collst.setValue(4,4);
}

int SparseMatrix::getRows(){
    return m_rows;
}
int SparseMatrix::getCols(){
    return m_cols;
}

void SparseMatrix::testSparse() {

	this->setValue(5, 3, 5);
	this->setValue(7, 3, 7);
	this->setValue(2, 3, 2);
	this->setValue(0, 3, 2);
	this->setValue(6, 5, 6);
	this->setValue(4, 5, 4);
	this->setValue(3, 7, 3);
	this->setValue(1, 7, 1);

	this->printMatrix();
	this->printMatrixNonZero();

	SparseMatrix mat2(10, 10);
	mat2.setValue(5, 1, 9);
	mat2.setValue(6, 3, 8);
	mat2.setValue(9, 9, 9);
	this->add(mat2);
	this->printMatrixNonZero();
}
