#pragma once
#include <vector>
#include <glad/glad.h>
#include "Vertex.h"

class Polygon {
public:
    GLuint vao, vbo;
    std::vector<Vertex> vertices;

    Polygon(const std::vector<Vertex>& verticesList);
    ~Polygon();
    virtual void render(GLenum mode = GL_TRIANGLES);
    virtual void render();
};
