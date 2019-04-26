#include "controller.h"

void Controller::add(const std::string& identifier, const std::string& size, const double& level_of_infection, const double& quantity_of_micro_fragments, const std::string& photograph)
{
	Organic_fragment new_organic_fragment{ identifier, size, level_of_infection, quantity_of_micro_fragments, photograph };
	this->repository.Repository::add_to_admin_data(new_organic_fragment);
}

void Controller::update(const std::string& identifier, const std::string& size, const double& level_of_infection, const double& quantity_of_micro_fragments, const std::string& photograph)
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

const Organic_fragment& Controller::next()
{
	return this->repository.Repository::next();
}

void Controller::save(const std::string& identifier)
{
	this->repository.Repository::save(identifier);
}

Dynamic_vector<Organic_fragment> Controller::get_filtered_list(const std::string& size, const double& quantity_of_micro_fragments)
{
	const Dynamic_vector<Organic_fragment>& admin_data = this->repository.Repository::get_admin_data();
	Dynamic_vector<Organic_fragment> filtered_data{};
	int index;

	for (index = 0; index < admin_data.get_size(); index++)
	{
		if (admin_data[index].get_size().compare(size) == 0 && admin_data[index].get_quantity_of_micro_fragments() >= quantity_of_micro_fragments)
		{
			filtered_data.add(admin_data[index]);
		}
	}

	return filtered_data;
}

const Dynamic_vector<Organic_fragment>& Controller::get_user_data()
{
	return this->repository.Repository::get_user_data();
}