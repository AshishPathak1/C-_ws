// 12. IO_cin_cout.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdio>
#include <fstream>

void using_lib_function() {
	char name[10];
	std::printf("Please enter your name : ");
	scanf_s("%9s",name,sizeof(name));  //safe
	//std::scanf("%9s", name);  //unsafe
	std::printf("Welcome %s\n", name);
	
	int roll{};
	std::printf("Please enter your roll Number : ");
	scanf_s("%i", &roll);
	//std::scanf("%d", &roll);
	std::printf("your roll number is %d\n", roll);

	float per{};
	std::printf("Please enter your Percentage : ");
	scanf_s("%f", &per);
	//scanf("%f", &per);

	std::printf("%s with roll Number %d has scored %.2f percentage marks", name, roll, per);

	/*unsigned long long int mobile_no{};
	std::printf("Please enter your Mobile number : ");
	scanf_s("%ulld", &mobile_no, sizeof(mobile_no));
	std::printf("Mobile number is %ulld", mobile_no);

	long double earth_radius{};
	std::printf("Guess the diameter of earth in cm ? : ");
	scanf_s("%Lf", &earth_radius, sizeof(earth_radius));
	std::printf("Earth radius = %Lf\n", earth_radius);*/
	return;
}

int using_cin_cout() {
	int in1{};
	std::cout << "Enter a Integer : ";
	std::cin >> in1;
	//std::cin.operator >> (in1);
	std::cout << "The Integer is :";
	std::cout << in1 << "\n\n";
	//std::cout.operator <<(in1);

	float fn1{};
	std::cout << "Enter a Float : ";
	std::cin >> fn1;
	std::cout << "The Float is :" << fn1 << "\n\n";

	double dn1{};
	std::cout << "Enter a Double : ";
	std::cin >> dn1;
	std::cout << "The Double is :" << dn1 << "\n\n";

	long long int ln1{};
	std::cout << "Enter a Long Long Integer : ";
	std::cin >> ln1;
	std::cout << "The Long Long Integer is :" << ln1 << "\n\n";

	std::string str{};
	std::cout << "Enter a String : ";
	std::cin >> str;
	std::cout << "The String is :" << str << "\n\n";

	return 0;
}

int buffer() {
	std::ofstream myfile{ "d:\\data.txt" };
	myfile << "Hello";
	myfile << "Hi";
	myfile << "Bye";
	myfile.close();

	return 0;
}


void buffered_stream() {
	std::cout << "Harsh";
	std::cout << "Rahul";
	std::cout << "Viraj";
	std::cout.flush();
}

int main()
{
	//using_lib_function();
	//using_cin_cout();
	buffered_stream();
	//buffer();
}
