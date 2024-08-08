// 46. LvalueRvalue.cpp : 
/*
* You can overload a function to take an lvalue reference and an rvalue reference.

By overloading a function to take a const lvalue reference or an rvalue reference,
you can write code that distinguishes between non-modifiable objects (lvalues) and
modifiable temporary values (rvalues). You can pass an object to a function that takes
an rvalue reference unless the object is marked as const. The following example shows
the function f, which is overloaded to take an lvalue reference and an rvalue reference.
The main function calls f with both lvalues and an rvalue.
*/
// reference-overload.cpp
// Compile with: /EHsc
#include <iostream>


// A class that contains a memory resource.
struct MemoryBlock
{
	int data{ 99 };
	
};

/*const reference can receive const and non-const lvalues but cannot modify them*/
void f(const MemoryBlock&)
{
	std::cout << "In f(const MemoryBlock&). This version cannot modify the parameter." << std::endl;
}

void f(const  MemoryBlock&&)
{
	std::cout << "In f(const MemoryBlock&&). This version can modify the parameter." << std::endl;

}


int main()
{
	/*The compiler treats a named rvalue reference as an lvalue and an unnamed rvalue reference as an rvalue.*/
	MemoryBlock block{};		//non-const object (lvalue)
	//f(block);			//passes a local variable (an lvalue) as its argument.
	//f(MemoryBlock());	//passes a non-const temporary object as its argument


	const MemoryBlock cblock{};
	//f(cblock);		//constant object l-value
	/*You can pass an object to a function that takes an rvalue reference unless the object is marked as const.*/
	//f((const MemoryBlock()));  //passes a const temporary/anonymous object as its argument

	/*The C++ Standard Library std::move function enables you to convert an object to an 
	rvalue reference to that object. */
	f(std::move(block));

	/*Alternatively, you can use the static_cast keyword (operator) to cast an lvalue 
	to an rvalue reference*/
	f(static_cast<MemoryBlock&&>(block));
	f(static_cast<const MemoryBlock&&>(cblock));
	return EXIT_SUCCESS;
}