#include "repository.h"

void Repository::add_to_admin_data(Organic_fragment& new_organic_fragment)
{
	int index;

	for (index = 0; index < this->admin_data.get_size(); index++)
	{
		if (this->admin_data[index].Organic_fragment::get_identifier().compare(new_organic_fragment.Organic_fragment::get_identifier()) == 0)
			throw std::exception("element with same identifier already exists!");
	}

	this->admin_data.add(new_organic_fragment);
}

void Repository::update_to_admin_data(Organic_fragment& updated_organic_fragment)
{
	int index;

	for (index = 0; index < this->admin_data.get_size(); index++)
	{
		if (this->admin_data[index].Organic_fragment::get_identifier().compare(updated_organic_fragment.Organic_fragment::get_identifier()) == 0)
		{
			this->admin_data[index] = updated_organic_fragment;
			return;
		}
	}

	throw std::exception("no organic fragment with such identifier exists!");
}

void Repository::delete_in_admin_data(const std::string& identifier)
{
	int index;

	for (index = 0; index < this->admin_data.get_size(); index++)
	{
		if (this->admin_data[index].Organic_fragment::get_identifier().compare(identifier) == 0)
		{
			this->admin_data.remove(this->admin_data[index]);
			return;
		}
	}
}

const Dynamic_vector<Organic_fragment>& Repository::get_admin_data()
{
	return this->admin_data;
}

const Organic_fragment& Repository::next()
{
	const Organic_fragment& current_element = this->admin_data[current_admin_data_index];

	this->current_admin_data_index++;
	if (current_admin_data_index == this->admin_data.get_size())
	{
		current_admin_data_index = 0;
	}
	
	return current_element;
}

void Repository::save(const std::string& identifier)
{
	int index;

	for (index = 0; index < this->admin_data.get_size(); index++)
	{
		if (this->admin_data[index].Organic_fragment::get_identifier().compare(identifier) == 0)
		{
			this->user_data.add(this->admin_data[index]);
			return;
		}
	}
}

const Dynamic_vector<Organic_fragment>& Repository::get_user_data()
{
	return this->user_data;
}
