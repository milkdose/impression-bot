//This is a mess, most of the code has been pasted and edited here and there from stack overflow. But it sorta works OK...
//Day number...lost count but this thing is only getting messier and messier over time

//The product image(background) must contain no alpha channel(3 channel) and the logo(foreground) must contain an alpha channel(4 channel)

#include "ProductList.h"

class Bad_input {};

int main()
{
	printf("\033c"); //wtf? Weird console command for clearing terminal console
	const char *DIR_NAME = "../Impression2018_high/"; //why const char *? bacause function has C code, c does not have classes so no concept of string type
	string DIR_NAME_LOGO = "./test_images/"; //input dir
	string DIR_OUTPUT = "./output_images/"; //output dir
	string userDataInput; //product number
	string colourChoice; //product colour choice
	string ImageInput1; //product image
	string ImageInput2; //logo image

	cout << BOLD(FMAG("\nImpression Visual Bot"));
	cout << "\n-----------------------------------------------\n";

	cout << FMAG("Please type on the corresponding numbers to provided questions.\n");
	cout << BOLD(FMAG("\nType in the product number: "));
	cin >> userDataInput;

	cout << BOLD(FMAG("Pick colour of product: "));
	cin >> colourChoice;

	cout << BOLD(FMAG("Type in the second image: "));
	cin >> ImageInput2;

	cout << FMAG("\nCalculating, please wait...\n");

	//Regular Expression to navigate through the directory - linux/mac
	ImageInput1 = regexing((char *)DIR_NAME, userDataInput, colourChoice);

	//Turns the JPG image into a png without white pixels 
	Mat image2 = turnToAlpha(DIR_NAME_LOGO+ImageInput2);

	string dir_converted(DIR_NAME); //convert const char to string
 	Mat image1 = imread(dir_converted + "/" + ImageInput1); // Read the product image file
 	Mat image1_size = imread(dir_converted + "/" + ImageInput1); // Read the product image file

	string image1_full_path = DIR_NAME+ImageInput1; //full path for product image
	//string image2_full_path = DIR_NAME_LOGO+"converted_image.jpg"; //full path for logo image
	string image2_full_path = DIR_OUTPUT+"converted_image.jpg"; //full path for logo image

	double height_of_prod = print_area_pixels_height_prod(userDataInput);
	double width_of_prod = print_area_pixels_width_prod(userDataInput);
	
	resize(image1, image1, ratio_resize_prod(width_of_prod, height_of_prod, image1, image1_full_path, DIR_OUTPUT));

	if( image1.empty()) // Check for product image input
	{
	    cout <<  FRED("\nCould not open or find the PRODUCT image from regex.\n");
	    return -1;
	}
	else if( image2.empty()) // Check for artwork image input
	{
	    cout <<  FRED("\nCould not open or find the ARTWORK image.\n");
	    return -1;
	}

	Mat result;

	imwrite(DIR_OUTPUT+userDataInput+".jpg", productList((userDataInput),image2_full_path , image2, image1, colourChoice, result, image1_size, DIR_OUTPUT));
	return_product_data(userDataInput); //print out the product data from the CSV file to the terminal
	cout << "\n-----------------------------------------------\n";
	cout << FCYN("Image saved in: ") + DIR_OUTPUT << '\n' << endl;

	//remove temp logo and image files
	remove((DIR_OUTPUT+"output2.png").c_str()); //remove function is C code from stdio.h library, c_str() is c equivalent to string
	remove((DIR_OUTPUT+"output.png").c_str());
	remove((DIR_OUTPUT+"converted_image.jpg").c_str());

	return 0;
}
