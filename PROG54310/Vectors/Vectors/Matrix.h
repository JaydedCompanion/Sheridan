//
// Created by Jayde Iris Callejas on 2025-09-10.
//

#ifndef MATRIX_H
#define MATRIX_H

class Matrix {
	private:
	Matrix();
	std::vector<std::vector<float>> matrix;
    public:
    Matrix(int x, int y);
	Matrix(const Matrix *other);
	int SizeX() const;
    int SizeY() const;
	float Get(int x, int y) const;
    void Set(int x, int y, float value);
    std::string to_string() const;
	Matrix operator+ (const Matrix& other);
	Matrix operator- (const Matrix& other);
	Matrix operator* (const Matrix& other);
};

#endif //MATRIX_H
