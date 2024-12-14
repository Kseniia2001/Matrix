#include "Matrix.h"
#include <vector>
#include <iostream>

SparseMatrix::SparseMatrix(int r, int c) :rows(r), cols(c) {
	IA.resize(r + 1, 0);
}

void SparseMatrix::addElement(int row, int col, double val) {
   if (row < 0 || row >= rows || col < 0 || col >= cols) {
        throw std::out_of_range("Индекс выходит за пределы матрицы");
    }
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

SparseMatrix SparseMatrix::operator+(const SparseMatrix& matrix) {
    if (rows != matrix.rows || cols != matrix.cols) {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }

    SparseMatrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        int row_start_1 = IA[i], row_next_1 = IA[i + 1];
        int row_start_2 = matrix.IA[i], row_next_2 = matrix.IA[i + 1];

        while (row_start_1 < row_next_1 || row_start_2 < row_next_2) {
            if (row_start_1 < row_next_1 && (row_start_2 >= row_next_2 || JA[row_start_1] < matrix.JA[row_start_2])) {
                result.addElement(i, JA[row_start_1], value[row_start_1]);
                ++row_start_1;
            }
            else if (row_start_2 < row_next_2 && (row_start_1 >= row_next_1 || matrix.JA[row_start_2] < JA[row_start_1])) {
                result.addElement(i, matrix.JA[row_start_2], matrix.value[row_start_2]);
                ++row_start_2;
            }
            else {
                double sum = value[row_start_1] + matrix.value[row_start_2];
                if (sum != 0) {
                    result.addElement(i, JA[row_start_1], sum);
                }
                ++row_start_1;
                ++row_start_2;
            }
        }
    }

    return result;
}

SparseMatrix SparseMatrix::operator-(const SparseMatrix& matrix) {
    if (rows != matrix.rows || cols != matrix.cols) {
        throw std::invalid_argument("Размеры матриц не совпадают");
    }

    SparseMatrix result(rows, cols);

    for (int i = 0; i < rows; ++i) {
        int row_start_1 = IA[i], row_next_1 = IA[i + 1];
        int row_start_2 = matrix.IA[i], row_next_2 = matrix.IA[i + 1];

        while (row_start_1 < row_next_1 || row_start_2 < row_next_2) {
            if (row_start_1 < row_next_1 && (row_start_2 >= row_next_2 || JA[row_start_1] < matrix.JA[row_start_2])) {
                result.addElement(i, JA[row_start_1], value[row_start_1]);
                ++row_start_1;
            }
            else if (row_start_2 < row_next_2 && (row_start_1 >= row_next_1 || matrix.JA[row_start_2] < JA[row_start_1])) {
                result.addElement(i, matrix.JA[row_start_2], -matrix.value[row_start_2]);
                ++row_start_2;
            }
            else {
                double sum = value[row_start_1] - matrix.value[row_start_2];
                if (sum != 0) {
                    result.addElement(i, JA[row_start_1], sum);
                }
                ++row_start_1;
                ++row_start_2;
            }
        }
    }

    return result;
}


 std::vector<double> SparseMatrix::operator*(const std::vector<double>& vec) {
     if (cols != vec.size()) {
         throw std::invalid_argument("Размер вектора не соответствует количеству столбцов матрицы");
     }

     std::vector<double> result(rows, 0.0);

     for (int i = 0; i < rows; ++i) {
         for (int j = IA[i]; j < IA[i + 1]; ++j) {
             result[i] += value[j] * vec[JA[j]];
         }
     }

     return result;
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