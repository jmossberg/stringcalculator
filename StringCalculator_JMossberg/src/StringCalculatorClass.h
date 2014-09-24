#ifndef STRINGCALCULATORCLASS_H_
#define STRINGCALCULATORCLASS_H_

#include <string>
#include <sstream>

class StringCalculatorClass
{
public:
	StringCalculatorClass();
	int add(std::string addString);
private:
	void checkForNewDelimiter(std::stringstream& ss);
	void parseDelimiter(std::stringstream& ss);
	void checkForNegativeNumber(int number);
	void throwIfNegativeNumbers();

	std::stringstream myExceptionMessage;
	bool throwException;
};

#endif /* STRINGCALCULATORCLASS_H_ */
