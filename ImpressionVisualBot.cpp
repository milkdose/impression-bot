//This is a mess, most of the code has been pasted and edited here and there from stack overflow. But it sorta works OK...
//Day number...lost count but this thing is only getting messier and messier over time

//The product image(background) must contain no alpha channel(3 channel) and the logo(foreground) must contain an alpha channel(4 channel)

#include "ProductList.h"

int main()
{
	printf("\033c"); //wtf? Weird console command for clearing terminal console
	const char *DIR_NAME = "../Impression2018_high"; //why const char *? Find why const is a requirement
	string DIR_NAME_LOGO = "./test_images/";
	string userDataInput; //product number
	string colourChoice; //product colour choice
	string ImageInput1; //product image
	string ImageInput2; //logo image

	cout << "\nImpression Visual Bot";
	cout << "\n-----------------------------------------------\n";

	cout << "Type in the product number: ";
	cin >> userDataInput;

	cout << "Pick colour of product: ";
	cin >> colourChoice;

	cout << "\nType in the second image: ";
	cin >> ImageInput2;

	cout << "\nCalculating, please wait...\n";

	//Regular Expression to navigate through the directory - linux/mac
	ImageInput1 = regexing((char *)DIR_NAME, userDataInput, colourChoice);

	Mat image2 = turnToAlpha(DIR_NAME_LOGO+ImageInput2);	//tuenToAlpha() turns the JPG image into a png without white pixels 

	string dir_converted(DIR_NAME); //convert const char to string
 	Mat image1 = imread(dir_converted + "/" + ImageInput1); // Read the product image file
 	Mat image1_size = imread(dir_converted + "/" + ImageInput1); // Read the product image file

	resize(image1, image1, ratio_resize(print_area_pixels_width_prod(userDataInput), print_area_pixels_height_prod(userDataInput), image1));

	if( image1.empty()) // Check for product image input
	{
	    cout <<  "\nCould not open or find the PRODUCT image from regex.\n";
	    return -1;
	}
	else if( image2.empty()) // Check for artwork image input
	{
	    cout <<  "\nCould not open or find the ARTWORK image.\n";
	    return -1;
	}

	Mat result;
  	//namedWindow( "Display window", WINDOW_AUTOSIZE ); // Create a window for display.
   	//imshow( "Display window", productList((userDataInput), image2, image1, colourChoice, result, image1_size));
	//waitKey(0); // Wait for a keystroke in the window

	imwrite("./output_images/"+userDataInput+".jpg", productList((userDataInput), image2, image1, colourChoice, result, image1_size));	
	cout << "\nDone.";
	cout << "\n-----------------------------------------------\n";

	return 0;
}
