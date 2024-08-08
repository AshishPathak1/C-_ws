#pragma once
#include <iostream>
class X {
	int data;
public:
	X() {
		std::cout << "Default Ctor\n";
	}

	X(const X& ref ) {
		std::cout << "Copy Ctor\n";
	}

	X(const X&& ref) {
		std::cout << "Move Ctor\n";
	}

	X& operator = (const X& ref) {
		std::cout << "Overloaded operator =()\n";
		return *this;
	}

	X(int p_data)  {
		std::cout << "X(int) \n";
	}

	X(double) = delete;
	X(float)  = delete;
	X(char)   = delete;
};


/*Explicit ctor are used to prevent implicit type conversion:
 Explicit conversion are allowed
*/
class Y {
	int data;
public:
	//converting ctor
	//Y(int p_data) { //parameterized ctor
	//	data = p_data;
	//}

	//it cannot be used for implicit conversions and copy-initialization.
	explicit Y(int p_data) { 
		data = p_data;
	}

	
};

void foo(Y y) {
	std::cout << "Foo is called\n";
}
