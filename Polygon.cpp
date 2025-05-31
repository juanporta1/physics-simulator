#include "Polygon.h"
#include <iostream>

Polygon::Polygon(const std::vector<Vertex>& verticesList) : vertices(verticesList) {
    std::vector<float> floatData;

	float totalPosX = 0.0f;
	float totalPosY = 0.0f;

    // Pasamos los datos a un vector de floats
    for (const auto& v : vertices) {
        floatData.insert(floatData.end(), v.vertexData.begin(), v.vertexData.end());
	
    }

	
    std::cout << posX << std::endl;
	std::cout << posY << std::endl;

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
    



    render();
}