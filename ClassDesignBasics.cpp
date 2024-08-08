// ClassDesignBasics.cpp : Designing of Class
//

#include <iostream>
#include <string>
#include "Point.h"
#include "Pixel.h"
int main()
{
	//Test Point
	{
		struct Point p1;
		//Point p2;

		p1.set_x_cord(10);
		p1.set_y_cord(30);
		std::cout << "X Coordinate : " << p1.get_x_cord() << std::endl;
		std::cout << "Y Coordinate : " << p1.get_y_cord() << std::endl;
	}
	
	//Test Pixel
	{
	//	struct Pixel p1;
		Pixel p;
		p.set_red(255);
		p.set_green(102);
		p.set_blue(204);

		std::cout << "Red  : " << p.get_red() << std::endl;
		std::cout << "Green: " << p.get_green() << std::endl;
		std::cout << "Blue : " << p.get_blue() << std::endl;

		std::cout << p.get_pixel_colors() << std::endl;

	}
	return EXIT_SUCCESS;

}
