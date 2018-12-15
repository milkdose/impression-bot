#infomration on compiling ImageMagick on linux
#https://imagemagick.org/Magick++/
output_mac_ID: ImpressionVisualBot.cpp ProductList.cpp ProductList.h turnToAlpha.cpp image_place.cpp regexing.cpp get_file_name.cpp ratio_resize_prod.cpp print_area_regex.cpp print_area_regex_prod.cpp down_size.cpp product_data.cpp ratio_resize_logo.cpp
	sudo g++ -O2 -o impressionbot ./image_place.cpp ./ImpressionVisualBot.cpp ./ProductList.cpp ./turnToAlpha.cpp ./regexing.cpp ./get_file_name.cpp ./ratio_resize_prod.cpp ./print_area_regex.cpp ./print_area_regex_prod.cpp ./down_size.cpp ./product_data.cpp ./ratio_resize_logo.cpp `pkg-config --libs --cflags opencv` `Magick++-config --cppflags --cxxflags --ldflags --libs`

output_mac: ImpressionVisualBot.cpp ProductList.cpp ProductList.h turnToAlpha.cpp image_place.cpp regexing.cpp get_file_name.cpp ratio_resize.cpp print_area_regex.cpp print_area_regex_prod.cpp down_size.cpp product_data.cpp
	sudo g++ ./image_place.cpp ./ImpressionVisualBot.cpp ./ProductList.cpp ./turnToAlpha.cpp ./regexing.cpp ./get_file_name.cpp ./ratio_resize.cpp ./print_area_regex.cpp ./print_area_regex_prod.cpp ./down_size.cpp ./product_data.cpp `pkg-config --libs --cflags opencv`

