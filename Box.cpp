#include <iostream>
#include <iomanip>
#include "Box.h"
#include <string>
/*Default No-Arg ctor*/
Box::Box():box_number(1),length{1},width{1},height{1},name{"box"}
{
	/*length =  1.0F ;
	height = 1.0F;
	width = 1.0f;*/
}

/*Default Parameterized ctor*/
//Box::Box(float length, float height, float width, std::string name)
//{
//	this->length = length;
//	this->height = height;
//	this->width = width;
//	this->name = name;
//}

/*Parameterized ctor*/
Box::Box(float length, float height, float width, std::string name, int number):box_number(number)
{
	this->length = length;
	this->height = height;
	this->width = width;
	this->name = name;
	return;
}

float Box::get_length() const
{
	return length;
}

float Box::get_height() const
{
	return height;
}

float Box::get_width() const
{
	return width;
}

std::string Box::get_name() const
{
	return name;
}

void Box::print_box_details() const
{
	std::cout << std::showpoint << std::setprecision(3);
	std::cout << "Name : " << name << "\tNumber : " << box_number 
		<< "\tLength : " << length << "cm\tHeight : " << height << "cm\tWidth : " << width << "cm\n";
	

}
