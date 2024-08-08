// Static_member_3_intitalization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <cstdlib>
#include <iostream>


class C
{
private:
	//  Declaration of Static data members inside class
	static int i; //static data member
	static int j; //static data member
	static int k; //static data member
	static int m; //static data member
	static int n; //static data member
	int a; //non-static data members
	
	static int f(); //static member function

public:

	C() {
		a = 0;
	}

}; //end of class declaration

//Definition and initialization of 
//Static members outside class

int C::f() //static member function
{
	return 1;
}

// initialize using private static member function
int C::i{ C::f() };

// initialize using  another private static data member
int C::j{ C::i };

// initialize with a constant value (literal)
int C::m{ 1 };

//: 'm' : redefinition; multiple initialization
//cannot defined static member again  
//int C::m{ 10 };

C obj; //defining object of class C

// initialize with non-static data member
int C::k{ obj.a };



/*Default value zero*/
int C::n{};

int main()
{

	C object;
	std::cout << "Size of  C class object: " << sizeof(object) << " bytes" << std::endl;

	/*	 cannot access private member declared in class 'C' 	*/
	/*std::cout << obj.a;
	std::cout << C::i;
	std::cout << C::f();*/
	return 0;
}
