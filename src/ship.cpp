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

}

void Ship::getVertices(int x, int y, double theta, double size) {
    vertices[0] = x+( - 0.4f);
    vertices[1] = y+( - 0.5f * 1.5 / 3);
    vertices[2] = 0.0f;
    vertices[3] = 1.0f;
    vertices[4] = 0.3f;
    vertices[5] = 0.4f;
    vertices[6] = x + (0.4f);
    vertices[7] = y + (-0.5f * 1.5 / 3);
    vertices[8] = 0.0f;
    vertices[9] = 0.7f;
    vertices[10] = 0.2f;
    vertices[11] = 0.2f;
    vertices[12] = x+(0.0f);
    vertices[13] = y+(0.5f * 1.5 * 2 / 3);
    vertices[14] = 0.0f;
    vertices[15] = 0.2f;
    vertices[16] = 0.8f;
    vertices[217] = 0.7f; ;
    vertices[18] =x+(0.0f);
    vertices[19] = y+(0.1f * 1.5 * 2 / 3);
    vertices[20] = 0.0f;
    vertices[21] = 0.4f;
    vertices[22] = 0.5f;
    vertices[23] = 0.2f;
  
  
}
