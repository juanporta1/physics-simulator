#include "Polygon.h"
#include <GLFW/glfw3.h>
#include <iostream>


void Polygon::updateFloatData() {
    std::vector<float> data;
    for (const auto& v : vertices) {
        data.insert(data.end(), v.vertexData.begin(), v.vertexData.end());
    }
    floatData = data;
}

void Polygon::updateBuffer() {
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, floatData.size() * sizeof(float), floatData.data());
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Polygon::updateVertices(float dt) {
    float deltaX = velX * dt + 0.5f * accX * (dt * dt);
    float deltaY = velY * dt + 0.5f * accY * (dt * dt);
    for (auto& v : vertices) {
        v.updateVertexData(deltaX, deltaY);
    }
}

Polygon::Polygon(const std::vector<Vertex>& verticesList, GLFWwindow* w) : vertices(verticesList), window(w) {

	float totalPosX = 0.0f;
	float totalPosY = 0.0f;

    updateFloatData();
	

    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, floatData.size() * sizeof(float), floatData.data(), GL_DYNAMIC_DRAW);

    // Posición
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // Color
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, 7 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Polygon::~Polygon() {
    glDeleteBuffers(1, &vbo);
    glDeleteVertexArrays(1, &vao);
}

void Polygon::render() {
    glBindVertexArray(vao);
    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLsizei>(vertices.size()));
}



void Polygon::render(GLenum mode) {
    glBindVertexArray(vao);
    glDrawArrays(mode, 0, static_cast<GLsizei>(vertices.size()));
}

void Polygon::update(float deltaTime) {
    updateVertices(deltaTime);
    updateBuffer();
    updateFloatData();

    velX += accX * deltaTime;
    velY += accY * deltaTime;
}