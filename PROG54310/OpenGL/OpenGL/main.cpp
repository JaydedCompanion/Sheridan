#include <vector>
#include <cassert>
#include <string>
#include <iostream>

// Windows specific includes and defines
#ifdef _WIN32
#include <Windows.h>
#endif

// OpenGL Helper headers
#include <GL/glew.h>	//Include GLEW
#include <GLFW/glfw3.h> //Include GLFW
#include <glm/glm.hpp>	//Include GLM

void error_callback(int code, const char* description) {

}

GLFWwindow* Initialize() {

	GLFWwindow* _window = nullptr;

	auto assertPlaceholder = glfwInit();
	glfwSetErrorCallback(error_callback);
	// assert(assertPlaceholder, "Failed to initialize GLFW.");	// Initialize GLFW

	glfwWindowHint(GLFW_SAMPLES, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1); //macOS only supports OpenGL 3.2 or above. On OpenGL 3.2 or above, not passing a shader results in the triangle not appearing. I tried running in compatibility mode, but macOS doesn't support that, only Core.
	_window = glfwCreateWindow(1024, 768, "A sample scene!", NULL, NULL);
	// assert(_window != nullptr, "Failed to open a GLFW window.");
	glfwMakeContextCurrent(_window);
	glfwSwapInterval(0);

	assertPlaceholder = glewInit();
	// assert(assertPlaceholder == GLEW_OK, throw std::exception());
	glfwSetInputMode(_window, GLFW_STICKY_KEYS, GL_TRUE); // Ensure we can capture the escape key
	glClearColor(247 / 255.0f, 176 / 255.0f, 222 / 255.0f, 0.0f);

	return _window;

}

int main(void) {

	GLFWwindow* window = Initialize();

	GLuint vertexBuffer = 0;
	std::vector<GLfloat> vertexData;

	vertexData = {
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f, 1.0f, 0.0f
	};
	volatile GLenum error = glGetError();
	glGenBuffers(1, &vertexBuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
	glBufferData(GL_ARRAY_BUFFER, vertexData.size() * sizeof(float), vertexData.data(), GL_STATIC_DRAW);

	double frameTime = 0;
	double frameTimeLast = 0;

	do {
		glClear(GL_COLOR_BUFFER_BIT); // Clear the screen

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
		glVertexAttribPointer(
			0,				// attribute 0. No particular reason for 0, but must match the layout in the shader
			3,				// size
			GL_FLOAT,		// type
			GL_FALSE,		// normalized?
			0,				// stride
			(void*)0		// array buffer offset
		);
		// Draw the triangle!
		glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
		glDisableVertexAttribArray(0);

		glfwSwapBuffers(window); // Swap the front and back buffers
		glfwPollEvents();

		//#ifdef DEBUG
		frameTime = glfwGetTime();
		std::cout << std::to_string(1/(frameTimeLast - frameTime)) << "\n";
		frameTimeLast = frameTime;
		//#endif

	} while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0);

	glDeleteBuffers(1, &vertexBuffer);
	glfwTerminate();

	return 0;

}