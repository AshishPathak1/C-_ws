// 24. Auto_any.cpp : 

#include <iostream>
#include <cmath>
#include <typeinfo>
#include <thread>
#include <chrono>
#include <vector>
#include <cctype>
#include <algorithm>
#include <string>
#include <climits>
#include <cinttypes>
#include<iomanip>
//#include <intsafe.h>
#include <array>
#include <any>


void type_name_demo() {

	//Type of Literal (constant)
	std::cout << "Type of 3.14  :" << typeid(3.14).name() << std::endl;
	std::cout << "Type of 3.14F :" << typeid(3.14f).name() << std::endl;

	//Type of the Variable
	int i = 12;
	std::cout << "Type of i     :" << typeid(i).name() << std::endl;

	//Type of Expression
	std::cout << "Type of expression :" << typeid(i * 3.14).name() << std::endl;

}

void initialization_necessary() {
	//int age;
	//std::cout << " Age is " << age << "\n";

	//auto weight; //not possible to create variable using auto without initialization
	auto weight{74.5};
	std::cout << "Type of weight     :" << typeid(weight).name() << std::endl;
	std::cout << "Weight : " << weight << "\n";
	std::cout << "Size of variable weight  : " << sizeof(weight) << " bytes\n";

}

/*
* Using auto ensures that you always use the correct type 
  and that implicit conversion will not occur
*/
void no_implicit_conversion() {
	long long int tel{ 9988776655LL };
	int length = sizeof(tel);	//implicit conversion from size_t to int
	std::cout << "Size of tel : " << length << " bytes\n";
	char ch = 'A';
	int value = ch;  //implicit conversion from char to int
	value = 10000000;
	char ch1 = value;  //implicit conversion from int to char
	int result = 7.0 / 2.0; //implicit conversion from double to int resulting in loss of data
	std::cout << "Result : " << result << '\n';

	std::vector<std::string> friends{ "Aryan","Rushi","Appu","Dhanashree" };
	int number_of_friends = friends.size();		//implicit conversion from size_t to int
	std::cout << "Number of friends : " << number_of_friends << '\n';
	
	auto friend_count = friends.size();
	std::cout << "Number of friends : " << number_of_friends << "\tType : "
		<< typeid(friend_count).name() << '\n';

	std::cout << std::setprecision(15);
	int root1= sqrtl(50) ;	//possible loss of precision; long double converted to double (narrowing)
	std::cout << "Square root1  : " << root1 << '\n';

	auto root2= sqrtl(50);				//NO possibility of loss of precision
	std::cout << "Square root2  : " << root2 << "\t root2 : " << typeid(root2).name() << '\n';

}

/*
It means less typing and less concern for actual types that we don't care about anyway.
*/

void less_typing() {
	std::vector <int> even_nos{ 2, 4, 6, 8, 10, 12 };

	for (size_t i{ 0 }; i < even_nos.size(); ++i) {

	}

	std::cout << "Using iterators :  too much code \n";
	for (std::vector<int>::iterator iter = even_nos.begin(); iter != even_nos.end(); ++iter) {
		std::cout << (*iter) << ',';
	}
	std::cout << '\n';


	std::cout << "Using auto :  less typing \n";
	for (auto iter = even_nos.begin(); iter != even_nos.end(); ++iter) {
		std::cout << (*iter) << ',';
	}
	std::cout << '\n';
	auto iter = even_nos.begin();
	std::cout << "Data type of iter : " << typeid(iter).name();
	std::cout << '\n';
}


/*
* The auto specifier is only a placeholder for the type, 
not for the const/ volatile and references specifiers
*/
void where_we_cannot_use_auto() {
	//The auto specifier is only a placeholder for the type
	auto var1{ "Hahaa" };
	std::cout << "Type of var1  : " << typeid(var1).name() << '\n';

	using namespace std::string_literals;
	auto var2{ "Hahaa"s };
	std::cout << "Type of var2  : " << typeid(var2).name() << '\n';

	std::string name{ "Aparajita" };
	std::string& alias1{ name };  //reference

	std::cout << "Name : " << name << "\tAlias1 : " << alias1 << '\n';
	name = "appu";
	std::cout << "Name : " << name << "\tAlias1 : " << alias1 << '\n';

	std::string surname{ "Patil" };
	auto alias2{ surname };  //copy; auto cannot be used as reference
	std::cout << "Surname Name : " << surname << "\tAlias2 : " << alias2 << '\n';
	surname = "Pandit";
	std::cout << "Surname Name : " << surname << "\tAlias2 : " << alias2 << '\n';

}

