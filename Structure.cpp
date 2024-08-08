// 41. Structure.cpp :compound data type


#include <iostream>
#include <bitset>
#include <iomanip>
#include <cstdint>
#include <vector>
#include <array>
#include <limits>
#include <string_view>
#include <ios>
#include <algorithm>
//void structure_introduction();
//void aggregate_initialization();
//void accessing_struct_members();
//void struct_layout();
//void alignment();
//void alignas_demo();
//void compact_struct();
//void struct_bit_fields();
//void struct_encapsulation();

void simple_application();
//
int main()
{
	//	//structure_introduction();
	//	//aggregate_initialization();
	//	//accessing_struct_members();
	//	//alignment();
	//	//struct_layout();
	//	//alignas_demo();
	//	//compact_struct();
	//	//struct_bit_fields();
	//	//struct_encapsulation();
	simple_application();
	return EXIT_SUCCESS;
}
//
//void structure_introduction() {
//	/*Structure Declaration : giving the compiler information about the design of
//	new user-defined / program-defined data type*/
//
//	struct Point {
//		int x;   //structure member
//		int y;   //struct element(member)
//	}p1; //structure variable
//
//	std::cout << "Size of Struct Point : " << sizeof(struct Point) << " bytes\n";
//	std::cout << "Size of Struct Point : " << sizeof(Point) << " bytes\n";
//	std::cout << "Size of Struct Point : " << sizeof(p1) << " bytes\n";
//
//	/*Defining Structure Variable*/
//	struct Point p2;
//	// uninitialized local variable 'p2' used
//    // std::cout << "x : " << p2.x << "\ty : " << p2.y << std::endl;
//
//	//Default initialization of members will be done
//	Point p3{};
//	std::cout << "x : " << p3.x << "\ty : " << p3.y << std::endl;
//
//	Point p4{ 1 }; // y is implicitly initialized to 0
//	std::cout << "x : " << p4.x << "\ty : " << p4.y << std::endl;
//
//	struct Point p5 { 10, 20 };
//	std::cout << "x : " << p5.x << "\ty : " << p5.y << std::endl;
//
//	return;
//
//}
//
//void aggregate_initialization() {
//	struct Employee
//	{
//		int id{};
//		int age{};
//		double wage{};
//	};
//	Employee sparsh;
//	Employee faizal = { 1, 32, 60000.0 }; // copy-list initialization using braced list
//	Employee jay{ 2, 28, 45000.0 };       // list initialization using braced list (preferred)
//	Employee aman{ 2, 28 };				  // aman.wage will be value-initialized to  0.0
//
////Employee raju(3, 45, 62500.0);		 // direct initialization using parenthesized list (C++20)
//	Employee kamlesh{ raju }; //A structure variable can be initialized with another structure variable
//	Employee sai{.id=55,.age=27,.wage = 80000.0 }; //designated initializers
//
//	//Assignment with an initializer list
//	aman = { aman.id, 33, 66000.0 }; // Aman had a birthday and got a raise
//
//	//Assignment with designated initializers C++20
//	aman = { .id = aman.id, .age = 30, .wage = 77000.0 }; // aman had a birthday and got a raise
//
//	aman = jay; //A structure variable can be assigned with another structure variable
//
//	struct Student {
//		int roll{};
//		int yob{ 2020 }; //year of birth
//		double per{ };
//	};
//	Student aryan{ .roll = 12, .per = 66.77};
////	aman = aryan; // no known conversion for argument 1 from main()::Student to main()::Employee
//}
//
//void accessing_struct_members() {
//	/*Structure Declaration : No memory is allocated when a structure is declared */
//	struct Point {
//		int x;
//		int y;
//	};
//
//	/*Defining a structure variable*/
//	struct Point p1 { 10, 20 };
//	Point p3{ 20, 30 };
//
//	/*Direct Access : access structure member using dot operator along with structure variable
//		structure_variable.member;     structure_variable[dot]member;
//	 */
//	std::cout << "x : " << p3.x << "\ty : " << p3.y << std::endl;
//
//	//Indirect Access : Accessing using pointer ot structure
//	Point* ptr = &p1;
//	/*
//	  The arrow operator (->) is a dereference operator that is used exclusively with pointers to objects
//	  Access structure member using -> operator along with pointer to structure variable
//		  pointer_to_structure->member;
//	   */
//	std::cout << "x : " << ptr->x << "\ty : " << ptr->y << std::endl;
//
//	int a{ 55 };
//	int* p{ &a };
//	std::cout << "Direct access using variable name: " << a << std::endl;
//	std::cout << "InDirect access using pointer to variable : " << (*p) << std::endl;
//
//	std::cout << "x : " <<  p1.x << "\ty : " << p1.y << std::endl;
//	std::cout << "x : " << (*ptr).x << "\ty : " << (*ptr).y << std::endl;
//
//	//Address of the Structure
//	std::cout << "Address of p1 : " << &p1 << std::endl;
//	std::cout << "Address of p1 : " << ptr << std::endl;
//
//	//Address of Structure Members using structure variable
//	std::cout << "Address of p1.x : " << &(p1.x) << std::endl;
//
//	// dot operator has higher precedence than &
//	std::cout << "Address of p1.x : " << &p1.x << std::endl;
//	std::cout << "Address of p1.y : " << &p1.y << std::endl;
//
//	std::cout << "Address of ptr->x : " << &(ptr->x) << std::endl;
//	// -> operator has higher precedence than &
//	std::cout << "Address of ptr->x : " << &ptr->x << std::endl;
//	std::cout << "Address of ptr->y : " << &ptr->y << std::endl;
//
//
//	return;
//
//}
//
//void alignment() {
//	/*
//    Every object type has the property called alignment requirement,
//	which is a nonnegative integer value (of type std::size_t, and always a power of two)
//	representing the number of bytes between successive addresses at which
//	objects of this type can be allocated.
//	An object doesn't just need enough storage to hold its representation.
//	In addition, on some machine architectures, the bytes used to hold it
//	must have proper alignment for the hardware to access it efficiently
//	(or in extreme cases to access it at all)
//	The alignof() operator returns the alignment of its argument expression
//	*/
//	char c_var1 = { 'A' };
//	std::cout << "Size of c_var1 : " << sizeof(c_var1) << " bytes\n";
//	std::cout << "Address of c_var1 : "
//		<< std::showbase << std::hex
//		<< reinterpret_cast<unsigned long long>(&c_var1) << "\t"
//		<< std::dec << reinterpret_cast<unsigned long long>(&c_var1)
//		<< std::endl;
//	char c_var2 = 'A';
//	std::cout << "Address of c_var2 : "
//		<< std::showbase << std::hex
//		<< reinterpret_cast<unsigned long long>(&c_var2) << "\t"
//		<< std::dec << reinterpret_cast<unsigned long long>(&c_var2)
//		<< std::endl;
//
//	std::cout << "Alignment of char variable   : " << alignof(char)  << std::endl;
//	std::cout << "Alignment of int variable    : " << alignof(int)   << std::endl;
//	std::cout << "Alignment of float variable  : " << alignof(float) << std::endl;
//	std::cout << "Alignment of double variable : " << alignof(double)<< std::endl;
//	//constant not allowed
//	//std::cout << "Alignment of double variable : " << alignof(4.5) << std::endl;
//
//	double d_var{};
//	std::cout << "Address of d_var : "
//		<< std::showbase << std::hex
//		<< reinterpret_cast<unsigned long long>(&d_var) << "\t"
//		<< std::dec << reinterpret_cast<unsigned long long>(&d_var)
//		<< std::endl;
//
//	float f_var{};
//	std::cout << "Address of f_var : "
//		<< std::showbase << std::hex
//		<< reinterpret_cast<unsigned long long>(&f_var) << "\t"
//		<< std::dec << reinterpret_cast<unsigned long long>(&f_var)
//		<< std::endl;
//	return;
//
//}
//
//
//void struct_layout() {
//	// An object of a struct holds its members in the order they are declared
//	struct Readout {
//		char hour; // [0:23]
//		int  value;
//		char seq; // sequence mark ['a':'z']
//	};
//
//	std::cout << "Size of struct Readout : " << sizeof(Readout) << " bytes\n";
//	std::cout << "Alignment of struct Readout  : " << alignof(struct Readout) << std::endl;
//	//Members are allocated in memory in declaration order,
//	struct Writeout {
//		int  value;
//		char hour;
//		char seq;
//	};
//	std::cout << "Size of struct Writeout : " << sizeof(Writeout) << " bytes\n";
//	std::cout << "Alignment of struct Writeout : " << alignof(struct Writeout) << std::endl;
//
//	struct ReadIn {
//		char hour;      // 7 slack bytes
//		double value;   // 0 slack bytes
//		char seq;       // 7 slack bytes
//	};
//	std::cout << "Size of struct ReadIn : " << sizeof(ReadIn) << " bytes\n";
//	std::cout << "Alignment of struct ReadIn : " << alignof(struct ReadIn) << std::endl;
//	/*
//	You can minimize wasted space by simply ordering members by size (largest member first).
//	*/
//	struct WriteIn {
//		double value;   // 0 slack bytes
//		char hour;      // 0 slack bytes
//		char seq;       // 6 slack bytes
//	};
//	std::cout << "Size of struct WriteIn : " << sizeof(WriteIn) << " bytes\n";
//	std::cout << "Alignment of struct ReadIn : " << alignof(WriteIn) << std::endl;
//	//so the address of hour must be less than the address of value.
//
//	/*
//	the size of an object of a struct is not necessarily the sum of the sizes of
//	its members. This is because many machines require objects of certain types
//	to be allocated on architecture dependent boundaries or handle such objects
//	much more efficiently if they are.
//	For example, integers are often allocated on word boundaries. On such machines,
//	objects are said to have to be properly aligned. This leads to holes (slack bytes)
//	in the structures.
//
//	*/
//}
//
//void  alignas_demo() {
//	/*
//	alignas specifier(since C++11)
//	Specifies the alignment requirement of a type or an object.
//	*/
//	struct alignas(16) ReadIn {
//		char hour;     // 15 slack bytes
//		double value;  // 0 slack byte
//		char seq;      // 7 slack bytes
//	};
//	std::cout << "Size of struct ReadIn : " << sizeof(ReadIn) << " bytes\n";
//	std::cout << "Alignment of struct ReadIn  : " << alignof(struct ReadIn) << std::endl;
//
//	struct alignas(double) WriteIn {
//		char hour;     // 7 slack bytes
//		double value;  // 0 slack byte
//		char seq;      // 7 slack bytes
//	};
//	std::cout << "Size of struct ReadIn : " << sizeof(WriteIn) << " bytes\n";
//	std::cout << "Alignment of struct WriteIn  : " << alignof(struct WriteIn) << std::endl;
//
//
//	struct alignas(double) WriteOut {
//		double value;  // 0 slack byte
//		char hour;     // 0 slack bytes
//		char seq;      // 6 slack bytes
//	};
//	std::cout << "Size of struct WriteOut : " << sizeof(WriteOut) << " bytes\n";
//	std::cout << "Alignment of struct WriteOut  : " << alignof(struct WriteOut) << std::endl;
//}
//
//#pragma ms_struct off
//
//void compact_struct() {
//	//Specifies the packing alignment for structure, union, and class members. (MSVS Compiler)
//	#pragma pack(1)
//	struct ReadIn {
//		char cdata1; // 3
//		int  idata;  // 0
//		char cdata2; // 3
//	};
//	std::cout << "Size of struct ReadIn : " << sizeof(ReadIn) << " bytes\n";
//
//	/*
//	//Works under linux __attribute__((__packed__))
//	struct WriteOut {
//		 char cdata1;
//		 int  idata;
//		 char cdata2;
//	 }__attribute__((__packed__));
//	 std::cout << "Size of struct WriteOut : " << sizeof(WriteOut) << " bytes\n";
//
//	 struct __attribute__((__packed__)) ReadOut {
//		 char cdata1;
//		 int  idata;
//		 char cdata2;
//	 };
//	std::cout << "Size of struct ReadOut : " << sizeof(ReadOut) << " bytes\n";
//	 */
//
//}
//
//void struct_bit_fields() {
//	struct HotelGuestProfile {
//		uint8_t isVeg;
//		uint8_t isAlcoholic;
//		uint8_t isSmoker;
//		uint8_t isFrequentFlyer;
//		uint8_t isIndianCitizen;
//		uint8_t isAdult;
//		uint8_t isEmployed;
//		uint8_t isMarried;
//	};
//	std::cout << "Size of struct HotelGuestProfile : " << sizeof(HotelGuestProfile) << " bytes\n";
//
//	struct GuestProfileFlags {
//		uint8_t isVeg : 1;
//		uint8_t isAlcoholic : 1;
//		uint8_t isSmoker : 1;
//		uint8_t isFrequentFlyer : 1;
//		uint8_t isIndianCitizen : 1;
//		uint8_t isAdult : 1;
//		uint8_t isEmployed : 1;
//		uint8_t isMarried : 1;
//	};
//	std::cout << "Size of struct GuestProfileFlags : " << sizeof(GuestProfileFlags) << " bytes\n";
//	GuestProfileFlags gp{};
//	auto status  = std::bitset<8>(reinterpret_cast<char*>(&gp));
//	status.set(6, 1);
//	std::cout << "Is he employed : " << std::boolalpha << status.test(6) << std::endl;
//
//	GuestProfileFlags gp1{};
//	gp1.isAlcoholic = 0b1; //binary literal
//	gp1.isVeg = 0b1;
//	std::cout << "Is he alcoholic  " << std::boolalpha<< static_cast<bool>(gp1.isAlcoholic) <<std::endl;
//	std::cout << "Is he vegiee : " << std::boolalpha  << static_cast<bool>(gp1.isVeg) << std::endl;
//	gp1.isVeg = 0b0;
//	std::cout << "Is he vegiee : " << std::boolalpha  << static_cast<bool>(gp1.isVeg) << std::endl;
//
//	std::cout << "Is smoking default choice : " << std::boolalpha << static_cast<bool>(gp1.isSmoker) << std::endl;
//	std::cout << "do you prefer Smoking (Y/N) : ";
//	char choice{};
//	std::cin >> choice;
//	if (std::toupper(choice) == 'Y') {
//		gp1.isSmoker = 0b1;
//	}
//	std::cout << "Is smoking his choice now : " << std::boolalpha << static_cast<bool>(gp1.isSmoker) << std::endl;
//
//
//	auto profile = std::bitset<8>(reinterpret_cast<char*>(&gp));
//	std::cout << "Is alcoholic default choice : " << std::boolalpha << profile.test(2)	<< std::endl;
//	std::cout << "do you prefer alcoholic drinks (Y/N) : ";
//
//	std::cin >> choice;
//	if (std::toupper(choice) == 'Y') {
//		profile.set(2, true);
//	}
//	std::cout << "Is alcoholic user preference  : " << std::boolalpha << profile.test(2) << std::endl;
//
//
//	struct StudentProfile {
//		uint8_t grade  : 3;
//		uint8_t rollNo : 5;
//	};
//
//	std::cout << "Size of struct StudentProfile : " << sizeof(StudentProfile) << " bytes\n";
//	StudentProfile sp1{ 2, 29 };
//	std::cout << "Grade :" << static_cast<int>(sp1.grade) << "\tRoll No." << static_cast<int>(sp1.rollNo) << std::endl;
//	sp1.grade = 0b11;
//	sp1.rollNo = 0b1111;
//	std::cout << "Grade :" << static_cast<int>(sp1.grade) << "\tRoll No." << static_cast<int>(sp1.rollNo) << std::endl;
//	auto sprofile = std::bitset<8>(*(reinterpret_cast<char*>(&sp1)));
//
//	std::cout << "Grade   :" << ((sprofile << 5) >> 5).to_ullong() << std::endl;
//	std::cout << "Roll no :" << (sprofile >> 3).to_ullong() << std::endl;
//
//	//int* ptr = reinterpret_cast<int*>(&sp1);
//	//std::cout << "235 : " << std::bitset<8>(*ptr) << std::endl;
//	//std::cout << "Grade   :" << ((*ptr << 29) >> 29) << std::endl;
//	//std::cout << "Roll no :" << (*ptr >> 3) << std::endl;
//
//	std::cout << "************";
//}
//
//using namespace std::literals;
//void struct_encapsulation() {
//	struct Student {
//		std::string name;
//		int roll;
//		float percentage;
//	};
//
//	Student s1{ "Raja"s, 12, 78.9F };
//	std::cout << "Name       : " << s1.name << std::endl;
//	std::cout << "Roll no    : " << s1.roll << std::endl;
//	std::cout << "Percentage : " << s1.percentage << std::endl;
//
//	s1.roll = -89;
//	s1.percentage = 788.9F;
//	s1.name = "1234567";
//	std::cout << "Name       : " << s1.name << std::endl;
//	std::cout << "Roll no    : " << s1.roll << std::endl;
//	std::cout << "Percentage : " << s1.percentage << std::endl;
//
//
//	// Encapsulation using access specifiers
//	struct StudentDetails {
//	private:
//		std::string _name{};
//		int _roll{};
//		float _per{};
//	public:
//		StudentDetails(std::string name, int roll, float per) {
//			_name = name;
//			_roll = roll;
//			_per = per;
//		}
//
//		std::string getName() {
//			return _name;
//		}
//
//		int getRoll() {
//			return _roll;
//		}
//
//		float getPercentage() {
//			return _per;
//
//		}
//
//		void setName(std::string name) {
//			_name = name;
//		}
//
//		void setRoll(int roll) {
//			if (roll > 0 and roll < 30) {
//				_roll = roll;
//			}
//			else {
//				std::cerr << "Incorrect Roll number supplied!\n";
//				std::cerr << "Roll number should be in the range of 1 to 30\n";
//			}
//		}
//
//		void setPercentage(float per) {
//			if (per >= 0 and per <= 100) {
//				_per = per;
//			}
//			else {
//				std::cerr << "Percentage should be in the range of 0 to 100\n";
//			}
//
//		}
//
//	};
//
//	StudentDetails sd1{ "Rani",12,78.9F };
//
//	/*std::cout << "Name       : " << sd1._name << std::endl;
//	std::cout << "Roll no    : " << sd1._roll << std::endl;
//	std::cout << "Percentage : " << sd1._percentage << std::endl;*/
//
//	std::cout << "Name       : " << sd1.getName() << std::endl;
//	std::cout << "Roll no    : " << sd1.getRoll() << std::endl;
//	std::cout << "Percentage : " << sd1.getPercentage() << std::endl;
//
//	sd1.setName("Rameshwari");
//	sd1.setRoll(-13);
//	sd1.setPercentage(189.6F);
//	std::cout << "Name       : " << sd1.getName() << std::endl;
//	std::cout << "Roll no    : " << sd1.getRoll() << std::endl;
//	std::cout << "Percentage : " << sd1.getPercentage() << std::endl;
//
//
//}

