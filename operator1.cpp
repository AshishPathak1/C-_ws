// 7. Operators.cpp : 
//

#include <iostream>
#include <vector>
#include <iomanip>

/*

	a + b;
	+ operator
	a & b : operands are variables


	10 / 2;
	- operator
	10 & 2 : operands are literals (constants)

	a * 10;
	* operator
				  ---
	a  : variable     | operands
	10 : literals     |
				  ---

*/

// Unary +, -
void unary_operator1() {
	int i1n{ 40 };
	std::cout << "i1n (Before):" << i1n << std::endl;
	std::cout << "i1n (unary Expression):" << std::showpos << -i1n << std::endl;
	std::cout << "i1n (After):" << i1n << std::endl;
	std::cout << "i1n (unary Expression):" << +i1n << std::endl;
	std::cout << "i1n (After):" << i1n << std::endl;

	int i2n{};
	std::cout << "i2n (Before):" << i2n << std::endl;
	i2n = -i1n;
	std::cout << "i2n (Before):" << i2n << std::endl;
}

// ++ (increment), --(decrement)
void unary_operator2() {
	int a{ 10 };
	int b{ 10 };

	/* Irrespective of whether the application of operator is prefix or postfix,
		++ will always increment the value of the opernd by 1 */
	++a; // prefix ++
	b++; // postfix++
	std::cout << "a : " << a << "\n";
	std::cout << "b : " << b << "\n";
	a = 100;
	b = 100;
	/* irrespective of whether the application of operator is prefix or postfix,
	   -- will always decrement the value of the opernd by 1 */
	--a; // prefix ++
	b--; // postfix++
	std::cout << "a : " << a << "\n";
	std::cout << "b : " << b << "\n";
}

void unary_operator3() {
	int a{ 10 };
	int b{};
	std::cout << "a : " << a << "\tb : " << b << "\n";
	/*When the application of the operator is prefixed; it returns the updated value of the operand*/
	b = ++a;
	std::cout << "a : " << a << "\tb : " << b << "\n";

	a = 10;
	b = 0;
	std::cout << "a : " << a << "\tb : " << b << "\n";
	/*When the application of the operator is postfix; it returns the original value of the operand*/
	b = a++;
	std::cout << "a : " << a << "\tb : " << b << "\n";

	return;
}


void binary_operator() {
	int i1n{ 40 };
	int i2n{ 60 };
	std::cout << "\ni1n (Before):" << i1n << std::endl;
	std::cout << "i2n (Before):" << i2n << std::endl;
	std::cout << "(i1n + i2n ):" << (i1n + i2n) << std::endl;
	std::cout << "i1n (After) :" << i1n << std::endl;
	std::cout << "i2n (After) :" << i2n << std::endl;
}


void arithmetic_operators() {
	int x{ 401 };
	int y{ 100 };
	int z = x + y; // addition
	std::cout << x << " + " << y << " = " << z << '\n';
	z = x - y; // subtraction
	std::cout << x << " - " << y << " = " << z << '\n';
	z = x * y; // multiplication
	std::cout << x << " * " << y << " = " << z << '\n';
	z = x / y; // division (quotient)
	std::cout << x << " / " << y << " = " << z << '\n';
	z = x % y; // modolus (remainder)
	std::cout << x << " % " << y << " = " << z << '\n';

	float f1{ 5.0f };
	float f2{ 2.6F };
	float f3{};
	std::cout << std::showpoint << std::setprecision(3);
	f3 = f1 + f2; // addition
	std::cout << f1 << " + " << f2 << " = " << f3 << '\n';
	f3 = f1 - f2; // subtraction
	std::cout << f1 << " - " << f2 << " = " << f3 << '\n';
	f3 = f1 * f2; // subtraction
	std::cout << f1 << " * " << f2 << " = " << f3 << '\n';
	f3 = f1 / f2; // division
	std::cout << f1 << " / " << f2 << " = " << f3 << '\n';
	//f3 = f1 % f2; // modolus (remainder)

}


