#include "ProductList.h"

Mat productList(string a, string logo_dir, Mat b, Mat c, string colChoice, Mat final_image, Mat image_size, string directory) //image2(logo) = b, image1(image) = c, choice = position choice
{
	//actually apply new size transformations to logo - keep ratio
	double prod_w = c.size().width;
	double prod_h = c.size().height;
	//resize(b, b, ratio_resize_logo(print_area_pixels_width(a), print_area_pixels_height(a), prod_w, prod_h, b, logo_dir, directory));
	resize(b, b, ratio_resize_logo(print_area_pixels_width(a), print_area_pixels_height(a), print_area_pixels_width_prod(a), print_area_pixels_height_prod(a), b, logo_dir, directory));
	/////////

	string manual_input;
	cout << BOLD(FMAG("\nManually place artwork onto product?"));
	cout << FMAG("\nMove the logo image with 'w, a, s, d' (press ENTER when done).\n");
	cout <<  FMAG("(yes or no): ");
	cin >> manual_input;

	string a_full = a + string("-") + colChoice;
	colChoice = string("-") + colChoice;
	if (manual_input == "yes" || manual_input == "y")
	{
		if(find_values_x(a) && find_values_y(a))
		{
			cout << FMAG("Data already present as been used, please remove data and re run for new artwork location.\n");
			int x_cor = find_values_x(a);		
			int y_cor = find_values_y(a);
			overlayImage(c, b, final_image, cv::Point(x_cor, y_cor));
		}
		else
		{
			place_interactive(a, c, b); //product string, product, logo
			int x_cor = find_values_x(a);		
			int y_cor = find_values_y(a);
            cout << "x: " << x_cor << endl;
            cout << "y: " << y_cor << endl;
			overlayImage(c, b, final_image, cv::Point(x_cor, y_cor));
		}
	}
	else if (manual_input == "no" || manual_input == "n")
	{
		if (a_full == string("3076") + colChoice)
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
		else if (a_full == string("2147") + colChoice)
			overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2)));
		else 
			overlayImage(c, b, final_image, cv::Point((c.size().width/2)-(b.size().width/2), (c.size().height/2)-(b.size().height/2))); //just place plogo centrally onto product image by default
	}
	else
		cout << "Please type yes or no.\n";
	
	return final_image;
	//Mat original_size_prod = down_size(image_size, final_image);
	//return original_size_prod;	
}
