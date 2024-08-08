// Constants.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <math.h>
#include <iomanip>
#include <thread>
#include <chrono>
void constant_basics();
void constant_use_case1();
void constant_use_case2();
void const_constexpr_diff();
void constexpr_define_diff();
void bar();

int main()
{
	//constant_basics();

	//constant_use_case1();
	//constant_use_case2();
	//const_constexpr_diff();
	//constexpr_define_diff();
	//constant_demo1();
	//constant_demo2();
	//constant_demo3();
	constant_demo4();
	//std::this_thread::sleep_for(std::chrono::seconds(4));
	return EXIT_SUCCESS;
}

void constant_basics() {

	const int ci1 = 2;
	std::cout << "ci1 : " << ci1 << std::endl;
	//ci1 = 33;		//error
	//const int ci3; // Error: no value
	//ci3 = 55;
	const float pi = 3.14159f;
	std::cout << "pi  : " << pi << std::endl;
	const char cc = 'a';
	std::cout << "cc  : " << cc << std::endl;
	const bool cmp = ci1 < pi;
	std::cout << "cmp : " << cmp << std::endl;
	int a = 10;
	int b;
	std::cout << "Enter two integers ";
	std::cin >> a >> b;
	const bool flag = a < b;

	std::cout << "flag :" << flag << std::endl;


	//A constexpr variable accepts only compile - time values
	constexpr short scale = 4;
	//constexpr short int scale = 4;
	std::cout << "scale : " << scale << std::endl;
	constexpr bool is_signed = true;
	std::cout << "is_signed : " << is_signed << std::endl;

	std::cout << "is_signed : "
		<< std::boolalpha << is_signed << std::endl;

	std::cout << "is_signed : " << std::boolalpha << is_signed << std::endl;

	constexpr int max = 8 * 1024; //compile time constant
	std::cout << "max : " << max << std::endl;
	constexpr int min = 10;
	constexpr bool flag1 = min < max;

	//constexpr int product = a * b; //the initializer has to be evaluated at compile time
	const int product = a * b; //runtime constant
	std::cout << "product : " << product << std::endl;
	//product = 34;
	//constexpr int product1 = (a * b); //Error
}

void constant_use_case1() {
	int age;
	std::cout << "What's your age (years) ? ";
	std::cin >> age;
	if (age >= 18) {
		std::cout << "You are eligible to vote!" << std::endl;
	}
	else {
		std::cout << "You are not eligible to vote!" << std::endl;
	}

	//Avoid �magic constants�; use symbolic constants
	constexpr int MIN_AGE_YEAR_FOR_VOTING = 18;
	std::cout << "What's your age (years) ? ";
	std::cin >> age;
	if (age >= MIN_AGE_YEAR_FOR_VOTING) {
		std::cout << "You are eligible to vote!" << std::endl;
	}
	else {
		std::cout << "You are not eligible to vote!" << std::endl;
	}

}


void constant_use_case2() {
	std::cout << "What's the rate of the product(Rs) :";
	float price;
	std::cin >> price;
	std::cout << "How many such products have you purchased ? :";
	float qty_purchased;
	std::cin >> qty_purchased;
	//Avoid �magic constants�; use symbolic constants
	float bill_amount = (price * qty_purchased * 0.05F);
	bill_amount = bill_amount - (bill_amount * 0.02f);

	std::cout << "The bill amount payable is Rs :" << bill_amount << std::endl;

	constexpr float DISCOUNT_RATE = 0.05f;
	constexpr float LOYALTY_DISCOUNT_RATE = 0.02f;

	bill_amount = (price * qty_purchased) * DISCOUNT_RATE;
	bill_amount = bill_amount - (bill_amount * LOYALTY_DISCOUNT_RATE);

	std::cout << "The bill amount payable is Rs :" << bill_amount << std::endl;
}

void const_constexpr_diff() {
	const double      C_PI = 3.142;
	constexpr double CE_PI = 3.142;
	std::cout << "Value of const     PI : " << C_PI << std::endl;
	std::cout << "Value of constexpr PI : " << CE_PI << std::endl;

	const double     C_PI_2 = C_PI / 2;   // evaluates at runtime
	constexpr double CE_PI_2 = CE_PI / 2;   // evaluation happens at compile time
	std::cout << "Value of const     PI/2 : " << C_PI_2 << std::endl;
	std::cout << "Value of constexpr PI/2 : " << CE_PI_2 << std::endl;

	const double     C_PI_4 = CE_PI / 4;
	std::cout << "Value of const     PI/4 : " << C_PI_4 << std::endl;

	constexpr double CE_PI_4 = C_PI / 4;
	const double x = CE_PI;
}



void constexpr_define_diff() {
	constexpr int max = 77;
#define MIN 2
	constexpr int max1 = MIN;
	std::cout << "max = " << max << std::endl;
	std::cout << "MIN = " << MIN << std::endl;

}

void bar() {
	//std::cout << "max = " << max << std::endl; //undefined
	std::cout << "MIN = " << MIN << std::endl;
}


void constant_demo1() {
	char const ch1{ 'A' };  //const T is same as T const
	const char ch2{ 'B' };
	char ch3{ 'C' };

	//declares a non-constant pointer pointing to const
	const char* cptr;

	cptr = &ch1;
	std::cout << *cptr;
	// *cptr = 'X';
	cptr++;
	--cptr;
	cptr = &ch2;
	cptr = &ch3;
	// *cptr = 'c';
	ch3 = 'c';
}


void constant_demo2() {
	char ch1{ 'A' };
	char ch2{ 'B' };
	
	//non-constant pointer pointing to non-constant
	char* cptr;

	/*Address stored in the pointer can be changed*/
	cptr = &ch1;
	cptr++;
	cptr = &ch2;
	/*the value of the vaiable to which it is pointing to can also be changed*/
	*cptr = 'Q';
}

void constant_demo3() {
	char ch1{ 'A' };
	char ch2{ 'B' };
	const char ch3{ 'C' };

	/*constant pointer pointing to non-constant*/
	char* const cptr{ &ch1 };

	/*address stored in the constant pointer cannot be changed*/
	//cptr = &ch2;

	/*The value of the variable that it is pointing to can be changed*/
	*cptr = 'Q';

	/*char* const cptr1{ &ch3 };
	*cptr1 = 'R';*/
}

void constant_demo4() {
	const char ch1{ 'A' };
	char ch2{ 'B' };

	/*constant pointer pointing to constant*/
	const char* const cptr1{ &ch1 };
	const char* const cptr2{ &ch2 };

	/*Address stored in constant pointer cannot be changed*/
	//cptr1++;
	/*Value of the variable pointed to by pointer to constant cannot be changed*/
	//*cptr1 = 'S';
}