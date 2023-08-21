#include "./Headers/asteroid.h"
#include<cmath>
Asteroid::Asteroid(float x, float y, float radius){
this->getVertices(x, y, radius);
}

void Asteroid::getVertices(float x, float y, float radius) {
	float circleRadius = radius;
	float centerX = x; // Custom x-coordinate for the center of the circle
	float centerY = y; // Custom y-coordinate for the center of the circle
	// Calculate the circle vertices around the custom center position
	for (int i = 0; i < 8; ++i) {
		float angle = 2 * 3.14f * static_cast<float>(i) / 8;
		vertices[i * 5] = x + radius* cos(angle);  // x-coordinate
		vertices[i * 5 + 1] =y + radius * sin(angle);  // y-coordinate
		vertices[i * 5 + 2] = 1.0f; // Red color
		vertices[i * 5 + 3] = 0.0f; // Green color
		vertices[i * 5 + 4] = 0.0f; // Blue color
	}
	// Define indices for the circle vertices
	
	for (int i = 0; i < 8; ++i) {
		indices[i] = i;
	}
}