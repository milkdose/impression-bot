#include "ProductList.h"

Size ratio_resize(double maxWidth, double maxHeight, Mat image)
{
        double srcWidth = image.size().width;
        double srcHeight = image.size().height;

        double resizeWidth = srcWidth;
        double resizeHeight = srcHeight;
        
        double aspect = resizeWidth / resizeHeight;
       
	double Width;
	double Height;

	if (srcWidth > srcHeight || srcWidth == srcHeight || srcHeight == srcWidth)
	{
		resizeWidth = maxWidth;
		resizeHeight = resizeWidth / aspect;
		      
		Width = resizeWidth;
		Height = resizeHeight;
	}
	else if (srcHeight > srcWidth)
	{
		resizeHeight = maxHeight; resizeWidth = resizeHeight * aspect; 
		Width = resizeWidth;
		Height = resizeHeight;
	}
        
	//define size
        Size resized_image(Width, Height);

	return resized_image;
}
