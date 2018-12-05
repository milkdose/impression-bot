#include "ProductList.h"

float PIXEL_DIM = 3.7;
ifstream myfile ("./products_list_edited.csv");

double print_area_pixels_width(string code)
{
	vector<string> tok;

        string line = "";
        while(getline(myfile, line))
        {
                stringstream strstr(line);
                string word = "";
                while(getline(strstr, word, ',')) tok.push_back(word);
        }

        //regex
        string print_area_string;
        for (unsigned i=0;i<tok.size();i++)
        {
                if (tok[i] == code)
                {
                        //cout << tok[i+2] << endl;
                        print_area_string = tok[i+2];
                        break;
                }
        }

        //separate print area width and height values
        string temp = print_area_string;
        string print_area_del_width;
        string print_area_del_height;
        int total = 0;
        for (int i=0;i<print_area_string.length();i++)
        {
                total++;
                if(print_area_string[i] == 'x') //width
                {
                        print_area_del_width = temp.erase(i, total+1);
                }
                temp = print_area_string;
                if(print_area_string[i] == 'x') //height
                {
                        print_area_del_height = temp.erase(0, i+2);
                }
        }

        //cout << print_area_del_width << endl;
        //cout << print_area_del_height << endl;

        stringstream width(print_area_del_width);
        stringstream height(print_area_del_height);
        int prod_width;
        int prod_height;
        width >> prod_width; //value converted to int
        height >> prod_height; //value converted to int
	
	double width_pixels = (prod_height * PIXEL_DIM)-(PIXEL_DIM*20); //need to remove 20mm from final artwork for some reason

	return width_pixels;
}

double print_area_pixels_height(string code)
{
	vector<string> tok;

        string line = "";
        while(getline(myfile, line))
        {
                stringstream strstr(line);
                string word = "";
                while(getline(strstr, word, ',')) tok.push_back(word);
        }

        //regex
        string print_area_string;
        for (unsigned i=0;i<tok.size();i++)
        {
                if (tok[i] == code)
                {
                        //cout << tok[i+2] << endl;
                        print_area_string = tok[i+2];
                        break;
                }
        }

        //separate print area width and height values
        string temp = print_area_string;
        string print_area_del_width;
        string print_area_del_height;
        int total = 0;
        for (int i=0;i<print_area_string.length();i++)
        {
                total++;
                if(print_area_string[i] == 'x') //width
                {
                        print_area_del_width = temp.erase(i, total+1);
                }
                temp = print_area_string;
                if(print_area_string[i] == 'x') //height
                {
                        print_area_del_height = temp.erase(0, i+2);
                }
        }

        //cout << print_area_del_width << endl;
        //cout << print_area_del_height << endl;

        stringstream width(print_area_del_width);
        stringstream height(print_area_del_height);
        int prod_width;
        int prod_height;
        width >> prod_width; //value converted to int
        height >> prod_height; //value converted to int

	double heigth_pixels = (prod_height * PIXEL_DIM)-(PIXEL_DIM*20);

	return heigth_pixels;
}
