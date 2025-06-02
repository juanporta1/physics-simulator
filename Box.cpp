#include <Box.h>
#include <Vertex.h>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>
#include <vector>

std::vector<Vertex> getVertices(float x, float y, glm::vec4 color, float width, float height, GLFWwindow* window) {

	int wW, wH;
	glfwGetWindowSize(window, &wW, &wH);
	std::vector<Vertex> vertices = {
			Vertex(x,y,0.0f,color[0], color[1], color[2], color[3],wW, wH),
			Vertex(x,y + height,0.0f,color[0], color[1], color[2], color[3],wW, wH),
			Vertex(x + width,y + height,0.0f,color[0], color[1], color[2], color[3],wW, wH),
			Vertex(x + width,y,0.0f,color[0], color[1], color[2], color[3],wW, wH),
	};
	return vertices;
};

Box::Box(float x, float y, float width, float height, glm::vec4 color, GLFWwindow* window)
	:Polygon(getVertices(x,y,color,width,height, window), window)
{}


void Box::render() {
	Polygon::render(GL_TRIANGLE_FAN);
}