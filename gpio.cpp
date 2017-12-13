#include "gpio.h"
#include <fstream>

using namespace std;

gpio::gpio()
{
	this->gpionum = "4";
}

gpio::gpio(string x)
{
	this->gpionum = x;
}

bool gpio::exports()
{
	ofstream file;
	file.open("/sys/class/gpio/export");
	file << gpionum;
	file.close();	
	this->isopen = true;

	return true;
}

bool gpio::unexport()
{
	ofstream file;
	file.open("/sys/class/gpio/unexport");
	file << gpionum;
	this->isopen = false;
	return true;
	file.close();
}

bool gpio::setdir(string dir)
{
	ofstream file;	
	if (!isopen)
		return false;
	file.open("/sys/class/gpio/gpio" + this->gpionum + "/direction");

	file << dir;
	file.close();
}

bool gpio::setval(string val)
{
	ofstream file;
	if (!isopen)
		return false;
	file.open("/sys/class/gpio/gpio" + this->gpionum + "/value");

	file << val;

	file.close();
}

bool gpio::getval(string& val)
{
	ifstream file;
	if (!isopen)
		return false;
	file.open("/sys/class/gpio/gpio" + this->gpionum + "/value");

	file >> val;

	file.close();
	
}
