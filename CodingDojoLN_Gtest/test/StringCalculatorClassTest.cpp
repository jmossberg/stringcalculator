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

TEST_F(StringCalculatorClassTest, CanCallAddWithEightNumbersInString)
{
	//Exercise
	int result = myStringCalculatorClass_p->add("1,2,3,4,5,6,7,8");

	//Exercise
	ASSERT_EQ(36, result);
}

TEST_F(StringCalculatorClassTest, CanCallAddWithNewLineDelimiter)
{
	//Exercise
	int result = myStringCalculatorClass_p->add("1\n2,3");

	//Exercise
	ASSERT_EQ(6, result);
}

TEST_F(StringCalculatorClassTest, StringStreamExperiment)
{

	std::stringstream ss;

	ss << "123\n456";
	//ss << "123";

	int number1;
	int number2;
	//char delim1;

	//ss >> number1 >> delim1 >> number2;
	ss >> number1;
	char c = ss.peek();
	ss >> number2;

	//Exercise
	//ASSERT_EQ('\n', delim1);
	ASSERT_EQ(123, number1);
	ASSERT_EQ('\n', c);
	ASSERT_EQ(456, number2);
}

