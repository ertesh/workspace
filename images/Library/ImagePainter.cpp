#include "stdafx.h"
#include "ImagePainter.h"

ImagePainter::ImagePainter(int width, int height) {
	_width = width;
	_height = height;
}

ImageData ImagePainter::CreateSampleImage() {
	ImageData image;
	image.data.resize(_width);
	for (int i = 0; i < _width; i++) {
		image.data[i].resize(_height);
		for (int j = 0; j < _height; j++) {
			image.data[i][j].alpha = 255;
			image.data[i][j].green = 255;
		}
	}
	return image;
}

double ImagePainter::ConvertToUnitRange(int val, int max) {
	return val / (max / 2.0) - 1;
}

uint8_t ImagePainter::ConvertToColor(double val) {
	return uint8_t((val + 1) * 127.5);
}

ImageData ImagePainter::CreateFromFormula(const ImageFormula& red, const ImageFormula& green, const ImageFormula& blue) {
	ImageData image;
	image.data.resize(_width);
	for (int i = 0; i < _width; i++) {
		image.data[i].resize(_height);
		for (int j = 0; j < _height; j++) {
			image.data[i][j].alpha = 255;
			double x = ConvertToUnitRange(i, _width - 1);
			double y = ConvertToUnitRange(j, _height - 1);
			image.data[i][j].red = ConvertToColor(red.calculate(x, y));
			image.data[i][j].green = ConvertToColor(green.calculate(x, y));
			image.data[i][j].blue = ConvertToColor(blue.calculate(x, y));
		}
	}
	return image;
}