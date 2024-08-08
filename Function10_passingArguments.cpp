// Function10_passingArguments.cpp : This file contains the 'main' function. Program execution begins and ends there.



#include <iostream>
#include <cstdlib>
/*
* Pass-by-Value
In C/C++, by default, arguments are passed into functions by value
(except arrays which is treated as pointers).
That is, a clone copy of the argument is made and passed into the function.
Changes to the clone copy inside the function has no effect to the original
argument in the caller. In other words, the called function has no access
to the variables in the caller.
Changes made to formal arguments do not affect the actual arguments
*/
int square(int);
void swap(int, int);

/*
* Pass-by-Reference with Pointer Arguments
In many situations, we may wish to modify the original copy directly
(especially in passing huge object or array) to avoid the overhead of cloning.
This can be done by passing a pointer of the object into the function,
known as pass-by-reference.
*/
void square(int*);
void swap(int*, int*);

void firstExample();
void secondExample();


int main()
{
    // firstExample();
     secondExample();
  
    return EXIT_SUCCESS;
}

void firstExample() {
    //Case-I
    std::cout << "Call by Value\n";
    int number{ 8 }; //local variable
    std::cout << std::hex << std::showbase;
    std::cout << "In Calling Routine: Address of number: " 
        << reinterpret_cast<unsigned int>( &number) << std::endl;  // 0x22ff1c
    std::cout << std::dec << std::showbase;
    std::cout << "In Calling Routine: Value of number  : " << number << std::endl;    // 8
    // number in the next call is the actual argument
    std::cout << "In Calling Routine: " << square(number) << std::endl; // 64
    std::cout << "In Calling Routine: Value of number  :" << number << std::endl;    // 8 - no change

    //Case-II
    std::cout << "Call by Reference\n";
    number = 8;
    std::cout << std::hex << std::showbase;
    std::cout << "In Calling Routine: Address of number:"  
        << reinterpret_cast<unsigned int>(&number) << std::endl;
    std::cout << std::dec << std::showbase;
    std::cout << "In Calling Routine: Value of number  : " << number << std::endl;   // 8
    square(&number);          // Explicit referencing to pass an address
    std::cout << "In Calling Routine: Value of number  : " << number << std::endl;   // 64
    return;
}

void secondExample() {
    int i1n{ 10 };
    int i2n{ 20 };
    std::cout << "(In Calling Routine) i1n : " << i1n << "\ti2n : " << i2n << std::endl;
    swap(i1n, i2n); //Call by Value
    std::cout << "(In Calling Routine) i1n : " << i1n << "\ti2n : " << i2n << std::endl;
    swap(&i1n, &i2n); //Call by reference using pointer
    std::cout << "(In Calling Routine) i1n : " << i1n << "\ti2n : " << i2n << std::endl;
    return;
}

/* 'number' over here is the formal argument(parameter); they receive the value of the
actual argument */
int square(int number) {  // non-const
    std::cout << std::hex << std::showbase;
    std::cout << "In square(): Address of number: " 
        << reinterpret_cast<unsigned int>(&number) << std::endl;    // 0x22ff00
    std::cout << std::dec << std::showbase;
    std::cout << "In square(): Value of number  :" << number << std::endl;
    number *= number;           // clone modified inside the function
    std::cout << "In square(): Value of number  :" << number << std::endl;
    return number;
}


/* 'pNumber' over here is the formal argument(parameter); they receive the address of the
actual argument */
void square(int* pNumber) {  // Function takes an int pointer (non-const)
    std::cout << std::hex << std::showbase;
    std::cout << "In square(): Address of number: " 
        << reinterpret_cast<unsigned int>(pNumber) << std::endl;  // 0x22ff00
    std::cout << std::dec << std::showbase;
    std::cout << "In square(): Value of number  :" << *pNumber << std::endl;
    *pNumber = (*pNumber) * (*pNumber);      // Explicit de-referencing to get the value pointed-to
    std::cout << "In square(): Value of number  :" << *pNumber << std::endl;
}

void swap(int i1n, int i2n) {
    int itemp{ i1n };
    i1n = i2n;
    i2n = itemp;
    std::cout << "(In Called Routine)  i1n : " << i1n << "  i2n : " << i2n << std::endl;
    return;
}


void swap(int* iptr1, int* iptr2) {
    /*Pointers can manipulate the the value of the variables whose address they store*/
    int itemp{ *iptr1 };
    *iptr1 = *iptr2;
    *iptr2 = itemp;
    std::cout << "(In Called Routine)  i1n : " << *iptr1 << "  i2n : " << *iptr2 << std::endl;
    return;
}

