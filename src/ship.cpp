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
   
    
    vertices[5] = (GLfloat) x + (0.4f);
    vertices[6] = (GLfloat) y + (-0.5f * 1.5 / 3);

   
    vertices[10] = (GLfloat) x+(0.0f);
    vertices[11] = (GLfloat) y+(0.5f * 1.5 * 2 / 3);
    
   
    vertices[15] = (GLfloat) x+(0.0f);
    vertices[16] = (GLfloat) y+(0.1f * 1.5 * 2 / 3);
  
   
}

void Ship::setColor(float r, float g, float b) {
    vertices[2] = (GLfloat)r;
    vertices[3] = (GLfloat)g;
    vertices[4] = (GLfloat)b;

    vertices[7] = (GLfloat)r;
    vertices[8] = (GLfloat)g;
    vertices[9] = (GLfloat)b;

    vertices[12] = (GLfloat)r;
    vertices[13] = (GLfloat)g;
    vertices[14] = (GLfloat)b;

    vertices[17] = (GLfloat)r;
    vertices[18] = (GLfloat)g;
    vertices[19] = (GLfloat)b;
}
