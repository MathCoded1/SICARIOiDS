#ifndef SHIP_CLASS_H
#define SHIP_CLASS_H

#include "gl.h"

class Ship {
public:
    Ship();

    GLfloat vertices[20];
    GLuint indices[6] =
    {
        0, 2, 3,
        1, 2, 3
};

    void getVertices(float x, float y, float theta, float size);
    void setColor(float r, float g, float b);
};

#endif
