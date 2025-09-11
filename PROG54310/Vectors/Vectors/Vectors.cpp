// Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define GLM_ENABLE_EXPERIMENTAL

#include <string>
#include <iostream>
#include <vector>
#include "Matrix.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

extern void exportOBJ(std::vector<glm::vec3> a, std::vector<glm::vec3> b, std::string filename);

float square(float in) {
	return in * in;
}

glm::vec3 PromptVector() {
	glm::vec3 v = { 0,0,0 };
	std::cout << "x: ";
	std::cin >> v.x;
	std::cout << "y: ";
	std::cin >> v.y;
	std::cout << "z: ";
	std::cin >> v.z;
	std::cout << "Created vector: " << glm::to_string(v) << std::endl;
	return v;
}

void Task1() {
	float stepSize;
	std::cout << "Enter starting position." << std::endl;
	glm::vec3 start = PromptVector();
	std::cout << "Enter ending position." << std::endl;
	glm::vec3 end = PromptVector();
	std::cout << "Step size: ";
	std::cin >> stepSize;
	float stepCount = glm::distance(end, start) / stepSize;
	std::cout << stepCount << " step(s) must be taken to get from " << glm::to_string(start) << " to " << glm::to_string(end) << "." << std::endl;
}

void Task2() {
	glm::vec3 tri[3];
	for (int i = 0; i < 3; i++) {
		std::cout << "Enter vertex #" << i << "." << std::endl;
		tri[i] = PromptVector();
	}
	float perimeter = glm::distance(tri[0], tri[1]) + glm::distance(tri[1], tri[2]) + glm::distance(tri[2], tri[0]);
	// Area calculation, according to Math Stack Exchange: https://math.stackexchange.com/a/1710728
	float area = 0.5f * sqrt(square(glm::distance(tri[0], tri[1])) * square(glm::distance(tri[0], tri[2])) - square(glm::dot(tri[1] - tri[0], tri[2] - tri[0])));
	std::cout << "Triangle perimeter: " << perimeter << "." << std::endl << "Triangle area: " << area << " (pending implementation)." << std::endl;
}

void Task3() {
	const int vertCountPerFace = 4;
	std::vector<glm::vec3> planeA = std::vector<glm::vec3>(vertCountPerFace);
	for (int i = 0; i < 3; i++) {
		std::cout << "Enter vertex #" << i << "." << std::endl;
		planeA[i] = PromptVector();
	}
	planeA[3] = planeA[2] + planeA[1] - planeA[0];
	std::cout << "Extrude depth: ";
	float depth = 0;
	std::cin >> depth;
	glm::vec3 extrudeDelta = glm::normalize(glm::cross(planeA[1] - planeA[0], planeA[2] - planeA[0])) * depth;
	std::vector<glm::vec3> planeB;
	planeB.resize(vertCountPerFace);
	std::cout << "Resulting cuboid:\n";
	for (int i = 0; i < planeB.size(); i++) {
		planeB[i] = planeA[i] + extrudeDelta;
		std::cout << glm::to_string(planeA[i]) << std::endl << glm::to_string(planeB[i]) << std::endl;
	}
	exportOBJ(planeA, planeB, "Task3.obj");
}

void Task4Hardcoded() {
	int size;
	std::cout << "size (GLM calculations will only be performed on 2x2 and 3x3 matrices): ";
	size = 3;
	std::cout << size << std::endl;
	std::cout << "enter data for first matrix:\n";
	Matrix m1 = Matrix(size, size); //Example values acquired from slide 36
	m1.Set(0, 0,  3); m1.Set(1, 0,  -8); m1.Set(2, 0, 12);
	m1.Set(0, 1, 15); m1.Set(1, 1,  14); m1.Set(2, 1, -2);
	m1.Set(0, 2, 32); m1.Set(1, 2, 0.5); m1.Set(2, 2,  1);
	glm::mat3 glm1;
	          glm1[0][0] =  3;			  glm1[1][0] = -8;			  glm1[2][0] = 12;
	          glm1[0][1] = 15;			  glm1[1][1] = 14;			  glm1[2][1] = -2;
	          glm1[0][2] = 32;			  glm1[1][2] =0.5;			  glm1[2][2] =  1;
	std::cout << m1.to_string();
	std::cout << "enter data for second matrix:\n";
	Matrix m2 = Matrix(size, size);
	m2.Set(0, 0, -4); m2.Set(1, 0, 12); m2.Set(2, 0, 3);
	m2.Set(0, 1, -8); m2.Set(1, 1,  2); m2.Set(2, 1, 8);
	m2.Set(0, 2, 16); m2.Set(1, 2, -4); m2.Set(2, 2, 0);
	glm::mat3 glm2;
			  glm2[0][0] = -4;			  glm2[1][0] = 12;			  glm2[2][0] =  3;
			  glm2[0][1] = -8;			  glm2[1][1] =  2;			  glm2[2][1] =  8;
			  glm2[0][2] = 16;			  glm2[1][2] = -4;			  glm2[2][2] =  0;
	std::cout << m2.to_string();
	std::cout << "matrix sum:\n" << (m1+m2).to_string();
	std::cout << "matrix sum (glm):\n" << glm::to_string(glm1+glm2) << std::endl;
	std::cout << "matrix diff:\n" << (m1-m2).to_string();
	std::cout << "matrix diff (glm):\n" << glm::to_string(glm1-glm2) << std::endl;
	std::cout << "matrix mult:\n" << (m1*m2).to_string();
	std::cout << "matrix mult (glm):\n" << glm::to_string(glm1*glm2) << std::endl;
}

int main() {
	bool quit = false;
	while (!quit) {
		std::cout << "Enter a task number between 1 and 4 (inclusive), or Q to quit: ";
		char in;
		std::cin >> in;
		switch (in) {
			case 'q':
			case 'Q':
				quit = true;
				break;
			case '1':
				Task1();
				break;
			case '2':
				Task2();
				break;
			case '3':
				Task3();
				break;
			case '4':
				Task4Hardcoded();
				break;
			default:
				std::cout << "Invalid input." << std::endl;
		}
	}
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
