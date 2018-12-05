#include "ProductList.h"

Mat productList(string a, Mat b, Mat c, string colChoice, Mat final_image, Mat image_size) //image2(logo) = b, image1(image) = c, choice = position choice
{
	//////resize image and keep ratio//////
	//actually apply new size transformations to logo
	resize(b, b, ratio_resize(print_area_pixels_width(a), print_area_pixels_height(a), b));
	/////////
	
	a = a + string("-") + colChoice;
	if (a == string("3076") + string("-") + colChoice)
	{

		cout << "\nImage position?\n";
		cout << "1. Central\t2. Top central\t3. Bottom Central\n";
		int choice;
		cin.clear();
		cin >> choice;

		if (choice==1) //central
		{
			overlayImage(c, b, final_image, Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)-95)); 
		}
		else if(choice==2) //top central
		{
			overlayImage(c, b, final_image, Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)-265)); 
		}
		else if(choice==3) //bottom central
		{
			overlayImage(c, b, final_image, Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)+115)); 
		}

	}
	else 
		overlayImage(c, b, final_image, Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2))); //just place plogo centrally onto product image by default
	
	//return final_image;
	Mat original_size_prod = down_size(image_size, final_image);
	return original_size_prod;	
}
