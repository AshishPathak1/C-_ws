//Application of references while 
//passing and returning objects 
//from functions

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>

//Application of references while 
//passing and returning objects 
//from functions

class Person {
private:
	char name[100];
	char address[892];
	float weight;
	int age;
public:
	//default ctor
	Person() {
		std::cout << "Default ctor invoked" << std::endl;
		strcpy_s(name, "ABHI");
		strcpy_s(address, "Pune Pradhikaran");
		age = 34;
		weight = 69.5f;
	}

	//copy ctor
	Person(const Person& tobj) {
		std::cout << "Copy ctor invoked" << std::endl;
		strcpy_s(name, tobj.name);
		strcpy_s(address, tobj.address);
		age = tobj.age;
		weight = tobj.weight;
		fflush(stdout);
	}
	//dtor

	~Person() {
		std::cout << "Dtor invoked" << std::endl;
		//do_clean_up_Operation
	}

	void acceptDetails(void) {
		//statements
	}

	void displayDetails(void)const {
		std::cout << "Age : " << age << std::endl;
		//statements
	}

	void updateAge(int a) {
		age = a;
	}

}; // end of class declaration

// Formal argument is an object therefore ctor 
// and dtor are called for it and duplication 
// of memory also occurs

void foo1(Person x) {
	x.displayDetails();
	return;
}

// Formal argument is an reference therefore 
// ctor and dtor are not called for it and no
// duplication of memory occurs

void foo2(Person& x) {
	x.displayDetails();
	return;
}

// Formal argument and return type are objects
// resulting into repeated calls to ctors 
// and dtors and thus resulting in unnecessary 
// duplication of memory while 
// receiving and returning object

Person foo3(Person x) {
	x.displayDetails();
	return x;
}

// formal argument and return type are references
// therefore call to ctors and dtors are avoided 
// when the function is called and reference is 
// returned from function. Duplicate or temporary 
// objects are not are created

Person& foo4(Person& x) {
	x.displayDetails();
	x.updateAge(12);
	return x;
}

// Creates a temporary object which is a copy 
// of local object to be returned by calling 
// copy ctor before destroying local object

Person foo5(void) {
	Person x;//Local object
	x.updateAge(22);
	return x;
}


// cannot return reference to a local object.
// Since local object will be destroyed when
// the function returns and references are
// always supposed to refer (point) to 
// live object.

//Person& foo6(void) {
//    Person x;
//    x.updateAge(100);
//    return x;
//}

//Same object behaves differently at different
// places.The object is modifiable in main() 
// whereas behaves as if its constant in foo7() 
// by receiving it in a reference 'to' 
// constant object

void foo7(Person const& x) {
	x.displayDetails();
   //x.updateAge(12); //error
	return;
}

int main() {
	Person p;
	foo1(p);
	foo2(p);
	foo3(p);
	foo4(p);
	foo5();
	foo7(p);
	int const& r = 10;
	return EXIT_SUCCESS;
}

