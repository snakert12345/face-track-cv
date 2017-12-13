#ifndef GPIO_CLASS_H
#define GPIO_CLASS_H

#include <string>

class gpio
{
	public:
	gpio();
	gpio(std::string x);

	bool exports();
	bool unexport();
	bool setdir(std::string dir);
	bool setval(std::string val);
	bool getval(std::string& val);

	std::string getNum();

	private:
	bool isopen = false;
	std::string gpionum;
};

#endif
