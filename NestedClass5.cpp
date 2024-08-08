// Nested Class have permission to access the all members of the surrounding class including private members
// Static memebers of the surrounding class can eb accessed directly in the nested class 
// Non static members of the surrounding class can be accessed inthe nested class using the instance 
// of Surrounding class instance

#include <iostream>

class Surround {
private:
    int non_static_data;
    static int static_data; //Static members are declared inside the class
public:
    Surround();
    class FirstWithin; //forward Declaration
};

//Static members are defined inside the class
int Surround::static_data{ 44 };

Surround::Surround() :non_static_data(22) {

}

class Surround::FirstWithin {
public:
    int non_static_function();
    static int static_function();
    void foo();
};

int Surround::FirstWithin::non_static_function() {
    // Non static members are allocated memory only when an object of the class is created
    //non_static_data = 45;
    /*Surrounding class static member (including private members) can be accessed directly*/
    static_data = 56;
    return static_data;
}

int Surround::FirstWithin::static_function() {
    //non_static_data = 45;
    static_data = 66;
    return static_data;
}

void Surround::FirstWithin::foo()
{
    Surround sobj{};
    /*Have permission to access the private member of surround class using the instance of surround class*/
    std::cout << sobj.non_static_data << std::endl;
}

class Other { //unrelated class
public:
    void other_foo() { 
        Surround sobj{};
       // cannot access private member declared in class 'Surround'
       //std::cout << sobj.non_static_data << std::endl;
    }
};

int main()
{
    Surround::FirstWithin fobj;
    std::cout << fobj.non_static_function() << std::endl;
    fobj.foo();
    std::cout << Surround::FirstWithin::static_function() << std::endl;
    

    Surround sobj;
    // cannot access private member declared in class 'Surround'
    // std::cout << sobj.non_static_data << std::endl;
}