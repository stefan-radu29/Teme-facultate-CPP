#pragma once
#include "organic_fragment.h"
#include <exception>
#include <vector>

class Repository
{
protected:
	std::vector<Organic_fragment> admin_data;
	std::vector<Organic_fragment> user_data;
	int current_admin_data_index = 0;

public:

	Repository() {};
	void add_to_admin_data(Organic_fragment& new_organic_fragment);
	void update_to_admin_data(Organic_fragment& updated_organic_fragment);
	void delete_in_admin_data(const std::string& identifier);
	std::vector<Organic_fragment>& get_admin_data();

	Organic_fragment& next();
	virtual void save(const std::string& identifier);
	std::vector<Organic_fragment>& get_user_data();
};