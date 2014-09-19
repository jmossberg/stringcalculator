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

TEST_F(StringCalculatorClassTest, SupportDifferentDelimiter)
{
	//Exercise
	int result = myStringCalculatorClass_p->add("//;\n1;7;3");

	//Exercise
	ASSERT_EQ(11, result);
}

TEST_F(StringCalculatorClassTest, NegativeNumbersThrowException)
{
	//Exercise
	ASSERT_ANY_THROW(myStringCalculatorClass_p->add("-1"));
}

TEST_F(StringCalculatorClassTest, NegativeNumberThrowExceptionWithMessage)
{
	try {
		//Exercise
		myStringCalculatorClass_p->add("-1");
		FAIL(); //Fail if we reach this line since we should have thrown an exception
	}
	catch (std::string& message) {
		ASSERT_EQ("negatives not allowed: -1", message);
	}
}

TEST_F(StringCalculatorClassTest, NegativeNumbersThrowExceptionWithMessage)
{
	try {
		//Exercise
		myStringCalculatorClass_p->add("-1,3,-6");
		FAIL(); //Fail if we reach this line since we should have thrown an exception
	}
	catch (std::string& message) {
		ASSERT_EQ("negatives not allowed: -1,-6", message);
	}
}

TEST_F(StringCalculatorClassTest, NegativeNumbersThrowExceptionTwiceWithMessage)
{
	try {
		//Exercise
		myStringCalculatorClass_p->add("-1,3,-6");
		FAIL(); //Fail if we reach this line since we should have thrown an exception
	}
	catch (std::string& message) {
		ASSERT_EQ("negatives not allowed: -1,-6", message);
	}

	try {
		//Exercise
		myStringCalculatorClass_p->add("-1,3,-7");
		FAIL(); //Fail if we reach this line since we should have thrown an exception
	}
	catch (std::string& message) {
		ASSERT_EQ("negatives not allowed: -1,-7", message);
	}
}

TEST_F(StringCalculatorClassTest, NegativeNumbersThenPositiveNumbers)
{
	try {
		//Exercise
		myStringCalculatorClass_p->add("-1,3,-6");
		FAIL(); //Fail if we reach this line since we should have thrown an exception
	}
	catch (std::string& message) {
		ASSERT_EQ("negatives not allowed: -1,-6", message);
	}

    //Exercise
	int result = myStringCalculatorClass_p->add("3,2");

	ASSERT_EQ(5,result);
}

