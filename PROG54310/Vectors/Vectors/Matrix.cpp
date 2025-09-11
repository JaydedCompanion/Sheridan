//
// Created by Jayde Iris Callejas on 2025-09-10.
//

#include <string>
#include <iostream>
#include <vector>
#include "Matrix.h"

Matrix::Matrix(const int x, const int y) {
	matrix = std::vector<std::vector<float>>(x);
	for (int i = 0; i < x; i++) {
		matrix[i] = std::vector<float>(y);
	}
}
Matrix::Matrix(const Matrix* other) {
	matrix = std::vector<std::vector<float>>(other->SizeX());
	for (int x = 0; x < matrix.size(); x++) {
		matrix[x] = std::vector<float>(other->SizeY());
		for (int y = 0; y < matrix[x].size(); y++)
			matrix[x][y] = other->matrix[x][y];
	}
}
float Matrix::Get(int x, int y) const {
	return matrix[x][y];
}
void Matrix::Set(int x, int y, float value) {
	matrix[x][y] = value;
}
int Matrix::SizeX() const {
	return matrix.size();
}
int Matrix::SizeY() const {
	if (Matrix::matrix.size() == 0)
		return 0;
	else
		return Matrix::matrix[0].size();
}
std::string Matrix::to_string() const {
	std::string out = "";
	for (int i = 0; i < matrix.size(); i++) {
		out += "| ";
		for (int j = 0; j < matrix[i].size(); j++)
			out += std::to_string(matrix[i][j]) + ' ';
		out += "|\n";
	}
	return out;
}
Matrix Matrix::operator+ (const Matrix& other) {
	Matrix result = Matrix(other);
	for (int x = 0; x < result.SizeX(); x++)
		for (int y = 0; y < result.SizeY(); y++)
			result.matrix[x][y] += matrix[x][y];
	return result;
}
Matrix Matrix::operator- (const Matrix& other) {
	Matrix result = Matrix(other);
	for (int x = 0; x < result.SizeX(); x++)
		for (int y = 0; y < result.SizeY(); y++)
			result.matrix[x][y] = matrix[x][y] - other.matrix[x][y];
	return result;
}
Matrix Matrix::operator* (const Matrix& other) {
	int minDimension = std::min(std::min(std::min(SizeX(), SizeY()), other.SizeX()), other.SizeY());
	Matrix result = Matrix(minDimension, minDimension);
	for (int x = 0; x < result.SizeX(); x++)
		for (int y = 0; y < result.SizeY(); y++) {
			float sum = 0;
			for (int diag = 0; diag < result.SizeY(); diag++) {
				sum += matrix[diag][y] * other.matrix[x][diag];
			}
			result.Set(x, y, sum);
			sum = 0;
		}
	return result;
}