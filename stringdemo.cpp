// 39. Strngs.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cassert>
#include <stdexcept>
#include <format>
#include <string_view>
#include <algorithm>
#include <xutility>  
#include <cctype>
/*
* Standard series of ASCII characters (a.k.a. C strings) are delimited by double quotes, supporting
escape sequences like \n, \\ and \", and ending in 0-bytes. Such series of ASCII-characters are
commonly known as null-terminated byte strings
*/
void ntbs() {
	
	char str[15] = "IMPETUS";
	std::cout << "Using Array name : " << str << "\n";
	const char* ptr = str;
	std::cout << "Using Pointer : " << ptr << "\n";

	size_t idx = 0;
	//Traditional style
	while (str[idx] != '\0') {
		std::cout << str[idx];
		++idx;
	}
	std::cout << "\n";
	
	// since cpp20
	for (auto const& element : str) {
		std::cout << element << ".";
	}

	std::cout << "\n";
	for (auto& element: str) { 
		std::cout << element << ".";
		element = 'Q';
	}
	
	std::cout << "\n";
	for (idx = 0; auto const& element : str) {
		std::cout << idx++ << ":"<< element << '\n';
	}
	
	return;
}

//Since cpp11
void raw_strings() {

	//The problem
	std::string dir = "F:\fprog\new\tata\bata.txt";
	std::string special_str = "newline\n";

	std::cout << dir << std::endl;
	std::cout << special_str << std::endl;
	std::cout << std::endl;

	//Possible Solutions :	Using \\in strings (escaping of any character \\).
	dir = "F:\\Cprog\\new\\tata\\bata.txt";
	special_str = "newline\\n";

	std::cout << dir << std::endl;
	std::cout << special_str << std::endl;
	std::cout << std::endl;
	/*  \n \t \b \f \v \r \\ */
	/*Using R for raw string:
	From C++11 on - wards, we can write the code more easily and fancy with the help of
	R in - front of the string and parenthesis in the string which treats special characters as literal.
	 Used to avoid escaping of any character. Anything between the delimiters becomes part of the string. 
	*/

	dir = R"(F:\Cprog\new\tata\bata.txt)";
	special_str = R"(newline\n)";

	std::cout << dir << std::endl;
	std::cout << special_str << std::endl;
	std::cout << std::endl;

	/*
	tag is a sequence of up to 16 characters (and an empty tag is both OK and common).
	The characters after ‘“tag(‘ and before the first following occurrence of ‘)tag”’ are
	used literally as the contents of the string literal
	*/

	special_str = R"tag(whatever \n you \t want \r to \f say)tag";
	std::cout << special_str << std::endl;
	std::cout << std::endl;

	std::string pattern = "(? : \"(? : \\\\\" | [^ \"]) * \" | '(?:\\\\' | [^ '])*";
	std::cout << "Regular Expression : " << pattern << std::endl;
	special_str = "\\\\\"";
	std::cout << special_str << std::endl;

	pattern = R"regex((?<=\.) {2,}(?=[A-Z]))regex";
	std::cout << "Regular Expression : " << pattern << std::endl;
	pattern = R"regex(? : "(?:\\" | [^ "])*" | '(?:\\' | [^ '])*')regex";
	std::cout << "Regular Expression : " << pattern << std::endl;

	return;
}

