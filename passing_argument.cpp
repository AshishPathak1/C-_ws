// 36. Function_passing_arguments.cpp : 
// Passing arguments during Function Calls
#include <iostream>
#include <cmath>



long double factorial(int value);
int get_integer(std::string msg);
void call_by_value1();
void call_by_value2();
void swap1(int, int);

void call_reference_need();
float get_float(std::string msg);
int maximum(float);
int minimum(float f);


void call_by_reference1();
void maxmin(float, int*, int*);


void call_by_reference2();
void swap2(int* const, int* const);

class Widget {};
/*discuss this after exploring value categories*/
void pass_by_rvalue(Widget&& w) { // parameter is rvalue reference
}

using namespace std::literals;

int main()
{
	//call_by_value1();
	//call_by_value2();
	//call_reference_need();
	//call_by_reference1();
	//call_by_reference2();

	
	pass_by_rvalue(Widget{}); // rvalue as function argument
	Widget x; //lvalue
	//pass_by_rvalue(x); //rvalue reference cannot bind to lvalue
	pass_by_rvalue(std::move(x)); //enables moving of resources of argument x to function parameter w

}

void call_by_value1()
{
	int number = get_integer("Please enter a ingeter : "s);
	auto facto = factorial(number);
	std::cout << "Factorial of " << number << " is " << facto << '\n';
	std::cout << "Factorial of " << 5 << " is " << factorial(5) << '\n';
	std::cout << "Factorial of " << 5 + number << " is " << factorial(5 + number) << '\n';
}

/* takes no argument and retruns a integer */
int get_integer(std::string msg) {
	int number{};
	do {
		std::cout << msg;
		std::cin >> number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cerr << "The input was incorrect!\n";
		}
		else {
			return number;
		}

	} while (true);
}


long double factorial(int number) {
	long double f{ 1 };
	while (number != 1) {
		f *= number;
		--number;
	}

	return f;
}

void swap1(int in1, int in2) {
	int itemp{};
	itemp = in1;
	in1 = in2;
	in2 = itemp;
	std::cout << "(in called routine - swap) in1 : " << in1 << "\tin2 : " << in2 << '\n';
	return;

}

void call_by_value2()
{
	int in1{ 10 };
	int in2{ 20 };
	std::cout << "(Before : in calling routine) in1 : " << in1 << "\tin2 : " << in2 << '\n';
	swap1(in1, in2);
	std::cout << "(After  : in calling routine) in1 : " << in1 << "\tin2 : " << in2 << '\n';
}

/*function couldnt return more than one value*/
void call_reference_need() {
	float f = get_float("Enter a floating point value : "s);
	std::cout << "The Largest integer not greater than " << f << " is " << maximum(f) << '\n';
	std::cout << "The Minimum integer not smaller than " << f << " is " << minimum(f) << '\n';

}

/* takes no argument and retruns a integer */
float get_float(std::string msg) {
	float number{};
	do {
		std::cout << msg;
		std::cin >> number;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(), '\n');
			std::cerr << "The input was incorrect!\n";
		}
		else {
			return number;
		}

	} while (true);
}

int maximum(float f) {
	return static_cast<int>(f);
}


int minimum(float f) {
	int n = static_cast<int>(f);
	if (n < f) {
		return n + 1;
	}
	return n;
}

void call_by_reference1() {
	int max{122};
	int min{3};
	float f = get_float("Enter a floating point value : "s);
	maxmin(f, &max, &min);
	std::cout << "The Largest integer not greater than " << f << " is " << max << '\n';
	std::cout << "The Minimum integer not smaller than " << f << " is " << min<< '\n';
}

void maxmin(float f, int* p_max, int* p_min)
{
	/*std::cout << "Address : " << p_max << "\tValue : " << *p_max << '\n';
	std::cout << "Address : " << p_min << "\tValue : " << *p_min << '\n';*/
	*p_max = std::floor(f);
	*p_min = std::ceil(f);
}

void swap2(int* const ptr1, int * const ptr2) {
	int itemp{};
	itemp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = itemp;
	//ptr2++;
	std::cout << "(in called routine - swap2) in1 : " << *ptr1 << "\tin2 : " << *ptr2 << '\n';
	return;
}

void call_by_reference2() {
	int in1{ 10 };
	int in2{ 20 };
	std::cout << "(Before : in calling routine) in1 : " << in1 << "\tin2 : " << in2 << '\n';
	swap2(&in1, &in2);
	std::cout << "(After  : in calling routine) in1 : " << in1 << "\tin2 : " << in2 << '\n';
}


