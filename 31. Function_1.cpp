	// 31. Function_1.cpp : Introduction
//

#include <iostream>
#include <optional>
#include <string>
#include <stdexcept>
#include <errno.h>
// Poor design
//int main()
//{
//    int number{};
//    std::cout << "Please enter a integer : ";
//    std::cin >> number;
//    long double facto{ 1 };
//    for (int i{ 1 }; i <= number; ++i) {
//        facto *= i;
//    }
//    std::cout << "Factorial of " << number << " is " << facto << "\n";
//    return 0;
//}

//function Declaration (Prototype)
int get_positive_integer(void);

/*
* Takes a single integer as parameter and returns its factorial
*/
long double  calculate_factorial(int);

/*
Takes two arguments viz the integer and its factorial and prints the same
*/
void print_result(int number, long double factorial);

inline auto square(int number)->long long int {
	return static_cast<long long>(number) * number;
}

// Function Definition
int main() {	
	int number = get_positive_integer();	       // Function Call
	auto factorial = calculate_factorial(number);  // Function Call
	print_result(number, factorial);	           // Function Call
	number = get_positive_integer();
	std::cout << number << " Square + 1  " << " is " << (square(number)+1) << "\n";
	return 0;
}

// Function Definition
int get_positive_integer() {
	int number{};
	do {
		std::cout << "Please enter a integer : ";
		std::cin >> number;
		if (std::cin.fail()) {
			std::cout << "Input format is invalid. Please enter only digits\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<int>::max(),'\n');
			//throw std::invalid_argument("Input format is invalid. Please enter only digits\n");
			//exit(1);
		}
		else {
			if (number < 0) {
				std::cout << "Please enter only positive numbers \n";
			}
			else {
				break;
			}
		}
	} while (true);
	return number;
}

// Function Definition
long double  calculate_factorial(int number) { 
	long double facto{ 1 };
	for (int i{ 2 }; i <= number; ++i) {
		facto *= i;
	}
	return facto;
}


void print_result(int number, long double factorial) {
	std::cout << "Factorial of " << number;
	std::cout << " is " << factorial << "\n";
	return;
}
