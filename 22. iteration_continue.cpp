// 22. iteration_continue.cpp : continue statement
// When it is encountered in the loop the subsequent statements 
// in the loop are skipped and the contorl is transferred to the conditional statement
// Causes the remaining portion of the enclosing for, range-for, while or do-while loop body to be skipped.

#include <iostream>

//while (test) {
//    // ... 
//    continue; // acts as goto contin;
//    // ...
//    statements;
//}

void while_continue_demo() {
    int i{ 0 };
    while ( i < 10) {
        ++i;
        if (i == 5) {
            continue;
        }
        std::cout << i << "\n";
    }
}




//do {
//    // ...
//    continue; // acts as goto contin;
//    // ...
//    contin:;
//} while (/* ... */);

/*Accept and alphabet and toggle its case. Continue till user enters 'z' */
void  do_while_continue_demo() {
    char ch{};
    do {
        std::cout << "Please enter a Alphabet : ";
        std::cin >> ch;
        if (not isalpha(ch)) {
            continue;
        }

        if (std::isupper(ch)) {
            std::cout << "The character is : " << static_cast<char>(std::tolower(ch)) << "\n";
        }
        else {
            std::cout << "The character is : " << static_cast<char>(std::toupper(ch)) << "\n";
        }

    } while (std::toupper(ch) != 'Z');
}

int main()
{
  //   while_continue_demo();
    do_while_continue_demo();
}
