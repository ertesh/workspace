#include "stdafx.h"
#include "CppUnitTest.h"

#include "ImagePainter.h"
#include "RandomGenerator.h"
#include "FormulaGenerator.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	class MockRandGenerator : public RandomGenerator {
	private:
		int _value;
	public:
		int generateTwo() {
			return _value % 2;
		}
		int generate(int number, bool uniform = true) {
			return _value;
		}
		MockRandGenerator(int value) :
			_value(value)
		{}
	};

	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(SinFormulaTest)
		{
			shared_ptr<ImageFormula> f = FuncSin(FuncFirst());
			Assert::AreEqual(0.0, f->calculate(1, 0), 1e-9);
			Assert::AreEqual(1.0, f->calculate(0.5, 0), 1e-9);
		}

		TEST_METHOD(AverageFormulaTest)
		{
			shared_ptr<ImageFormula> f = FuncAvg(FuncFirst(), FuncSecond());
			Assert::AreEqual(0.5, f->calculate(1, 0), 1e-9);
			Assert::AreEqual(0.5, f->calculate(0, 1), 1e-9);
			Assert::AreEqual(0.0, f->calculate(1, -1), 1e-9);
		}

		TEST_METHOD(FormulasPrint) {
			Assert::AreEqual(string("x"), FuncFirst()->toString());
			Assert::AreEqual(string("y"), FuncSecond()->toString());
			Assert::AreEqual(string("sin(pi * x)"), FuncSin(FuncFirst())->toString());
			Assert::AreEqual(string("cos(pi * y)"), FuncCos(FuncSecond())->toString());
			Assert::AreEqual(string("avg(x, y)"), FuncAvg(FuncFirst(), FuncSecond())->toString());
			Assert::AreEqual(string("(y * x)"), FuncMult(FuncSecond(), FuncFirst())->toString());
		}

		TEST_METHOD(ConversionTest) {
			ImagePainter painter(640, 480);
			Assert::AreEqual(-1.0, painter.ConvertToUnitRange(0, 640), 1e-9);
			Assert::AreEqual(0.0, painter.ConvertToUnitRange(320, 640), 1e-9);
			Assert::AreEqual(1.0, painter.ConvertToUnitRange(640, 640), 1e-9);
		}

		TEST_METHOD(BackConversionTest) {
			ImagePainter painter(640, 480);
			Assert::AreEqual(0, (int)painter.ConvertToColor(-1.0));
			Assert::AreEqual(255, (int)painter.ConvertToColor(1.0));
			Assert::AreEqual(127, (int)painter.ConvertToColor(0));
		}

		TEST_METHOD(TestImagePainter) {
			int width = 20, height = 20;
			ImagePainter painter(width, height);
			shared_ptr<ImageFormula> f = FuncFirst();
			ImageData image = painter.CreateFromFormula(*f, *f, *f);
			Assert::AreEqual(0, (int)image.data[0][0].red);
			Assert::AreEqual(255, (int)image.data[width - 1][0].red);
			double x = painter.ConvertToUnitRange(10, width - 1);
			int ret = painter.ConvertToColor(f->calculate(x, 0));
			Assert::AreEqual(ret, (int)image.data[10][0].red);
		}

		TEST_METHOD(TestFormulaGenerator) {
			auto randGenerator = unique_ptr<RandomGenerator>(new MockRandGenerator(2));
			FormulaGenerator formulaMaker(std::move(randGenerator));
			shared_ptr<ImageFormula> ret = formulaMaker.createFormula(0);
			Assert::AreEqual(string("x"), ret->toString());
			ret = formulaMaker.createFormula(1);
			Assert::AreEqual(string("sin(pi * x)"), ret->toString());
			ret = formulaMaker.createFormula(2);
		}
	};
}
