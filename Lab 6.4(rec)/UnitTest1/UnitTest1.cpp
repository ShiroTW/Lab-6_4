#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.4(rec)/Lab_6.4_rec.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 4;
			double a[n] = { 2, -7, -8, 3 };
			double expectation = SumOfPositiveElements(a, n, 0);
			double actual = 5;
			Assert::AreEqual(expectation, actual);
		}

		TEST_METHOD(TestMethod2)
		{
			const int n = 5;
			double a[n] = { 3, -3, -6, 7 };
			double expectation = SumOfPositiveElements(a, n, 0);
			double actual = 10;
			Assert::AreEqual(expectation, actual);
		}
	};
}