#include <vector>
class SparseMatrix {
private:
	int rows, cols;
	std::vector<double> value; // �������� ��������� ���������
	std::vector<int> JA; // ������� �������� ��� ������� ���������� ��������
	std::vector<int> IA; // ��������� ������ ������ ������ � value � JA
public:
	SparseMatrix(int r, int c); //�����������
	void addElement(int row, int col, double val); //���������� ��������� � ����������� �������
	void print();//����� �������
	//SparseMatrix operator+(const SparseMatrix& matrix) const; //�������� ������
	//SparseMatrix operator-(const SparseMatrix& matrix) const; //��������� ������
	//SparseMatrix operator*(const SparseMatrix& matrix) const; //��������� ������
	//std::vector<double> operator*(const std::vector<double>& vec) const; //��������� ������� �� ������
};