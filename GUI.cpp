#include "GUI.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <qlabel.h>

GUI::GUI(Controller& controller) : controller{ controller }
{
	this->initialize_GUI();
	this->populate_admin_list();
}

GUI::~GUI()
{
}

void GUI::initialize_GUI()
{
	QVBoxLayout *main_layout = new QVBoxLayout{ this };

	QLabel *admin_data_label = new QLabel{};
	admin_data_label->setText("All fragments");

	QLabel *user_data_label = new QLabel{};
	user_data_label->setText("Saved fragments");

	
	QHBoxLayout* layout = new QHBoxLayout{};
	QVBoxLayout* admin_layout = new QVBoxLayout{};
	QVBoxLayout* user_layout = new QVBoxLayout{};

	this->admin_data = new QListWidget{};
	admin_layout->addWidget(admin_data_label);
	admin_layout->addWidget(this->admin_data);
	
	this->user_data = new QListWidget{};
	user_layout->addWidget(user_data_label);
	user_layout->addWidget(this->user_data);

	layout->addLayout(admin_layout);
	layout->addLayout(user_layout);
	main_layout->addLayout(layout);

	QVBoxLayout* right_side = new QVBoxLayout{};
	QVBoxLayout* left_side = new QVBoxLayout{};
	
	layout->addLayout(right_side);
	layout->addLayout(left_side);

	QFormLayout* data_layout = new QFormLayout{};
	this->identifier = new QLineEdit{};
	data_layout->addRow("Identifier", this->identifier);
	this->size = new QLineEdit{};
	data_layout->addRow("Size", this->size);
	this->level_of_infection = new QLineEdit{};
	data_layout->addRow("Level of infection", this->level_of_infection);
	this->quantity_of_micro_fragments = new QLineEdit{};
	data_layout->addRow("Quantity of micro fragments", this->quantity_of_micro_fragments);
	this->photograph = new QLineEdit{};
	data_layout->addRow("Photograph", this->photograph);

	QHBoxLayout *buttons_layout = new QHBoxLayout{};
	
	QVBoxLayout *mode_A_buttons = new QVBoxLayout{};
	this->mode_A_button = new QPushButton{};
	mode_A_button->setText("Mode A");
	this->add_button = new QPushButton{};
	add_button->setText("Add organic fragment");
	this->delete_button = new QPushButton{};
	delete_button->setText("Delete organic fragment");
	this->update_button = new QPushButton{};
	update_button->setText("Update organic fragment");

	QVBoxLayout *mode_B_buttons = new QVBoxLayout{};
	this->mode_B_button = new QPushButton{};
	mode_B_button->setText("Mode B");
	this->next_button = new QPushButton{};
	next_button->setText("Next organic fragment");
	this->save_button = new QPushButton{};
	save_button->setText("Save organic fragment");
	this->filter_button = new QPushButton{};
	filter_button->setText("Filter by size");
	
	mode_A_buttons->addWidget(this->mode_A_button);
	mode_A_buttons->addWidget(this->add_button);
	mode_A_buttons->addWidget(this->delete_button);
	mode_A_buttons->addWidget(this->update_button);
	mode_B_buttons->addWidget(this->mode_B_button);
	mode_B_buttons->addWidget(this->next_button);
	mode_B_buttons->addWidget(this->save_button);
	mode_B_buttons->addWidget(this->filter_button);

	buttons_layout->addLayout(mode_A_buttons);
	buttons_layout->addLayout(mode_B_buttons);

	right_side->addLayout(data_layout);
	right_side->addLayout(buttons_layout);
}

void GUI::populate_admin_list()
{
	for (Organic_fragment& fragment : this->controller.get_admin_data())
	{
		this->admin_data->addItem(QString::fromStdString(fragment.get_identifier() + " " + fragment.get_size() + " " + std::to_string(fragment.get_level_of_infection()) + " " + std::to_string(fragment.get_quantity_of_micro_fragments()) + " " + fragment.get_photograph()));
	}
}
