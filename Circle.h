#pragma once
#include <Polygon.h>
#include <glm/glm.hpp>
class Circle : public Polygon {
public:
    Circle(float x, float y, float radius, int segments, glm::vec4 color, float& wW, float& wH);
    void render() override;
};