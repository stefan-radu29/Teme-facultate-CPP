#pragma once
#include "Repository_with_file.h"
class Repository_with_file_and_HTML :
	public Repository_with_file
{
private:
	std::string html_file_name;
public:
	Repository_with_file_and_HTML(std::string file_name, std::string html_file_name);
	~Repository_with_file_and_HTML();
	void save(const std::string& identifier);
};

