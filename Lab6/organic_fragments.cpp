#include "organic_fragment.h"
#include <cstring>

Organic_fragment::Organic_fragment(const std::string& identifier, const std::string& size, const double level_of_infection, double quantity_of_micro_fragments, const std::string& photograph)
{
	this->identifier.assign(identifier);

	this->size.assign(size);

	this->level_of_infection = level_of_infection;

	this->quantity_of_micro_fragments = quantity_of_micro_fragments;

	this->photograph.assign(photograph);
}

Organic_fragment::Organic_fragment(): identifier(""), size(""), level_of_infection(0), quantity_of_micro_fragments(0), photograph("1") {}

const std::string& Organic_fragment::get_identifier() const
{
	return this->identifier;
}

void Organic_fragment::operator=(const Organic_fragment& other_fragment)
{
	this->identifier = other_fragment.get_identifier();
	this->size = other_fragment.get_size();
	this->level_of_infection = other_fragment.get_level_of_infection();
	this->quantity_of_micro_fragments = other_fragment.get_quantity_of_micro_fragments();
	this->photograph = other_fragment.get_photograph();
}

bool Organic_fragment::operator==(const Organic_fragment& other_fragment)
{
	if (this->identifier.compare(other_fragment.get_identifier()) == 0)
		if (this->size.compare(other_fragment.get_size()) == 0)
			if (this->level_of_infection == other_fragment.level_of_infection)
				if (this->quantity_of_micro_fragments == other_fragment.quantity_of_micro_fragments)
					if (this->photograph.compare(other_fragment.get_photograph()) == 0)
						return true;
	return false;
}

std::string Organic_fragment::get_size() const
{
	return this->size;
}

double Organic_fragment::get_level_of_infection() const
{
	return this->level_of_infection;
}

double Organic_fragment::get_quantity_of_micro_fragments() const
{
	return this->quantity_of_micro_fragments;
}

std::string Organic_fragment::get_photograph() const
{
	return this->photograph;
}

