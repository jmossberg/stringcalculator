#include "gmock/gmock.h"
#include "FlagClass.h"
#include <string>


class FlagClassTest : public ::testing::Test {
public:
	FlagClass flagClass;
};

TEST(FlagClassTest, CanCreateFlagClassWithTextType)
{
	//Setup
	FlagClass flagClass;

	//Exercise
	flagClass.setFlag("d", FlagType_TEXT);

	//Verify
	ASSERT_EQ(flagClass.getFlag(), "d");
	ASSERT_EQ(flagClass.getType(), FlagType_TEXT);
}

TEST(FlagClassTest, CanCreateFlagClassWithIntegerType)
{
	//Setup
	FlagClass flagClass;

	//Exercise
	flagClass.setFlag("f", FlagType_INTEGER);

	//Verify
	ASSERT_EQ(flagClass.getFlag(), "f");
	ASSERT_EQ(flagClass.getType(), FlagType_INTEGER);
}


//TEST(ArgumentClassTests, CanStoreOneFlagType)
//{
//	//Setup
//	ArgumentClass argumentClass;
//
//	//Excercise
//	argumentClass.addFlag("d", TEXT);
//
//	//Verify
//	std::vector<std::>argumentClass.
//}

//TEST(ArgsClassTest, CanStoreOneSchemaLine)
//{
//	//Setup
//	ArgsClass argsClass;
//	std::string oneSchemaLine("p;integer");
//
//	//Excercise
//	argsClass.parseOneSchemaLine(std:string oneSchemaLine);
//
//
//
//}
