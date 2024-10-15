#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab06_4rec/Lab06_4rec.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			int a[22];

			Create(a, 22, -10, 35, 0);

			int expected[22] = { 31,  11,  22, -6,  23,  28,  14,   0, -4,  28, -9,  29, -5,  27,  15,  21, -5,  18,  33, -2, -3,  12 };

			for (int i = 0; i < 22; i++)
			{
				Assert::AreEqual(expected[i], a[i], L"Elements are not equal", LINE_INFO());
			}
		}
		TEST_METHOD(TestMethod2)
		{
			int a[22] = { 10, -2,   3,   9,   7,   6,   2, -10 };
			int s_expected = 37;
			int d_expected = 453600;

			int s = 0;
			int d = 1;
			f1(a, 8, s, d, -10, 10, 0);


			Assert::AreEqual(s_expected, s, 0.0000001);
			Assert::AreEqual(d_expected, d, 0.0000001);

		}
		TEST_METHOD(TestMethod3)
		{
			int a[8] = { 10, -2 ,  3,   9,   7,   6,   2, -10 };

			Sort(a, 8, 0);

			int expected[22] = { 10, -2,   9,   7,   6,   3,   2, -10 };

			for (int i = 0; i < 8; i++)
			{
				Assert::AreEqual(expected[i], a[i], L"Elements are not equal", LINE_INFO());
			}
		}
		TEST_METHOD(TestMethod4)
		{
			int a[22] = { 10, -2,   3,   9,   7,   6,   2, -10 };
			
			int expected = -10;
			int res = Min(a, 8, 0, 10);


			Assert::AreEqual(expected, res, 0.0000001);
		}
		TEST_METHOD(TestMethod5)
		{
			int a[22] = { 10, -2,   3,   9,   7,   6,   2, -10 };

			int expected = 10;
			int res = Max(a, 8, 0, -10);


			Assert::AreEqual(expected, res, 0.0000001);
		}
	};
}