struct StudentDetails {
private:
	std::string _name{};
	int _roll{};
	float _per{};
public:
	StudentDetails(std::string name, int roll, float per) {
		_name = name;
		_roll = roll;
		_per = per;
	}
	StudentDetails() {

	}
	std::string getName() {
		return _name;
	}

	int getRoll() {
		return _roll;
	}

	float getPercentage() {
		return _per;

	}

	void setName(std::string name) {
		_name = name;
	}

	void setRoll(int roll) {
		if (roll > 0 and roll < 30) {
			_roll = roll;
		}
		else {
			std::cerr << "Incorrect Roll number supplied!\n";
			std::cerr << "Roll number should be in the range of 1 to 30\n";
		}
	}

	void setPercentage(float per) {
		if (per >= 0 and per <= 100) {
			_per = per;
		}
		else {
			std::cerr << "Percentage should be in the range of 0 to 100\n";
		}

	}

};

int get_number_of_students() {
	int number_of_students;
	std::cout << "How many students details are to be stored ? ";
	std::cin >> number_of_students;
	return number_of_students;
}

void accept_student_details(StudentDetails& s) {
	std::cout << "Please enter the name : ";
	std::string name{};
	std::cin >> name;
	s.setName(name);

	std::cout << "Please enter the roll Number : ";
	int roll{};
	std::cin >> roll;
	s.setRoll(roll);

	std::cout << "Please enter the Percentage : ";
	float per{};
	std::cin >> per;
	s.setPercentage(per);
	std::cout << std::endl;

}

