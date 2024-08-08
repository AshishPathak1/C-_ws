// 2.Variables_Data_types.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <limits>
#include <cstdlib>
#include <cstddef> //needed for std::byte

void valid_identifiers(void) {
	//Identifier should be meaningful
	int m;      // poor 
	int age;    // Good

	//First letter of an identifier must be alphabetic character or a underscore or Dollor
	//int 1unit;  // Error
	int unit1;  //OK
	int _unit1; //ok
	int $unit1; //ok

	//Embedded spaces are not allowed.
	//int product rate; //Error
	int product_rate;
	int productRate; //Lower camel case

	//Must be composed of alphabetic characters, or digits or underscores or $.
	//int interest%;
	//int interest-rate;
	//int domain@in;
	//[A-Z][a-z][0-9]$
	int $rate;
	int product_1;

	//Identifier should not be same as that of any keyword
	/*int asm;
	int case;*/

	int case_no;

	//Cpp  is case sensitive
	int limit{ 3 };
	int Limit{ 4 };
	int LIMIT{ 5 };

	return;
}

/*Function returning nothing and not requiring any parameter*/
void void_type(void) {

	//void var; //It is an incomplete type; type with an empty set of values.

	int age{};
	int* ptr_i = &age;

	//Generic pointer
	void* ptr;
	ptr = &age;

	char grade{};
	ptr = &grade;

	float per{};
	ptr = &per;

	//ptr_i = &per;

	void (*fp)(void) = valid_identifiers;
	fp();
	return;
}



void foo(int* p) {
	std::cout << "foo(int*)\n";
}

void foo(double* p) {
	std::cout << "foo(double*)\n";
}

void foo(std::nullptr_t p) {
	std::cout << "foo(nullptr_t)\n";
}

void foo(char* p) {
	std::cout << "foo(char*)\n";
}

/*
* nullptr_t:
*   size : equal to size of native pointer
*   introducted in C11
*   it is not a pointer
*   it's value is null pointer ( nullptr )
*
*/
void null_ptr_type_demo() {
	//Dangling pointers
	int* ptr_i;
	char* ptr_c;
	//std::cout << "ptr_i : " << *ptr_i << "\tptr_c : " << *ptr_c << std::endl;
	float* ptr_f = NULL; //poor
	int dummy = NULL;  // implicit converion of NULL to integer 0
	//int sunny = nullptr; //no implicit conversion
	double* ptr_d = nullptr; //Good ;  nullptr is a literal of type std::nullptr_t
	std::nullptr_t nothing{};
	std::cout << "Size of nullptr_t type variable " << sizeof(nothing) << " bytes\n";
	int* ptr_ii = nothing;

	int a{ 10 };
	ptr_i = &a;
	foo(ptr_i);

	double d{ 0.0 };
	ptr_d = &d;
	foo(ptr_d);

	//foo(0);
	//foo(NULL);

	foo(nullptr);

	ptr_c = nullptr;
	foo(ptr_c);


	// nulptr is comparable
	int* p = NULL;
	if (p == NULL) {  }
	if (p == 0) {}

	p = 0;
	if (p == 0) { }

	a = NULL;
	if (a == NULL) {}
	if (a == 0) {}

	p = nullptr;
	if (p == nullptr) {}
	a = 0;
	//if ( a == nullptr) {} //illegal since integers cannot be compared with pointer type

	//null_ptr  can be converted to bool type
//	bool b1 = nullptr; //direct initialization not allowed
	bool b2{ nullptr }; //copy initialization allowed

	// data type of NULL is not same as data type of nullptr
	std::cout << std::boolalpha << std::is_same<decltype(NULL), std::nullptr_t>::value << ' ';

}

/*true/false are the only two types of values of type boolean*/
void bool_demo() {
	bool is_eligible_for_voting{};
	std::cout << "Is Eligible ? " << is_eligible_for_voting << "\n";
	std::cout << "Is Eligible ? " << std::boolalpha << is_eligible_for_voting << "\n";
	int age{ 25 };
	is_eligible_for_voting = (age >= 18);
	std::cout << "Is Eligible ? " << std::boolalpha << is_eligible_for_voting << "\n";
	is_eligible_for_voting = true;
	std::cout << "Is Eligible ? " << std::boolalpha << is_eligible_for_voting << "\n";

	std::cout << std::boolalpha;
	std::cout << "Is Eligible ? " << is_eligible_for_voting << "\n";
	is_eligible_for_voting = false;
	std::cout << "Is Eligible ? " << is_eligible_for_voting << "\n";

	std::cout << "Size of false   : " << sizeof(bool) << " bytes" << std::endl;
	std::cout << "Size of true    : " << sizeof(true) << " bytes" << std::endl;
	std::cout << "Size of Boolean : " << sizeof(is_eligible_for_voting) << " bytes" << std::endl;
	std::cout << "Size of 1 : " << sizeof(1) << " bytes" << std::endl;
	std::cout << "Size of 0 : " << sizeof(0) << " bytes" << std::endl;

	std::cout << std::noboolalpha;
	is_eligible_for_voting = true;
	std::cout << "Is Eligible ? " << is_eligible_for_voting << "\n";
	is_eligible_for_voting = false;
	std::cout << "Is Eligible ? " << is_eligible_for_voting << "\n";

	return;
}

