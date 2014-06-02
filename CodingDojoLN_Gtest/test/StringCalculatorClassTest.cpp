#include "gmock/gmock.h"
#include "StringCalculatorClass.h"

TEST(StringCalculatorClassTest, CanInstantiateStringCalculatorClass)
{
	//Exercise
	StringCalculatorClass * stringCalculatorClass_p = 0;
	stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	ASSERT_FALSE(0 == stringCalculatorClass_p);

	//Tear down
	delete stringCalculatorClass_p;
}
