#pragma once
#include <vector>
#include <glad/glad.h>
#include "Vertex.h"

class Polygon {
public:
    GLuint vao, vbo;
    std::vector<Vertex> vertices;
    float velX = 0.0f, velY = 0.0f;  
    float posX = 0.0f, posY = 0.0f;  
	

    Polygon(const std::vector<Vertex>& verticesList);
    ~Polygon();
    virtual void render(GLenum mode);
    virtual void render();

    virtual void update(float deltaTime);
};
