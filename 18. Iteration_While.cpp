// 18. Iteration_While.cpp : 

#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
void why_loop() {
	std::string name{};
	std::cout << "What's your name ? ";
	std::cin >> name;
	std::cout << "Hello " << name << "\n";
	std::cout << "Hello " << name << "\n";
	std::cout << "Hello " << name << "\n";
	std::cout << "Hello " << name << "\n";
	return;
}

void loop_basic1() {
	std::string name{};
	std::cout << "What's your name ? ";
	std::cin >> name;
	std::cout << "How many time should we greet '" << name << "' ";
	int limit;
	std::cin >> limit;

	int counter{ 1 };
	while (counter <= limit) {
		std::cout << counter << ". Hello " << name << "\n";
		++counter;
	}

	return;
}


/* Any non-zero integral value evaluates to true and only zero evalutes to false*/
void loop_basic2() {
	std::string name{};
	std::cout << "What's your name ? ";
	std::cin >> name;
	std::cout << "How many time should we greet '" << name << "' ";
	int limit;
	std::cin >> limit;
	/*As long as value of variable limit is non zero the expression evaluates to true
	  Moment the value becomes zero the expression evaluates to false*/
	while (limit) {
		std::cout << "Hello " << name << "\n";
		--limit;
	}


	return;
}

// Divide the number by all numbers in the range of (1 to n) and check the number of factors
// complexity 2n+1   ... 2n+2
void check_prime1() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;
	int factor_count{ 0 }; //keeps track of the count of factors
	int divisor{ 1 };

	while (divisor <= number) {
		if (number % divisor == 0) {
			++factor_count;
		}
		++divisor;
	}
	constexpr int expected_number_of_factors{ 2 };
	if (factor_count == expected_number_of_factors ) {
		std::cout << number << " is a Prime Number\n";
	}
	else {
		std::cout << number << " is not a Prime Number\n";
	}

}

// Divide the number by all numbers in the range of 2 to (n-1) and check the number of factors
//complixity : (n-1)+(n-2) : 2n-2
void check_prime2() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;
	int factor_count{ 0 };

	int divisor{ 2 };
	while (divisor < number) {
		if (number % divisor == 0) {
			++factor_count;
		}
		++divisor;
	}

	if (factor_count == 0) {
		std::cout << number << " is a Prime Number\n";
	}
	else {
		std::cout << number << " is not a Prime Number\n";
	}

}

/*
* Divide the number 'n' with all integers in the range of 2 to n/2 and then check the number of factors
*/
/*complixity: (n / 2) + (n / 2) - 1 : n - 1
 */
void check_prime3() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;
	int factor_count{ 0 };
	
	int divisor{ 2 };
	int limit{ number / 2 };

	while (divisor <= limit) {
		if (number % divisor == 0) {
			++factor_count;
		}
		++divisor;
	}

	if (factor_count == 0) {
		std::cout << number << " is a Prime Number\n";
	}
	else {
		std::cout << number << " is not a Prime Number\n";
	}
	return;
}


/*Divide the number by all integers in the range of 2 to sqrt(n)*/
//2(sqrt(n))+2
void check_prime4() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;

	int factor_count{ 0 };

	int divisor{ 2 };
	int limit{ static_cast<int>(sqrt(number)) };

	while (divisor <= limit) {
		if (number % divisor == 0) {
			++factor_count;
		}
		++divisor;
	}

	if (factor_count == 0) {
		std::cout << number << " is a Prime Number\n";
	}
	else {
		std::cout << number << " is not a Prime Number\n";
	}
	return;
}


/*Divide the number by all integers in the range of 2 to sqrt(n)*/
void check_prime5() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;
	
	int divisor{ 2 };
	int limit{ static_cast<int>(std::sqrt(number)) };

	while (divisor <= limit) {
		if (number % divisor == 0) {
			break; // terminate the loop when a factor is found
		}
		++divisor;
	}

	if (divisor <= limit) {
		std::cout << number << " is a NOT Prime Number\n";
	}
	else {
		std::cout << number << " is a Prime Number\n";
	}
	return;
}

