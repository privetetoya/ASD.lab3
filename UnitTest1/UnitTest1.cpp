#include "pch.h"
#include "CppUnitTest.h"
#include "../ASD.lab3.newTry/Floyd.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestlab3
{
	TEST_CLASS(UnitTestlab3)
	{
	public:
		TEST_METHOD(ExсeptionTest)
		{
			Floyd f;
			try
			{
				f.algorithm("a", "b", "sample_text");
				Assert::IsTrue(false);
			}
			catch (invalid_argument e)
			{
				Assert::AreEqual("Incorrect data", e.what());
			}
		}

		TEST_METHOD(MatrixText)
		{
			Floyd f;
			string str = f.algorithm("MSC", "SPB", "data.txt");
			Assert::AreEqual("MSC->SPB", str.c_str());
		}
	};
	/*SPB;MSC;10;20
MSC;KHB;40;35
SPB;KHB;14;N/A
VLS;KHB;13;8
VLS;SPB;N/A;20*/
}