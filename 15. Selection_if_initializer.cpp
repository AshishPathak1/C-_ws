// 15. Selection_if_initializer.cpp : if with initializer
//language feature 'init-statements in if/switch' requires compiler flag '/std:c++17'	


/*
The cricket referee puts the toss. if its head then Rohit decides and 
if its Tail than Edgar decides
*/

#include <iostream>
#include <random>
#include <ctime>

void toss_example1()
{
	constexpr int head{ 1 };

	std::srand(std::time(nullptr)); //Initialize the Random Number generator

	if (int toss = std::rand(); (toss % 2) == head) {
		std::cout << "The Indian Captain takes the call\n";
	}
	else {
		std::cout << "The South African Captain takes the call\n";
	}
	return;
}

bool is_toss_head() {
	std::srand(std::time(nullptr)); //Initialize the Random Number generator
	return static_cast<bool>(std::rand()%2);
}

void toss_example2()
{
	if (is_toss_head()) { //better
	
		std::cout << "The Indian Captain takes the call\n";
	}
	else {
		std::cout << "The South African Captain takes the call\n";
	}
	return;
}


int main()
{
	//toss_example1();
	toss_example2();
}
