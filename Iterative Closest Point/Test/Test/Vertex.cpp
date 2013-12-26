#include "vertex.h"

float Vertex::a[3][3] = {{cos120, -sin120, 0}, {sin120, cos120, 0} ,{0 ,0 ,1}};

Vertex::Vertex(float x, float y, float z)
{
	xPos = x;
	yPos = y;
	zPos = z;
	neighbourPoint = NULL;
	//rotate120();
}

void Vertex::moveBy(float x, float y, float z)
{
	xPos += x;
	yPos += y;
	zPos += z;
}

void Vertex::rotate120()
{
	float xOld = xPos;
	float yOld = yPos;
	xPos = cos120 * xOld + (-sin120 * yOld);
	yPos = sin120 * xOld + cos120 * yOld;
	zPos = zPos;
}