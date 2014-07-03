#pragma once
#include "ImageFormulas.h"

class ImagePainter {
	int _width;
	int _height;
public:
	ImagePainter(int width, int height);
	ImageData CreateSampleImage();
	double ConvertToUnitRange(int val, int max);
	uint8_t ConvertToColor(double val);
	ImageData CreateFromFormula(const ImageFormula& red, const ImageFormula& green, const ImageFormula& blue);
};

