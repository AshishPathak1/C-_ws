// 34. Function_inline_macro.cpp :
/*
to check if inlining has happend or failed

g++ -Winline -O1 <program.cpp>
*/
#include <iostream>
#include <cctype>
#include <limits>
#include <cstdlib>

inline  int square(int x) {
    return x * x;
}

inline char toggle(char ch) {
    if (isalpha(ch)) {
        if (isupper(ch)) {
            return static_cast<char>(tolower(ch));
        }
        else {
            return static_cast<char>(toupper(ch));
        }
    }
    return ch;
}

inline char get_alphabet(void) {
    char alpha{};
    while (true) {
        std::cout << "Please enter an alphabet : ";
        std::cin >> alpha;
        if (std::cin.fail()) {
            //clear the cin status flag
            std::cin.clear();
            //clears the input stream
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Last Input operation failed!\n";
        }
        else {
            if (isalpha(alpha)) {
                return alpha;
            }
            else {
                std::cerr << "Entered character is not a alphabet\n";
            }
        }
    }
}


int main()
{
    char alpha{};
    alpha = get_alphabet() ;
    alpha = toggle(alpha);
    std::cout << "The toggled character is " << alpha << '\n';
    std::cout << "Square of 5 = " << square(5) << std::endl;
    return EXIT_SUCCESS;
}
