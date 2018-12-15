#include "ProductList.h"

ifstream myfile3 ("./products_list_edited.csv");

void return_product_data(string code)
{
	vector<string> specs;

        string line = "";
        while(getline(myfile3, line))
        {
                stringstream strstr(line);
                string word = "";
                while(getline(strstr, word, ',')) specs.push_back(word);
        }

	cout << '\n';
        //regex
        string print_area_string;
        for (unsigned i=0;i<specs.size();i++)
        {
                if (specs[i] == code)
                {
                        cout << FCYN("Product code: ") << specs[i] << endl;
                        cout << FCYN("Item: ") << specs[i+1] << endl;
                        cout << FCYN("Print area: ") << specs[i+2] << " mm" << endl;
                        cout << FCYN("Product dimensions: ") << specs[i+4] << " cm" << endl;
                        cout << FCYN("Materials: ") << specs[i+5] << endl;

                        break;
                }
        }
}
