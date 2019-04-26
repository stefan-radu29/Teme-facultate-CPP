#include "tests.h"
#include <assert.h>
#include "controller.h"
#include <string>
#include <fstream>


void test__controller_add__valid__true()
{
	std::string location = "A:\\OOP\\Laboratory\\lab7\\lab7\\test_file.txt";
	std::ofstream file(location);
	file.close();
	Repository_with_file file_repository{location};
	Controller controller{ file_repository };
	controller.add("x", "x", 1.2, 1.2, "x");
	assert(controller.get_admin_data().size() == 1);
	controller.add("y", "x", 1.2, 1.2, "x");
	assert(controller.get_admin_data().size() == 2);
}

void test__controller_delete__valid__true()
{
	std::string location = "A:\\OOP\\Laboratory\\lab7\\lab7\\test_file.txt";
	Repository_with_file file_repository{ location };
	Controller controller{ file_repository };
	controller.delete_fragment("x");
	assert(controller.get_admin_data().size() == 1);
}
void test__controller_update__valid__true()
{
	std::string location = "A:\\OOP\\Laboratory\\lab7\\lab7\\test_file.txt";
	Repository_with_file file_repository{ location };
	Controller controller{ file_repository };
	controller.update("y", "y", 1.2, 1.2, "y");
	Organic_fragment fragment{ "y", "y", 1.2, 1.2, "y" };
	assert(controller.get_admin_data()[0] == fragment);
	Organic_fragment fragment2{ "z", "y", 1.2, 1.2, "y" };
	assert(!(controller.get_admin_data()[0] == fragment2));
}
//
void test__controller_next__valid__true()
{
	std::string location = "A:\\OOP\\Laboratory\\lab7\\lab7\\test_file.txt";
	Repository_with_file file_repository{ location };
	Controller controller{ file_repository };
	controller.add("x", "x", 1, 1, "x");
	Organic_fragment fragment1{ "y", "y", 1.2, 1.2, "y" };
	Organic_fragment fragment2{ "x", "x", 1, 1, "x" };
	assert(controller.next() == fragment1);
	assert(controller.next() == fragment2);
	assert(controller.next() == fragment1);
}
void test__controller_save__valid__true()
{
	std::string location = "A:\\OOP\\Laboratory\\lab7\\lab7\\test_file.txt";
	Repository_with_file file_repository{ location };
	Controller controller{ file_repository };
	Organic_fragment fragment1{ "y", "y", 1.2, 1.2, "y" };
	Organic_fragment fragment2{ "x", "x", 1, 1, "x" };
	controller.save("x");
	assert(controller.get_user_data()[0] == fragment2);
	assert(controller.get_user_data().size() == 1);
	controller.save("y");
	assert(controller.get_user_data()[1] == fragment1);
	assert(controller.get_user_data().size() == 2);
}
void test__controller_get_filtered_list__valid__true()
{
	std::string location = "A:\\OOP\\Laboratory\\lab7\\lab7\\test_file.txt";
	Repository_with_file file_repository{ location };
	Controller controller{ file_repository };
	assert(controller.get_filtered_list("x", 1.2).size() == 0);
	assert(controller.get_filtered_list("y", 1.5).size() == 0);
	assert(controller.get_filtered_list("x", 0.5).size() == 1);
}
void test__controller_add__invalid__false()
{
	std::string location = "A:\\OOP\\Laboratory\\lab7\\lab7\\test_file.txt";
	Repository_with_file file_repository{ location };
	Controller controller{ file_repository };
	try
	{
		controller.add("x", "x", 1, 1, "x");
		assert(false);
	}
	catch(...)
	{
		assert(true);
	};
}
void test__controller_update__invalid__false()
{
	std::string location = "A:\\OOP\\Laboratory\\lab7\\lab7\\test_file.txt";
	Repository_with_file file_repository{ location };
	Controller controller{ file_repository };
	try
	{
		controller.update("z", "x", 1, 1, "x");
		assert(false);
	}
	catch (...)
	{
		assert(true);
	};
}
void test__bad_file_location()
{
	try
	{
		std::string location = "A:\\OOP\\Laboratory\\lab7\\lab7\\test_fil.txt";
		Repository_with_file file_repository{ location };
		assert(false);
	}
	catch (...)
	{
		assert(true);
	};
}

void run_tests()
{
	test__controller_add__valid__true();
	test__controller_delete__valid__true();
	test__controller_update__valid__true();
	test__controller_next__valid__true();
	test__controller_save__valid__true();
	test__controller_get_filtered_list__valid__true();
	test__controller_add__invalid__false();
	test__controller_update__invalid__false();
	test__bad_file_location();
}