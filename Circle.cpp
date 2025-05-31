#include <Circle.h>
#include <Vertex.h>
#include <glm/glm.hpp>
#include <vector>

std::vector<Vertex> getCircleVertices(float x, float y, float radius, int segments, glm::vec4 color, float& wW, float& wH) {
	std::vector<Vertex> vertices;
	for (int i = 0; i < segments; i++) {
		float angle = 2.0f * 3.14159265359 * i / segments;
		float vertexX = x + sin(angle) * radius;
		float vertexY = x + cos(angle) * radius;
		vertices.push_back(Vertex(vertexX, vertexY, 0.0f, color[0], color[1], color[2], color[3], wW, wH));
	}
	return vertices;
}

Circle::Circle(float x, float y, float radius, int segments, glm::vec4 color, float& wW, float& wH)
	:Polygon({
			getCircleVertices(x, y, radius, segments,color, wW, wH)
		})
{
}


void Circle::render() {
	Polygon::render(GL_TRIANGLE_FAN);
}

