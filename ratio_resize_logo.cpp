#include "ProductList.h"

//product and artwork image comes in as the following: Width x Height
Size ratio_resize_logo(double width, double height, double prod_w, double prod_h, Mat image, string image_name, string directory)
{
	double logo_h = image.size().height;
	double logo_w = image.size().width;

	stringstream w;
	w << width;
	stringstream h;
	h << height;
	string str_w = w.str();
	string str_h = h.str();

	//perform image operations
	Image image_in;
	image_in.read(image_name);

	//NOTE: measure length of notebook ribbon/marker and add to the height
	if (prod_w > prod_h && logo_w > logo_h && logo_h > height)
		image_in.scale(str_w+"x"+str_h);
	else if (prod_w > prod_h && logo_w > logo_h) //for when 
		image_in.scale(str_w+"x"+str_w);
	else if (prod_w > prod_h && logo_h > logo_w) //works vertical 1110 scale(wxw)
		image_in.scale(str_h+"x"+str_h);
	else if (prod_h > prod_w && logo_h > logo_w) //work 2432	
		image_in.scale(str_w+"x"+str_h);
	else if (prod_h > prod_w && logo_w > logo_h) //works 2432
		image_in.scale(str_w+"x"+str_w);
	else if (logo_w == logo_h && width < height) //if logo is square
		image_in.scale(str_w+"x"+str_w);
	else if (logo_w == logo_h) //if logo is square
		image_in.scale(str_h+"x"+str_h);
	else if (prod_w == prod_h && height < width && logo_w > logo_h)
		image_in.scale(str_w+"x"+str_w);
	else if (prod_w == prod_h && height < width && logo_h > logo_w)
		image_in.scale(str_h+"x"+str_h);
	else if (width < height)
		image_in.scale(str_w+"x"+str_w);
	else
		image_in.scale(str_h+"x"+str_h);

	//create temp files
	image_in.write(directory+"output2.png");
	Mat final_image = imread(directory+"output2.png", -1);

	//DEBUG print
//	cout << "Print area h: " << height/5 << endl;
//	cout << "Print area w: " << width/5 << endl;
//	//MORE DEBUG PRINT
//	cout << "Logo image w: " << final_image.size().width/5 << endl;
//	cout << "Logo image h: " << final_image.size().height/5 << endl;

	Size final_size(final_image.size().width, final_image.size().height);
	
	return final_size;
}
