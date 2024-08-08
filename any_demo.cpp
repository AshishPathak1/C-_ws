// 28. any_demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <complex>
#include <string>
#include <utility>
#include <any>  //since C++17
using namespace std::literals;

void any_basics() {
	std::cout << std::boolalpha;

	std::any a; // a is empty
	//function type() : returns the type of the contained value; Queries the contained type.
	std::cout << "type of data in empty any object(a) : " << a.type().name() << "\n";
	a = 42; // a has value 42 of type int
	std::cout << "type of data in any object(a) : " << a.type().name() << "\n";
	a = true;
	std::cout << "type of data in any object(a) : " << a.type().name() << "\n";

	std::any b = 4.3; // b has value 4.3 of type double
	std::cout << "type of data in any object(b) initialized by 4.3 : " << b.type().name() << "\n";
	b = std::string{ "hi" }; // b has value "hi" of type std::string
	std::cout << "type of data in any object(b) assigned value 'hi' : " << b.type().name() << "\n";

	if (b.type() == typeid(std::string)) {
		std::string s = std::any_cast<std::string>(b);//Performs type-safe access to the contained object.
		std::cout << "Original String : " << s << '\n';
	}

	a = 100;
	std::cout << "Integer stored in a : " << std::any_cast<int>(a) << '\n';

	/*If the cast fails, because the object is empty or the contained type doesn't fit,
	  a std::bad_any_cast is thrown*/
	try {
		std::cout << std::any_cast<std::string>(a) << '\n';
	}
	catch (const std::bad_any_cast& e) {
		std::cout << e.what() << '\n';
	}

	a = 100;
	//checks if object holds a value
	std::cout << "std::any object a holds value ? : " << a.has_value() << '\n';
	
	//destroys contained object not the any object
	a.reset();
	std::cout << "std::any object a holds value ? : " << a.has_value() << '\n';
	
	a = 200;
	std::cout << "std::any object a holds value ? : " << a.has_value() << '\n';
	//empty std::any object
	a = std::any{};
	std::cout << "std::any object a holds value ? : " << a.has_value() << '\n';

}

void using_any() {
	std::vector<std::any> v; //effectively heterogenous vector
	
	v.push_back(42);
	std::string s = "hello"s;
	v.push_back(s);
	v.push_back(5.6);

	for (const auto& a : v) {
		if (a.type() == typeid(std::string)) {
			std::cout << "string: " << std::any_cast<const std::string>(a) << '\n';
		}
		else if (a.type() == typeid(int)) {
			std::cout << "int: " << std::any_cast<int>(a) << '\n';
		}else if (a.type() == typeid(double)) {
			std::cout << "double: " << std::any_cast<double>(a) << '\n';
		}
	}

}

void holding_values() {
	std::any a1{ 42 };
	std::cout << "type of data in any object(a1) : " << a1.type().name() << "\n";

	std::any a2{ "Hello" };
	std::cout << "type of data in any object(a2) : " << a2.type().name() << "\n";

	//To hold a different type than the type of the initial value, you have to use the in_place_type tags
	//used to specify type of the object to be constructed.
	std::any a3{ std::in_place_type<float>, 42 };
	std::cout << "type of data in any object(a3) : " << a3.type().name() << "\n";

	std::any a4{ std::in_place_type<std::string>, "hello" };
	std::cout << "type of data in any object(a4) : " << a4.type().name() << "\n";

	/*Constructs an any object containing an object of type T,*/
	auto a5 = std::make_any<long double>(3.0L);
	std::cout << "type of data in any object(a5) : " << a5.type().name() << "\n";

	auto a6 = std::make_any<std::string>("hello");
	std::cout << "type of data in any object(a6) : " << a6.type().name() << "\n";

	auto a7 = std::make_any<std::complex<double>>(3.0, 4.0);
	std::cout << "type of data in any object(a7) : " << a7.type().name() << "\n";
}

/*
* When you want to change the currently stored value in std::any then you have 
  two options: use emplace or the assignment
*/
void emplace_demo() {
	std::any a{};
	std::cout << "type of data in any object : " << a.type().name() << "\n";

	a = std::complex<float>(10.0f, 11.0F);
	std::cout << "type of data in any object : " << a.type().name() << "\n";

	a = "Hello"s;
	std::cout << "type of data in any object : " << a.type().name() << "\n";
	
	a.emplace<float>(100.5f);
	std::cout << "type of data in any object : " << a.type().name() << "\n";

	a.emplace<std::vector<int>>({ 10, 11, 12, 13 });
	std::cout << "type of data in any object : " << a.type().name() << "\n";

	a.emplace <std::complex<double>>( 1.0, 1.1);
	std::cout << "type of data in any object : " << a.type().name() << "\n";
}

/*
* The crucial part of being safe for std::any is not to leak any resources. 
  To achieve this behaviour std::any will destroy any active object before 
  assigning a new value.
*/
void object_lifetime() {
	struct MyType {
		MyType() { std::cout << "MyType Object Created\n"; } //Ctor
		~MyType() { std::cout << "MyType Object Destroyed\n"; } //Dtor

	};
	///MyType m;
	std::any var = std::make_any<MyType>();
	
	var = 100.5f;
	
	std::cout << "data = " << std::any_cast<float>(var) << '\n';

}

int main()
{
	//any_basics();
	// using_any();
	//holding_values();
	//emplace_demo();
	object_lifetime(); 

}
