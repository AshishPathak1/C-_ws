// smart_pointer2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <xutility>
#include <functional>
/*We get opportunity to pocess the data present in the array before the array is destroyed*/
void my_deleter(int* p) {
	std::cout << "function deleting the array\n";
	delete[] p;
}

void with_custom_deleter_primitive_type() {
	//Shared pointer holding array of integer with default deleter
	std::shared_ptr<int[]> ptr1{ new int[5] };

	//Shared pointer holding array of integer with custom deleter function
	std::shared_ptr<int[]> ptr2{ new int[5], my_deleter };

	//Shared pointer holding array of integer with custom lambda
	std::shared_ptr<int[]> ptr3{ new int[5],
				[](int* p) {std::cout << "lambda deleting the array\n"; delete[] p; }};
}

class X {
	std::string name;
public:
	X(std::string _name = "Harry") {
		name = _name;
		std::cout << "X Object " << name << " is  constructed\n";
	}

	~X() {
		std::cout << "X Object " << name << " is  destroyed\n";
	}
};

void x_deleter(X* p) {
	std::cout << "X deleter is in action\n";
	delete[]p;
}

//Callable object class declaration
class XDeleter {
public:
	void operator()(X*p) const {
		std::cout << "Functor object deleting the resource\n";
		delete[] p;
	}
};

void with_custom_deleter_class_type() {
	//Shared pointer holding array of X class objects with default deleter
	std::shared_ptr<X[]> ptr1{ new X[5] };
	std::cout << std::endl;
	
	//Shared pointer holding array of X with custom deleter function
	std::shared_ptr<X[]> ptr2{ new X[5], x_deleter };
	std::cout << std::endl;

	//Shared pointer holding array of X with custom deleter of type std::function
	std::function<void(X*)> fun_deleter = x_deleter;

	std::shared_ptr<X[]> ptr3{ new X[5], fun_deleter };
	std::cout << std::endl;

	//Shared pointer holding array of X with custom deleter lambda
	std::shared_ptr<X[]> ptr4{ new X[5],
		[](auto* p) {std::cout << "\nLambda deleter in action\n"; delete[]p; } };
	std::cout << std::endl;

	//Shared pointer holding array of X with custom deleter XDeleter (functors)
	std::shared_ptr<X[]> ptr5{ new X[5], XDeleter()}; //callable object
	std::cout << std::endl;
}


int main()
{
	//with_custom_deleter_primitive_type();
	 with_custom_deleter_class_type();
}
