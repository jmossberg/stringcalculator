#include "gmock/gmock.h"
#include "StringCalculatorClass.h"

class StringCalculatorClassTest : public ::testing::Test {
public:
	StringCalculatorClass * myStringCalculatorClass_p;

	StringCalculatorClassTest();
	~StringCalculatorClassTest();
};

StringCalculatorClassTest::StringCalculatorClassTest() {
	myStringCalculatorClass_p = new StringCalculatorClass();
}

StringCalculatorClassTest::~StringCalculatorClassTest() {
	delete myStringCalculatorClass_p;
}


TEST_F(StringCalculatorClassTest, CanCallAddWithEmptyString)
{
	//Exercise
	int result = myStringCalculatorClass_p->add("");

	//Exercise
	ASSERT_EQ(0, result);
}

TEST_F(StringCalculatorClassTest, CanCallAddWithOneNumberInString)
{
	//Exercise
	int result = myStringCalculatorClass_p->add("1");

	//Exercise
	ASSERT_EQ(1, result);
}
