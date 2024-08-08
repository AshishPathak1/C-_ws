#pragma once
#include <string>
struct Pixel
{
	/*data members : fields*/
	int red;
	int green;
	int blue;
	
	/*returns the value of red color*/
	inline int get_red() const;

	/*returns the value of green color*/
	inline int get_green() const;

	/*returns the value of blue color*/
	inline int get_blue() const;

	/*Prints the value of all colours in the Pixel*/
	std::string get_pixel_colors() const;

	/*Methods takes a single argument of type int to set the value of red color*/
	void set_red(int );

	/*Methods takes a single argument of type int to set the value of green color*/
	void set_green(int);

	/*Methods takes a single argument of type int to set the value of blue color*/
	void set_blue(int );

};

