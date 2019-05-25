#pragma once
#include <exception>

class Repository_exception :public std::exception
{
public:
	Repository_exception(char const* const message):std::exception(message){}
};