#pragma once
#include <vector>
#include <ConvertUnits.h>
struct Vertex {
    float x, y, z;
    float r, g, b, t;

    float pX, pY;
    std::vector<float> vertexData;

    float wW, wH;
    // Constructor con conversión de píxeles a NDC
    Vertex(float pixelX, float pixelY, float pz, float pr, float pg, float pb, float pt, float screenWidth, float screenHeight);

    void updateVertexData(float deltaX,float deltaY);
};
