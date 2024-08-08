#include <iostream>

int main() {
    int i{ 99 };
    std::cout << "Value of i = " << i 
        << std::hex << std::showbase 
        << " and address = " << reinterpret_cast<unsigned int>( &i) << std::endl;

    int j{ i };
    std::cout << std::dec << "Value of j = " << j 
        << std::hex << std::showbase
        << " and address = " << reinterpret_cast<unsigned int>(&j) << std::endl;

    i = 88;
    std::cout << std::dec << "i = " << i << std::endl 
        << "j = " << j << std::endl;

    int& k{ i };
    std::cout << std::dec << "Value of k = " << k
        << std::hex << std::showbase
        << " and address = " << reinterpret_cast<unsigned int>(&k) << std::endl;

    k = 55;
    std::cout << std::dec << std::showbase;
    std::cout << "Value of k = " << k << std::endl;
    std::cout << "Value of i = " << i << std::endl;

    // additional reference to variable i
    int& m{ i };
    std::cout << "Value of m = " << m 
        << std::hex << std::showbase
        << " and address = " << reinterpret_cast<unsigned int>(&m) << std::endl;

    //pointer to reference variable
    int* ptr = &k; // &i // &m
    std::cout << "ptr = " <<  reinterpret_cast<unsigned int>(ptr) << std::endl;
    ptr = &m;
    std::cout << "ptr = " << reinterpret_cast<unsigned int>(ptr) << std::endl;
    ptr = &i;
    std::cout << "ptr = " << reinterpret_cast<unsigned int>(ptr) << std::endl;

    //Reference to pointer variable ptr
    int*& p = ptr;
    std::cout << "Address of ptr = " << reinterpret_cast<unsigned int>(&ptr) << std::endl;
    std::cout << "Address of p = " << reinterpret_cast<unsigned int>(&p) << std::endl;
    std::cout << "Address stored in ptr " << reinterpret_cast<unsigned int>(ptr) << std::endl;
    std::cout << "Address stored in p " << reinterpret_cast<unsigned int>(p) << std::endl;
    std::cout << std::dec;
    std::cout << "Value pointed by ptr : " << *ptr << std::endl;
    std::cout << "Value pointed by p : " << *p << std::endl;
    ptr = &j;

    //    &k = j; //once initialized a ref var cannot refer
    // to another variable
    int* p1;
    //    int &temp;// Reference variable cannot be created
    //			   without initialization

    int& kk = k; //we can create a reference to ref var
    std::cout << "kk = " << kk << std::endl;

    int const& temp{ 12 };
    std::cout << temp << "\t" << &temp << std::endl;
 //   temp = 8;
    //    
    return 0;
}