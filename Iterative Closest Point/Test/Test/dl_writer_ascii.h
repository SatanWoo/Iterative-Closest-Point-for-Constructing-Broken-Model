#ifndef DL_WRITER_ASCII_H
#define DL_WRITER_ASCII_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "dl_writer.h"
#include <fstream>
#include <string>
using std::string;

class DL_WriterA : public DL_Writer {
public:
    DL_WriterA(const char* fname, DL_Codes::version version=VER_2000)
            : DL_Writer(version), m_ofile(fname) {}
    virtual ~DL_WriterA() {}

	bool openFailed() const;
    void close() const;
    void dxfReal(int gc, double value) const;
    void dxfInt(int gc, int value) const;
    void dxfHex(int gc, int value) const;
    void dxfString(int gc, const char* value) const;
    void dxfString(int gc, const string& value) const;

	static void strReplace(char* str, char src, char dest);

private:
    /**
     * DXF file to be created.
     */
    mutable std::ofstream m_ofile;

};

#endif

