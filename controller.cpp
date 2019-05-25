#include "controller.h"

void Controller::add(const std::string& identifier, const std::string& size, const double& level_of_infection, const double& quantity_of_micro_fragments, const std::string& photograph)
//Function for adding a new organic fragment to admin_data
{
	Organic_fragment new_organic_fragment{ identifier, size, level_of_infection, quantity_of_micro_fragments, photograph };
	this->validator.validate(new_organic_fragment);
	this->repository.add_to_admin_data(new_organic_fragment);
}

void Controller::update(const std::string& identifier, const std::string& size, const double& level_of_infection, const double& quantity_of_micro_fragments, const std::string& photograph)
//Function for updating an organic fragment 
{
	Organic_fragment updated_organic_fragment{ identifier, size, level_of_infection, quantity_of_micro_fragments, photograph };
	this->validator.validate(updated_organic_fragment);
	this->repository.update_to_admin_data(updated_organic_fragment);
}

void Controller::delete_fragment(const std::string& identifier)
//Function for deleting an organic fragment from admin_data
{
	this->repository.delete_in_admin_data(identifier);
}

std::vector<Organic_fragment>& Controller::get_admin_data()
//Getter for admin_data
{
	return this->repository.get_admin_data();
}

Organic_fragment& Controller::next()
{
	return this->repository.next();
}

void Controller::save(const std::string& identifier)
{
	this->repository.save(identifier);
}

std::vector<Organic_fragment> Controller::get_filtered_list(const std::string& size, const double& quantity_of_micro_fragments)
/*
Function for getting a filtered list from the admin_data vector, using size and quantity_of_micro_fragments
precond: size - type string, quantity_of_micro_fragments - double
postcond: returns a vector containing all the organic fragments having the same size as the one given as the first argument an the quantity_of_micro_fragments 
greater or equal than the one given as the second argument
*/
{
	const std::vector<Organic_fragment>& admin_data = this->repository.get_admin_data();
	std::vector<Organic_fragment> filtered_data(admin_data.size());

	auto end_iterator = std::copy_if(admin_data.begin(), admin_data.end(), filtered_data.begin(), [size, quantity_of_micro_fragments](const Organic_fragment& fragment)
	{
		if (fragment.get_size().compare(size) == 0 && fragment.get_quantity_of_micro_fragments() >= quantity_of_micro_fragments)
			return true;
		return false;
	});

	filtered_data.resize(std::distance(filtered_data.begin(), end_iterator));//shrink container to new size
	return filtered_data;
}

std::vector<Organic_fragment>& Controller::get_user_data()
//Getter for user_data
{
	return this->repository.get_user_data();
}