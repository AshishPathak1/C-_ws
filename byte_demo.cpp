// 30. byte_demo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <iterator>
#include <bitset>
void initializing_bytes() {
	std::byte b1{};
	std::cout << "Value of b1 : " << std::to_integer<int>(b1) << '\n';

	std::byte b2{ 100 };
	std::cout << "Value of b2 : " << std::to_integer<int>(b2) << '\n';

	//'initializing': cannot convert from 'int' to 'std::byte'	
	char ch = 97; //'a';
	//std::byte b3 =  100;
	//std::byte b3 (100);
	std::byte b3{ 100 };
	//initialization requires a narrowing conversion from 'int' to 'unsigned char'	
	//std::byte b0{ 1000 };

	std::byte b4{ 255 }; //largest value that can be used ot initialized byte
	std::cout << "Value of b4 : " << std::to_integer<int>(b4) << '\n';

	//initialization requires a narrowing conversion from 'int' to 'unsigned char'
	//std::byte b4_{ -5};

	std::byte b5{ 0 }; //smallest possible value
	std::cout << "Value of b5: " << std::to_integer<int>(b5) << '\n';

	std::byte b6{ 0b01100100 }; 
	std::cout << "Value of b6 : " << std::to_integer<int>(b6) << '\n';

	std::byte b7{ 0b01'10'00'00 }; //initializer is binary literal
	std::cout << "Value of b7 : " << std::to_integer<int>(b7) << '\n';

	std::byte b8{ 0x64 }; //initializer is hex literal
	std::cout << "Value of b8 : " << std::to_integer<int>(b8) << '\n';

	std::byte b9{ 0144 }; //initializer is oct literal
	std::cout << "Value of b9 : " << std::to_integer<int>(b9) << '\n';

	std::cout << "Size of single byte : " << sizeof(b9) << " bytes\n";
	std::byte arr[100];
	std::cout << "Size of single byte : " << std::size(arr) << " elements\n";

}

void   byte_operation() {
	std::byte b1{ 100 };
	std::cout << "Value of b1 : " << std::to_integer<int>(b1) << '\n';
	b1 <<= 1; // b1 = b1 << 1; 50
	std::cout << "Value of b1 <<= 1 : " << std::to_integer<int>(b1) << '\n';
	b1 >>= 2; // b1 = b1 >> 2
	std::cout << "Value of b1 >>= 2 : " << std::to_integer<int>(b1) << '\n';
	std::cout << "Value of b1 >>= 2 : " << std::bitset<8>(std::to_integer<int>(b1)) << '\n';
	std::byte b2 = ~b1;
	std::cout << "Value of b2 = ~b1 : " << std::bitset<8>(std::to_integer<int>(b2)) << '\n';
	std::cout << "Value of b1  : " << std::to_integer<int>(b1) << '\n';
	std::cout << "Value of b1  : " << std::bitset<8>(std::to_integer<int>(b1)) << '\n';
	b1 = b1 | std::byte{ 4 };
	std::cout << "Value of b1  : " << std::to_integer<int>(b1) << '\n';
	std::cout << "Value of b1  : " << std::bitset<8>(std::to_integer<int>(b1)) << '\n';
	b1 = b1 & std::byte{16 };
	std::cout << "Value of b1  : " << std::to_integer<int>(b1) << '\n';
	std::cout << "Value of b1  : " << std::bitset<8>(std::to_integer<int>(b1)) << '\n';
//	b1 = b1 * b2;
//	b1 = b1 + b2;
}


int main()
{
	//initializing_bytes();
	byte_operation();

}
