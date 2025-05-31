#include <Vertex.h>

Vertex::Vertex(float pixelX, float pixelY, float pz, float pr, float pg, float pb, float pt, float screenWidth, float screenHeight) {

    pX = pixelX;
    pY = pixelY;
    wW = screenWidth;
    wH = screenHeight;
    z = pz;
    r = convertUnits(pr);
    g = convertUnits(pg);
    b = convertUnits(pb);
    t = pt;
    updateVertexData(0.0f, 0.0f);
}

void Vertex::updateVertexData(float deltaX, float deltaY) {
    pX += deltaX;
    pY += deltaY;

    x = convertUnits(pX, wW);
    y = convertUnits(pY, wH);
    vertexData = { x, y, z, r, g, b, t };
}
