// 34. Function_inline_macro.cpp :
//

#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>
#include <string>
using namespace std::literals;
//expressions passed as arguments to macros can be evaluated more than once.
#define maximum(n1,n2) (n1 > n2)?n1:n2
#define sqr(x) (x * x)
#define STARS_LINE "***********************"
#define print_int_thrice(x) std::cout << x << " " << x << " " <<x <<"\n";

int minimum(int n1, int n2) {
    return (n1 < n2) ? n1 : n2;
}
//type safety
inline void print_int_twice(int x) {
    std::cout << x << " " << x << "\n";
}

void print_data(int var) {
    std::cout << "In Print_data function : " << var << '\n';
    //   std::cout << "In Print_data function : " << i1n << '\n'; // 'i1n' : undeclared identifier
#define AGE_LIMIT 60 
    std::cout << "In Print_data function AGE_LIMIT: " << AGE_LIMIT << '\n';
}

int main()
{
    int i1n{ 10 };
    int i2n{ 20 };
    int maxx = maximum(i1n, i2n);
    std::cout << "Maximum of " << i1n << " & " << i2n << " is " << maxx << '\n';
    maxx = maximum(++i1n, ++i2n);
    std::cout << "Maximum of " << i1n << " & " << i2n << " is " << maxx << '\n';

    std::cout << STARS_LINE << std::endl;
    i1n = 10;
    std::cout << "Square of " << i1n << " = " << sqr(i1n) << '\n';
    std::cout << "Square of " << i1n + 5 << " = " << sqr((i1n + 5)) << '\n';
    std::cout << "Square of " << i1n + 5 << " = " << sqr(i1n + 5) << '\n';

    std::cout << STARS_LINE << std::endl;

    print_data(i1n);

    //  std::cout << "In Print_data function : " << var << '\n'; //	'var': undeclared identifier	

    std::cout << "In Main function AGE_LIMIT: " << AGE_LIMIT << '\n';
    //no type checking for macro
    print_int_thrice(100);
    print_int_thrice("Hrishi"s);
    //strict type checking for functions
    print_int_twice(100);
    print_int_twice("Hrishi"s);


    i1n = 10;
    i2n = 20;
    std::cout << "Minimum of " << i1n << " & " << i2n << " is " << minimum(++i1n, ++i2n) << '\n';
    return EXIT_SUCCESS;
}
