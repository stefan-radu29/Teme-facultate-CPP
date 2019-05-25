#pragma once
#include "organic_fragment.h"
#include "Validator_exception.h"
class Validator
{
public:
	Validator(){}
	~Validator(){}
	void validate(Organic_fragment& fragment);
};

