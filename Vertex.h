#include <glm/glm.hpp>
#include <vector>
#include <array>
class Vertex {
public:
    float x, y, z;
    glm::vec3 color;
    std::array<float, 6> vertexData;

    Vertex(float xIn, float yIn, float zIn, const glm::vec3& c)
        : x(xIn), y(yIn), z(zIn), color(c)
    {
        vertexData = { x, y, z, c.r, c.g, c.b };
    }
}; 