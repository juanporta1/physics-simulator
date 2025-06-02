#include <Circle.h>
#include <Vertex.h>
#include <glm/glm.hpp>
#include <vector>
#include <GLFW/glfw3.h>


std::vector<Vertex> getCircleVertices(float x, float y, float radius, int segments, glm::vec4 color, GLFWwindow* window) {
	std::vector<Vertex> vertices;
	int wW, wH;
	glfwGetWindowSize(window, &wW, &wH);


	vertices.push_back(Vertex(x, y, 0.0f, color[0], color[1], color[2], color[3], wW, wH));

	for (int i = 0; i <= segments; i++) {
		float angle = 2.0f * 3.14159265359 * i / segments;
		float vertexX = x + sin(angle) * radius;
		float vertexY = x + cos(angle) * radius;
		vertices.push_back(Vertex(vertexX, vertexY, 0.0f, color[0], color[1], color[2], color[3], wW, wH));
	}
	return vertices;
}

Circle::Circle(float x, float y, float radius, int segments, glm::vec4 color, GLFWwindow* window)
	:Polygon({
			getCircleVertices(x, y, radius, segments,color,window)
		}, window)
{
	
}


void Circle::render() {
	Polygon::render(GL_TRIANGLE_FAN);
}

void Circle::update(float dt) {
	Polygon::update(dt);
	
	if (vertices[0].x < -1.0f) {
		velX = 900.0f;
	}
	if (vertices[0].x > 1.0f) {
		velX = -900.0f;
	}
	if (vertices[0].y < -1.0f) {
		velY = 900.0f;
	}
	if (vertices[0].y > 1.0f) {
		velY = -900.0f;
	}
	
}

