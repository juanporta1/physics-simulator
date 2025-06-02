#include <glad/glad.h> 
#include <iostream>
#include <GLFW/glfw3.h>
#include <Vertex.h>
#include <Polygon.h>
#include <glm/glm.hpp>
#include <Box.h>
#include <Circle.h>
#include <ReadFile.h>
#include <chrono>
#include <thread>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
}

void processInput(GLFWwindow* window) {
	if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
		glfwSetWindowShouldClose(window, true);
	}
}

int main() {
	float windowWidth = 1280;
	float windowHeight = 720;
	const int FPS = 60;
	const std::chrono::duration<double, std::milli> frameDuration(1000.0 / FPS);

	std::string fragmentShaderSource = readFile("fragmentShader.glsl");
	const char* fsSource = fragmentShaderSource.c_str();
	std::string vertexShaderSource = readFile("vertexShader.glsl");
	const char* vsSource = vertexShaderSource.c_str();



	if (!glfwInit()) {
		std::cout << "Failed to initialize GLFW" << std::endl;
		return -1;
	}
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, 0);

	GLFWwindow* window = glfwCreateWindow(windowWidth, windowHeight, "Physics Simulation", nullptr, nullptr);
	if (!window) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	

	glfwMakeContextCurrent(window);
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
	
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		std::cout << "Failed to initialize GLAD\n";
		return -1;
	}

	//Habilitar la transparencia
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


	//Compliacion de los Shaders
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vsSource, nullptr);
	glCompileShader(vertexShader);
	int success;
	char infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}

	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fsSource, nullptr);
	glCompileShader(fragmentShader);
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
	}


	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);

	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);

	Box square1(100.0f, 100.0f, 200.0f, 100.0f, glm::vec4(255.0f, 255.0f, 255.0f, 1.0f), window);
	Box square2(150.0f, 100.0f, 200.0f, 100.0f, glm::vec4(0.0, 255.0f, 255.0f, 0.5f), window);
	Circle c1(400.0f, 400.0f, 50.0f, 36, glm::vec4(255.0f, 255.0f, 255.0f, 1.0f), window);

	auto lastTime = std::chrono::high_resolution_clock::now();

	while (!glfwWindowShouldClose(window)) {

		auto currentTime = std::chrono::high_resolution_clock::now();
		std::chrono::duration<float> delta = currentTime - lastTime;
		float deltaTime = delta.count();
		lastTime = currentTime;

		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glUseProgram(shaderProgram);
		c1.update(deltaTime);
		c1.render();
		square1.update(deltaTime);
		square1.render();
		glfwSwapBuffers(window);
		glfwPollEvents();
		auto frameEnd = std::chrono::high_resolution_clock::now();

		
	}
	glDeleteProgram(shaderProgram);
	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}


