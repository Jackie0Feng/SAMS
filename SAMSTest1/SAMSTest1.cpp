#include "pch.h"
#include "CppUnitTest.h"
#include "../SAMS/SAMS.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace SAMSTest1
{
	TEST_CLASS(SAMSTest1)
	{
	public:
		TEST_METHOD(AverSumofScoreTest)
		{
			int n = 2;
			long num[STU_NUM] = { 1,2 };
			float score[STU_NUM] = { 20.0,80.0 };
			
			double sum = AverSumofScore(score,n);
			
			Assert::AreEqual(100.0, sum);
		}
	};
}

