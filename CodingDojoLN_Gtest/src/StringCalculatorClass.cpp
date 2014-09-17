#include <cstdlib>
#include "StringCalculatorClass.h"

int StringCalculatorClass::add(std::string newString) {

	int number = 0;

	if(newString.size() > 0) {
		number = atoi(newString.c_str());
	}

	return number;
}
