#include "./Headers/asteroid.h"
#include<cmath>
Asteroid::Asteroid(){
float circleRadius = 0.1f;
float centerX = 0.8f; // Custom x-coordinate for the center of the circle
float centerY = 0.8f; // Custom y-coordinate for the center of the circle
this->getVertices(0.8f, 0.8f, 0.1f);
}

void Asteroid::getVertices(float x, float y, float radius) {
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