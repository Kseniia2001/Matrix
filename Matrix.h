#include <vector>
class SparseMatrix {
private:
	int rows, cols;
	std::vector<double> value; // значения ненулевых элементов
	std::vector<int> JA; // индексы столбцов для каждого ненулевого элемента
	std::vector<int> IA; // указатели начала каждой строки в value и JA
public:
	SparseMatrix(int r, int c); //конструктор
	void addElement(int row, int col, double val); //добавление элементов в разреженную матрицу
	void print();//вывод матрицы
	SparseMatrix operator+(const SparseMatrix& matrix); //сложение матриц
	SparseMatrix operator-(const SparseMatrix& matrix); //вычитание матриц
};