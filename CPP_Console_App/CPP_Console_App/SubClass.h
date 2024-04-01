#pragma once

#include <sstream>
#include "MainClass.h"

class SubClass : public MainClass
{
private:
	std::string m_Name;
public:
	SubClass(const std::string& name);

	std::string GetName() override;
};