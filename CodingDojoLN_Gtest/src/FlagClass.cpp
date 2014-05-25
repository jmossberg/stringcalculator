#include "FlagClass.h"

void FlagClass::setFlag(std::string newFlag, FlagType newFlagType) {
	flag = newFlag;
	flagType = newFlagType;
}

std::string FlagClass::getFlag() {
	return flag;
}

FlagType FlagClass::getType() {
	return flagType;
}
/*
 * FlagClass.cpp
 *
 *  Created on: May 25, 2014
 *      Author: codingdojoln
 */




