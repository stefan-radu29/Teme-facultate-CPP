#include "lab9.h"
#include <QtWidgets/QApplication>
#include "controller.h"
#include "Repository_with_file.h"
#include "validator.h"
#include <fstream>
#include <memory>
#include "Repository_with_file_and_HTML.h"
#include "main.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	Repository_with_file repository{ "organic_fragments.txt"};
	Validator validator;
	Controller controller{ repository, validator };

	GUI ui{ controller };
	ui.show();

	return a.exec();
}
