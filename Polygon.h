#pragma once
#include <vector>
#include <glad/glad.h>
#include "Vertex.h"
class Polygon {
private:
    void updateBuffer();
    void updateFloatData();
    void updateVertices(float dt);
public:
    GLuint vao, vbo;
    std::vector<Vertex> vertices;
    float velX = 0.0f, velY = 0.0f;  
    float accX = 0.0f, accY = -600.0f;
    std::vector<float> floatData;
	

    Polygon(const std::vector<Vertex>& verticesList);
    ~Polygon();
    virtual void render(GLenum mode);
    virtual void render();
      
    virtual void update(float deltaTime);
};
