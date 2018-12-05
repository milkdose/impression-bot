#include "ProductList.h"

Mat down_size(Mat image_size, Mat image)
{
	Size resized_image(image_size.size().width, image_size.size().height);
	resize(image, image, resized_image);

	return image;
}
