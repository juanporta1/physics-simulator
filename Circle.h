#pragma once  
#include <Polygon.h>  
#include <glm/glm.hpp>  
#include <GLFW/glfw3.h>  

class Circle : public Polygon {  
public:  
    Circle(float x, float y, float radius, int segments, glm::vec4 color, GLFWwindow* window);  
    void render() override;  
    void update(float deltaTime) override; 
};