// 39. Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Strings.cpp : This file contains the 'main' function. Program execution begins and ends there.

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
#include <array>
#include "39. Strngs.h"
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
	for (auto& element : str) {
		std::cout << element << ".";
		element = 'Q';
	}

	std::cout << "\n";
	for (idx = 0; auto const& element : str) {
		std::cout << idx++ << ":" << element << '\n';
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

	char a[10] = { 'a','b','c','d','e','f','g','h','i' ,'j' };
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

using namespace std::literals;
void string_assignment() {
	char cstring1[10] = "Hello";
	char cstring2[10] = "Bye";
	//cstring2 = cstring1; //Cannot assing one S-style string to another C-Style String
	std::string adjective{ "hornswoggling" }; // Defines adjective
	std::string word{ "rubbish" }; // Defines word
	std::cout << "adjective :" << adjective << "\tword : " << word << std::endl;
	word = adjective; //  assign one string object to another
	adjective = "twotiming"; // const char * : assign 'C' style strig constant to string object
	std::cout << "adjective :" << adjective << "\tword : " << word << std::endl;
	word = "C++ string literal"s; //String literal being asigned to string object
	std::cout << "word : " << word << std::endl;

}

void string_concatenation() {
	std::string first; // Stores the first name
	std::string second; // Stores the second name
	std::cout << "Enter your first name: ";
	std::cin >> first; // Read first name
	std::cout << "Enter your second name: ";
	std::cin >> second; // Read second name
	std::string sentence{ "Your full name is " }; // Create basic sentence
	sentence += first + " " + second + "."; // Augment with names 
	std::cout << sentence << std::endl; // Output the sentence
	std::cout << "The string contains " // Output its length
		<< sentence.length() << " characters." << std::endl;
	sentence = "Hi there!"s + " how are you?"s; // Concatenating C++ string literals
	std::cout << sentence;
	//sentence = "Hi there!" + " how are you?"; // Concatenating two C string literals (const char*) is error
	sentence = "Hi there!"s + " how are you?"; //OK: cancatenation of C++ String lietral with C-String literal
}

/*Fails to read string containing whitespace characters
operator >> could extract single word; supress the whitespace character that appear before the input*/
void reading_string_problem() {
	std::string name;
	std::string city;

	std::cout << "Please enter your name: ";
	std::cin >> name;
	std::cout << "Enter the city you live in: ";
	std::cin >> city;
	//	std::cout << "has reading failed ? " << std::boolalpha << std::cin.fail() << '\n';
	std::cout << "Hello, " << name << std::endl;
	std::cout << "You live in " << city << std::endl;

	return;
}

/*Accept strings containing embedded spaces until carriage return is not encountered
getline() extracting single line*/
void reading_string_solution() {
	std::string name;
	std::string city;

	std::cout << "Please enter your name: ";
	std::getline(std::cin, name); //getline(source_stream, destination)
	std::cout << "Enter the city you live in: ";
	std::getline(std::cin, city);

	std::cout << "Hello, " << name << std::endl;
	std::cout << "You live in " << city << std::endl;
	return;

}

/*Extracting multiple lines*/
void read_multiple_lines() {
	std::string address{};
	std::cout << "Please enter your address :";
	//getline(std::cin, address,'\n');  //Default delimiter
	std::getline(std::cin, address, '.');
	std::cout << "Address :" << address << std::endl;
}


void read_strings_using_method() {
	/*Read String containing embedded white space character until \n is not encountered*/
	{
		std::array<char, 100> address{}; //C++ style array
		std::cout << "Please enter your address :";
		std::cin.getline(&address[0], address.size());
		std::cout << "Address :" << address.data() << std::endl;
	}

	/*Read String containing embedded white space character until '.' is not encountered*/
	{
		std::array<char, 100> address{};
		std::cout << "Please enter your address :";
		std::cin.getline(&address[0], address.size(), '.');
		std::cout << "Address :" << address.data() << std::endl;
	}

	/*Read String containing embedded white space character until '.' is not encountered*/
	{
		char address[100]; //C-Style array
		std::cout << "Please enter your address :";
		std::cin.getline(address, sizeof(address), '.');
		std::cout << "Address :" << address << std::endl;
	}
}

void read_character() {
	{
		std::cout << "Enter your Employee Id : ";
		int empid;
		std::cin >> empid;
		std::cout << "Your ID is :" << empid << std::endl;

		//To clear the input stream
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//	std::cout << "Max Limit : " << std::numeric_limits<std::streamsize>::max() << std::endl;

		std::cout << "Enter your Grade (A/B/C/D) :";
		char grade;
		std::cin >> grade;
		std::cout << "Your grade is : " << grade << std::endl;

		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Enter your Department Code (X/Y/Z) :";
		char dept_code;
		std::cin >> dept_code;
		std::cout << "Your Department code is : " << dept_code << std::endl;
	}
}


void read_using_get() {
	//read a single character; doesn't suppress white space character
	{
		std::cout << "Enter your Grade (A/B/C/D) :";
		char grade;
		std::cin.get(grade);
		std::cout << "Your grade is : " << grade << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//read a string; doesn't suppress white space character
	{
		std::cout << "Enter your Name :";
		std::array<char,100> name;
		std::cin.get(name.data(), name.size());
		std::cout << "Your name is : " << name.data() << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//read a string; doesn't suppress white space character
	{
		std::cout << "Enter your Address :";
		std::array<char, 100> address;
		std::cin.get(address.data(), address.size());
		std::cout << "Your address is : " << address.data() << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	//read a string; doesn't suppress white space character
	{
		std::cout << "Enter your Degree :";
		char degree[100];
		std::cin.get(degree, sizeof(degree));
		std::cout << "Your degree is : " << degree << std::endl;
	}

	//read a string; multi line string
 //   default delimiter(\n) changed to '.'
	{
		std::cout << "Enter your Address :";
		std::array<char, 100> address;
		std::cin.get(address.data(), address.size(),'.'); //Defaul
		std::cout << "Your address is : " << address.data() << std::endl;
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}


void problem_read_data() {
	int roll_no;
	std::cout << "Enter roll Number : ";
	std::cin >> roll_no;
	std::cout << "Enter Percentage Marks : ";
	float per;
	std::cin >> per;
	std::cout << "Roll No :" << roll_no << "\tPercentage :" << per << std::endl;
}

void problem_read_data_solved() {
	std::string data{};
	try {
		std::cout << "Enter roll Number : ";
		std::getline(std::cin, data);
		//converts string ot integer
		//int roll_no = std::stoi(data); //default is decimal
		int roll_no = std::stoi(data,nullptr,10); //decimal
		//int roll_no = std::stoi(data,nullptr,16); // data string has hex value
		// int roll_no = std::stoi(data, nullptr, 8);   // if the input string is octal

		std::cout << "Enter Percentage Marks : ";
		std::getline(std::cin, data);

		//converts string to float
		float per = std::stof(data);
		std::cout << "Roll No :" << roll_no << "\tPercentage :" << per << std::endl;
	}
	catch (std::invalid_argument& e) {
		std::cout << e.what() + ": Please enter only digits"s  << std::endl;
	}
	{
		std::cout << "Enter a Number : ";
		std::getline(std::cin, data);
		size_t count{};
		int roll_no = std::stoi(data, &count, 10); //decimal
		std::cout << "Processed : " << count << " digits\n";
		std::cout << "Value : " << roll_no << std::endl;
	}


}

using namespace std::literals;

void diff_string_types()
{
	//g++
	std::u8string word{ u8"Ород" };
	std::cout << "Number of characters in Russian string (Ород): " << word.length() << std::endl;
	std::cout << "size is " << sizeof(word) << " bytes\n";

	//std::cout << u8"\n字符串";
	std::u8string quote{ u8"GOD" };// char8_t characters
	std::cout << "Number of characters in Latin string (GOD): " << quote.length() << std::endl;;

	//Devnagari
	std::u16string question{ u"अबकड" }; // char16_t characters
	std::cout << "Number of characters in Devnagari  string (अबकड): " << question.length() << std::endl;
	std::cout << "size is " << sizeof(question) << " bytes\n";

	std::u32string sentence{ U"字符串" }; // char32_t characters
	std::cout << "Number of characters in Chinees string (字符串): " << sentence.length() << std::endl;;
	std::cout << "size is " << sizeof(sentence) << " bytes\n";
}

//Replaces the contents of the string with the values in the range
void assign_range_demo() {
	std::array<char, 10> source{ 'a','b','c','d','e','f','g','h','i','j'};
	std::string destination;
	destination.assign_range(source);
	std::cout << "Destination String : " << destination << std::endl;
}

void string_capacity() {
	std::string s1{};
	std::cout << std::boolalpha;
	//checks whether the string is empty
	std::cout << "Is String empty ? " << s1.empty() <<std::endl;
	s1 = "Test"s;
	std::cout << "Is String empty ? " << s1.empty() << std::endl;
	
	//returns the number of characters
	std::cout << "Size of the String   : " << s1.size() << " Characters" << std::endl;
	std::cout << "Length of the String : " << s1.length() << " Characters" << std::endl;

	//returns the number of characters that can be held in currently allocated storage
	std::cout << "Capacity of the String   : " << s1.capacity() << " Characters" << std::endl;
	s1 = "abcdefghijklmnopqrst";
	std::cout << "Capacity of the String   : " << s1.capacity() << " Characters" << std::endl;
	std::cout << "Length of the String     : " << s1.length() << " Characters" << std::endl;
	
	//reduces memory usage by freeing unused memory
	//It is a non-binding request to reduce capacity() to size()
	s1.shrink_to_fit(); // compiler dependent behaviour (check G++) 
	std::cout << "Capacity of the String after shrinking  : " << s1.capacity() << " Characters" << std::endl;
	std::cout << "Length of the String after shrinking    : " << s1.length() << " Characters" << std::endl;

	std::cout << "String Before reserving : " << s1 << std::endl;
	// MVC allocate atleast the specified maount of memory
	// gcc allocates exactly the amount specified if the request is more than the current size
	s1.reserve(50);
	std::cout << "String After  reserving : " << s1 << std::endl;
	std::cout << "Capacity of the String after reserving  : " << s1.capacity() << " Characters" << std::endl;
	std::cout << "Length of the String after reserving    : " << s1.length() << " Characters" << std::endl;

	//returns the maximum number of characters
	std::cout << "Max Size of the String   : " << s1.max_size() << " Characters" << std::endl;

}


void string_modification_insert() {
	{
		std::string s1{ "Anniruddha"s };
		std::cout << "String : " << s1 << std::endl;
		std::cout << std::boolalpha;
		std::cout << "Is String empty before clearing ? " << s1.empty() << std::endl;
		s1.clear();
		std::cout << "Is String empty after clearing  ? " << s1.empty() << std::endl;
	}
	
	
	{
		std::string s1 = "aaaaaaaaaa"s;
		std::cout << "String : " << s1 << std::endl;
		size_t count{ 3 };
		size_t index{ 4 };
		char ch{ 'X' };
		s1.insert(index, count, ch); // Inserts count copies of character ch at the position index.
		std::cout << "String : " << s1 << std::endl;
	}
	{
		std::string s1 = "aaaaaaaaaa"s;
		size_t index{ 4 };
		//Inserts null-terminated character string pointed to by ntbs at the position index
		char ntbs1[]{ "HELLO" };
		s1.insert(index, ntbs1);
		std::cout << "String : " << s1 << std::endl;
	}
	{
		//Inserts the characters in the range[s, s + count) at the position index
		std::string s1 = "aaaaaaaaaa"s;
		std::cout << "String : " << s1 << std::endl;
		const char ntbs2[11]{ "bbbbbbbbbb" };
		size_t count{ 5 };
		size_t index{ 4 };
		/*Inserts the characters in the range [ntbs2, ntbs2 + count) at the position index.
		The range can contain null characters.*/
		s1.insert(index, ntbs2, count);
		std::cout << "String : " << s1 << std::endl;
	}
	{
		std::string s1{ "aaaaaaaaaa"s };
		std::string s2{ "ABCDEFGHIJK"s };
		s1.insert(s1.begin() + 5, s2.begin(), s2.begin() + 4);
		std::cout << "String : " << s1 << std::endl;
	}
	{
		std::string s1{ "aaaaaaaaaaaaaa"s };
		std::string s2{ "ABCDEFGHIJK"s };
		s1.insert(s1.end()-2 , s2.begin(), s2.begin() + 4);
		std::cout << "String : " << s1 << std::endl;
	}

}

void string_erase_demo() {
	{
		std::string s1{ "ABCDEFGHIJK"s };
		std::cout << "String : " << s1 << std::endl;
		size_t index{ 4 };
		s1.erase(index); //Erases all characters starting from the given index
		std::cout << "String : " << s1 << std::endl;
		std::cout <<  std::endl;
	}

	{
		std::string s1{ "ABCDEFGHIJK"s };
		std::cout << "String : " << s1 << std::endl;
		size_t index{ 4 };
		size_t count{ 5 };
		s1.erase(index, count); //Erases count number  characters starting from the given index
		std::cout << "String : " << s1 << std::endl;
		std::cout << std::endl;
	}

	{
		std::string s1{ "ABCDEFGHIJK"s };
		std::cout << "String : " << s1 << std::endl;
		s1.erase(s1.begin()+5); //Erases the characters at the iterator position
		std::cout << "String : " << s1 << std::endl;
		std::cout << std::endl;
	}

	{
		std::string s1{ "ABCDEFGHIJKLMNOPQRST"s };
		std::cout << "String : " << s1 << std::endl;
		s1.erase(s1.begin() + 5, s1.begin() + 10); //Erases the characters in the given range
		std::cout << "String : " << s1 << std::endl;
		std::cout << std::endl;
	}
}

void string_push_pop_demo() {
	{//Appends the given character ch to the end of the string.
		std::string s1{ "ABCDEFGHIJKLMNOPQRST"s };
		std::cout << "String : " << s1 << std::endl;
		s1.push_back('@');
		std::cout << "String : " << s1 << std::endl;
	}
	{//removes the last character
		std::string s1{ "ABCDEFGHIJKLMNOPQRST"s };
		std::cout << "String : " << s1 << std::endl;
		s1.pop_back();
		std::cout << "String : " << s1 << std::endl;
	}
}

void string_append_demo() {
	{//Appends the given character ch to the end of the string.
		std::string s1{"ABCDE"s};
		constexpr size_t count{ 5 };
		s1.append(count,'X');
		std::cout << "String s1: " << s1 << std::endl;
		std::cout << std::endl;
	}

	{//Appends string str.
		std::string s1{ "ABCDE"s };
		std::string s2{ "XYZ"s };
		s1.append(s2);
		std::cout << "String s1: " << s1 << std::endl;
		std::cout << "String s2: " << s2 << std::endl;
		std::cout << std::endl;
	}

	{
		std::string s1{ "aaaaaaaaaa"s };
		std::string s2{ "ABCDEFGHIJK"s };
		std::cout << "String s1: " << s1 << std::endl;
		std::cout << "String s2: " << s2 << std::endl;
		size_t index{ 5 };
		size_t count{ 3 };
		s1.append(s2, index, count); //Appends a substring [index, (index+ count)] of s2.
		std::cout << "String s1: " << s1 << std::endl;
		std::cout << "String s2: " << s2 << std::endl;
		std::cout << std::endl;
	}

	{
		std::string s1{ "aaaaaaaaaa"s };
		std::string s2{ "ABCDEFGHIJK"s };
		std::cout << "String s1: " << s1 << std::endl;
		std::cout << "String s2: " << s2 << std::endl;
		s1.append(s2.begin()+3, s2.end()-3); //Appends a all charactes expcept the fisrt and last 3 characters from s2
		std::cout << "String s1: " << s1 << std::endl;
		std::cout << "String s2: " << s2 << std::endl;
		std::cout << std::endl;
	}
}

void string_replace_demo() {
	{
		std::string s1{ "ABCDEFGHIJK"s };
		std::string replacement{ "XXXXXXX" };
		std::cout << "String s1: " << s1 << std::endl;
		s1.replace(5, 3, replacement);
		std::cout << "String s1: " << s1 << std::endl;
		std::cout << std::endl;
	}

	{
		std::string s1{ "abcdefghijk"s };
		std::string s2{ "ABCDEFGHIJK"s };
		std::cout << "String s1: " << s1 << std::endl;
		std::cout << "String s2: " << s2 << std::endl;
		s1.replace(5, 3, s2, 5, 3);
		std::cout << "String s1: " << s1 << std::endl;
		std::cout << "String s2: " << s2 << std::endl;
		std::cout << std::endl;
	}
}


int main()
{
	// ntbs();

	//raw_strings();
	//string_initialization();
	//string_initialization_with_docs();
	//string_assignment();
	//string_concatenation();
	//reading_string_problem();
	//reading_string_solution();
	//read_multiple_lines();
	// read_strings_using_method();
	// read_character();
	// read_using_get();
	//problem_read_data();
	//problem_read_data_solved();

	//diff_string_types();
	//assign_range_demo();
	//string_capacity();
	//string_modification_insert();
	//string_erase_demo();
	//string_push_pop_demo();

	//string_append_demo();

	string_replace_demo();

	return EXIT_SUCCESS;
}

