#pragma once
#include "repository.h"
class Repository_with_file :
	public Repository
{
private:
	std::string file_name;

public:
	Repository_with_file(std::string file_name):Repository()
	{
		this->file_name = file_name;
		load_from_file();
	}

private:
	void load_from_file();
	void save_to_file();

public:
	void add_to_admin_data(Organic_fragment & new_organic_fragment);
	void update_to_admin_data(Organic_fragment & updated_organic_fragment);
	void delete_in_admin_data(const std::string& identifier);
};

