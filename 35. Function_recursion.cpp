// 35. Function_recursion.cpp 

#include <iostream>

void print_ascending(int limit);
void print_ascending_rec(int limit);
void print_descending(int limit);
void print_descending_rec(int limit);
void print_digits(int number);
void print_digits_rec(int number);
int sum_of_digits(int number);
int sum_of_digits_rec(int number);
int reverse_rec(int number);
long long int factorial_rec(int number);
int main()
{
    int number{ 256 };
    print_ascending(5000);
    print_ascending_rec(number);
    print_descending(number);
    std::cout << "Integers in the range of 1 to " << number << " in descending order are \n";
    print_descending_rec(number);
    std::cout << "Digits of " << number << " are as follows \n";
    print_digits(number);
    print_digits_rec(number);
    std::cout << "Sum of Digits of " << number << " are :"  << sum_of_digits(number) <<'\n';
    std::cout << "Sum of Digits of " << number << " are :" << sum_of_digits_rec(number) << '\n';
    return 0;
}


void print_ascending(int limit) {
    std::cout << "Integers in the range of 1 to " << limit << " in ascending order are \n";
    for (int i = 1; i <= limit; ++i) {
        std::cout << i << '\n';
    }
    /*int i = 1;
    while(i <= limit) {
        std::cout << i++ << '\n';
    }*/
}

void print_ascending_rec(int limit) {
    if (limit > 1) {
        print_ascending_rec(limit - 1);
    }
    std::cout << limit << '\n';
    return;
}

void print_descending(int limit) {
    std::cout << "Integers in the range of 1 to " << limit << " in descending order are \n";

    while (limit > 0) {
        std::cout << limit-- << '\n';
    }
    return;
}

void print_descending_rec(int limit) {
    if (limit > 0) {
        std::cout << limit << '\n';
        print_descending_rec(limit - 1);
    }
    return;
}

void print_digits(int number) {
    while (number != 0) {
        std::cout << (number % 10) << '\n';
        number = number / 10;
    }
    return;
}

void print_digits_rec(int number) {
    if(number != 0) {
        std::cout << (number % 10) << '\n';
        print_digits_rec(number / 10);
    }
    return;
}

int sum_of_digits(int number) {
    int sum{ 0 };
    int digit{};
    while (number != 0) {
        digit = (number % 10);
        sum = sum + digit;
        number = number / 10;
    }
    return sum;
}

int sum_of_digits_rec(int number) {
    int digit{0};
    if (number != 0) {
        digit = (number % 10);
        return digit + sum_of_digits_rec(number / 10);
    }
    return digit;
}