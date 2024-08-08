// 40. String_view.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// string_view_demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <string_view>
#include <algorithm>
#include <xutility>
#include <cassert>
#include <fstream>
#include <random>
#include <chrono>
#include <sstream>
#include <vector>
#include <cassert>
using namespace std::literals;

void* operator new(std::size_t count) {
	std::cout << "   " << count << " bytes" << std::endl;
	return malloc(count);
}

/*
* Creating a std::string& parameter from a char* argument requires the argument to be copied, 
just as if we were passing it by value.
*/
void print_string(const std::string str) { // const std::string& str
	std::cout << "The String is : " << str << '\n';
}

void print_string_sv(std::string_view str) { 
	std::cout << "The String is : " << str << '\n';
}

void why_string_view() {
	print_string("Learn Traditional C++::const char *"); //const char *
	print_string("Learn Modern C++::string "s);
	print_string_sv("Learn Modern C++::string_view"sv); //string_view literal

}


void receive_string(std::string_view input) {
	std::cout << "Received : " << input << '\n';
}

void creating_string_view(){
	receive_string("This was a C-style string"); // const char * (ntbs)
	receive_string("This was a std::string"s);   // std::string literal :allocated memory on heap
	receive_string("This was a std::string_view"sv);  // std::string_view literal
}

//bool compare(const std::string& s1, const std::string& s2)
//{
//	if (s1 == s2)
//		return true;
//	std::cout << '\"' << s1 << "\" does not match \"" << s2 << "\"\n";
//	return false;
//}

//void string_compare() {
//	std::string str{ "this is the first String"s };
//
//	compare(str, "this is the first test string");
//	compare(str, "this is the second test string"s);
//	//compare(str, "this is the third test string"sv); //type mismatch
//}

bool compare(std::string_view s1, std::string_view s2) 
{
	if (s1 == s2)
		return true;
	std::cout << '\"' << s1 << "\" does not match \"" << s2 << "\"\n";
	return false;
}


void string_view_literal_compare() {
	std::string_view str_v{ "this is the first String"sv };

	compare(str_v, "this is the first test string");		// string_view object and const char * literal
	compare(str_v, "this is the second test string"s);		// string_view object and std::string literal
	compare(str_v, "this is the third test string"sv);	// string_view object and std::string_view literal
}

void string_basic() {
	{
		char text[15]{ "I love C++" }; //stack
		std::string str;
		std::cout << "Size of str : "<< sizeof(str) << std::endl;
		std::cin >> str;
		std::string str1{ text };
		std::string str2{ str1 };
		std::cout << "Text : " << text << "\tAddress : " << reinterpret_cast<unsigned int>(text) << std::endl;
		std::cout << "str1 : " << str1 << "\tAddress : " << reinterpret_cast<unsigned int>(str1.data()) << std::endl;
		std::cout << "str2 : " << str2 << "\tAddress : " << reinterpret_cast<unsigned int>(str2.data()) << std::endl;
	}
	{
		char text[15]{ "I love C++" }; //stack
		/*Unlike std::string, which keeps its own copy of the string,
		std::string_view provides a view of a string that is defined elsewhere.*/
		std::string_view sv1{ "I am fascinated with C++" };
		/*The string "I am fascinated with C++" is stored in the binary and is not allocated at run-time*/
		std::string_view sv2{ sv1 };
		std::cout << "sv1 : " << sv1 << std::endl;
		std::cout << "sv2 : " << sv2 << std::endl;
		std::cout << "sv1  : " << sv1 << "\tAddress : " << reinterpret_cast<unsigned int>(sv1.data()) << std::endl;
		std::cout << "sv2  : " << sv2 << "\tAddress : " << reinterpret_cast<unsigned int>(sv2.data()) << std::endl;
		std::string_view sv3{ text };
		std::cout << "Text : " << text << "\tAddress : " << reinterpret_cast<unsigned int>(text) << std::endl;
		std::cout << "sv3  : " << sv3 << "\tAddress : " << reinterpret_cast<unsigned int>(sv3.data()) << std::endl;

	}
	{
		/*Because std::string_view doesn't create a copy of the string,
		* if we change the viewed string, the changes are reflected in the std::string_view.*/
		char arr[]{ "Gold" };
		std::string_view sv{ arr };
		std::cout << "Earlier: " << sv << '\n'; // Gold

		// Change 'd' to 'f' in arr
		arr[3] = 'f';
		std::cout << "Later  : " << sv << '\n'; // Golf
	}
}