/*It is not possible to use auto for multi-word types: like long double or long long int*/
//Visual studio allows
void multi_word_type() {
	auto ivar = int(40);
	std::cout << "ivar : " << ivar << "\ttype : " << typeid(ivar).name() << '\n';

	//auto llvar = long long{ 40 }; //Error under G++
	//std::cout << "llvar : " << llvar << "\ttype : " << typeid(llvar).name() << '\n';

	//auto ldvar = long double{ 40 };
	//std::cout << "llvar : " << ldvar << "\ttype : " << typeid(ldvar).name() << '\n';

	using llong   = long long;
	using ldouble = long double;

	auto llvar1 = llong{ 40 };
	std::cout << "llvar1 : " << llvar1 << "\ttype : " << typeid(llvar1).name() << '\n';

	auto ldvar1 = ldouble{ 40.4 };
	std::cout << "llvar : " << ldvar1 << "\ttype : " << typeid(ldvar1).name() << '\n';
}

//if a trailing return type is used then the leading return type shall 
// be the single type - specifier 'auto' (not 'int')	
// C++11
auto square(int const i) -> int
{
	return  i * i;
}

// C++14
auto cube(int const i)
{
	return i * i * i;
}


void function_return_type() {
	std::cout << "Square of 10 : " << square(10) << '\n';
	std::cout << "Cube of 10   : " << cube(10) << '\n';
	auto result = square(10);
	std::cout << "Type of the result : " << typeid(result).name() << '\n';
}


char convert(const char ch) {
	// return (char)std::toupper(ch);            //c-Style
	return static_cast<char>(std::toupper(ch));  //C++ Style : Explicit Conversion
}

int addit(int n1, int n2) {
	return (n1 + n2);
}

/*To declare named lambda functions, with the form
		auto name = lambda_expression,
unless the lambda needs to be passed or returned to a function 
*/
void auto_with_lambda() {
	
	std::cout << convert('q') << std::endl;

	// Lambda
	auto upper = [](char const ch) {std::cout << static_cast<char>(std::toupper(ch)) << '\n'; };
	std::cout << "Type of upper : " << typeid(upper).name() << std::endl;

	auto data = std::vector<char>{ 'a','b','c','d','e','f','g'};
	std::cout << "Type of data : " << typeid(data).name() << std::endl;
	std::for_each(data.begin(), data.end(), upper);

	auto print = [](auto val) {std::cout << val << ", "; };

	int a[] = { 1,2,3,4,5 };

 	std::cout << "\nInitial Array:\n";
	std::for_each(std::begin(a), std::end(a), print);

	std::vector<float> v{ 1.1F,2.2F,3.3F,4.4F,5.5F };
	std::cout << "\nInitial Vector:\n";
	std::for_each(std::begin(v), std::end(v), print);

	std::vector<std::string> friends{ "Aryan","Rushi","Appu","Dhanashree" };
	std::for_each(friends.begin(),friends.end(), print);
	std::cout << std::endl;
}

void lambda_parameter() {
	//To declare lambda parameters and return values:
	auto add = [](auto const a, auto const b) {return a + b; };

	std::cout << "Addition of integers: " << add(10, 20) << std::endl;
	std::cout << "Addition of double  : " << add(10.5, 20.7) << std::endl;

	using namespace std::literals;
	std::string s1{ "Robin"s };
	std::string s2{ "Singh"s };
	std::cout << "Addition of Strings: " << add(s1, s2) << std::endl;
}

int main()
{
	// type_name_demo();
	// initialization_necessary();
	// no_implicit_conversion();
	// less_typing();
	// where_we_cannot_use_auto();
	// multi_word_type();
	// function_return_type();
	// auto_with_lambda();
	 lambda_parameter();
}
