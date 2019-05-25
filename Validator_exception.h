#pragma once
#include <exception>
class Validator_exception:public std::exception
{
public:
	Validator_exception(char const* const message):std::exception(message){}
};

