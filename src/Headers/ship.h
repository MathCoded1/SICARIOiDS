#ifndef SHIP_CLASS_H
#define SHIP_CLASS_H

#include "gl.h"

class Ship {
public:
    Ship();

    GLfloat vertices[24];
    GLuint indices[6];

    void getVertices(int x, int y, double theta, double size);
};

#endif
