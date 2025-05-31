#pragma once
#include <vector>

struct Vertex {
    float x, y, z;
    float r, g, b, t;

    float nX, nY;
    std::vector<float> vertexData;

    // Constructor con conversión de píxeles a NDC
    Vertex(float pixelX, float pixelY, float pz, float pr, float pg, float pb,float pt, int screenWidth, int screenHeight): nX(pixelX), nY(pixelY) {
        x = (pixelX / (screenWidth / 2.0f)) - 1.0f;
        y =  (pixelY / (screenHeight / 2.0f)) - 1.0f; // OpenGL tiene Y invertida respecto a la pantalla
        z = pz / 255;
        r = pr / 255;
        g = pg / 255;
        b = pb / 255;
		t = pt;
        vertexData = { x, y, z, r, g, b, t };
    }
};