#include "ProductList.h"

void place_interactive(string code, Mat c, Mat b) //c = product, b = logo
{
	initscr();

//	Mat c = imread("bag.jpg", -1);
//	Mat b = turnToAlpha("square.jpg");
	Mat final_image;

	char user_input = 1;
	//place logo centrally onto product image to start with
	int x = (c.size().width/2)-(b.size().width/2);
	int y = (c.size().height/2)-(b.size().height/2);

	overlayImage(c, b, final_image, cv::Point(x, y)); 
	int wait_time = 1;
	int distance = 5;
	while(user_input != '\n')
	{
		cvNamedWindow("Display", WINDOW_AUTOSIZE);
		imshow("Display", final_image);
		user_input = getch();

		switch(user_input)
		{
			case 'w': y -= distance;
			 	  overlayImage(c, b, final_image, cv::Point(x, y)); 
			 	  waitKey(wait_time);
				  break;
			case 's': y += distance;
			 	  overlayImage(c, b, final_image, cv::Point(x, y)); 
			 	  waitKey(wait_time);
				  break;
			case 'd': x += distance;
			 	  overlayImage(c, b, final_image, cv::Point(x, y)); 
			 	  waitKey(wait_time);
				  break;
			case 'a': x -= distance;
			 	  overlayImage(c, b, final_image, cv::Point(x, y)); 
			 	  waitKey(wait_time);
				  break;
			case '\n':cout << "Placement complete.\n";
				  cvDestroyAllWindows();
				  break;
		}
	}

	endwin();

//	cout << "x: " << x << endl;
//	cout << "y: " << y << endl;

	custom_coordinates(code, x, y);
}
