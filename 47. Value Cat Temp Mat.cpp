// 47. Value Cat Temp Mat.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


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

class Widget {};

void func(Widget& ref) { //parameter is lvalue reference

}

void foo(Widget&& ref) { //parameter is rvalue reference

}

void baz(const Widget& ref) { // parameter is constant reference

}

Widget bar() { //ob=ject returned by function by value
    Widget w;
    //....
    if (true)
        return w;
    else
        return Widget{};
}

void  materialization() {
    Widget w{};
    func(w);        // argument is lvalue that can bind to lvalue reference
  //  func(Widget{}); // argument is rvalue that cannot bind to lvalue reference

    foo(Widget{}); // argument is rvalue that can bind to rvalue reference
  //  foo(w); // argument is lvalue that cannot bind to rvalue reference

    baz(w);        //argument is lvalue that can bind to const reference
    baz(Widget{}); //argument is prvalue that can bind to const reference
    // the question of caller observing the changes made to parameter does not apply
    // since the parameter of baz() is a const reference 

     Widget& ref1 = w;
     Widget&& ref2 = Widget{};

     const Widget& ref3 = w;
     const Widget& ref4 = Widget{}; //Widget{} is prvalue which is converted to xvalue

     const Widget& ref5 = bar();

}


int main()
{
    categories();
    materialization();
}
