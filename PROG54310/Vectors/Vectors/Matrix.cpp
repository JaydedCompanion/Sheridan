
#include <string>
#include <iostream>
#include <vector>

class Matrix {
	std::vector<std::vector<float>> matrix;
	Matrix(int x, int y) {
		matrix.resize(x);
		for (int i = 0; i < matrix.size(); i++)
			matrix[i].resize(y);
	}
	Matrix(const Matrix* other) {
		matrix.resize(other->SizeX());
		for (int i = 0; i < matrix.size(); i++) {
			matrix[i].resize(other->SizeY());
			for (int j = 0; j < matrix[i].size(); j++)
				matrix[i][j] = other[i][j];
		}
	}
	void Set(int x, int y, float value) {
		matrix[x][y] = value;
	}
	const int SizeX(){
		return matrix.size();
	}
	const int SizeY() {
		if (matrix.size() == 0)
			return 0;
		else
			return matrix[0].size();
	}
	std::string to_string(Matrix const& self) {
		std::string out = "";
		for (int i = 0; i < matrix.size(); i++) {
			out += "| ";
			for (int j = 0; j < matrix[i].size(); i++)
				out += matrix[i][j] + ' ';
			out += "|";
		}
		return out;
	}
	Matrix operator+ (Matrix& other) {
		Matrix result = new Matrix(this*);
		for (int i = 0; i < other.SizeX(); i++)
			for (int j = 0; j < other.SizeY(); i++)
				
	}
	Matrix operator- (Matrix& other) {

	}
	Matrix operator* (Matrix& other) {

	}
};