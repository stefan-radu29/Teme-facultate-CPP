#include "ui.h"
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdlib>

void Console::run()
{
	while (true)
	{
		char mode_choice[50];
		gets_s(mode_choice, 50);
		try
		{
			if (strcmp(mode_choice, "mode A") == 0)
			{
				while (true)
				{
					try
					{
						while (true)
						{
							char command[100];
							char* split_command;
							scanf(" %[^'\n']s", command);
							split_command = strtok(command, " ");

							if (strcmp(split_command, "add") == 0)
							{
								this->ui_add(split_command);
							}

							else if (strcmp(split_command, "update") == 0)
							{
								this->ui_update(split_command);
							}

							else if (strcmp(split_command, "delete") == 0)
							{
								this->ui_delete(split_command);
							}

							else if (strcmp(split_command, "list") == 0)
							{
								this->ui_list();
							}

							else if (strcmp(split_command, "exit") == 0)
							{
								return;
							}

							else
							{
								throw std::exception("wrong command name!");
							}
						}
					}
					catch (std::exception& exception_A)
					{
						std::cout << exception_A.what() << '\n';
					}
				}
			}
			else if (strcmp(mode_choice, "mode B") == 0)
			{
				while (true)
				{
					try
					{
						while (true)
						{
							return;
						}
					}
					catch (std::exception& exception_B)
					{
						std::cout << exception_B.what() << '\n';
					}
				}
			}
			else if (strcmp(mode_choice, "exit") == 0)
				return;
			else
			{
				throw std::exception("wrong mode!");
			}
		}
		catch (std::exception& exception_mode)
		{
			std::cout << exception_mode.what() << '\n';
		}
	}
}

void Console::ui_add(char* split_command)
{
	double level_of_infection;
	int quantity_of_micro_fragments;
	char* arguments_for_add;

	split_command = split_command + 4;//go to the argmuents of the command add

	arguments_for_add = strtok(split_command, ", ");
	std::string identifier(arguments_for_add);
	//std::cout << identifier << '\n';

	arguments_for_add = strtok(NULL, ", ");
	std::string size(arguments_for_add);
	//std::cout << size << '\n';

	arguments_for_add = strtok(NULL, ", ");
	level_of_infection = strtod(arguments_for_add, NULL);
	if (level_of_infection == 0)
		throw std::exception("invalid argument!");
	//printf("%.2f", level_of_infection);

	arguments_for_add = strtok(NULL, ", ");
	quantity_of_micro_fragments = atoi(arguments_for_add);
	if (quantity_of_micro_fragments == 0)
		throw std::exception("invalid argument!");
	//std::cout << quantity_of_micro_fragments << '\n';

	arguments_for_add = strtok(NULL, ", ");
	std::string photograph(arguments_for_add);
	//std::cout << photograph << '\n';

	this->controller.Controller::add(identifier, size, level_of_infection, quantity_of_micro_fragments, photograph);
}

void Console::ui_update(char* split_command)
{
	double level_of_infection;
	int quantity_of_micro_fragments;
	char* arguments_for_update;

	split_command = split_command + 7;//go to the argmuents of the command update

	arguments_for_update = strtok(split_command, ", ");
	std::string identifier(arguments_for_update);
	//std::cout << identifier << '\n';

	arguments_for_update = strtok(NULL, ", ");
	std::string size(arguments_for_update);
	//std::cout << size << '\n';

	arguments_for_update = strtok(NULL, ", ");
	level_of_infection = strtod(arguments_for_update, NULL);
	if (level_of_infection == 0)
		throw std::exception("invalid argument!");
	//printf("%.2f", level_of_infection);

	arguments_for_update = strtok(NULL, ", ");
	quantity_of_micro_fragments = atoi(arguments_for_update);
	if (quantity_of_micro_fragments == 0)
		throw std::exception("invalid argument!");
	//std::cout << quantity_of_micro_fragments << '\n';

	arguments_for_update = strtok(NULL, ", ");
	std::string photograph(arguments_for_update);
	//std::cout << photograph << '\n';

	this->controller.Controller::update(identifier, size, level_of_infection, quantity_of_micro_fragments, photograph);
}

void Console::ui_delete(char* split_command)
{
	split_command = strtok(NULL, " ");
	std::string identifier(split_command);
	//std::cout << identifier << '\n';

	this->controller.Controller::delete_fragment(identifier);
}

void Console::ui_list()
{
	const Dynamic_vector<Organic_fragment>& vector_to_print = this->controller.Controller::get_admin_data();
	int size = vector_to_print.get_size();
	int index;

	for (index = 0; index < size; index++)
	{
		std::cout << vector_to_print[index].Organic_fragment::get_identifier() << ' ';
		std::cout << vector_to_print[index].Organic_fragment::get_size() << ' ';
		std::cout << vector_to_print[index].Organic_fragment::get_level_of_infection() << ' ';
		std::cout << vector_to_print[index].Organic_fragment::get_quantity_of_micro_fragments() << ' ';
		std::cout << vector_to_print[index].Organic_fragment::get_photograph() << '\n';
	}
}