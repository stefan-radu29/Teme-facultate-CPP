#include "Repository_with_file.h"
#include <fstream>

bool is_empty(std::ifstream& in_file)
/*
Checks if a stream is empty
*/
{
	return in_file.peek() == std::ifstream::traits_type::eof();
}

void Repository_with_file::load_from_file()
/*
Functon for loading information from a text file
precond: -
postcond: the information from the file is loaded into the admin_data vector
exception: an exception is thrown if the file cannot be opened for reading
*/
{
	std::ifstream in_file(this->file_name);

	if (!in_file.is_open())
	{
		throw std::exception("file cannot be opened!\n");
	}
	if (is_empty(in_file) == false)
	{
		Organic_fragment fragment{};
		while (in_file >> fragment)
		{
			if (in_file.eof()) break;
			this->admin_data.push_back(fragment);
		}
	}
	in_file.close();
}

void Repository_with_file::save_to_file()
/*
Function for writing to a text file
precond: -
postcond: the information stored in admin_data is written to the text file
*/
{
	std::ofstream out_file(this->file_name);

	for (auto fragment : this->admin_data)
	{
		out_file << fragment << "\n";
	}

	out_file.close();
}

void Repository_with_file::add_to_admin_data(Organic_fragment& new_organic_fragment)
/*
Function that adds new_organic_fragment, instance of Organic_fragment class, to the admin_data vector
precond: new_organic_fragment is a valid instance of Organic_fragment
postcond: admin_data' = admin_data U {new_organic_fragment}
exceptions: if there is an element with the same identifier in the admin_data vector, an exception will be thrown
*/
{
	int index;

	for (auto fragment : this->admin_data)
	{
		if (fragment.Organic_fragment::get_identifier().compare(new_organic_fragment.Organic_fragment::get_identifier()) == 0)
			throw std::exception("element with same identifier already exists!");
	}

	this->admin_data.push_back(new_organic_fragment);

	save_to_file();
}

void Repository_with_file::update_to_admin_data(Organic_fragment& updated_organic_fragment)
/*
Function that updates an organic fragment by changing every attribute, except for the identifier, which is used for finding the 
object, with the attributes of updated_organic_fragment
precond: updated_organic_fragment is a valid instance of Organic_fragment
postcond: the update to the organic fragment is performed
exception: if there is no organic fragment with such an identifier, an exception is thrown
*/
{
	int index;

	for (Organic_fragment& fragment : this->admin_data)
	{
		if (fragment.Organic_fragment::get_identifier().compare(updated_organic_fragment.Organic_fragment::get_identifier()) == 0)
		{
			fragment = updated_organic_fragment;
			save_to_file();
			return;
		}
	}

	throw std::exception("no organic fragment with such identifier exists!");
}

void Repository_with_file::delete_in_admin_data(const std::string& identifier)
/*
Function for deleting a certain organic fragment from admin_data
precond: identifier - type string
postcond: the organic fragment having the identifier given as an argument to the function if removed from admin_data; if there is no
such organic fragment, nothing happens
*/
{
	int index;

	for (index = 0; index < this->admin_data.size(); index++)
	{
		if (this->admin_data[index].Organic_fragment::get_identifier().compare(identifier) == 0)
		{
			this->admin_data.erase(admin_data.begin() + index);
			break;
		}
	}

	save_to_file();
}