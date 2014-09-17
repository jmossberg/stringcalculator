#include "gmock/gmock.h"
#include "StringCalculatorClass.h"
#include <sstream>

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

TEST_F(StringCalculatorClassTest, CanCallAddWithTwoNumbersInString)
{
	//Exercise
	int result = myStringCalculatorClass_p->add("1,2");

	//Exercise
	ASSERT_EQ(3, result);
}

TEST_F(StringCalculatorClassTest, StringStreamExperiment)
{

	std::stringstream ss;

	ss << "123,456";

	int number1;
	int number2;
	char delim1;

	ss >> number1 >> delim1 >> number2;

	//Exercise
	ASSERT_EQ(123, number1);
	ASSERT_EQ(456, number2);
}
