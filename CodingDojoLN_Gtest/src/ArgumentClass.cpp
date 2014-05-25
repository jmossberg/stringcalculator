#include "ArgumentClass.h"

void ArgumentClass::addFlag(FlagClass newFlag) {
	flags.push_back(newFlag);
}

std::vector<FlagClass> ArgumentClass::getFlags() {
	return flags;
}
