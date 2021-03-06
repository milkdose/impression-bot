#include "ProductList.h"

double MULTIPLIER2 = 5; //default 5
float PIXEL_DIM2 = 3.7;
ifstream myfile2 ("./products_list_edited.csv");

double print_area_pixels_height_prod(string code)
{
    vector<string> tok;
    
    string line = "";
    while(getline(myfile2, line))
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
                    //cout << tok[i+4] << endl;
                    print_area_string = tok[i+4];
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
    double prod_width;
    double prod_height;
    width >> prod_width; //value converted to int
    height >> prod_height; //value converted to int
    
    //	if (prod_width > prod_height)
    //		prod_height = prod_width;
    //	else if (prod_height > prod_width)
    //		prod_width = prod_height;
    
    double height_pixels_mm = prod_height * 10; //convert to mm from cm
    //double height_pixels_prod = ((height_pixels_mm * PIXEL_DIM2)-(PIXEL_DIM2*20))*MULTIPLIER2;
    double height_pixels_prod = height_pixels_mm*MULTIPLIER2;
    
    return height_pixels_prod;
}
