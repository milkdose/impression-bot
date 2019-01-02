#https://imagemagick.org/Magick++/
output_mac_ID: ImpressionVisualBot.cpp ProductList.cpp ProductList.h turnToAlpha.cpp image_place.cpp regexing.cpp get_file_name.cpp ratio_resize_prod.cpp print_area_regex.cpp print_area_regex_prod.cpp down_size.cpp product_data.cpp ratio_resize_logo.cpp image_type.cpp
	sudo g++ -O2 -o impressionbot ./image_place.cpp ./ImpressionVisualBot.cpp ./ProductList.cpp ./turnToAlpha.cpp ./regexing.cpp ./get_file_name.cpp ./ratio_resize_prod.cpp ./print_area_regex.cpp ./print_area_regex_prod.cpp ./down_size.cpp ./product_data.cpp ./ratio_resize_logo.cpp ./image_type.cpp `pkg-config --libs --cflags opencv` `Magick++-config --cppflags --cxxflags --ldflags --libs`

#https://stackoverflow.com/questions/30581375/linking-error-with-simple-opencv-program
output_clang: ImpressionVisualBot.cpp ProductList.cpp ProductList.h turnToAlpha.cpp image_place.cpp regexing.cpp get_file_name.cpp ratio_resize_prod.cpp print_area_regex.cpp print_area_regex_prod.cpp down_size.cpp product_data.cpp ratio_resize_logo.cpp image_type.cpp
	sudo clang++ -Wall -g -o impressionbot ./image_place.cpp ./ImpressionVisualBot.cpp ./ProductList.cpp ./turnToAlpha.cpp ./regexing.cpp ./get_file_name.cpp ./ratio_resize_prod.cpp ./print_area_regex.cpp ./print_area_regex_prod.cpp ./down_size.cpp ./product_data.cpp ./ratio_resize_logo.cpp ./image_type.cpp `pkg-config --libs --cflags opencv` `Magick++-config --cppflags --cxxflags --ldflags --libs`

cmake:
	sudo cmake -H. -Bbuild -DCMAKE_C_COMPILER=$CC -DCMAKE_CXX_COMPILER=$CXX
