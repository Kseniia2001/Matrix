#include <iostream>
#include <vector>
#include "Matrix.h"
int main() {
    SparseMatrix matrix1(3, 3);
    matrix1.addElement(0, 1, 1);
    matrix1.addElement(1, 1, 2);
    matrix1.addElement(2, 2, 3);

    SparseMatrix matrix2(3, 3);
    matrix2.addElement(0, 0, 4);
    matrix2.addElement(1, 1, 5);
    matrix2.addElement(2, 2, 6);

    SparseMatrix sum_matrix = matrix1 + matrix2;

    sum_matrix.print();

}