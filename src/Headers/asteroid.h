#ifndef ASTEROID_CLASS_H
#define ASTEROID_CLASS_H

#include"gl.h"


class Asteroid {
public:
	Asteroid(float x, float y, float radius);
	const int numCircleVertices = 8;
	float circleRadius;

	float centerX;
	float centerY;
	GLfloat vertices[40];
	GLuint indices[8];
	void getVertices(float x, float y, float radius);
};

#endif