/*Divide the number by all integers in the range of 2 to sqrt(n)*/
void check_prime6() {
	std::cout << "Please enter a integer : ";
	int number{};
	std::cin >> number;

	int divisor{ 2 };
	int limit{ static_cast<int>(std::sqrt(number)) };
	if (number != 2) {
		if (number % divisor != 0) {
			divisor = 3;
			while (divisor <= limit) {
				if (number % divisor == 0) {
					break; // terminate the loop when a factor is found
				}
				divisor+=2;
			}
		}
	}
	if (divisor <= limit) {
		std::cout << number << " is a NOT Prime Number\n";
	}
	else {
		std::cout << number << " is a Prime Number\n";
	}
	return;
}

void print_digits1() {
	int number{};
	std::cout << "Please enter a integer : ";
	std::cin >> number;
	int digit{};
	while (number != 0) {
		digit = number % 10;
		std::cout << "Digit is : " << digit << std::endl;
		number = number / 10;
	}
	return;
}


void print_digits2() {
	int number{};
	std::cout << "Please enter a integer : ";
	std::cin >> number;
	if (number == 0) {
		std::cout << "0";
		return;
	}

	std::cout << "digits of " << number << " are as follows : \n";
	int reversedNum{ 0 };
	while (number > 0) {
		int digit = number % 10;
		reversedNum = reversedNum * 10 + digit;
		number /= 10;
	}

	
	while (reversedNum > 0) {
		int digit = reversedNum % 10;
		std::cout << "\t" << digit << '\n';
		reversedNum /= 10;
	}
}

void print(char ch) {
	std::cout << "\t" << ch << "\n";
}

void print_digits3(int number) {
	std::string num_string{ std::to_string(number) };
	std::for_each(num_string.begin(), num_string.end(), print);
}


// 4352  : Do a dry run
void doit() {
	int number{};
	std::cout << "Please enter a integer : ";
	std::cin >> number;
	int x{number};
	int y{};
	int z{};
	while (x != 0) {
		y = x % 10;
		z = (z * 10) + y;
		x = x / 10;
	}
	if (z == number) {
		std::cout << "Hurray!!!\n";
	}
	else {
		std::cout << "Hmmmm!!!\n";
	}
	return;
}

void check_palindrome() {
	int number{};
	std::cout << "Please enter a integer : ";
	std::cin >> number;
	int temp{ number };
	int digit{};
	int reverse{};
	while (temp != 0) {
		digit = temp % 10;
		reverse = (reverse * 10) + digit;
		temp = temp / 10;
	}
	if (reverse == number) {
		std::cout << "Number " << number << " is a Palindrome\n";
	}
	else {
		std::cout << "Number " << number << " is a Not Palindrome\n";
	}
	return;
}

bool isArmstrongNumber(int num) {
	int originalNum{ num };
	int numDigits{ 0 };
	int tempNum{ num };

	while (tempNum > 0) {
		tempNum /= 10;
		numDigits++;
	}

	tempNum = num;
	int sum{ 0 };

	while (tempNum > 0) {
		int digit = tempNum % 10;
		sum = sum + static_cast<int>(std::pow(digit, numDigits));
		tempNum /= 10;
	}

	return (sum == originalNum);
}

bool isArmstrongNumber1(int num) {
	int originalNum{ num };
	int tempNum{ num };

	std::size_t numDigits{ std::to_string(num).length() };
	tempNum = num;
	int sum{ 0 };

	while (tempNum > 0) {
		int digit = tempNum % 10;
		sum = sum + static_cast<int>(std::pow(digit, numDigits));
		tempNum /= 10;
	}

	return (sum == originalNum);
}


void check_is_armstrong() {
	int inputNum;
	std::cout << "Enter an integer to check whether if it's an Armstrong number or not: ";
	std::cin >> inputNum;

	if (isArmstrongNumber1(inputNum)) {
		std::cout << inputNum << " is an Armstrong number.\n";
	}
	else {
		std::cout << inputNum << " is not an Armstrong number.\n";
	}

}


int main()
{
	// why_loop();
	// loop_basic1();
	// loop_basic2();
	// check_prime1();
	// check_prime2();
	// check_prime3();
	// check_prime4();
	// check_prime5();
	// check_prime6();
	// print_digits1();
	// print_digits2();
	int number{ 5678 };
	std::cout << "digits of " << number << " are as follows : \n";
	print_digits3(number);
	//doit();
	//check_palindrome();
	//check_is_armstrong();
	return 0;
}
