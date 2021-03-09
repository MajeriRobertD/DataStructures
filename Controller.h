#include"SparseMatrix.h"


class Controller
{
private:
    SparseMatrix matrix = SparseMatrix{nullptr, nullptr, 10, 10 };
public:
    Controller();
    ~Controller(){}

    void searchCtrl();
    void run();
private:
    static void printMenu();

    void modifyCtrl();

    void getElementCtrl();
    void resizeCtrl();
    void theSize();

};