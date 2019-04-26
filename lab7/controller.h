#pragma once
#include "repository.h"
#include <vector>
#include <algorithm>
#include "Repository_with_file.h"

class Controller
{
private:

	Repository_with_file repository;

public:
	
	Controller(Repository_with_file& repository) : repository(repository) {}
	void add(const std::string& identifier, const std::string& size, const double& level_of_infection, const double& quantity_of_micro_fragments, const std::string& photograph);
	void update(const std::string& identifier, const std::string& size, const double& level_of_infection, const double& quantity_of_micro_fragments, const std::string& photograph);
	void delete_fragment(const std::string& identifier);
	std::vector<Organic_fragment>& get_admin_data();

	Organic_fragment& next();
	void save(const std::string& identifier);
	std::vector<Organic_fragment> get_filtered_list(const std::string& size, const double& quantity_of_micro_fragments);
	std::vector<Organic_fragment>& get_user_data();
};
