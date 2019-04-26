#include "ui.h"
#include <iostream>
#include <Windows.h>
#include <string>

int main()
{
	/*Dynamic_vector<int> d{ 50 };
	d.add(5);
	d.add(6);
	d.add(7);
	d.remove(6);
	std::cout << d[1];
	d[1] = 10;
	try
	{
		d[2] = 10;
	}
	catch (std::exception& e) { std::cout << e.what(); }
	std::cout << d.get_size();
	system("pause");*/
	
	Repository repository{};
	Controller controller{ repository };
	Console console{ controller };

	console.run();

	return 0;
}