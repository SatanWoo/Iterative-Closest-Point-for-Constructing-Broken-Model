#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "dl_dxf.h"
#include "dl_creationadapter.h"
#include "Calculator.h"

#include "test_creationclass.h"

#define kNumber 500
#define kIterative 30

WUDXFParser* parseDXF(char* file);
void writeToDXF(DataCloudSet *set, DataCloudSet *set2, DataCloudSet *set3);
void writeVertex(DL_WriterA *dw, DL_Dxf *dxf, Vertex *vertex);

int main(int argc, char** argv) {
	// Step 1: Read into vertex 
	WUDXFParser *firstPart = parseDXF("0004.dxf");
	WUDXFParser *secondPart = parseDXF("0005.dxf");
	WUDXFParser *thirdPart = parseDXF("0006.dxf");

	// Step 2: Rotate 120
	DataCloudSet *set1 = firstPart->getCloudSet();
	DataCloudSet *set2 = secondPart->getCloudSet();
	DataCloudSet *set3 = thirdPart->getCloudSet();

	for (int i = 0; i < set2->getCount();i ++)
		set2->getVertexAt(i)->rotate120();
	for (int i = 0; i <set3->getCount();i++)
	{
		set3->getVertexAt(i)->rotate120();
		set3->getVertexAt(i)->rotate120();
	}

	//////Step 2: Calculate nearest point
	Vertex **subset1 = set1->subSet(0,kNumber);
	Vertex **subset2 = set2->subSet(0,kNumber);

	int i = 0;
	while (i < kIterative) 
	{
		//Calculator::findNearestVertex(subset1, thirdPart->getCloudSet(),kNumber);
		Calculator::findNearestVertex(subset2, firstPart->getCloudSet(),kNumber);

		//// Step 3:Calcalate Move smallest distance
		//Calculator::calculateMinmiumDistance(subset1, kNumber, set1);
		Calculator::calculateMinmiumDistance(subset2, kNumber, set2);
		i ++;
	}

	writeToDXF(set1, set2, set3);

	// Delete
	
	delete []subset1;
	delete []subset2;

	delete firstPart;
	delete secondPart;
	delete thirdPart;
	//delete testPart
    return 0;
}

void writeVertex(DL_WriterA *dw, DL_Dxf *dxf, Vertex *vertex)
{
	//cout << "Write Point "<< vertex->getX() << " " << vertex->getY() << " " << vertex->getZ() << endl;
	dxf->writePoint(
		*dw,
		DL_PointData(vertex->getX(),
		vertex->getY(),
		vertex->getZ()),
		WUDXFAttribute("mainlayer", 7, -3, "BYLAYER")
		);
}

WUDXFParser* parseDXF(char* file) {
    // Load DXF file into memory:
    std::cout << "Reading file " << file << "...\n";
    WUDXFParser* creationClass = new WUDXFParser();
    DL_Dxf* dxf = new DL_Dxf();
    if (!dxf->in(file, creationClass)) { 
        std::cerr << file << " could not be opened.\n";
        return NULL;
    }
	delete dxf;
	return creationClass;
}

void writeToDXF(DataCloudSet *dataCloud, DataCloudSet *set2, DataCloudSet *set3) {
    DL_Dxf* dxf = new DL_Dxf();
    DL_Codes::version exportVersion = DL_Codes::AC1015;
    DL_WriterA* dw = dxf->out("result.dxf", exportVersion);
    if (dw==NULL) {
        printf("Cannot open file 'test.dxf' \
               for writing.");
    }
	// Header
    dxf->writeHeader(*dw);
    dw->dxfString(9, "$INSUNITS");
    dw->dxfInt(70, 4);
    dw->dxfString(9, "$DIMEXE");
    dw->dxfReal(40, 1.25);
    dw->dxfString(9, "$TEXTSTYLE");
    dw->dxfString(7, "Standard");
    dw->dxfString(9, "$LIMMIN");
    dw->dxfReal(10, 0.0);
    dw->dxfReal(20, 0.0);
    dw->sectionEnd();
    dw->sectionTables();
    dxf->writeVPort(*dw);
    dw->tableLineTypes(25);
    dxf->writeLineType(*dw, DL_LineTypeData("BYBLOCK", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("BYLAYER", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("CONTINUOUS", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("ACAD_ISO02W100", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("ACAD_ISO03W100", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("ACAD_ISO04W100", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("ACAD_ISO05W100", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("BORDER", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("BORDER2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("BORDERX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("CENTER", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("CENTER2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("CENTERX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHDOT", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHDOT2", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("DASHDOTX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHED", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHED2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DASHEDX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DIVIDE", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DIVIDE2", 0));
    dxf->writeLineType(*dw,
                      DL_LineTypeData("DIVIDEX2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DOT", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DOT2", 0));
    dxf->writeLineType(*dw, DL_LineTypeData("DOTX2", 0));
    dw->tableEnd();
    int numberOfLayers = 2;
    dw->tableLayers(numberOfLayers);
    dxf->writeLayer(*dw,
                   DL_LayerData("0", 0),
                   WUDXFAttribute(
                       std::string(""),      // leave empty
                       DL_Codes::black,        // default color
                       100,                  // default width
                       "CONTINUOUS"));       // default line style
    dw->tableEnd();
    dxf->writeStyle(*dw);
    dxf->writeView(*dw);
    dxf->writeUcs(*dw);
    dw->tableAppid(1);
    dw->tableAppidEntry(0x12);
    dw->dxfString(2, "ACAD");
    dw->dxfInt(70, 0);
    dw->tableEnd();
    dxf->writeDimStyle(*dw,
                      1,
                      1,
                      1,
                      1,
                      1);
    dxf->writeBlockRecord(*dw);
    dxf->writeBlockRecord(*dw, "myblock1");
    dxf->writeBlockRecord(*dw, "myblock2");
    dw->tableEnd();
    dw->sectionEnd();
    dw->sectionBlocks();
    dxf->writeBlock(*dw,
                   DL_BlockData("*Model_Space", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Model_Space");
    dxf->writeBlock(*dw,
                   DL_BlockData("*Paper_Space", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Paper_Space");
    dxf->writeBlock(*dw,
                   DL_BlockData("*Paper_Space0", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "*Paper_Space0");
    dxf->writeBlock(*dw,
                   DL_BlockData("myblock1", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "myblock1");
    dxf->writeBlock(*dw,
                   DL_BlockData("myblock2", 0, 0.0, 0.0, 0.0));
    dxf->writeEndBlock(*dw, "myblock2");
    dw->sectionEnd();
    dw->sectionEntities();

    // write all your entities..
	for (int i = 0; i < dataCloud->getCount();i++)
	{
		writeVertex(dw,dxf,dataCloud->getVertexAt(i));
	}
	for (int i = 0; i < set2->getCount();i++)
	{
		writeVertex(dw,dxf,set2->getVertexAt(i));
	}
	for (int i = 0; i < set3->getCount();i++)
	{
		writeVertex(dw,dxf,set3->getVertexAt(i));
	}
	
    //dxf->writeLine(
    //    *dw,
    //    DL_LineData(25.0,   // start point
    //                30.0,
    //                0.0,
    //                100.0,   // end point
    //                120.0,
    //                0.0),
    //    WUDXFAttribute("mainlayer", 256, -1, "BYLAYER"));


    dw->sectionEnd();
    dxf->writeObjects(*dw);
    dxf->writeObjectsEnd(*dw);
    dw->dxfEOF();
    dw->close();
    delete dw;
    delete dxf;
}

