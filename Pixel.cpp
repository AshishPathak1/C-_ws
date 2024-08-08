#include "Pixel.h"
#include <string_view>
#include <string>
using namespace std::literals;


/*returns the value of red color*/
inline int Pixel::get_red() const {
	return red;
}

/*returns the value of green color*/
inline int Pixel::get_green() const {
	return green;
}

/*returns the value of blue color*/
inline int Pixel::get_blue() const {
	return blue;
}

/*Prints t*/
std::string Pixel::get_pixel_colors() const {
	return "Red : "s + std::to_string(red) +"\t"
		+ "Green : "s + std::to_string(green) + "\t"
		+ "Blue : "s + std::to_string(blue) +"\n";
}

/*Methods takes a single argument of type int to set the value of red color*/
void Pixel::set_red(int r) {
	red = r;
}

/*Methods takes a single argument of type int to set the value of green color*/
void Pixel::set_green(int g) {
	green = g;
}

/*Methods takes a single argument of type int to set the value of blue color*/
void Pixel::set_blue(int b) {
	blue = b;
}
