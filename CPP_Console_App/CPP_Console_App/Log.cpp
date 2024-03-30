#include <iostream>
#include <sstream>
#include "Log.h"

void InitialLog()
{
	std::cout << "Program initialized successfully... \n" << std::endl;
}

void SaveLogToBuffer(const std::string& message, std::ostringstream& buffer)
{
	buffer << message << std::endl;
}

void LogBuffer(std::ostringstream& buffer)
{
	std::cout << buffer.str();
	buffer.str("");
}