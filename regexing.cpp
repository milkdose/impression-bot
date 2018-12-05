#include "ProductList.h"

Mat rawImage;

string regexing(char *dir_name, string userData, string colourChoice)
{
	//string ImageInput1;
	DIR *directory; 
	struct dirent *_dirent;
	string temp_file_name;

	//open directory
	directory = opendir(dir_name);
	//read files
 	while((_dirent = readdir(directory)) != NULL)
 	{
	       string fileName = string(dir_name) + "/" + string(_dirent->d_name);
	       Mat rawImage = cv::imread(fileName.c_str());

		//find the correct file
	        regex r(userData + string("-") + colourChoice); //regex condition number 1 - r
		regex t("FRT");	//regex condition number 2 - t
		regex u("TOP"); //regex condition number 3 - u
	        bool match = regex_search(fileName, r);
		bool match2 = regex_search(fileName, t);
		bool match3 = regex_search(fileName, u);
		if((match==true && match2==true) || (match==true && match3==true))
		{
			temp_file_name = SplitFilename(fileName);

			//temp_file_name = fileName;
			//temp_file_name.erase(0, 2); //get file name only, doesn't work for long directories
			cout << "Product image found -> " << temp_file_name << endl;
			return temp_file_name;
			break;
		}
    	}
	closedir(directory);
	
 	if(!directory) //if folder cannot be opened
		cout << "Cannot open Input Folder\n";
	else if(rawImage.data == NULL) //if file cannot be found
		cout << "\nPlease Note Cannot Open Image: Image file might not exist.\n";
}
