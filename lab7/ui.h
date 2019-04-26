#pragma once
#include "controller.h"

class Console
{
private:

	Controller& controller;

public:

	Console(Controller& controller) : controller(controller) {}
	
	void run();

private:

	void ui_add(char* split_command);
	void ui_update(char* split_command);
	void ui_delete(char* split_command);
	void ui_list();
	void ui_next();
	void ui_save(char* split_command);
	void ui_list_given_size(char* split_command);
	void ui_list_mylist();
};