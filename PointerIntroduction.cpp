// 37. PointerIntroduction.cpp : 
// Pointer introduction

#include <iostream>

void  size_of_pointers() {
    char*   cptr = nullptr;
    int*    iptr = nullptr;
    double* dptr = nullptr;
    /*all pointer variables of same size and same type*/
    std::cout << "Size of Pointer to Character : " << sizeof(cptr) << " bytes\n";
    std::cout << "Size of Pointer to Integer   : " << sizeof(iptr) << " bytes\n";
    std::cout << "Size of Pointer to Double    : " << sizeof(dptr) << " bytes\n";

    /*Pointer variables point to variables of different size*/
    std::cout << "Size of Character : " << sizeof(*cptr) << " bytes\n";
    std::cout << "Size of Integer   : " << sizeof(*iptr) << " bytes\n";
    std::cout << "Size of Double    : " << sizeof(*dptr) << " bytes\n";
    return;
}

void  access_char_data_indirectly() {
    char grade{ 'A' };
    std::cout << "Grade:\tAddress : " << std::hex << std::showbase
        << reinterpret_cast<unsigned int>(&grade) 
        << "\tValue : " << grade << "\n";
    char* cptr{ &grade };
    std::cout << "Cptr :" <<  std::hex << std::showbase <<
        "\nAddress : " << reinterpret_cast<unsigned int>(&cptr) <<
        "\nAddress stored in cptr : " << reinterpret_cast<unsigned int>(cptr) <<
        "\nValue stored at the address stored in cptr : " << *cptr << "\n";

    grade = 'B'; //change directly using variable name
    std::cout << "\n\nGrade:\tAddress : " << std::hex <<std::showbase
        << reinterpret_cast<unsigned int>(&grade) 
        << "\tValue : " << grade << "\n";
    std::cout << "Cptr :" <<
        "\nAddress : " << std::hex << reinterpret_cast<unsigned int>(&cptr) <<
        "\nAddress stored in cptr : " << std::hex << reinterpret_cast<unsigned int>(cptr) <<
        "\nValue stored at the address stored in cptr : " << *cptr << "\n";

    *cptr = 'Q'; //change indirectly using pointer variable name
    std::cout << "\n\nGrade:\tAddress : " << std::hex
        << reinterpret_cast<unsigned int>(&grade)
        << "\tValue : " << grade << "\n";
    std::cout << "Cptr :" <<
        "\nAddress : " << std::hex << reinterpret_cast<unsigned int>(&cptr) <<
        "\nAddress stored in cptr : " << std::hex << reinterpret_cast<unsigned int>(cptr) <<
        "\nValue stored at the address stored in cptr : " << *cptr << "\n";
    return;
}

void  multiple_indirection() {
    int age{ 19 };
    std::cout << std::hex << std::showbase;
    
    //Direct access
    std::cout << "Age : \tAddress : " << reinterpret_cast<unsigned int>(&age)
        << std::dec << "\tValue : " << age <<'\n';
   
    //indirect access
    int* iptr{ &age }; /*A Pointer to integer can store address of integer variable */
    std::cout << std::hex << std::showbase;
    std::cout << "\nAddress of pointer iptr " << reinterpret_cast<unsigned int>(&iptr)
        << "\nAddress stored in pointer iptr : " << reinterpret_cast<unsigned int>(iptr)
        << std::dec << "\nValue stored at the address stored in pointer iptr: " << *iptr 
        <<"\n\n";
        
   // int* iptr1{ &iptr };
   /* A Pointer to integer cannot store the address of another pointer to integer*/
   
    /*Pointer to a Pointer can be used to store the address of pointer*/
    int** pp{ &iptr };
    std::cout << std::hex << std::showbase;
    std::cout << "Address of pp : " << reinterpret_cast<unsigned int>(&pp)
        << "\nAddress stored in pp : " << reinterpret_cast<unsigned int>(pp)
        << "\nValue stored at the address stored in pp : " << reinterpret_cast<unsigned int>(*pp)
        << std::dec <<  "\nValue of age : " << (**pp)
        << std::endl << std::endl;


    int*** ppp{ &pp };
    std::cout << std::hex << std::showbase;
    std::cout << "Address of ppp : " << reinterpret_cast<unsigned int>(&ppp)
        << "\nAddress stored in ppp : " << reinterpret_cast<unsigned int>(ppp)
        << "\n 1st level dereference : " << reinterpret_cast<unsigned int>(*ppp)
        << "\n 2nd level dereference : " << reinterpret_cast<unsigned int>(**ppp)
        << std::dec << "\nValue of age : " << (***ppp)
        << std::endl;
}

int foo() {
    return 0;
}

void  generic_pointer() {
    int i{ 10 };
    char c{ 'A' };
    float f{ 5.0F };
    int* ip{ &i };

    void* gp{ nullptr };
    /*generic pointer can store address of any type of variable*/
    gp = &i;
    gp = &c;
    gp = &f;
    /*generic pointer can store address of any type of pointer variable*/
    gp = &ip;
    /*generic pointer can store address of any function*/
    gp = foo;
    
    /*Generic pointer cannot be de-referenced*/

}

void pointer_arithmetics() {
    int i{ 10 };
    std::cout << std::dec << "\nAddress of i : " << reinterpret_cast<unsigned int>(&i) ;
    int* ip{ &i };
    std::cout << std::dec << "\nAddress stored in ip : " << reinterpret_cast<unsigned int>(ip);
    ++ip; //increments by the size of variable to which it is pointing
    std::cout << std::dec << "\nAddress stored in ip : " << reinterpret_cast<unsigned int>(ip);

    /*All arithmetics on pointer are performed in terms of the size of the variable to which it is pointing*/
    ip = ip + 4;
    std::cout << std::dec << "\nAddress stored in ip : " << reinterpret_cast<unsigned int>(ip) ;
    ip = ip - 2;
    std::cout << std::dec << "\nAddress stored in ip : " << reinterpret_cast<unsigned int>(ip) << '\n';
    std::cout << std::dec << "\nValue stored at address stored in ip : " << *ip << '\n'; //undefined

    double d{ 1000.0 };
    std::cout << std::dec << "\nAddress of d : " << reinterpret_cast<unsigned int>(&d) ;
    double* dp{ &d };
    std::cout << std::dec << "\nAddress stored in dp : " << reinterpret_cast<unsigned int>(dp) ;
    ++dp; //increments by the size of variable to which it is pointing
    std::cout << std::dec << "\nAddress stored in dp : " << reinterpret_cast<unsigned int>(dp);
    --dp; //decrements by the size of variable to which it is pointing
    std::cout << std::dec << "\nAddress stored in dp : " << reinterpret_cast<unsigned int>(dp) << '\n';


}


int main()
{
   // size_of_pointers();
   // access_char_data_indirectly();
   // multiple_indirection();
   // generic_pointer();
    pointer_arithmetics();
}
