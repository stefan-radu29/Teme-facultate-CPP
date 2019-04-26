#include "ui.h"
#include <iostream>
#include <cstring>
#include <stdexcept>
#include <cstdlib>

void Console::run()
{
	int mode_indicator = 0;
	char mode_choice[50];
	while (true)
	{
		if (mode_indicator == 0)
		{
			gets_s(mode_choice, 50);
		}
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

							else if(strcmp(split_command, "mode") == 0)
							{
								split_command = strtok(NULL, " ");
								if (strcmp(split_command, "B") == 0)
								{
									strcpy(mode_choice, "mode B");
									mode_indicator = 2;
									break;
								}
								else if (strcmp(split_command, "A") != 0)
								{
									strcpy(mode_choice, "wrong mode");
									break;
								}
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
					break;
				}
			}
			if (strcmp(mode_choice, "mode B") == 0)
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

							if (strcmp(split_command, "next") == 0)
							{
								this->ui_next();
							}

							else if (strcmp(split_command, "save") == 0)
							{
								this->ui_save(split_command);
							}

							else if (strcmp(split_command, "list") == 0)
							{
								this->ui_list_given_size(split_command);
							}

							else if (strcmp(split_command, "mylist") == 0)
							{
								this->ui_list_mylist();
							}

							else if (strcmp(split_command, "exit") == 0)
							{
								return;
							}

							else if (strcmp(split_command, "mode") == 0)
							{
								split_command = strtok(NULL, " ");
								if (strcmp(split_command, "A") == 0)
								{
									strcpy(mode_choice, "mode A");
									mode_indicator = 1;
									break;
								}
								else if (strcmp(split_command, "B") != 0)
								{
									strcpy(mode_choice, "wrong mode");
									break;
								}
							}
							else
							{
								throw std::exception("wrong command name!");
							}
						}
					}
					catch (std::exception& exception_B)
					{
						std::cout << exception_B.what() << '\n';
					}
					break;
				}
			}
			if (strcmp(mode_choice, "exit") == 0)
				return;
			else if (strcmp(mode_choice, "mode B") != 0 && strcmp(mode_choice, "mode A") != 0)
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
	double quantity_of_micro_fragments;
	char* arguments_for_add;

	split_command = split_command + 4;//go to the arguments of the command add

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
	quantity_of_micro_fragments = strtod(arguments_for_add, NULL);
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
	double quantity_of_micro_fragments;
	char* arguments_for_update;

	split_command = split_command + 7;//go to the arguments of the command update

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
	quantity_of_micro_fragments = strtod(arguments_for_update, NULL);
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

void Console::ui_next()
{
	const Organic_fragment& element_to_show = this->controller.Controller::next();
	std::cout << element_to_show.Organic_fragment::get_identifier() << ' ';
	std::cout << element_to_show.Organic_fragment::get_size() << ' ';
	std::cout << element_to_show.Organic_fragment::get_level_of_infection() << ' ';
	std::cout << element_to_show.Organic_fragment::get_quantity_of_micro_fragments() << ' ';
	std::cout << element_to_show.Organic_fragment::get_photograph() << '\n';
}

void Console::ui_save(char* split_command)
{
	split_command = strtok(NULL, " ");
	std::string identifier(split_command);
	//std::cout << identifier << '\n';

	this->controller.Controller::save(identifier);
}

void Console::ui_list_given_size(char* split_command)
{
	double quantity_of_micro_fragments;
	char* arguments_for_filter;

	split_command = split_command + 5;//go to the arguments of the command list_filter

	arguments_for_filter = strtok(split_command, ", ");
	std::string size(arguments_for_filter);
	//std::cout << size << '\n';

	arguments_for_filter= strtok(NULL, ", ");
	quantity_of_micro_fragments = strtod(arguments_for_filter, NULL);
	if (quantity_of_micro_fragments == 0)
		throw std::exception("invalid argument!");
	
	Dynamic_vector<Organic_fragment> filtered_vector = this->controller.Controller::get_filtered_list(size, quantity_of_micro_fragments);

	int vector_size = filtered_vector.get_size();
	int index;

	for (index = 0; index < vector_size; index++)
	{
		std::cout << filtered_vector[index].Organic_fragment::get_identifier() << ' ';
		std::cout << filtered_vector[index].Organic_fragment::get_size() << ' ';
		std::cout << filtered_vector[index].Organic_fragment::get_level_of_infection() << ' ';
		std::cout << filtered_vector[index].Organic_fragment::get_quantity_of_micro_fragments() << ' ';
		std::cout << filtered_vector[index].Organic_fragment::get_photograph() << '\n';
	}
}	


void Console::ui_list_mylist()
{
	const Dynamic_vector<Organic_fragment>& vector_to_print = this->controller.Controller::get_user_data();
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