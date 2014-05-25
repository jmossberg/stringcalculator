/*
 * ArgumentClass.h
 *
 *  Created on: May 25, 2014
 *      Author: codingdojoln
 */

#ifndef ARGUMENTCLASS_H_
#define ARGUMENTCLASS_H_

#include "FlagClass.h"
#include <vector>

class ArgumentClass
{
private:
	std::vector<FlagClass> flags;
public:
	void addFlag(FlagClass newFlag);
	std::vector<FlagClass> getFlags();
};



#endif /* ARGUMENTCLASS_H_ */
