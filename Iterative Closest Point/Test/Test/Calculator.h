#ifndef _CALCULATOR_H
#define _CALCULATOR_H

#include "DataCloudSet.h"
#include "vertex.h"

class Calculator {
public:
	static void calculateMinmiumDistance(Vertex **subset, int size, DataCloudSet *dataSet);
	static void findNearestVertex(Vertex **subset, DataCloudSet *dataSet, int size);
	static float getInvertNumber(int size, int parameter);
protected:
	static void findNearestVertex(Vertex *vertex, DataCloudSet *dataSet);
	static float GetDistance(Vertex *a, Vertex *b);
};

#endif