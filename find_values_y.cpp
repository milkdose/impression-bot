#include "ProductList.h"

int find_values_y(string code)
{
	ifstream myfile ("./placement_xy.csv");

	vector<string> tok;
	
	string line = "";
	while(getline(myfile, line))
	{
	        stringstream strstr(line);
	        string word = "";
	        while(getline(strstr, word, ',')) 
			tok.push_back(word);
	}

	string x, y = "";
	for (int i=0;i<tok.size();i++)
		if (tok[i] == code)
		{
			x = tok[i+1];
			y = tok[i+2];
		}

	int int_x, int_y = 0;
	istringstream ss_x(x);
	istringstream ss_y(y);
	ss_x >> int_x;
	ss_y >> int_y;

	return int_y;
}
