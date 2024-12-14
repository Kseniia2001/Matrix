#include <iostream>
#include <vector>
#include "Matrix.h"
int main() {
    SparseMatrix mat1(3, 3);
    mat1.addElement(0, 1, 1);
    mat1.addElement(1, 1, 2);
    mat1.addElement(2, 2, 3);

    mat1.print();

}