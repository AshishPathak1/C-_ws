#pragma once
#include <string>
#include <iostream>
class Product
{
private:
	std::string description;
	float price;
public:
	Product();
	Product(std::string p_description);
	Product(float p_price);
	Product(std::string p_description, float p_price);
	void print_details(void);
};

