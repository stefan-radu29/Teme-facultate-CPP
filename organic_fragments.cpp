#include "organic_fragment.h"
#include <cstring>

Organic_fragment::Organic_fragment(const std::string& identifier, const std::string& size, const double level_of_infection, double quantity_of_micro_fragments, const std::string& photograph)
/*
Constructor for objects of type Organic_fragment
Precond: identifier, size, photograph - type string, level_of_infection, quantity_of_microfragments - type double
Postcond: there is a new object of type Organic_fragment having the given attributes
*/
{
	this->identifier.assign(identifier);

	this->size.assign(size);

	this->level_of_infection = level_of_infection;

	this->quantity_of_micro_fragments = quantity_of_micro_fragments;

	this->photograph.assign(photograph);
}

Organic_fragment::Organic_fragment(): identifier(""), size(""), level_of_infection(0), quantity_of_micro_fragments(0), photograph("1") {}

const std::string& Organic_fragment::get_identifier() const
/*
Getter for identifier
*/
{
	return this->identifier;
}

void Organic_fragment::operator=(const Organic_fragment& other_fragment)
/*
Overriding the = operator
precond: other_fragment is a valid object of type Organic_fragment
postcond: the attributes of this are the same as the attributes of other_fragment
*/
{
	this->identifier = other_fragment.get_identifier();
	this->size = other_fragment.get_size();
	this->level_of_infection = other_fragment.get_level_of_infection();
	this->quantity_of_micro_fragments = other_fragment.get_quantity_of_micro_fragments();
	this->photograph = other_fragment.get_photograph();
}

bool Organic_fragment::operator==(const Organic_fragment& other_fragment)
/*
Overriding the == operator
precond: other_fragment is a valid object of type Organic_fragment
postcond: returns true if the objects have the same attributes, false otherwise
*/
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
/*
Getter for size
*/
{
	return this->size;
}

double Organic_fragment::get_level_of_infection() const
/*
Getter for level_of_infection
*/
{
	return this->level_of_infection;
}

double Organic_fragment::get_quantity_of_micro_fragments() const
/*
Getter for quantity_of_micro_fragments
*/
{
	return this->quantity_of_micro_fragments;
}

std::string Organic_fragment::get_photograph() const
/*
Getter for photograph
*/
{
	return this->photograph;
}

std::istream& operator>>(std::istream& in_stream, Organic_fragment& fragment)
/*
Overriding the >> operator for reading
*/
{
	std::string file_entry;
	getline(in_stream, file_entry);

	std::vector<std::string> attributes = tokenize(file_entry, ',');

	if (attributes.size() != 5)
	{
		return in_stream;
	}

	fragment.identifier = attributes[0];
	fragment.size = attributes[1];
	fragment.level_of_infection = stod(attributes[2]);
	fragment.quantity_of_micro_fragments = stod(attributes[3]);
	fragment.photograph = attributes[4];
	return in_stream;
}

std::ostream& operator<<(std::ostream& out_stream, Organic_fragment& fragment)
/*
Overriding the << operator for writing
*/
{
	out_stream << fragment.identifier << "," << fragment.size << "," << fragment.level_of_infection << "," << fragment.quantity_of_micro_fragments << "," << fragment.photograph;
	return out_stream;
}