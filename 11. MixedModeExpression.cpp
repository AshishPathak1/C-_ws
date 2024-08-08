// 11. MixedModeExpression.cpp : This file contains the 'main' function. Program execution begins and ends there.

//

#include <iostream>
#include <climits>
#include <typeinfo>
void  add_two_integers() {
    
    int num1{};
    std::cout << "Enter the first Integer : ";
    std::cin >> num1;
    
    int num2{};
    std::cout << "Enter the Second Integer : ";
    std::cin >> num2;

    long long int sum{};
   
    sum = static_cast<long long>(num1) + num2;
    
    std::cout  << num1 << " + " << num2 << " = " << sum << "\n";

   // Conversion is not permanant
    std::cout << "Type of num1 : " << typeid(num1).name() << "\n";
    //typeid operator: Queries information of a type.
    return;
}

void implicit_conversion() {
    //case 1
    {
        int a{ 10 };
        int b{ 3 };
        int c{ 0 };
        c = a / b;
        /*
            c  = a  / b
               = int / int
            c  = int
        */
        std::cout << a << " / " << b << " = " << c << "\n";
    }

    //case 2
    {
        int a{ 10 };
        int b{ 3 };
        float c{ 0 };
        c = a / b; //implicit conversion of result (3) to float (3.0f)
          /*
            c  = a  /  b
               = int / int  : 10 / 3
            c  = int        :  3
            implicit casting(conversion); 3 of type int is converted to float 3.0f
            c = 3.0f
        */
        std::cout << std::showpoint;
        std::cout << a << " / " << b << " = " << c << "\n";
    }

    //case 3
    {
        float a{ 7.0F };
        float b{ 2.0f };
        int c{ 0 };
        c = a / b; //implicit conversion of result (3.0f) to int (3)
          /*
            c  = a  / b
               = float / float  : 7.0f / 2.0f
            c  = float          :  3.5f
            implicit casting(conversion); 3.5f of type float is converted to int 3
            c = 3
        */
        std::cout << std::showpoint;
        std::cout << a << "  / " << b << " = " << c << "\n";
    }

}


void  mixed_mode_expression() {
    //case1
    {
        int a{ 7 };
        float b{ 2.0f };
        float c{ 0 };

        c = a / b; //Mixed mode expression : Operands are of different type
        /*  (promotion: All opearnds in the expression are converted upto the size of the largest operand)
         c = a / b;
         c = int / float     7 / 2.0f
           = float / float   7.0f / 2.0f    (promotion)
           = float           3.5f
        */
        std::cout << std::showpoint;
        std::cout << a << "  / " << b << " = " << c << "\n";
    }

    //case 2
    {
        double a{ 7.0 };
        int b{ 2 };
        int c{ 0 };
        std::cout << std::showpoint;
        c = a / b; //Mixed mode expression : Operands are of different type
        /*  (promotion: All opearnds in the expression are converted upto the size of the largest operand)
         c      = a / b;
         c      = double / int      7.0 / 2      (mixed mode)
                = double / double   7.0 / 2.0    (promotion)
         int c  = double            3.5         
             c  = int               3            (implicit conversion)
        */
        std::cout << a << "  / " << b << " = " << c << "\n";
    }
}


void explicit_conversion() {
    //case1
    {
        int a{ 7 };
        int b{ 2 };
        float c{ 0 };

        std::cout << std::showpoint;
        c = a / b;
        /*
        * The result of the expression which in int is implicitely converted to float
        * Refer to case 2 in implicit_conversion()
        */
        std::cout << a << "  / " << b << " = " << c << "\n";

        /*Explicit Conversion of operand 'a' to type float*/
        c = static_cast<float>(a) / b;
        /*
        *   c = static_cast<float>(int) / int;  : Explicit conversion    static_cast<float>(7) / 2;
        *       float / int     (mixed mode expr)                                           7.0f / 2
        *       float / float   (promotion)                                                 7.0f / 2.0f
        *       float                                                                       3.5f
        */
        std::cout << a << "  / " << b << " = " << c << "\n";
    }

    //case 2 : incorrect way of explicit casting
    {
        int a{ 7 };
        int b{ 2 };
        float c{ 0 };

        std::cout << std::showpoint;
       /*Explicit Conversion of result of expr (a/b) to type float*/
        c = static_cast<float> ( a / b );
        /*
        *   c = static_cast<float> (int / int);  
        *       static_cast<float> (int / int)     static_cast<float>( 7 / 2)
        *       static_cast<float> (int)           static_cast<float>( 3 )
        *       float                              3.0f
        */
        std::cout << a << "  / " << b << " = " << c << "\n";
    }
}

int main()
{
    add_two_integers();
    //implicit_conversion();
    //mixed_mode_expression();
    //explicit_conversion();
}
