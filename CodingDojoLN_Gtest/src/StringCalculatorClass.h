#ifndef STRINGCALCULATORCLASS_H_
#define STRINGCALCULATORCLASS_H_

#include <string>
#include <sstream>

class StringCalculatorClass
{
public:
	int add(std::string addString);
private:
	void checkForNewDelimiter(std::stringstream& ss);
	void parseDelimiter(std::stringstream& ss);
};

class myException : public std::exception {

	virtual const char* what() const throw() {
		std::string message = "negatives not allowed: ";
		return message.c_str();
	}
};



#endif /* STRINGCALCULATORCLASS_H_ */
