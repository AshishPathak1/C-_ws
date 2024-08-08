#pragma once
#include <string>
#include <sstream>
#include <iomanip>

class Box {
private:
	float height;
	float width;
	float length;
	std::string color;
public:
	//default deleted ctor
	Box() = delete;

	Box(float p_height, float p_width, float p_length, const std::string& p_color) {
		height = p_height;
		width = p_width;
		length = p_length;
		color = p_color;
	}

	std::string get_box_dimensions() {
		//Alternative -I
	/*	std::string dimensions = "Height : " + std::to_string(height) + 
			"  Width : " + std::to_string(width) + 
			"  Length : " + std::to_string(length) ;
			return dimensions;*/
			

		//Alternative -II 
		std::ostringstream ostr{};
		ostr << std::showpoint;
		ostr  << "Height : "  << std::setprecision(5) << height 
			<< "  Width  : " << std::setprecision(5) <<  width 
			<< "  Length : " << std::setprecision(5) << length 
			<< "  Color  : " << color << '\n';
		return ostr.str();
		
	}

	//Box(const Box&) = default;

	/*Copy constructor*/
	Box(const Box& other_box) {
		/*Member by menber copy : Shallow Copy*/
		/*The contents of the initializing object "other_box" are COPIED the new box that is being created*/
		width = other_box.width;
		height = other_box.height;
		length = other_box.length;
		color = other_box.color;
	}

	//Box(Box&& ) = delete;
	/*Move constructor: typically "steal" the resources held by the argument */
	Box(Box&& other_box) noexcept {
		/*The contents of the initializing object "other_box" are TRANSFERRED the new box that is being created*/
		width  = other_box.width;
		height = other_box.height;
		length = other_box.length;
		color  = std::move(other_box.color);
	}

	
};