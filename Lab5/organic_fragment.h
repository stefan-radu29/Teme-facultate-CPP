#pragma once
#include <string>

class Organic_fragment
{
private:

	std::string identifier;
	std::string size;
	double level_of_infection;
	int quantity_of_micro_fragments;
	std::string photograph;

public:

	Organic_fragment();

	Organic_fragment(const std::string& identifier, const std::string& size, const double level_of_infection, int quantity_of_micro_fragments, const std::string& photograph);

	void operator=(const Organic_fragment& other_fragment);
	bool operator==(const const Organic_fragment& other_fragment);

	const std::string& get_identifier() const;
	std::string get_size() const;
	double get_level_of_infection() const;
	int get_quantity_of_micro_fragments() const;
	std::string get_photograph() const;
};