#include "validator.h"
#include <string>

void Validator::validate(Organic_fragment& fragment)
{
	std::string errors = "\n";
 
	if (fragment.get_level_of_infection() == 0)
		errors += "Invalid level of infection!\n";
	if (fragment.get_quantity_of_micro_fragments() == 0)
		errors += "Invalid quantity of micro fragments!\n";
	const char* errors_const_char = errors.c_str();
	if(errors.compare("\n") != 0)
		throw Validator_exception(errors_const_char);
}
