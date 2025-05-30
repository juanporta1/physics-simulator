#include <Box.h>
#include <Vertex.h>
#include <glm/glm.hpp>
Box::Box(float x, float y, float width, float height, glm::vec3 color, float& wW, float& wH)
	:Polygon({
			Vertex(x,y,0.0f,color[0], color[1], color[2],wW, wH),
			Vertex(x,y + height,0.0f,color[0], color[1], color[2],wW, wH),
			Vertex(x + width,y + height,0.0f,color[0], color[1], color[2],wW, wH),
			Vertex(x + width,y,0.0f,color[0], color[1], color[2],wW, wH),
		})
{}


void Box::render() {
	Polygon::render(GL_TRIANGLE_FAN);
}