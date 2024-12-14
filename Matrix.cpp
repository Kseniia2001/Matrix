#include "Matrix.h"
#include <vector>
#include <iostream>

SparseMatrix::SparseMatrix(int r, int c) :rows(r), cols(c) {
	IA.resize(r + 1, 0);
}

void SparseMatrix::addElement(int row, int col, double val) {
  /*  if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Индекс выходит за пределы матрицы");
    }*/
    if (val != 0) {
        for (int i = IA[row]; i < IA[row + 1]; ++i) {
            if (JA[i] == col) {
                value[i] = val;
                return;
            }
        }
        int insertPos = IA[row + 1];
        for (int i = row + 1; i <= rows; ++i) {
            IA[i]++;
        }
        value.insert(value.begin() + insertPos, val);
        JA.insert(JA.begin() + insertPos, col);
    }
}


void SparseMatrix::print() {
    for (int i = 0; i < rows; ++i) {
        int pos = IA[i];
        for (int j = 0; j < cols; ++j) {
            if (pos < IA[i + 1] && JA[pos] == j) {
                std::cout << value[pos] << " ";
                ++pos;
            }
            else {
                std::cout << "0 ";
            }
        }
        std::cout << std::endl;
    }
}