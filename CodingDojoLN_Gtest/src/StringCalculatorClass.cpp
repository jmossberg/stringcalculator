#include <cstdlib>
#include <sstream>
#include "StringCalculatorClass.h"

int StringCalculatorClass::add(std::string newString) {
	int number = 0;
	std::stringstream ss;
	char TEMP_BUF[50];

	//Copy string to stringstream
	ss << newString;

	const int MAX_LENGTH_OF_NUMBER = 6;
	const char DELIMITER = ',';

	while(ss.getline(TEMP_BUF, MAX_LENGTH_OF_NUMBER, DELIMITER)) {
		number += atoi(TEMP_BUF);
	}

	return number;
}
