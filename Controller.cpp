#include"Controller.h"
#include<string>
#include <iostream>

using namespace std;


Controller::Controller() {
}

void Controller::searchCtrl(){
    string info;
    getline(cin, info);
    Node* current;
    current = this->matrix.search(info);
    string str;
    str += "Line: ";
    str += to_string(current->getLine());
    str += " Column: " ;
    str += to_string(current->getColumn());
    cout << str << endl;
}

void Controller::getElementCtrl(){
    cout << "Enter line: " << endl;
    int line;
    cin >> line ;
    cin.ignore();

    cout << "Enter Column: " << endl;
    int column;
    cin >> column ;
    cin.ignore();
    string str;

    str = this->matrix.getElement(line, column);
    cout << str << endl;

}

void Controller::modifyCtrl(){
    cout << "Enter line: " << endl;
    int line;
    cin >> line ;
    cin.ignore();

    cout << "Enter Column: " << endl;
    int column;
    cin >> column ;
    cin.ignore();

    cout << "Enter info: " << endl;
    string info;
    getline(cin, info);

    cout <<this->matrix.modify(line, column, info) << endl;
}

void Controller::printMenu(){
    cout << endl;
    cout << "0-Exit." << endl;
    cout << "1-Search element." << endl;
    cout << "2-Modify." << endl;
    cout << "3-Get element." << endl;
    cout << "4-Resize." << endl;
}
void Controller::resizeCtrl(){
     cout << "Enter new nr of lines: " << endl;
    int line;
    cin >> line ;
    cin.ignore();

    cout << "Enter new nr of Columns : " << endl;
    int column;
    cin >> column ;
    cin.ignore();

    this->matrix.resize(line,column);

}

void Controller::theSize(){
    string thesize;
    thesize +=" lines:";
    thesize += to_string(this->matrix.getNrLines()) ;
    thesize += "columns: ";
    thesize += to_string(this->matrix.getnrColumns());
    cout  <<thesize;

}

void Controller::run(){
    while(true){
        Controller::printMenu();
        int choice{0};
        cout << endl;
        cout << "Enter choice:" ;
        cin >> choice;
        cin.ignore();
        if(choice == 0)
            break;
        switch(choice){
            case 1:
                this->searchCtrl();
                break;
            case 2:
                this->modifyCtrl();
                break;
            case 3:
                this->getElementCtrl();
                break;
            case 4:
                this->resizeCtrl();
                break;
            case 5:
                this->theSize();
                break;
        }
    }
}