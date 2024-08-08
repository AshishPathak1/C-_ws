/*Use of references make the syntax clearer*/
#include <iostream>

//using pointer

void decrease(int* ptr) {
    *ptr = *ptr - 5;
}

// using reference

void increase(int& ref) { //int &ref = x;
    ref = ref + 5;
}

int main() {
    int x = 10;

    decrease(&x); // passed as address
    std::cout << "After decreasing : " << x << std::endl;   //5

    increase(x); // passed as reference
    std::cout << "After increasing : " << x << std::endl; // prints 10

    return EXIT_SUCCESS;
}

