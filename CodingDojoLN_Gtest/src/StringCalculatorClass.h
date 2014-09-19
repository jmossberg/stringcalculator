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



#endif /* STRINGCALCULATORCLASS_H_ */
