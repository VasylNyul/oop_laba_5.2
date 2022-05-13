#include "pch.h"
#include "CppUnitTest.h"
#include "../oop_laba_5.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace oopUnitTest52
{
	TEST_CLASS(oopUnitTest52)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			double a = D3(3, 3, 3, 0, 0);
			Assert::AreEqual(a, 3.0);
		}
	};
}