void sizeof_operator() {
	int i1n{ 444 };
	std::cout << "size of i1n :" << sizeof(i1n) << " bytes" << std::endl;
	std::cout << "size of 555 :" << sizeof(555) << " bytes" << std::endl;
	std::cout << "size of int :" << sizeof(int) << " bytes" << std::endl;

	char c1{ 'A' };
	std::cout << "size of c1   :" << sizeof(c1) << " bytes" << std::endl;
	std::cout << "size of 'A'  :" << sizeof('A') << " bytes" << std::endl;
	std::cout << "size of char :" << sizeof(char) << " bytes" << std::endl;

	long double d1{ 99999.999L };
	std::cout << "size of d1          :" << sizeof(d1) << " bytes" << std::endl;
	std::cout << "size of 99999.999L  :" << sizeof(99999.999L) << " bytes" << std::endl;
	std::cout << "size of long double :" << sizeof(long double) << " bytes" << std::endl;

	int iarr[10];
	std::cout << "size of int array  : " << sizeof(iarr) << " bytes" << std::endl;
	char carr[10];
	std::cout << "size of char array : " << sizeof(carr) << " bytes" << std::endl;

	std::string s{ "impetus" };
	size_t s1 = s.size(); //function
	std::cout << "size of string : " << s1 << " bytes" << std::endl;
	std::cout << "size of max string : " << s.max_size() << " bytes" << std::endl;
	/*s1 = s.max_size();
	std::cout << "size of max string : " << s1 << " bytes" << std::endl;*/
	size_t string_size = s.max_size();
	std::cout << "size of max string : " << string_size << " bytes" << std::endl;


	std::vector<int> v{ 1,2,3,4,5,6,7 };
	size_t s2 = v.size();  //function
	std::cout << "size of vector : " << s2 << " bytes" << std::endl;

	class X {
		int a[1000];
		double d[1000000];
		float  f[2000000];
	};

	size_t x_size = sizeof(X);
	std::cout << "size of X : " << x_size << " bytes\n";


}

void foo(int);

void assignment_operator() {
	int i1n{ 45 }; //initialization
	std::cout << i1n << "\n";
	i1n = 90; // assignment
	std::cout << i1n << "\n";
	int i2n{};
	int i3n{};
	i3n = i2n = i1n = 55;
	std::cout << i1n << ", " << i2n << ", " << i3n << "\n";
	foo(i1n);
	foo(40);
}

//int var = i1n;

void foo(int var) {
	std::cout << var << "\n";
	return;
}

void covert_distances() {
	//Zero initialization
	unsigned int yards{};
	unsigned int feet{};
	unsigned int inches{};
	// Convert a distance in yards, feet, and inches to inches
	std::cout << "Enter a distance as yards, feet, and inches "
		<< "with the three values separated by spaces: ";
	std::cin >> yards >> feet >> inches;

	constexpr unsigned feet_per_yard{ 3 };
	constexpr unsigned inches_per_foot{ 12 };
	unsigned total_inches{};
	total_inches = inches + inches_per_foot * (yards * feet_per_yard + feet);
	std::cout << "This distance corresponds to " << total_inches << " inches.\n";

	// Convert a distance in inches to yards, feet, and inches
	std::cout << "Enter a distance in inches: ";
	std::cin >> total_inches;

	feet = total_inches / inches_per_foot;
	inches = total_inches % inches_per_foot;
	yards = feet / feet_per_yard;
	feet = feet % feet_per_yard;
	std::cout << "This distance corresponds to "
		<< yards << " yards "
		<< feet << " feet "
		<< inches << " inches." << std::endl;
}

int main()
{
	//unary_operator1();
	//unary_operator2();
	//unary_operator3();
	//binary_operator();
	//arithmetic_operators();
	//sizeof_operator();
	//assignment_operator();
	covert_distances();
	
}
