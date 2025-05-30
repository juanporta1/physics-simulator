#pragma once
#include <vector>

struct Vertex {
    float x, y, z;
    float r, g, b;
    std::vector<float> vertexData;

    // Constructor con conversión de píxeles a NDC
    Vertex(float pixelX, float pixelY, float pz, float pr, float pg, float pb, int screenWidth, int screenHeight) {
        x = (pixelX / (screenWidth / 2.0f)) - 1.0f;
        y =  (pixelY / (screenHeight / 2.0f)) - 1.0f; // OpenGL tiene Y invertida respecto a la pantalla
        z = pz;
        r = pr;
        g = pg;
        b = pb;
        vertexData = { x, y, z, r, g, b };
    }
};