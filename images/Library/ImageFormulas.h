#pragma once

#include <stdint.h>
#include <vector>
#include <memory>

#define _USE_MATH_DEFINES
#include <math.h>

using std::vector;
using std::shared_ptr;
using std::unique_ptr;
using std::string;

struct ImageData {
	struct ImagePixel {
		uint8_t red;
		uint8_t green;
		uint8_t blue;
		uint8_t alpha;
	};
	vector<vector<ImagePixel>> data;
};

class ImageFormula {
public:
	virtual double calculate(double x, double y) const = 0;
	virtual string toString() const = 0;
};

class FirstValFormula : public ImageFormula {
public:
	double calculate(double x, double y) const { return x; }
	string toString() const { return "x"; }
};

class SecondValFormula : public ImageFormula {
public:
	double calculate(double x, double y) const { return y; }
	string toString() const { return "y"; }
};

class SinFormula : public ImageFormula {
private:
	shared_ptr<ImageFormula> _innerFormula;
public:
	SinFormula(shared_ptr<ImageFormula> innerFormula) :
		_innerFormula(std::move(innerFormula))
	{

	}
	double calculate(double x, double y) const {
		double val = _innerFormula->calculate(x, y);
		return sin(M_PI * val);
	}
	string toString() const {
		return "sin(pi * " + _innerFormula->toString() + ")";
	}
};

class CosFormula : public ImageFormula {
private:
	shared_ptr<ImageFormula> _innerFormula;
public:
	CosFormula(shared_ptr<ImageFormula> innerFormula) :
		_innerFormula(std::move(innerFormula))
	{
	}
	double calculate(double x, double y) const {
		double val = _innerFormula->calculate(x, y);
		return sin(M_PI * val);
	}
	string toString() const {
		return "cos(pi * " + _innerFormula->toString() + ")";
	}
};

class AverageFormula : public ImageFormula {
private:
	shared_ptr<ImageFormula> _innerFormula1;
	shared_ptr<ImageFormula> _innerFormula2;
public:
	AverageFormula(shared_ptr<ImageFormula> innerFormula1, shared_ptr<ImageFormula> innerFormula2) :
		_innerFormula1(std::move(innerFormula1)),
		_innerFormula2(std::move(innerFormula2))
	{
	}
	double calculate(double x, double y) const {
		double val1 = _innerFormula1->calculate(x, y);
		double val2 = _innerFormula2->calculate(x, y);
		return (val1 + val2) / 2;
	}
	string toString() const {
		return "avg(" + _innerFormula1->toString() + ", " + _innerFormula2->toString() + ")";
	}
};

class MultiplyFormula : public ImageFormula {
private:
	shared_ptr<ImageFormula> _innerFormula1;
	shared_ptr<ImageFormula> _innerFormula2;
public:
	MultiplyFormula(shared_ptr<ImageFormula> innerFormula1, shared_ptr<ImageFormula> innerFormula2) :
		_innerFormula1(std::move(innerFormula1)),
		_innerFormula2(std::move(innerFormula2))
	{
	}
	double calculate(double x, double y) const {
		double val1 = _innerFormula1->calculate(x, y);
		double val2 = _innerFormula2->calculate(x, y);
		return val1 * val2;
	}
	string toString() const {
		return "(" + _innerFormula1->toString() + " * " + _innerFormula2->toString() + ")";
	}
};

shared_ptr<ImageFormula> FuncFirst();
shared_ptr<ImageFormula> FuncSecond();
shared_ptr<ImageFormula> FuncSin(shared_ptr<ImageFormula> param);
shared_ptr<ImageFormula> FuncCos(shared_ptr<ImageFormula> param);
shared_ptr<ImageFormula> FuncAvg(shared_ptr<ImageFormula> param1, shared_ptr<ImageFormula> param2);
shared_ptr<ImageFormula> FuncMult(shared_ptr<ImageFormula> param1, shared_ptr<ImageFormula> param2);