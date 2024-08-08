// Constant_cast.cpp : constant_cast
//

#include <iostream>
#include <cstdlib>
#include <cctype>

void stringfun(char* const ptr)
{
    ptr[0] = std::toupper(ptr[0]);
    std::cout << "The string in title case is : " << ptr << std::endl;
    return;
}

int main()
{
    {
        char str[10] = "hello"; //C-style string : ntbs
        std::cout << "Original Non constant array: " << str << std::endl;
        stringfun(str);
        std::cout << "After Function Call : " << str << std::endl;
    }
    
    {
       //C-string literal is const i.e. "const char*" is passed
        //stringfun("baby");

        const char str[10] = "baby";
       //stringfun(str);
       // str[0] = 'L'; // Error
    }

    {
        const char str[10] = "baby";
        std::cout << "Original constant string :" << str << std::endl;
        stringfun(const_cast<char*> (str)); //Removes the constant - ness of the string
        std::cout << "After Function Call :" << str << std::endl;
    }

    {
        const int i{ 10 };
        const int* ptr1; //non-const pointer pointing to const int
        ptr1 = &i;

        int* ptr2; //	non-const pointer pointing to non-const 
        //ptr2 = &i; //invalid conversion
        std::cout << "i = " << i << '\n';
        ptr2 = const_cast<int*> (&i); //removing constantness
        *ptr2 = 100;
        std::cout << "i = " << *ptr2 << '\t' << i << '\n';
        //
        //    ptr2 = (int*)&i;
        const float x{ 9.5F };
        //  ptr2 = (int*) (&x); // C style
        //  ptr2 = const_cast<int*> (&x);
        //  int k = const_cast<int> (x);
        int k = static_cast<int> (x);
    }
    return 0;
}
