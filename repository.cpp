#include "repository.h"

void Repository::add_to_admin_data(Organic_fragment& new_organic_fragment)
{
	int index;

	for (auto fragment : this->admin_data)
	{
		if (fragment.Organic_fragment::get_identifier().compare(new_organic_fragment.Organic_fragment::get_identifier()) == 0)
			throw std::exception("element with same identifier already exists!");
	}

	this->admin_data.push_back(new_organic_fragment);
}

void Repository::update_to_admin_data(Organic_fragment& updated_organic_fragment)
{
	int index;

	for (Organic_fragment& fragment : this->admin_data)
	{
		if (fragment.Organic_fragment::get_identifier().compare(updated_organic_fragment.Organic_fragment::get_identifier()) == 0)
		{
			fragment = updated_organic_fragment;
			return;
		}
	}

	throw std::exception("no organic fragment with such identifier exists!");
}

void Repository::delete_in_admin_data(const std::string& identifier)
{
	int index;

	for (index = 0; index < this->admin_data.size(); index++)
	{
		if (this->admin_data[index].Organic_fragment::get_identifier().compare(identifier) == 0)
		{
			this->admin_data.erase(admin_data.begin() + index);
			return;
		}
	}
}

std::vector<Organic_fragment>& Repository::get_admin_data()
/*
Getter for admin_data
*/
{
	return this->admin_data;
}

Organic_fragment& Repository::next()
/*
Function that returns the next organic fragment in the admin_data vector
precond: -
postcond: returns the next organic fragment in the admin_data vector; if the end of the vector is reached, goes back to the first element in the vector
*/
{
	Organic_fragment& current_element = this->admin_data[current_admin_data_index];

	this->current_admin_data_index++;
	if (current_admin_data_index == this->admin_data.size())
	{
		current_admin_data_index = 0;
	}
	
	return current_element;
}

void Repository::save(const std::string& identifier)
/*
Function for saving an organic fragment having a certain identifier
precond: identifier - type string
postcond: user_data vector contains now the organic fragment from admin_data having the same identifier as the one given as an argument; nothing is added
if there is no such organic fragment
*/
{
	int index;

	for (Organic_fragment fragment : this->admin_data)
	{
		if (fragment.Organic_fragment::get_identifier().compare(identifier) == 0)
		{
			this->user_data.push_back(fragment);
			return;
		}
	}
}

std::vector<Organic_fragment>& Repository::get_user_data()
/*
Getter for user_data
*/
{
	return this->user_data;
}
