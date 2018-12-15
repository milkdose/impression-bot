#include "ProductList.h"

//product and artwork image comes in as the following: Width x Height
Size ratio_resize_prod(double width, double height, Mat image, string image_name, string directory)
{
	//convert the int intput to string for the image.scale() function
	stringstream val;
	if (height > width)
		val << height;
	else
		val << width;
	string value = val.str();

	//DEBUG print
	cout << "Prod h: " << image.size().height/5 << endl;
	cout << "Prod w: " << image.size().width/5 << endl;

	//perform image operations
	Image image_in;
	image_in.read(image_name);
	image_in.scale(value+"x"+value);
	//image_in.scale(width_string);
	image_in.write(directory+"output.png");

	Mat final_image = imread(directory+"output.png", -1);
	Size final_size(final_image.size().width, final_image.size().height);
	
	return final_size;
}