/*The std::numeric_limits provides a standardized way to query various properties of arithmetic types*/
void numeric_limits_demo() {
	std::cout << "\nInteger Type (int):\n";
	std::cout << "\tMax    : " << std::numeric_limits<int>::max() << std::endl;
	std::cout << "\tMin    : " << std::numeric_limits<int>::min() << std::endl;
	std::cout << "\tLowest : " << std::numeric_limits<int>::lowest() << std::endl;

	std::cout << "Integer Type (unsigned int):\n";
	std::cout << "\tMax    : " << std::numeric_limits<unsigned int>::max() << std::endl;
	std::cout << "\tMin    : " << std::numeric_limits<unsigned int>::min() << std::endl;
	std::cout << "\tLowest : " << std::numeric_limits<unsigned int>::lowest() << std::endl;

	std::cout << "Integer Type (long int):\n";
	std::cout << "\tMax    : " << std::numeric_limits<long int>::max() << std::endl;
	std::cout << "\tMin    : " << std::numeric_limits<long int>::min() << std::endl;
	std::cout << "\tLowest : " << std::numeric_limits<long int>::lowest() << std::endl;

	std::cout << "Integer Type (short int):\n";
	std::cout << "\tMax    : " << std::numeric_limits<short int>::max() << std::endl;
	std::cout << "\tMin    : " << std::numeric_limits<short int>::min() << std::endl;
	std::cout << "\tLowest : " << std::numeric_limits<short int>::lowest() << std::endl;

	std::cout << "Integer Type (unsigned  short int):\n";
	std::cout << "\tMax    : " << std::numeric_limits<unsigned short int>::max() << std::endl;


	std::cout << "Integer Type (long long int):\n";
	std::cout << "\tMax    : " << std::numeric_limits<long long int>::max() << std::endl;
	std::cout << "\tMin    : " << std::numeric_limits<long long int>::min() << std::endl;
	std::cout << "\tLowest : " << std::numeric_limits<long long int>::lowest() << std::endl;

	std::cout << "Integer Type (unsigned long long int):\n";
	std::cout << "\tMax    : " << std::numeric_limits<unsigned long long int>::max() << std::endl;


	std::cout << "Floating Type (float):\n";
	std::cout << "\tMax    : " << std::numeric_limits<float>::max() << std::endl;
	std::cout << "\tMin    : " << std::numeric_limits<float>::min() << std::endl;
	std::cout << "\tLowest : " << std::numeric_limits<float>::lowest() << std::endl;

	std::cout << "Floating Type (double):\n";
	std::cout << "\tMax    : " << std::numeric_limits<double>::max() << std::endl;
	std::cout << "\tMin    : " << std::numeric_limits<double>::min() << std::endl;
	std::cout << "\tLowest : " << std::numeric_limits<double>::lowest() << std::endl;

	std::cout << std::boolalpha;
	std::cout << "Is int signed by default : " << std::numeric_limits<int>::is_signed << std::endl;
	std::cout << "Is unsigned int signed by default : " << std::numeric_limits<unsigned int>::is_signed << std::endl;
}

// needs cstddef header
void byte_demo() {
	std::byte abyte{ 0b101 };  //can be initialized with binary literals
	//std::cout << abyte;
	std::cout << std::to_integer<int>(abyte) << "\n";
	std::byte anotherbyte{ 55 };  //can be initialized with int literals
	std::cout << std::to_integer<int>(anotherbyte) << "\n";

	std::byte result;
	/*Byte does not support arithmetic */
	//result = abyte + anotherbyte;

	//Supports only bitwise operations ~, <<, >> &, |   
	result = ~abyte;     // 0b00000101
						 // 0b11111010 
	std::cout << std::to_integer<int>(result) << "\n";
	result = abyte << 1;
	std::cout << std::to_integer<int>(result) << "\n";

}

int main()
{
	/*valid_identifiers();
	void_type();
	null_ptr_type_demo();
	bool_demo();
	numeric_limits_demo();*/
	byte_demo();
	return EXIT_SUCCESS;
}
