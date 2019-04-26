#pragma once
#include "repository.h"

class Controller
{
private:

	Repository repository;

public:
	
	Controller(const Repository& repository) : repository(repository) {}
	void add(const std::string& identifier, const std::string& size, const double& level_of_infection, const double& quantity_of_micro_fragments, const std::string& photograph);
	void update(const std::string& identifier, const std::string& size, const double& level_of_infection, const double& quantity_of_micro_fragments, const std::string& photograph);
	void delete_fragment(const std::string& identifier);
	const Dynamic_vector<Organic_fragment>& get_admin_data();

	const Organic_fragment& next();
	void save(const std::string& identifier);
	Dynamic_vector<Organic_fragment> get_filtered_list(const std::string& size, const double& quantity_of_micro_fragments);
	const Dynamic_vector<Organic_fragment>& get_user_data();
};
