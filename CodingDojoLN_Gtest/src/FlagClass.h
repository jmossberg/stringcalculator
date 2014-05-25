/*
 * FlagClass.h
 *
 *  Created on: May 25, 2014
 *      Author: codingdojoln
 */

#ifndef FLAGCLASS_H_
#define FLAGCLASS_H_

#include <string>

enum FlagType
{
	FlagType_TEXT,
	FlagType_INTEGER
};

class FlagClass
{
public:
	void setFlag(std::string newFlag, FlagType newFlagType);
	std::string getFlag();
	FlagType getType();

private:
	std::string flag;
	FlagType flagType;
};



#endif /* FLAGCLASS_H_ */
