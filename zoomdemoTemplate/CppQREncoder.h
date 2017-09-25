#pragma once
#define snprintf _snprintf
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include <getopt.h>
#include <errno.h>
#include <png.h>
#include <qrencode.h>
enum imageType {
	PNG_TYPE,
	PNG32_TYPE,
	EPS_TYPE,
	SVG_TYPE,
	XPM_TYPE,
	ANSI_TYPE,
	ANSI256_TYPE,
	ASCII_TYPE,
	ASCIIi_TYPE,
	UTF8_TYPE,
	ANSIUTF8_TYPE,
	UTF8i_TYPE,
	ANSIUTF8i_TYPE
};

#define INCHES_PER_METER (100.0/2.54)
const unsigned char fg_color[4] = { 0, 0, 0, 255 };
const unsigned char bg_color[4] = { 255, 255, 255, 255 };
class CppQREncoder
{

private:
	 int size = 3;
	 int margin = -1;
	 int dpi = 72;
	 enum imageType image_type = PNG_TYPE;
public:
	CppQREncoder();
	~CppQREncoder();
	void writePNG(const QRcode *qrcode, const char *outfile, enum imageType type);
	void fillRow(unsigned char *row, int num, const unsigned char color[]);
};

