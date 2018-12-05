// to see more info on working with images with alpha cannel: https://docs.opencv.org/3.4.1/d4/da8/group__imgcodecs.html#ga288b8b3da0892bd651fce07b3bbd3a56

#include "ProductList.h"

Mat turnToAlpha(string imagePlace)
{
	int choice;
	cout << "\nWhat colour is your artwork?";
	cout << "\n1.White\t2.Black\t3.Various Colours\n";
	cin >> choice;

	Mat input = imread("./" + string(imagePlace), -1);
	
	Mat input_bgra;
	cvtColor(input, input_bgra, CV_BGR2BGRA);

	if (choice == 1)
	{
		// find all white pixel and set alpha value to zero:
		for (int y = 0; y < input_bgra.rows; ++y)
		for (int x = 0; x < input_bgra.cols; ++x)
		{
			Vec4b & pixel = input_bgra.at<cv::Vec4b>(y, x);
			// if pixel is white
			int thres = 150; // where thres is some value smaller but near to 255(white).
			if (pixel[0] >= thres&& pixel[1] >= thres && pixel[2] >= thres)
			{
				// set alpha to zero:
				pixel[3] = 0;
			}
		}
	}
	else if (choice == 2)
	{
                // find all white pixel and set alpha value to zero:
                for (int y = 0; y < input_bgra.rows; ++y)
                for (int x = 0; x < input_bgra.cols; ++x)
                {
                        Vec4b & pixel = input_bgra.at<cv::Vec4b>(y, x);
                        // if pixel is white
                        int thres = 10; // where thres is some value greater but near to 0(black).
                        if (pixel[0] <= thres && pixel[1] <= thres && pixel[2] <= thres)
                        {
                                // set alpha to zero:
                                pixel[3] = 0;
                        }
                }
	}
	else if (choice == 3)
	{
		Mat input = imread("./" + string(imagePlace), -1); //UNCHANGED causes logo to not show in output
	
		Mat input_bgra;
		cvtColor(input, input_bgra, CV_BGR2BGRA);
		// find all white pixel and set alpha value to zero:
		for (int y = 0; y < input_bgra.rows; ++y)
		for (int x = 0; x < input_bgra.cols; ++x)
		{
			Vec4b & pixel = input_bgra.at<cv::Vec4b>(y, x);
			// if pixel is white
			int thres = 255; // where thres is some value smaller but near to 255(white).
			if (pixel[0] >= thres&& pixel[1] >= thres && pixel[2] >= thres)
			{
				// set alpha to zero:
				pixel[3] = 0;
			}
		}
	}

	// save as .png file (which supports alpha channels/transparency)
	//imwrite("./testAlpha.png", input_bgra); //for testing
	
	return input_bgra; //return input for non alpha logo (actually shows up)
}
