//function returns file name but not full path, break Mat variable type in main function as a result - needs an alternative or FIX

#include "ProductList.h"

string SplitFilename (const std::string& str)
{
	unsigned found = str.find_last_of("/");

	string name = str.substr(found+1);

	return name;
}