void remove_demo() {
	std::string str{ "C++ Language" };
	std::cout << "Original String : " << str << "\n";
	std::string_view sv{ str  };

	std::cout << sv << '\n';

	// Ignore the first character.
	sv.remove_prefix(1);

	std::cout << sv << '\n';

	// Ignore the last 2 characters.
	sv.remove_suffix(2);

	std::cout << sv << '\n';

	std::cout << "Original String : " << str << "\n";
	return;

}

void string_view_without_ntbs() {
	char vowel[]{ "aeiou" }; //ntbs : length 6
	// No null-terminator.
	char vowels[]{ 'a', 'e', 'i', 'o', 'u' }; // not ntbs : : length 5

	
	// vowels isn't null-terminated. We need to pass the length manually.
	// Because vowels is an array, we can use std::size to get its length.
	std::string_view str_v{ vowels, std::size(vowels)};

	std::cout << "vowels : " << str_v << '\n'; // This is safe. std::cout knows how to print std::string_views.

	char special_symbols[] {'!','@','#','$','%','^','&','*','(',')','+','~'};
	std::string_view str_v1{ special_symbols, 5};
	std::cout << "Special symbols first 5 : " << str_v1 << std::endl;

	std::string_view str_v2{ special_symbols+5, 5 };
	std::cout << "Special symbols later 5 : " << str_v2 << std::endl;
}


/*
* Ownership issues
Being only a view, a std::string_view�s lifetime is independent of that of the string it is viewing.
If the viewed string goes out of scope, std::string_view has nothing to observe and accessing it
causes undefined behavior. The string that a std::string_view is viewing has to have been created
somewhere else.
It might be a string literal that lives as long as the program does or it was created by a std::string,
in which case the string lives until the std::string decides to destroy it or the std::string dies.
std::string_view can�t create any strings on its own, because it�s just a view.
*/
std::string_view askForName()
{
	// Use a std::string, because std::cin needs to modify it.
	std::string str{};
	std::cout << "What's your name? : ";
	std::getline(std::cin, str);

	// We're switching to std::string_view for demonstrative purposes only.
	// If you already have a std::string, there's no reason to switch to
	// a std::string_view.
	std::string_view view{ str };

	std::cout << "Hello " << view << '\n';
	/*str = str + "**********";
	std::cout << "Hello " << view << '\n';*/


	return view;
} // str dies, and so does the string that str held.

/*
* Modifying a std::string can cause its internal string to die and be replaced with a new one
  in a different place. The std::string_view will still look at where the old string was, but it's not there anymore.
*/

void string_view_ownership_issue() {
	std::string_view view{ askForName() };

	// view is observing a string that already died.
	std::cout << "Your name is " << view << '\n'; // Undefined behavior
}

void string_view_conversion() {
	std::string_view sv{ "balloon"sv };

	sv.remove_suffix(3);

	std::cout << sv; // compile error : won't implicitly convert 

	std::string str{ sv }; // okay :: implicitly

	std::cout << str << std::endl; // okay

	std::cout << (static_cast<std::string>(sv)) << std::endl; // okay : Explicitly

	  // Get the null-terminated C-style string.
	const char* szNullTerminated{ str.c_str() };

	// Pass the null-terminated string to the function that we want to use.
	std::cout << str << " has " << std::strlen(szNullTerminated) << " letter(s)\n";

	// We use std::strlen because it's simple, this could be any other function
	// that needs a null-terminated string.
	// It's okay to use data() because we haven't modified the view, and the
	// string is null-terminated.
	std::cout << sv << " has " << std::strlen(sv.data()) << " letter(s)\n";
}


void getString(const std::string& str) {}

