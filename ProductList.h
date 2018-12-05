#include <opencv2/core.hpp>
//#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc.hpp>
#include <string>
#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>
#include <regex>
#include <algorithm>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctype.h>
#include <sstream>

using namespace std;
using namespace cv;

string regexing(char *dir_name, string, string); //regex for walking directory

Mat productList(string, Mat, Mat, string, Mat, Mat); //finding correct prodiuct specs

Mat turnToAlpha(string); //turns second image into alpha

void overlayImage(const Mat &, const Mat &, Mat &, Point2i); //combining logo and product image

string SplitFilename (const std::string& str); //retrieve file name only for regex

Size ratio_resize(double, double, Mat);

Mat down_size(Mat, Mat);

double print_area_pixels_width(string code);
double print_area_pixels_height(string code);
double print_area_pixels_height_prod(string code);
double print_area_pixels_width_prod(string code);
