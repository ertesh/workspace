#include "stdafx.h"
#include "ImageFormulas.h"

shared_ptr<ImageFormula> FuncFirst() {
	return std::move(shared_ptr<ImageFormula>(new FirstValFormula()));
}

shared_ptr<ImageFormula> FuncSecond() {
	return std::move(shared_ptr<ImageFormula>(new SecondValFormula()));
}

shared_ptr<ImageFormula> FuncSin(shared_ptr<ImageFormula> param) {
	return shared_ptr<ImageFormula>(new SinFormula(std::move(param)));
}

shared_ptr<ImageFormula> FuncCos(shared_ptr<ImageFormula> param) {
	return shared_ptr<ImageFormula>(new CosFormula(std::move(param)));
}

shared_ptr<ImageFormula> FuncAvg(shared_ptr<ImageFormula> param1, shared_ptr<ImageFormula> param2) {
	return shared_ptr<ImageFormula>(new AverageFormula(std::move(param1), std::move(param2)));
}

shared_ptr<ImageFormula> FuncMult(shared_ptr<ImageFormula> param1, shared_ptr<ImageFormula> param2) {
	return shared_ptr<ImageFormula>(new MultiplyFormula(std::move(param1), std::move(param2)));
}