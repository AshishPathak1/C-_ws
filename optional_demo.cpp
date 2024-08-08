// 29. Optional.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <optional>
#include <string>
#include <iostream>
#include <complex>
using namespace std::literals;

void  optional_creation() {
	/*You can create an optional object not having a value.
	  In that case you have to specify the contained  type */
	std::optional<int> o{};
	std::optional<int> o1;
	/*std::nullopt_t is an empty class type used to indicate optional type with uninitialized state.*/
	std::optional<int> o2{ std::nullopt };
	
	/*  You can pass a value to initialize the contained type.
		Due to a deduction guide you don't have to specify the contained type:*/
	std::optional o3{ 42 }; // deduces optional<int>
	std::optional<std::string> o4{ "hello"s };
	std::optional o5{ "hello" }; // deduces optional<const char*>

  /*  To initialize an optional object with multiple arguments,
	  you have to create the object or add std::in_place as
	  first argument(the contained type can't be deduced) :*/
	std::optional o6{ std::complex{3.0, 4.0} }; //creates temporary objects   
	// avoids the creation of a temporary object
	std::optional<std::complex<double>> o7{ std::in_place, 3.0, 4.0 };

	//You can copy optional objects(including type conversions).
	std::optional o8{ "hello"s }; // deduces optional<std::string>
	std::optional<std::string> o9{ o8 }; // OK

	//make_optional<>(), which allows an initialization with single or multiple 
 //   arguments(without the need for the in_place argument)
	auto o10 = std::make_optional(3.0); // optional<double>
	auto o11 = std::make_optional("hello"); // optional<const char*>
	auto o12 = std::make_optional<std::complex<double>>(3.0, 4.0); //optional<std::complex<double>>

}

void optional_accessing() {
	/*To check, whether an optional object has a value you can use it
	in a Boolean expression or call has_value() :*/
	std::optional o{ 0 }; //optional<int> o(42)
	if (o)  // true
	{
		std::cout << *o << "\n";
	}
	/* Object of type optional in boolean context 
	returns 'true'  if its not empty otherwise returns 'false'*/
	if (!o)  // false
	{
		std::cout << "Empty\n";
	}

	if (o.has_value())  // true
	{
		std::cout << *o << "\n";
	}

	std::optional<std::string> o1{ "hello"s };
	std::cout << *o1 << "\n"; // OK: prints �hello�
	o1 = std::nullopt;
	//std::cout << *o1; // undefined behavior

	//value(), which throws a std::bad_optional_access exception, 
	//	if there is no contained value :
	try {
		std::cout << o1.value() << '\n'; //returns the contained value
	}
	catch (std::bad_optional_access& e) {
		std::cerr << e.what() << '\n';
	}


	//you can ask for the value and pass a fallback value, which is used, 
	 //if the optional object has no value :
	std::cout << o1.value_or("fallback\n"s); // OK (outputs fallback if no value)
	//o1 = "HELLO"s;
	std::cout << o1.value_or("xxxx"); // OK (outputs fallback if no value)
}


void optional_changing_values() {
	using namespace std::complex_literals;
	//Assignment and emplace() operations exist corresponding to the initializations :
	std::optional<std::complex<double>> o; // has no value
	std::optional<int> ox{77}; // optional<int> with value 77

	o = 42; // value becomes complex(42.0, 0.0)
	std::cout << "Complex number is : " << *o << '\n';

	o = { 9.9, 4.4 }; // value becomes complex(9.9, 4.4)
	std::cout << "Complex number is : " << *o << '\n';

	o = ox; // OK, because int converts to complex<double>
	std::cout << "Complex number is : " << *o << '\n';

	o = std::nullopt; // o no longer has a value

	o.emplace(5.5, 7.7); // value becomes complex(5.5, 7.7)
	std::cout << "Complex number is : " << *o << '\n';

	//Assigning std::nullopt removes the value, which calls the destructor 
	//of the contained type if there was a value before.You can have the same 
	//effect by calling reset() :
	o.reset(); // o no longer has a value
	std::cout << "does optional has value now ? " << std::boolalpha << o.has_value() << '\n';

	//or assigning empty curly braces
	o = {};
	std::cout << "does optional has value now ? " << std::boolalpha << o.has_value() << '\n';

}

// convert string to int if possible:
std::optional<int> asInt(const std::string& s) // "56"; "abc"
{
	try {
		return std::stoi(s);
	}
	catch (...) {
		return std::nullopt;
	}
}

/*
* std::optional<> is used so that we can return �no int� and avoid to
define a special int value for it or throw an exception to the caller.
*/
void optional_return_values() {
	for (auto s : { "42", "77", "hello", "3.3" }) {
		// try to convert s to int and print the result if possible:
		auto oi = asInt(s);
		if (oi.has_value()) {
			std::cout << "convert '" << s << "' to int: " << *oi << "\n";
		}
		else {
			std::cout << "can't convert '" << s << "' to int\n";
		}
	}

}
int main()
{
	//optional_creation();
	//optional_accessing();
	//optional_changing_values();
	//optional_return_values();

}
