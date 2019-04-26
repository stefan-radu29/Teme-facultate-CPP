#pragma once
#include "organic_fragment.h"
#include "Dynamic_array.h"
#include <exception>

class Repository
{
private:

	Dynamic_vector<Organic_fragment> admin_data;
	Dynamic_vector<Organic_fragment> user_data;

public:

	Repository() {};
	void add_to_admin_data(Organic_fragment& new_organic_fragment);
	void update_to_admin_data(Organic_fragment& updated_organic_fragment);
	void delete_in_admin_data(const std::string& identifier);
	const Dynamic_vector<Organic_fragment>& get_admin_data();
};