void store_student_details(std::vector<StudentDetails>& stud) {
	for (size_t idx{}; idx < stud.size(); idx++) {
		accept_student_details(stud[idx]);
	}
}


void print_student_details(const std::vector<StudentDetails>& stud) {
	std::cout << "Details of " << stud.size() << " students are as follows:\n";

	for (StudentDetails element : stud) {
		std::cout << "Name        : " << element.getName() << std::endl;
		std::cout << "Roll Number : " << element.getRoll() << std::endl;
		std::cout << "Percentage  : " << element.getPercentage() << std::endl << std::endl;
	}
	std::cout << std::endl;
	return;
}
void search_student(const std::vector<StudentDetails>& stud, const int roll) {
	for (StudentDetails element : stud) {
		if (element.getRoll() == roll) {
			std::cout << "Name        : " << element.getName() << std::endl;
			std::cout << "Percentage  : " << element.getPercentage() << std::endl << std::endl;
			return;
		}
	}
	std::cerr << "Sorry!,No results found " << std::endl;
	return;
}

std::string convert_to_uppercase(std::string_view astring) {
//	auto uppercase = [](int ch) {return std::toupper(ch); };
//  std::transform(astring.begin(), astring.end(), upper_str.begin(), uppercase);
	std::string upper_str;
	std::transform(astring.begin(), astring.end(), upper_str.begin(), [](int ch) {return std::toupper(ch); });
	return upper_str;
}

bool delete_student(std::vector<StudentDetails>& stud, std::string& name_to_delete) {
	/*int count{ -1 };
	for (StudentDetails element : stud) {
		count++;
		if (element.getName() == nam) {
			stud.erase(stud.begin() + count);
			return;
		}
	}
	std::cerr << "Sorry!,No results found " << std::endl;
	return;*/
	for (auto it = stud.begin(); it != stud.end(); ++it) {
		if (convert_to_uppercase(it->getName()) == convert_to_uppercase(name_to_delete)) {
			stud.erase(it);
			return true;
		}
	}
	return false;
}


void simple_application() {
	int number_of_students = get_number_of_students();
	std::vector<StudentDetails> students(number_of_students);
	store_student_details(students);
	print_student_details(students);
	unsigned int roll{};
	std::cout << "Enter roll number to get details: ";
	std::cin >> roll;
	search_student(students, roll);
	std::cin.clear();
	std::string name{};
	std::cout << "Enter name to delete: " ;
	std::cin >> name;
	if (delete_student(students, name)) {
		std::cout << "Record of " << name << " has been deleted" << std::endl;
	}
	else {
		std::cout << "Record of " << name << " is not found " << std::endl;

	}

	print_student_details(students);
	return;

}
