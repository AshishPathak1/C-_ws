#include <iostream>
#include <stdexcept>
#include <limits>

//function Declaration (Prototype)
int get_integer(void);

long long int addition(int num1, int num2);

// Function Definition
int main() {
	int number1 = get_integer();	       // Function Call
	int number2 = get_integer();
	auto sum = addition(number1, number2);  // Function Call
	std::cout << number1 << " + " << number2 << " = " << sum << std::endl;
	return 0;
}

/* This function accepts an integer from user and returns the same*/
int get_integer(void) {
	int number{};
	do {
		std::cout << "Please enter a integer : ";
		std::cin >> number;
		if (std::cin.fail()) {
			std::cout << "Input format is invalid. Please enter only digits\n";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		else {
			break;
		}

	} while (true);
	return number;
}

/*Takes two integers as arguments and return their addition as long long int value*/
long long int addition(int num1, int num2) {
	return static_cast<long long int>(num1) + num2;
}