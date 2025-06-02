#pragma once
#include <Polygon.h>
#include <glm/glm.hpp>
class Box : public Polygon {
public:
    Box(float x, float y,float width, float height, glm::vec4 color, GLFWwindow* window);
    void render() override;
};