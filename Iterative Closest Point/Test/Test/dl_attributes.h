#ifndef DL_ATTRIBUTES_H
#define DL_ATTRIBUTES_H

#include <string>
using std::string;

#include "dl_codes.h"

class WUDXFAttribute {

public:
    WUDXFAttribute() {
        setLayer("");
        setColor(0);
        setWidth(0);
        setLineType("BYLAYER");
    }

    WUDXFAttribute(const string& layer,
                  int color, int width,
                  const string& lineType) {
        setLayer(layer);
        setColor(color);
        setWidth(width);
        setLineType(lineType);
    }

    void setLayer(const string& layer) {
        this->layer = layer;
    }

    string getLayer() const {
        return layer;
    }

    void setColor(int color) {
        this->color = color;
    }

    int getColor() const {
        return color;
    }

    void setWidth(int width) {
        this->width = width;
    }

    int getWidth() const {
        return width;
    }

    void setLineType(const string& lineType) {
        this->lineType = lineType;
    }

    string getLineType() const {
        if (lineType.length()==0) {
            return "BYLAYER";
        } else {
            return lineType;
        }
    }

    WUDXFAttribute operator = (const WUDXFAttribute& attrib) {
        setLayer(attrib.layer);
        setColor(attrib.color);
        setWidth(attrib.width);
        setLineType(attrib.lineType);

        return *this;
    }
private:
    string layer;
    int color;
    int width;
    string lineType;
};

#endif

