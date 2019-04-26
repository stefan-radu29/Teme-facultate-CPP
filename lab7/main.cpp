#include "ui.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include "tests.h"

int main()
{	

	std::string file_location_command;
	std::getline(std::cin, file_location_command);
	std::ofstream file(file_location_command.substr(13));
	file.close();
	Repository_with_file file_repository{ file_location_command.substr(13) };
	Controller controller{ file_repository };
	Console console{ controller };

	console.run();
	//run_tests();

	return 0;
}