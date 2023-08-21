#include "./Headers/ship.h"
#include <cmath>

Ship::Ship() {
    this->getVertices(0, 0, 0, 1);
    indices[0] = 0;
    indices[1] = 2;
    indices[2] = 3;
    indices[3] = 1;
    indices[4] = 2;
    indices[5] = 3;
    this->setColor(0.5f, 0.7f, 0.9f);
}

void Ship::getVertices(float x, float y, float theta, float size) {
    vertices[0] = (GLfloat) x+( - 0.4f);
    vertices[1] = (GLfloat) y+( - 0.5f * 1.5 / 3);
    vertices[2] = (GLfloat) 0.0f;
    
    vertices[6] = (GLfloat) x + (0.4f);
    vertices[7] = (GLfloat) y + (-0.5f * 1.5 / 3);
    vertices[8] = (GLfloat) 0.0f;
   
    vertices[12] = (GLfloat) x+(0.0f);
    vertices[13] = (GLfloat) y+(0.5f * 1.5 * 2 / 3);
    vertices[14] = (GLfloat) 0.0f;
   
    vertices[18] = (GLfloat) x+(0.0f);
    vertices[19] = (GLfloat) y+(0.1f * 1.5 * 2 / 3);
    vertices[20] = (GLfloat) 0.0f;
   
}

void Ship::setColor(float r, float g, float b) {
    vertices[3] = (GLfloat)r;
    vertices[4] = (GLfloat)g;
    vertices[5] = (GLfloat)b;

    vertices[9] = (GLfloat)r;
    vertices[10] = (GLfloat)g;
    vertices[11] = (GLfloat)b;

    vertices[15] = (GLfloat)r;
    vertices[16] = (GLfloat)g;
    vertices[17] = (GLfloat)b;

    vertices[21] = (GLfloat)r;
    vertices[22] = (GLfloat)g;
    vertices[23] = (GLfloat)b;
}
