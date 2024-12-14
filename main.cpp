#include <iostream>
#include <vector>
#include "Matrix.h"
int main() {
    SparseMatrix matrix1(3, 3);
    matrix1.addElement(0, 1, 1);
    matrix1.addElement(0, 2, 1);
    matrix1.addElement(1, 0, 2);
    matrix1.addElement(1, 1, 4);
    matrix1.addElement(1, 2, 6);
    matrix1.addElement(2, 0, 1);

    std::cout << "Matrix_1" << "\n";
    matrix1.print();
   
    SparseMatrix matrix2(3, 3);
    matrix2.addElement(0, 2, 7);
    matrix2.addElement(1, 0, 5);
    matrix2.addElement(1, 1, 10);
    matrix2.addElement(1, 2, 9);
    matrix2.addElement(2, 1, 6);

    std::cout << "Matrix_2" << "\n";
    matrix2.print();
    
    SparseMatrix sum_matrix = matrix1 + matrix2;
    SparseMatrix diff_matrix = matrix2 - matrix1;

    std::cout << "Sum_matrix" << "\n";
    sum_matrix.print();

    std::cout << "Diff_matrix" << "\n";
    diff_matrix.print();

}