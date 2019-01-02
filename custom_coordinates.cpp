#include "ProductList.h"

void custom_coordinates(string code, int x, int y)
{
	vector<string> tok;

	fstream myfile;
    myfile.open("./placement_xy.csv", ios::in | ios::out | ios::app);
    if (!myfile){
            cout << "Failed to open file" << endl;
    }

    stringstream prod;
	stringstream horizontal;
	stringstream vertical;
	horizontal << x;
	vertical << y;
	prod << code;
	string str_x = horizontal.str();
	string str_y = vertical.str();
	string str_code = prod.str();

    // TEMP SOLUTION // - Plug values straight
    myfile << str_code + ",";
    myfile << str_x + ",";
    myfile << str_y + "\n";

    // GET BACK TO THIS //
//- check if coordinates for product is already present and add them if not

//	string line;
//	while(getline(myfile, line))
//	{
//	        stringstream strstr(line);
//	        string word = "";
//	        while(getline(strstr, word, ',')) 
//		{
//			tok.push_back(word);
//			if (str_code == word)
//			{
//				cout << "VALUE ALREADY IN DATABASE FILE.(Please remove all instances and re-run the program)\n";
//				break;
//			}
//		}
//	}
//
//	line = "";
//
//
//    int linesGoTo = 0;
//	while(getline(myfile, line))
//	{
//	    stringstream strstr2(line);
//	    string word = "";
//	    while(getline(strstr2, word, ',') && linesGoTo < tok.size()) 
//		{
//			linesGoTo++;
//		}
//		if(linesGoTo == tok.size())
//        {
//			myfile << str_code << "," << str_x << "," << str_y << "," << "\n";
//        }
//	}
}
