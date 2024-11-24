#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab 6.4(it)/Lab_6.4_it.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			const int n = 4;
			double a[n] = { 6, 1, -5, 10 };
			double expectation = SumOfPositiveElements(a, n);
			double actual = 17;
			Assert::AreEqual(expectation, actual);
		}

		TEST_METHOD(TestMethod2)
		{
			const int n = 5;
			double a[n] = { 9, -5, 2, 7 };
			double expectation = SumOfPositiveElements(a, n);
			double actual = 18;
			Assert::AreEqual(expectation, actual);
		}
	};
}