#include "gmock/gmock.h"
#include "StringCalculatorClass.h"

TEST(StringCalculatorClassTest, CanCallAddWithEmptyString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	int result = stringCalculatorClass_p->add("");

	//Exercise
	ASSERT_EQ(0, result);

	//Teardown
	delete stringCalculatorClass_p;
}

TEST(StringCalculatorClassTest, CanCallAddWithOneNumberInString)
{
	//Setup
	StringCalculatorClass * stringCalculatorClass_p = new StringCalculatorClass();

	//Exercise
	int result = stringCalculatorClass_p->add("1");

	//Exercise
	ASSERT_EQ(1, result);

	//Teardown
	delete stringCalculatorClass_p;
}
