#include <cstdlib>
#include <iostream>
#include <exception>
#include "StringCalculatorClass.h"




class istream_trace : public std::istream
{
public:
	operator void*() const {
		bool found_word = std::istream::operator void*();
		//std::cout << "Getline found word: " << found_word << "\n";
		return reinterpret_cast<void *>(found_word);
	}
};

class stringstream_trace : public std::stringstream
{
public:
	istream_trace& getline (char* s, std::streamsize n, char delim )
	{
		std::istream& is = std::stringstream::getline(s, n, delim);
		return reinterpret_cast<istream_trace&>(is);
	}
};


//int StringCalculatorClass::add(std::string newString) {
//	int number = 0;
//	stringstream_trace ss;
//	char TEMP_BUF[50];
//
//	//Copy string to stringstream
//	ss << newString;
//
//	const int MAX_LENGTH_OF_NUMBER = 6;
//	const char DELIMITER = ',';
//
//	while(ss.getline(TEMP_BUF, MAX_LENGTH_OF_NUMBER, DELIMITER)) {
//		number += atoi(TEMP_BUF);
//	}
//
//	return number;
//}

int StringCalculatorClass::add(std::string addString) {
	stringstream_trace ss;

	//Copy string to stringstream
	ss << addString;

	int number = 0;
	int sum = 0;

	this->checkForNewDelimiter(ss);

	while(false == ss.eof()) {
		ss >> number;
//		if(number < 0) {
//			throwException = true;
//			exceptionMessage << number << ",";
//		}

		this->checkForNegativeNumber(number);
		sum += number;
		parseDelimiter(ss);
	}

	this->throwIfNegativeNumbers();

//	if (throwException) {
//		//remove last comma from exception message
//		std::string exceptionMessageStr = exceptionMessage.str();
//		exceptionMessageStr.resize(exceptionMessageStr.size() - 1);
//
//		throw exceptionMessageStr;
//	}

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
