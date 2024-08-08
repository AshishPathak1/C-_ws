#include "Person.h"
#include <string>
#include <iostream>
using namespace std::literals;

Person::Person() :blood_group("ab+")
{
	name = "Not_yet_known"s;
	//Body of ctor performs assignment and not initialization
	// const variables have to be initialized
	//blood_group = "unknown";
	phone_no = 0;

}

Person::Person(std::string p_name, std::string p_blood_group, size_t p_phone_no):
	name(p_name),blood_group(p_blood_group),phone_no(p_phone_no)
{
	/*name = p_name;
	blood_group = p_blood_group;
	phone_no = p_phone_no;*/
}

Person::~Person()
{
	std::cout << name << " object is destroyed\n";
	name.clear();
	phone_no = 0;

}

void Person::print_details()
{
	std::cout << "Name : " << name << '\n';
	std::cout << "Blood Group  : " << blood_group << '\n';
	std::cout << "Phone number : " << phone_no << '\n';
		
}
