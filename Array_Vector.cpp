// 26. Array_Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <type_traits>
#include <array>
#include <string>

using namespace std::string_literals;

void print(auto val) {
	std::cout << val << ", ";
}

void array_initialization() {
	//case1 : /*For fundamental types, the initial value might be undefined rather than zero*/
	{
		std::array<int, 4> my_array; // OOPS: elements of x have undefined value
		for (auto element : my_array) {
			std::cout << element << ' ';
		}
		std::cout << std::endl;
	}

	//case 2
	/*You can provide an empty initializer list instead. In that case,
	all values are guaranteed to be value initialized, which has the effect that elements
	of fundamental types are zero initialized:*/
	{
		std::array<int, 4> my_array{}; // OK: all elements of x have value 0 (int()
		for (auto element : my_array) {
			std::cout << element << ' ';
		}
		std::cout << std::endl;
	}

	/*case3: you can use an initializer list to initialize an array when it got created.
	* The elements in the initializer list must have the same type, or there must be a
	  type conversion to the element type of the array defined*/
	{
		std::array<int, 4> my_array{ 42, 377, 611, 21 };
		for (auto element : my_array) {
			std::cout << element << ' ';
		}
		std::cout << std::endl;
	}

	/*case4: If an initializer list does not have enough elements,
	the elements in the array are initialized via the default constructor of the element type.
	In this case, it is guaranteed that for fundamental data types the elements are zero initialized.*/
	{
		std::array<int, 4> my_array { 42 };
		for (auto element : my_array) {
			std::cout << element << ' ';
		}
		std::cout << std::endl;
	}

	/*Case5 : If the number of elements in the initializer lists is higher than the size of the array,
	the expression is 	ill - formed:*/
	{
	//		std::array<int, 5> c3 { 1, 2, 3, 4, 5, 6, 7 }; // ERROR: too many values
	}

	//Case 6
	//C++17 onwards : support type deduction
	{
		std::array<int, 4> marks{  };	//before C++17
		std::array percentages{ 67.8, 77.9, 88.6, 55.0 }; //since C++17
		for (auto element : percentages) {
			std::cout << element << ' ';
		}
		std::cout << std::endl;

		//Fails to automatically deduce the type
		//std::array weight{ 45.6, 66.7, 70, 56.7f }; //Error: all elements have ot be of same type

		using namespace std::string_literals;
		// fails since "string" is not convertible to int
		//std::array<int, 4> weight1{ 45.6, 66.7, 70, "56"s };
		
		// fails since "const char*" is not convertible to int
		//std::array<int, 4> weight2{ 45.6, 66.7, 70, "56" };

		//success since float and double are convertible to int
		std::array<int, 4> weight{ 45.6, 66.7, 70, 56.7f }; //ok; but possible loss of data
	}

	{
		std::cout << std::boolalpha;
		std::cout << "double to int ? " << std::is_convertible_v<double, int> << '\n';
		std::cout << "int to double ? " << std::is_convertible_v<int, double> << '\n';
		std::cout << "int to string ? " << std::is_convertible_v<int, std::string> << '\n';
	}

}

void array_iteration() {
	/*Case: 1
	 likely signed/unsigned mismatch in this code! Due to a curious decision,
	 the size() function and array index parameter to operator[] use a type called size_type
	*/
	{
		std::array myArray{ 7, 3, 1, 9, 5 };

		// Iterate through the array and print the value of the elements
		for (int i{ 0 }; i < myArray.size(); ++i) { //warning '<': signed/unsigned mismatch
			std::cout << myArray[i] << ' ';
		}
		std::cout << '\n';

	}

	/*Case 2:
	// std::array<int, 5>::size_type is the return type of size()

	*/
	{
		std::array myArray{ 7, 3, 1, 9, 5 };

		for (std::array<int, 5>::size_type i{ 0 }; i < myArray.size(); ++i) {
			std::cout << myArray[i] << ' ';
		}

		std::cout << '\n';
		//std::array::size_type is just an alias for std::size_t
		for (std::size_t i{ 0 }; i < myArray.size(); ++i) {
			std::cout << myArray[i] << ' ';
		}


	}

}

