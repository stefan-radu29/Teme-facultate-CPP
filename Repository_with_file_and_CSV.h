#pragma once
#include "Repository_with_file.h"
class Repository_with_file_and_CSV :
	public Repository_with_file
{
private:
	std::string csv_file_name;
public:
	Repository_with_file_and_CSV(std::string file_name, std::string csv_file_name);
	~Repository_with_file_and_CSV();
	void save(const std::string& identifier);
};

