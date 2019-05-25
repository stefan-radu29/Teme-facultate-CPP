#pragma once
#include "B:\qt\5.12.3\msvc2017_64\include\QtWidgets\qwidget.h"
#include "Controller.h"
#include <qlistwidget.h>
#include "qlineedit.h"
#include "qpushbutton.h"

class GUI :
	public QWidget
{
private:
	Controller& controller;
	QListWidget *admin_data, *user_data;
	QLineEdit *identifier, *size, *level_of_infection, *quantity_of_micro_fragments, *photograph;
	QPushButton *add_button, *delete_button, *update_button, *save_button, *filter_button, *next_button, *mode_A_button, *mode_B_button;
public:
	GUI(Controller& controller);
	~GUI();

private:
	void initialize_GUI();
	void populate_admin_list();
};