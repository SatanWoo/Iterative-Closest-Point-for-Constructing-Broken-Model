#include "Calculator.h"
#include<cmath>
#include "math.h"

#define infinitebig 1000000000

void Calculator::findNearestVertex(Vertex **subset, DataCloudSet *dataSet, int size)
{
	for (int i = 0; i < size;i++) 
	{
		subset[i]->setNeightbour(NULL);
		findNearestVertex(subset[i], dataSet);
	}
}

void Calculator::findNearestVertex(Vertex *vertex, DataCloudSet *dataSet)
{
	int closesetIndex = -1;
	double closestDistance = infinitebig;
	for (int i = 0;i < dataSet->getCount();i++)
	{
		Vertex *re = dataSet->getVertexAt(i);
		if (re != NULL)
		{
			float result = GetDistance(vertex, re); 
			if (result < closestDistance)
			{
				closestDistance = result;
				closesetIndex = i;
			}
		}
	}
	vertex->setNeightbour(dataSet->getVertexAt(closesetIndex));
}

float Calculator::GetDistance(Vertex *a, Vertex *b)
{
	float multiply = pow((a->getX() - b->getX()),2) + pow((a->getY() - b->getY()),2) + pow((a->getZ() - b->getZ()),2);  
	return sqrt(multiply);
}

void Calculator::calculateMinmiumDistance(Vertex **subset, int size, DataCloudSet *dataSet)
{
	float xSum = 0 , ySum = 0, zSum = 0;
	/*for (int i = 0;i < size;i ++)
	{
		xSum += fabs(subset[i]->getX() - subset[i]->getNeighbor()->getX());
		ySum += fabs(subset[i]->getY() - subset[i]->getNeighbor()->getY());
		zSum += fabs(subset[i]->getZ() - subset[i]->getNeighbor()->getZ());
	}*/

	/*xSum /= size;
	ySum /= size;
	zSum /= size;*/

	for (int i = 0;i < size;i ++)
	{
		xSum += subset[i]->getX() - subset[i]->getNeighbor()->getX();
		ySum += subset[i]->getY() - subset[i]->getNeighbor()->getY();
		zSum += subset[i]->getZ() - subset[i]->getNeighbor()->getZ();
	}

	xSum = getInvertNumber(size, xSum);
	ySum = getInvertNumber(size, ySum);
	zSum = getInvertNumber(size, zSum);
	for (int i = 0;i < dataSet->getCount();i ++) dataSet->getVertexAt(i)->moveBy(xSum, ySum, zSum);
}

float Calculator::getInvertNumber(int size, int parameter)
{
	float result = 0;
	parameter = -1 * parameter;
	result = parameter / size;
	return result;
}



