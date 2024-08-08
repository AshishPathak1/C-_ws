// 35. Function_5_constexpr.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

constexpr int sqr(int n)
{
    return n * n;
}


//since C++20
consteval int cube(int n)
{
	return n * n * n;
}



constexpr auto add(int a, int b)->long long int {
    return static_cast<long long int>(a) + b;
}

constexpr void foo(int x) {  // Error, return type should not be void.
    ++x;
    return;
}

void f(int n)
{
    int f1 = sqr(5);    // MAY be evaluated at compile time

    int f2 = sqr(n);    // evaluated at run time (n is a variable)

	constexpr int f3{ sqr(6) }; // MUST be evaluated at compile time

//  constexpr int a;        // constexpr variables must be initialized
//  constexpr int a = n;    // constexpr variables must be initialized using constant

//	constexpr int f4{ sqr(n) }; // error : can't guarantee compile-time evaluation (n is a variable)
	[[maybe_unused]] //Suppresses warnings on unused entities.
    char a1[sqr(4)]; // OK: array bounds must be constants and sqr() is constexpr

//  char a2[sqr(n)]; // error : array bounds must be constants and n is a variable

}


// C++11 constexpr functions use recursion rather than iteration
constexpr int factorial(int n)
{
    return n <= 1 ? 1 : (n * factorial(n - 1));
}

// C++14 constexpr functions may use local variables and loops
constexpr int calc_factorial(int n) {
	int f = 1;
	for (int i = 2; i <= n; ++i) {
		f = f * i;
	}
	return f;
}

//Does not get evaluated at compile time
const int array_size1(int x) {
    return x + 1;
}

//may get evaluated at compile time
constexpr int array_size2(int x) {
    return x + 1;
}

void constant_variable_demo();
void constexpr_function_demo1();
void constexpr_function_branching();
void const_eval_demo();

int main()
{
	//constant_variable_demo();
	//
 //   f(4);

 //   constexpr int result = factorial(4)+10;
 //   std::cout << result; 
	//constexpr int f = calc_factorial(4) + 10;
	//std::cout << f;

 //   constexpr int a{ 4 };
 //   int b{ 5 };
 //   std::cout << (b + 6); //Runtime
	//std::cout << (a + 6); // compile time

	//constexpr_function_demo1();
	//constexpr_function_branching();
    
	const_eval_demo();

    return EXIT_SUCCESS;
}



void constant_variable_demo()
{
	constexpr int a{ 10 };
	std::cout << "a:" << a << std::endl;
	//you cannot assign to a variable that is const
	// a = 20;  
	std::cout << "Value of a:" << a << "\tAddress of a : " << &a << std::endl;

	const int b{ 10 };
	std::cout << "b:" << b << std::endl;
	//you cannot assign to a variable that is const
	//b = 20;
	
	/*const int c;
	c = 8;
	std::cout << "c:" << c << std::endl;*/
}

void constexpr_function_demo1() {
	[[maybe_unused]] //Suppresses warnings on unused entities.C++17
	int a[10];  //literal : constant used to specify the size of array

	int size1{4};
	std::cin >> size1;
	//expression did not evaluate to a constant
	//int array1[size1]; //Error 

	const int size2{ 10 };

	[[maybe_unused]]
	int array2[size2]; //Ok

	constexpr int size3{ 10 };
	[[maybe_unused]]
	int array3[size3]; //Ok

	/*expression did not evaluate to a constant
	* Array size has to be specified at Compile time; whereas the functions get executed at Runtime
	*  Error, constant expression required in array declaration
	*/
	//int array4[array_size1(4)];

	//Will get evaluated at compile time since the argument is constant
    // should be usable in a constant expression when given constant
	//	expressions as arguments
	int array5[array_size2(9)];
	std::cout << "Array5 size : " << sizeof(array5) << " Bytes\n";

	//int array6[array_size2(size5)]; //Erorr
	//	Bcoz the argument to constexpr is ont const

	int size5{ 9 };
	//Will get evaluated at runtime since the argument is non-constant

	// OK, constexpr functions can be evaluated at compile time
   // and used in contexts that require constant expressions.
	std::cout << array_size2(size5);
	return;
}

/*
A branch of a conditional expression that is not taken in a constexpr
function is not evaluated.
This implies that a branch not taken can require run-time evaluation.
*/
constexpr int check(int i)
{
	constexpr int low{ 10 };
	constexpr int high{ 21 };
	//return (low <= i && i < high) ? (i+10) : throw std::out_of_range("value is out of range\n");
	
	if(low <= i && i < high){
		return i+10; //can return value at compile time
	}else{
		throw std::out_of_range("value is out of range\n"); //cannot throw exception at compile time
	}
	
}

void constexpr_function_branching() {
	constexpr int n1{ 15 };
	constexpr int n2{ 25 };
	
	try {
		//Call will get executed at and return value at  compile time
		std::cout << "Calling Check with n1 : " << check(n1) << "\n";
		//Call will get executed at runtime time
		std::cout << "Calling Check with n2 : " << check(n2) << "\n";
	}
	catch (std::out_of_range& err) {
		std::cerr << err.what();
	}

	//using check function in constant expression
	constexpr int n3{ check(n1) }; //compile time evaluation
	//using check function in constant expression
	//constexpr int n4{ check(n2) }; //runtime evaluation
	//int n5{ check(n2) }; //expression evaluates and fails at runtime
}


void const_eval_demo() {
	constexpr int n1{ 10 };
	int n2{ 20 };
	//Evaluates at compile time since the argument is constant
	std::cout << sqr(n1) << std::endl; //compile time
	//Fails to evaluate at compile time but gets evaluated at runtime 
	//since the argument is non-constant
	std::cout << sqr(n2) << std::endl; //runtime only

	constexpr int r1 = sqr(n1); //compile time
	//constexpr int r2 = sqr(n2); //runtime only

	std::cout << cube(n1) << std::endl; //compile time
	//Fails to evaluate at compile time since the argument is non-constant
	//std::cout << cube(n2) << std::endl; //runtime only
	//consteval functions cannot be evaluated at runtime
}