void array_operations_access() {
	// accessing element

	std::array marks{ 66,77,88,99 };

	//using index of operator []
	std::cout << "1st subject : " << marks[0] << '\n';
	std::cout << "4th subject : " << marks[3] << '\n';

	//using method at()
	std::cout << "1st subject : " << marks.at(0) << '\n';
	std::cout << "4th subject : " << marks.at(3) << '\n';

	//incorrect subscript result in undefined behaviour but no error
	/*std::cout << "last subject : " << marks[4] << '\n';
	std::cout << "first subject : " << marks[-1] << '\n';*/

	//any attempt made to access the elements beyond bounds generates exception 'std::out_of_range'
	try {
		std::cout << "4th subject : " << marks.at(4) << '\n';
		std::cout << "1st subject : " << marks.at(-1) << '\n';
	}
	catch (std::out_of_range err) {
		std::cerr << "Error : Accessing elements beyond bound!\n";
	}

}

void array_fill() {
	std::array marks{ 66,77,88,99 };
	for (auto mark : marks) {
		std::cout << mark << ' ';
	}
	std::cout << std::endl;
	/*fill the container with specified value*/
	marks.fill(80);
	for (auto mark : marks) {
		std::cout << mark << ' ';
	}
	std::cout << std::endl;
}

void array_swap() {
	std::array luckynos{ 3,13,31,39 };
	std::array unluckynos{ 10,20,30,40};
	std::cout << "Lucky Numbers : \n";
	for (auto number : luckynos) {
		std::cout << number << ' ';
	}
	std::cout << std::endl;
	std::cout << "UnLucky Numbers : \n";
	for (auto number : unluckynos) {
		std::cout << number << ' ';
	}
	std::cout << std::endl;

	/*swaps the contents*/
	luckynos.swap(unluckynos); //using method()

	std::cout << "After swapping\n";
	std::cout << "Lucky Numbers : \n";
	for (auto number : luckynos) {
		std::cout << number << ' ';
	}
	std::cout << std::endl;
	std::cout << "UnLucky Numbers : \n";
	for (auto number : unluckynos) {
		std::cout << number << ' ';
	}
	std::cout << std::endl;

	std::cout << "After swapping once again\n";
	std::swap(luckynos, unluckynos);   //using standard library function
	std::cout << "Lucky Numbers : \n";
	for (auto number : luckynos) {
		std::cout << number << ' ';
	}
	std::cout << std::endl;
	std::cout << "UnLucky Numbers : \n";
	for (auto number : unluckynos) {
		std::cout << number << ' ';
	}
	std::cout << std::endl;
}


void print_array(auto  a) {
	for (auto element: a) {
		std::cout << element << '\n'; // *(ptr+idx)
	}
	std::cout << std::endl;
}

void print_array(const int* ptr, size_t size) {
	for (size_t idx{}; idx < size; ++idx) {
		std::cout << ptr[idx] << '\n'; // *(ptr+idx)
	}
	std::cout << std::endl;
}


void array_access_data() {

	int a[]{ 12, 45, 67, 89 };
	std::cout << "Passing C style array with size\n";
	print_array(a,std::size(a));

	std::array even_nos{ 2,4,6,8,10 };

	std::cout << "Passing std::array with size\n";
	/* data() : Returns pointer to the underlying array serving as element storage*/
	print_array(even_nos.data(), even_nos.size());

	std::cout << "Passing std::array without specifying size\n";
	print_array(even_nos); // problem of decay does not occur
}

void create_array() {
	// C-style array
	char vowels[]{ 'a','e','i','o','u' }; //character array

	auto my_vowels = std::to_array(vowels);
	std::cout << "Type of my_vowels : " << typeid(my_vowels).name() << "\n";
	for (auto vowel : my_vowels) {
		std::cout << vowel << ", ";
	}
	std::cout << '\n';

	double values[]{ 34.0,56.7,66.7,44.5 };

	auto my_values = std::to_array(values);
	std::cout << "Type of my_values : " << typeid(my_values).name() << "\n";
	for (auto value : values) {
		std::cout << value << ", ";
	}
	std::cout << '\n';

	char v[] = "AEIOU";	// C-string : character array terminated with '\0'
	auto my_array = std::to_array(v);
	std::cout << "Type of my_array : " << typeid(my_array).name() << "\n";
	for (auto value : my_array) {
		std::cout << value << ", ";
	}
	std::cout << '\n';

}

int main()
{
	// array_initialization();

	//array_iteration();

	//array_operations_access();

	//array_fill();

	//array_swap();

	//array_access_data();

	create_array();
}