void string_initialization() {
	//An object of type string contains a sequence of characters of type char, which can be empty
	std::string empty;
	std::cout << "Empty String : " << empty << std::endl;

	//You can initialize a string object with a string literal when you define it :
	std::string proverb{ "A bad workman always blames his tools" };
	std::cout << "Proverb : " << proverb << std::endl;

	/*  You can convert a std::string object to a C - style string using two similar methods.
		The first is by	calling its c_str() member function(short for C - string) :
		This conversion results in a C - string of type const char* .Because it’s const,
		this pointer cannot be used to	modify the characters of the string, only to access them.
	*/
	const char* proverb_c_str = proverb.c_str();
	std::cout << "Proverb_c_str : " << proverb_c_str << std::endl;
	//proverb_c_str[0] = 'a'; //Error
	/*
		Your second option is the string’s data() function, which starting from C++17 evaluates
		to a non - const char* pointer1 	
		(prior to C++17, data() resulted in a 	const char* pointer as well) :
	*/
	char* proverb_data = proverb.data();
	std::cout << "Proverb_data : " << proverb_data << std::endl;
	proverb_data[0] = 'a';
	//proverb_data[5] = '\0';
	std::cout << "Proverb_data : " << proverb_data << std::endl;
	std::cout << "Proverb String: " << proverb << std::endl;
	/*
	* You can use an initial sequence from a  string literal, for instance: */
	std::string part_literal{ "Least said soonest mended.", 5 }; // "Least
	std::cout << "part_literal : " << part_literal << std::endl;

	/*you can initialize a string with any 	number of instances of a given character.*/

	std::string sleeping(6, 'z');
	std::cout << "sleeping : " << sleeping << std::endl;

	/*
	use an existing string object to provide the initial value.
	Given that you’ve defined proverb previously, you can define another object based on that:*/
	std::string sentence{ proverb };
	std::cout << "sentence : " << sentence << std::endl;
	/*
	You can use a pair of index values to identify part of an existing string and use that to initialize
	a new string object. */
	std::string phrase{ proverb, 2, 10 }; // Initialize with 13 characters starting at index 2
	std::cout << "phrase : " << phrase << std::endl;

	/*Using std::initializer_list from cpp docs*/
	std::string init_str{ 'T','a','t','a' };
	std::cout << "init_str : " << init_str << std::endl;

	//from cpp docs
	std::vector<char> coll{ 'a','b','c','d','e' };
	std::string from_container{ coll.begin(),coll.end() };
	std::cout << "from_container : " << from_container << std::endl;
	
	char a[10] = { 'a','b','c','d','e','f','g','h','i' ,'j'};
	std::string from_array{ std::begin(a),std::end(a) };
	std::cout << "from_array : " << from_array << std::endl;

}

void string_initialization_with_docs()
{
	{
		// string::string()
		std::string s{};
		assert(s.empty() && (s.length() == 0) && (s.size() == 0));
	}

	{
		// string::string(size_type count, charT ch)
		std::string s(4, '=');
		std::cout << s << '\n'; // "===="
		assert((not s.empty()) && (s.length() == 4) && (s.size() == 4));
	}

	{
		std::string const other("Exemplary");
		// string::string(string const& other, size_type pos, size_type count)
		std::string s(other, 0, other.length());
		std::cout << s << '\n'; // "Exemplary"
	}

	{
		// string::string(charT const* s, size_type count)
		std::string s("C-style string", 7);
		std::cout << s << '\n'; // "C-style"
	}

	{
		// string::string(charT const* s)
		std::string s("C-style\0string");
		std::cout << s << '\n'; // "C-style"
	}

	{
		char mutable_c_str[] = "another C-style string";
		// string::string(InputIt first, InputIt last)
		std::string s(std::begin(mutable_c_str) + 8, std::end(mutable_c_str) - 1);
		std::cout << s << '\n'; // "C-style string"
	}

	{
		std::string const other("Exemplary");
		std::string s(other);
		std::cout << s << '\n'; // "Exemplary"
	}

	{
		// string::string(string&& str)
		std::string s(std::string("C++ by ") + std::string("example"));
		std::cout << s << '\n'; // "C++ by example"
	}

	{
		// string(std::initializer_list<charT> ilist)
		std::string s({ 'C', '-', 's', 't', 'y', 'l', 'e' });
		std::cout << s << '\n'; // "C-style"
	}

	{
		// overload resolution selects string(InputIt first, InputIt last) [with InputIt = int]
		// which behaves as if string(size_type count, charT ch) is called
		std::string s(3, std::toupper('a'));
		std::cout << s << '\n'; // "AAA"
	}
}

int main()
{
	// ntbs();
	
	//raw_strings();
	//string_initialization();
	string_initialization_with_docs();
}