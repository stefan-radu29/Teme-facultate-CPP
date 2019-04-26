#include "controller.h"

void Controller::add(const std::string& identifier, const std::string& size, const double& level_of_infection, const int& quantity_of_micro_fragments, const std::string& photograph)
{
	Organic_fragment new_organic_fragment{ identifier, size, level_of_infection, quantity_of_micro_fragments, photograph };
	this->repository.Repository::add_to_admin_data(new_organic_fragment);
}

void Controller::update(const std::string& identifier, const std::string& size, const double& level_of_infection, const int& quantity_of_micro_fragments, const std::string& photograph)
{
	Organic_fragment updated_organic_fragment{ identifier, size, level_of_infection, quantity_of_micro_fragments, photograph };
	this->repository.Repository::update_to_admin_data(updated_organic_fragment);
}

void Controller::delete_fragment(const std::string& identifier)
{
	this->repository.delete_in_admin_data(identifier);
}

const Dynamic_vector<Organic_fragment>& Controller::get_admin_data()
{
	return this->repository.Repository::get_admin_data();
}