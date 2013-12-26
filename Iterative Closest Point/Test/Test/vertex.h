#ifndef _VERTEX_H
#define _VERTEX_H
#include <iostream>

#define cos120 -0.5
#define sin120 0.86

class Vertex
{
protected:
	float xPos;
	float yPos;
	float zPos;

	Vertex *neighbourPoint;
	static float a[3][3];
public:
	Vertex(){;}
	Vertex(float x, float y, float z);
	void setNeightbour(Vertex *neighbour){neighbourPoint = neighbour;}
	Vertex *getNeighbor()const {return neighbourPoint;}
	~Vertex();
	void moveBy(float x, float y, float z);
	void rotate120();

	float getX()const {return xPos;}
	float getY()const {return yPos;}
	float getZ()const {return zPos;}
};


#endif