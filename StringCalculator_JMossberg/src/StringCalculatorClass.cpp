#include <cstdlib>
#include <iostream>
#include <exception>
#include "StringCalculatorClass.h"

int StringCalculatorClass::add(std::string addString) {
	std::stringstream ss;

	//Copy string to stringstream
	ss << addString;

	int number = 0;
	int sum = 0;

	this->checkForNewDelimiter(ss);

	while(false == ss.eof()) {
		ss >> number;

		this->checkForNegativeNumber(number);
		sum += number;
		parseDelimiter(ss);
	}

	this->throwIfNegativeNumbers();

	return sum;
}

void StringCalculatorClass::checkForNewDelimiter(std::stringstream& ss) {
	const int MAX_LENGTH_TO_PARSE = 6;
	const char DELIMITER = '\n';
	char TEMP_BUF[50];

	if('/' == ss.peek()) {
		ss.getline(TEMP_BUF, MAX_LENGTH_TO_PARSE, DELIMITER);
	}
}

void StringCalculatorClass::parseDelimiter(std::stringstream& ss) {
	char delimiter;
	if('\n' != ss.peek()) {
		ss >> delimiter;
	}
}

void StringCalculatorClass::checkForNegativeNumber(int number) {
	if(number < 0) {
		throwException = true;
		myExceptionMessage << number << ",";
	}
}

StringCalculatorClass::StringCalculatorClass() {
	myExceptionMessage << "negatives not allowed: ";
	throwException = false;
}

void StringCalculatorClass::throwIfNegativeNumbers() {
	if (throwException) {
		//remove last comma from exception message
		std::string str = myExceptionMessage.str();
		str.resize(str.size() - 1);

		myExceptionMessage.str("");
		myExceptionMessage.clear(); // Clear state flags.
		myExceptionMessage << "negatives not allowed: ";
		throwException = false;

		throw str;
	}
}
