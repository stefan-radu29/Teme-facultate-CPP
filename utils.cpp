#include "utils.h"
#include <sstream>
std::vector<std::string> tokenize(std::string str, char delimiter)
//Function for dividing a string based on a delimiter and storing these substrings in a vector
//precond: string - type string, delimiter - type char
//postcond: result contains all the substrings from the string, which was divided based on the delimiter
{
	std::vector <std::string> result;
	std::stringstream ss(str);
	std::string token;
	while (getline(ss, token, delimiter))
		result.push_back(token);

	return result;
}