// Vectors.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define GLM_ENABLE_EXPERIMENTAL

#include <string>
#include <iostream>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

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

int main(){
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
