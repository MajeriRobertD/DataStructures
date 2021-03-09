#pragma once
#include<string>
using namespace std;


class Node
{
private:
    string info;
    int line;
    int column;
    Node* next;
    Node* prev;
public:
    Node(string info = "", int line= 1, int column = 1, Node* next = nullptr, Node* prev = nullptr);
    ~Node(){}


    Node* getNext() { return this->next; }
    Node* getPrev() {return this->prev; }
    int getLine() const { return this->line; }
    int getColumn() const {return this->column; }
    string getInfo() const {return this->info; }
    void setInfo(string newInfo) ;
    friend class SparseMatrix;

};


class SparseMatrix
{
private:
    Node* head;
    Node* tail;
    int nrLines;
    int nrColumns;

public:
    SparseMatrix(Node* head, Node* tail, int nrLines = 1, int nrColumns = 1);
    ~SparseMatrix() { }

    int getNrLines()  { return this->nrLines; }
    int getnrColumns() { return this->nrColumns; }

/*
Returns the element at a given position in the matrix
In:int line, int column -the line and the column
Out:string - the information at that position
*/
    string getElement(int line, int column);

    string modify(int line, int column, string info);

    Node* search(string info);

    void resize(int newLines, int newCols);


};








