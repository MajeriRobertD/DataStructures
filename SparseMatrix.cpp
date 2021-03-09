#include"SparseMatrix.h"



Node::Node(string info, int line, int column, Node* next, Node* prev): info(info), line(line), column(column) {
            this->next = nullptr;
            this->prev = nullptr;
             }


void Node::setInfo(string newInfo){
    this->info = newInfo;
}


SparseMatrix::SparseMatrix(Node* head, Node* tail, int nrLines, int nrColumns): nrLines(nrLines), nrColumns(nrColumns){
    this->head = nullptr;
    this->tail = nullptr;
}

string SparseMatrix::getElement(int line, int column){
    if(line < 1 || column < 1 || this->nrLines < line || this->nrColumns < column)
        throw "Invalid line or column!";

    Node* current ;
    current = this->head;
    while(current != nullptr && (current->getLine() < line || (current->getLine() == line && current->getColumn() < column)))
        current = current->getNext();

    if(current != nullptr && current->getLine() == line && current->getColumn() == column){
        return current->getInfo();

    }
    else
        return "Error" ;

}

string SparseMatrix::modify(int line, int column, string info){
    if(this->head == nullptr){
        this->head = new Node(info, line, column, nullptr, nullptr );
        string old = "Old value: Was empty.";
        old += "\nNew value: ";
        old += head->getInfo();
        return old;
    }
    if(line < 1 || column < 1 || this->nrLines < line || this->nrColumns < column)
        throw "Invalid line or column!";

    Node* current ;
    current = this->head;
    while(current != nullptr && (current->getLine() < line || (current->getLine() == line && current->getColumn() < column)))
        current = current->getNext();

    if(current != nullptr && current->getLine() == line && current->getColumn() == column){
        string old ;
        old += "Old value: ";
        old += current->getInfo();
        current->setInfo(info);
        old += "\nNew value:";
        old += current->getInfo();
        return old;

}
    else{

        Node* n = new Node(info, line, column, nullptr, this->head);
        this->head->prev = n;
        this->head = n;



    }


    return "Old Value:Was Empty.";
}

Node* SparseMatrix::search(string info){
    Node* current ;
    current = this->head;
    while(current->getInfo() != info && current != nullptr && (current->getLine() < this->getNrLines() || (current->getLine() == this->getNrLines() && current->getColumn() < this->getnrColumns())))
        current = current->getNext();


    if(current != nullptr && current->getInfo() == info)
        return current;
    else
        return nullptr;

}

void SparseMatrix::resize(int newLines, int newCols){
    if(newLines >= this->getNrLines() && newCols >= this->getnrColumns()){
        this->nrLines = newLines;
        this->nrColumns = newCols;
    }
    if(newLines < this->nrLines && newCols < this->nrColumns){
        Node* current ;
        current = this->head;
        while(current != nullptr && (current->getLine() < this->getNrLines() || (current->getLine() == this->getNrLines() && current->getColumn() < this->getnrColumns()))){
                current = current->getNext();
            if(current->getLine() > newLines && current->getColumn() > newCols){
                Node* prev = current->prev;
                prev->next = current->next;
                (current->next)->prev = prev;

            }

        }

    }

}