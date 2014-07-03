#pragma once
#include "RandomGenerator.h"
#include "ImageFormulas.h"
#include <cassert>

class FormulaGenerator {
private:
	enum FormulaTypes { FirstVal, SecondVal, SinVal, CosVal, AvgVal, MultVal, Count };
	unique_ptr<RandomGenerator> _generator;
public:
	FormulaGenerator() :
		_generator(unique_ptr<RandomGenerator>(new RandomGenerator()))
	{
	}

	FormulaGenerator(unique_ptr<RandomGenerator> generator) :
		_generator(std::move(generator))
	{}

	shared_ptr<ImageFormula> createFormula(int maxDepth) {
		assert(maxDepth >= 0);
		if (maxDepth == 0) {
			int randVal = _generator->generateTwo();
			if (randVal == FormulaTypes::FirstVal) {
				return FuncFirst();
			}
			else {
				return FuncSecond();
			}
		}
		int randVal = _generator->generate(FormulaTypes::Count, false);
		switch (randVal)
		{
		case FirstVal: return FuncFirst();
		case SecondVal: return FuncSecond();
		case SinVal: return FuncSin(createFormula(maxDepth - 1));
		case CosVal: return FuncCos(createFormula(maxDepth - 1));
		case AvgVal: return FuncAvg(createFormula(maxDepth - 1), createFormula(maxDepth - 1));
		case MultVal: return FuncMult(createFormula(maxDepth - 1), createFormula(maxDepth - 1));
		}
		assert(false);
		return nullptr;
	}
};