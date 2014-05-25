#include "gmock/gmock.h"
#include "ArgumentClass.h"

TEST(ArgumentClassTest, CanAddOneFlag)
{
	//Setup
	FlagClass flag;
	flag.setFlag("d", FlagType_TEXT);

	ArgumentClass argumentClass;

	//Exercise
	argumentClass.addFlag(flag);

	//Verify
	std::vector<FlagClass> flags = argumentClass.getFlags();
	FlagClass storedFlag = flags[0];
	ASSERT_EQ("d", storedFlag.getFlag());
	ASSERT_EQ(FlagType_TEXT, storedFlag.getType());
}

TEST(ArgumentClassTest, CanAddTwoFlags)
{
	//Setup
	FlagClass flag1;
	flag1.setFlag("d", FlagType_TEXT);
	FlagClass flag2;
	flag2.setFlag("g", FlagType_INTEGER);

	ArgumentClass argumentClass;

	//Exercise
	argumentClass.addFlag(flag1);
	argumentClass.addFlag(flag2);

	//Verify
	std::vector<FlagClass> flags = argumentClass.getFlags();
	FlagClass storedFlag = flags[0];
	ASSERT_EQ("d", storedFlag.getFlag());
	ASSERT_EQ(FlagType_TEXT, storedFlag.getType());
	storedFlag = flags[1];
	ASSERT_EQ("g", storedFlag.getFlag());
	ASSERT_EQ(FlagType_INTEGER, storedFlag.getType());
}
