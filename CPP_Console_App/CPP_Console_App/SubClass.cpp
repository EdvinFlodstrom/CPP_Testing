#include <sstream>
#include "SubClass.h"

std::string m_Name;

SubClass::SubClass(const std::string& name) : m_Name(name) { }

std::string SubClass::GetName()
{
	return m_Name;
}