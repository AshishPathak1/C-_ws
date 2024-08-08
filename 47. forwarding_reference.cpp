// 47. forwarding_reference.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std::literals;

void foo(int && r) { //parameter 'r' is of lvalue category having data type rvalue reference 

}

void bar(auto && r) { //the parameter of bar() binds to both lvalues and rvalues category of arguments.
                      // parameter 'r' here is a forwarding(universal) reference
}

void baz(const auto && r) { //parameter 'r' is of lvalue category having data type rvalue reference 
    //const qualifier is enough to disable the interpretation of && as a forwarding reference
    std::cout << " Rvalue ref  : " << std::endl;
}

class Widget{};


void categories() {
    std::string s1{ "Namaste" }; //
    std::string s2{ "Hello" };
    //What is the data type of s?
    //  - Std::string
    //What is its Value Category
    //  - Lvalue
  
    //std::string&& r = s; //Rvalue reference cannot refer to lvalue
    std::string&& r = std::move(s2); //result of std::move() is xlvalue
    // xvalue is glvalue whose resource can be reused
    // rvalue reference can bind only to rvalue; but xvalue is a kind of rvalue

    int age{ 43 }; //43 is pravlue

}

int main()
{
    std::cout << "Exploring forwarding reference\n";
    foo(4);          // rvalue reference (int&&) can bind to rvalue (4)
    int data{ 4 }; 
  //  foo(data);     // rvalue reference (int&&) cannot bind to lvalue (int)

    Widget w{ };
    bar(5);     // argument is of type int; category rvalue 
    bar(data);  // argument is of type int; category lvalue 
    bar("data");  // argument is of type const char *; category lvalue 
    bar("data"s);  // argument is of type std::string literal; category rvalue 
    bar(w);     // argument is of type Widget; category lvalue 

    baz(5);         //argument is rvalue
    baz(5.0);       //argument is rvalue
    baz(5.5F);      //argument is rvalue
 //   baz(Widget{});  //argument is rvalue
    baz("hello"s);   // std::string literal of value category rvalue
 // baz("data");    // const char * is of category lvalue since it refers to address
 // baz(data);     //argument is lvalue which cannot bind with rvalue reference
 // baz(w);
    
    auto&& r1 = Widget{};   // datatype of r1 is rvalue reference
    auto&& r2 = w;          // datatype of r2 is lvalue reference

 //   const auto&& r3 = w;    // datatype of r3 is rvalue reference which cannot bind to lvalue
    const auto&& r4 = Widget{}; // datatype of r4 is rvalue reference which can bind to rvalue

    categories();
}
