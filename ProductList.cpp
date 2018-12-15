#include "ProductList.h"

Mat productList(string a, string logo_dir, Mat b, Mat c, string colChoice, Mat final_image, Mat image_size, string directory) //image2(logo) = b, image1(image) = c, choice = position choice
{
	//actually apply new size transformations to logo - keep ratio
	double prod_w = c.size().width;
	double prod_h = c.size().height;
	resize(b, b, ratio_resize_logo(print_area_pixels_width(a), print_area_pixels_height(a), prod_w, prod_h, b, logo_dir, directory));
	/////////

	a = a + string("-") + colChoice;
	colChoice = string("-") + colChoice;
	if (a == string("3076") + colChoice)
	{
		
		cout << BOLD(FMAG("\nImage position?\n"));
		cout << FMAG("1. Central\t2. Top central\t3. Bottom Central\n");
		int choice;
		cin.clear();
		cin >> choice;

		if (choice==1) //central
			overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)-95)); 
		else if(choice==2) //top central
			overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)-265)); 
		else if(choice==3) //bottom central
			overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)+115)); 
	}
	else if (a == string("2147") + colChoice)
		overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)));
	else 
		overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2))); //just place plogo centrally onto product image by default
	
	return final_image;
	//Mat original_size_prod = down_size(image_size, final_image);
	//return original_size_prod;	
}