/*Constructing an std::string object could be expensive because it usually (but not always) requires
dynamic memory allocation. Where the cost of constructing an std::string object is a concern,
the readability and ease of usage are frequently compromised by using const char* and length parameters:*/
void small_string_optimization() { //sso
	std::cout << std::endl;

	std::cout << "std::string" << std::endl;

	std::string small = "0123456789";
	std::string substr = small.substr(5);
	std::cout << "   " << substr << std::endl;

	std::cout << std::endl;

	std::cout << "getString" << std::endl;

	getString(small);

	//Implicit Conversion of " const char * " to std::string
	getString("0123456789"); //const char * : C-style String => ntbs

	char message[] = "0123456789";
	//Implicit Conversion of  " char * " to std::string
	getString(message);

	std::cout << std::endl;
}


void getStringView(std::string_view strView) {}

/*
* the strings stores its data on the heap. But that is only true if the string exceeds 
* an implementation-dependent size. This size for std::string is 15 for MSVC and GCC and 23 for Clang.
*/
void big_string_optimization() {
	std::cout << std::endl;

	std::cout << "std::string" << std::endl;

	std::string large = "0123456789-123456789-123456789-123456789";
	std::string substr = large.substr(10); // starting from index 10 till the end of the string

	std::cout << std::endl;

	std::cout << "std::string_view" << std::endl;

	std::string_view largeStringView{ large.c_str(), large.size() };
	largeStringView.remove_prefix(10);

	assert (substr == largeStringView);

	std::cout << std::endl;

	std::cout << "getString" << std::endl;

	getString(large);
	getString("0123456789-123456789-123456789-123456789");
	const char message[] = "0123456789-123456789-123456789-123456789";
	getString(message);

	std::cout << std::endl;

	std::cout << "getStringView" << std::endl;

	getStringView(large);
	getStringView("0123456789-123456789-123456789-123456789");
	getStringView(message);

	std::cout << std::endl;
}

// string_view
// Unified way to view a string (memory and length) - without owning it 
//No allocation
std::size_t parse(std::string_view str_view) {
	return std::count(str_view.begin(), str_view.end(), 'e');
}

void string_view_demo() {
	const std::string str = "hello world";
	const char* c = "Rio de Janeiro";

	std::cout << "Occurrences of letter 'e': " << parse(std::string_view(str.data(), str.length())) << std::endl;
	std::cout << "Occurrences of letter 'e': " << parse(std::string_view(c, strlen(c))) << std::endl;
	std::cout << "Occurrences of letter 'e': " << parse(str) << std::endl;
	std::cout << "Occurrences of letter 'e': " << parse(c) << std::endl;
}


void check_performance()
{
	const int count = 30;
	const int access = 5000000;
	std::cout << std::endl;

	std::ifstream inFile(R"(d:\stories.txt)");

	std::stringstream strStream;
	strStream << inFile.rdbuf();
	std::string storyTales = strStream.str();

	size_t size = storyTales.size();

	std::cout << "Story'  Tales size: " << size << std::endl;
	std::cout << std::endl;

	// random values
	std::random_device seed;
	std::mt19937 engine(seed());
	std::uniform_int_distribution<> uniformDist(0, size - count - 2);
	std::vector<int> randValues;
	for (auto i = 0; i < access; ++i) {
		randValues.push_back(uniformDist(engine));
	}

	auto start = std::chrono::steady_clock::now();
	for (auto i = 0; i < access; ++i) {
		storyTales.substr(randValues[i], count);
	}
	std::chrono::duration<double> durString = std::chrono::steady_clock::now() - start;
	std::cout << "std::string::substr:      " << durString.count() << " seconds" << std::endl;

	std::string_view storyTalesView{ storyTales.c_str(), size };
	start = std::chrono::steady_clock::now();
	for (auto i = 0; i < access; ++i) {
		storyTalesView.substr(randValues[i], count);
	}
	std::chrono::duration<double> durStringView = std::chrono::steady_clock::now() - start;
	std::cout << "std::string_view::substr: " << durStringView.count() << " seconds" << std::endl;

	std::cout << std::endl;

	std::cout << "durString.count()/durStringView.count(): " << durString.count() / durStringView.count() << std::endl;

	std::cout << std::endl;
}

int main()
{
	//why_string_view();
	//creating_string_view();
	//string_compare();
	// string_view_literal_compare();
	//string_basic();
	
	//remove_demo();
	//string_view_without_ntbs();
	//string_view_ownership_issue();
	//string_view_conversion();
	//small_string_optimization();
	//big_string_optimization();
	//string_view_demo();
	check_performance();

	return EXIT_SUCCESS;
}
