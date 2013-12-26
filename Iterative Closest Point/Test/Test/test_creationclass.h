
#ifndef TEST_CREATIONCLASS_H
#define TEST_CREATIONCLASS_H

#include "dl_creationadapter.h"
#include "DataCloudSet.h"

class WUDXFParser : public DL_CreationAdapter {
public:
    WUDXFParser();
	~WUDXFParser();

    virtual void addLayer(const DL_LayerData& data);
    virtual void addPoint(const DL_PointData& data);
    virtual void addLine(const DL_LineData& data);
    virtual void addArc(const DL_ArcData& data);
    virtual void addCircle(const DL_CircleData& data);
    virtual void addPolyline(const DL_PolylineData& data);
    virtual void addVertex(const DL_VertexData& data);
    virtual void add3dFace(const DL_3dFaceData& data);

    void printAttributes();

	DataCloudSet *getCloudSet()const {return cloud;}

	//void print(){cout << "Count is " << count << endl; cloud->print();}
protected:
	DataCloudSet *cloud;
};

#endif
