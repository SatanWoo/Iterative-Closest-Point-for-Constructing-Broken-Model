#include "DataCloudSet.h"


void DataCloudSet::addVertex(Vertex *vertex)
{
	vetex.push_back(vertex);
}

DataCloudSet::DataCloudSet()
{

}

void DataCloudSet::print()
{
	cout << "Count of vector is " << vetex.size() << endl;
}

Vertex *DataCloudSet::getVertexAt(int i)
{
	if (i < 0 || i >= vetex.size())
		return NULL;
	return vetex[i];
}

Vertex **DataCloudSet::subSet(int start, int count)
{
	if (start < 0 || (start + count) >= vetex.size()) return NULL;
	Vertex **subset = new Vertex *[count];
	for (int i = start; i < count;i ++)
	{
		subset[i] = new Vertex();
		subset[i] = vetex[i];
	}
	return subset;
}



