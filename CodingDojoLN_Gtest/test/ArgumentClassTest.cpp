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
