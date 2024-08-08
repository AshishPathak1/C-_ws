// 51._Class_Ctor_Dtor.cpp : 
// Understand the role of constructor

#include <iostream>
#include <string>
#include "Player.h"
#include "Box.h"
#include "X.h"
#include "Product.h"
#include "Person.h"

using namespace std::literals;

void default_ctors() {
	Player p1;
	p1.print_player_details();
	Player p2;
	p2.print_player_details();
}


void parameterized_ctor() {
	{
		Player p("Gagan"s, 2018, 25);
		p.print_player_details();
	}
	{
		Player p("Gagan"s, 2018);
		p.print_player_details();
	}
	{
		Player p("Gagan"s);
		p.print_player_details();
	}
	{
		Player p;
		p.print_player_details();
	}
	{
		Player p( 2018, 25, "Gagan"s);
		p.print_player_details();
	}
}

void copy_constructor() {
	//Box b1; default ctor is deleted
	Box b1(100, 50, 20, "red"s);
	std::cout << b1.get_box_dimensions() << "\n";

	Box b2(b1);
	std::cout << b2.get_box_dimensions() << "\n";

	/*Player p1("Karan"s,2000,40);
	std::cout << "Player 1 details : \n";
	p1.print_player_details();

	Player p2(p1);
	std::cout << "Player 2 details : \n";
	p2.print_player_details();

	std::cout << "Address of player 1 " << &p1 << '\n';
	std::cout << "Address of player 2 " << &p2 << '\n';

	p1.set_age(50);
	std::cout << "Player 1 details : \n";
	p1.print_player_details();
	std::cout << "Player 2 details : \n";
	p2.print_player_details();*/
}

void forcing_compiler_for_default_ctor() {
	/*Parameterized Ctor supplied by developer*/
	A obj1(10);
	/*default ctor supplied by compiler*/
	A obj2;

}

void restricting_compiler_from_providing_default_ctor() {
	B b_obj1(10);
//	B b_obj2; //Forcefully delete the default ctor
}

void move_ctor() {
	try {
		/*the default constructor of "Box" cannot be referenced -- 	it is a deleted function	*/
		//Box box1;

		Box box2(10.2F, 20.5F, 15.0F,"red"s); // Parameterized ctor accepting three parameters (Dimension of Box)

		std::cout <<  "Box 2 : \n\t" << box2.get_box_dimensions();

		Box box3(box2); //copy constructor

		std::cout << "Box 2 : \n\t" << box2.get_box_dimensions();
		std::cout << "Box 3 : \n\t" << box3.get_box_dimensions();

		Box box4(std::move(box2)); //move ctor
		//std::cout << "Box 2 : \n" << box2.get_box_dimensions(); //undefined
		std::cout << "Box 4 : \n\t" << box4.get_box_dimensions();


	}
	catch (const std::exception& e) {
		std::cout << e.what() << '\n';
	}
}


void converting_constructor(){
	X x_obj1;			// Compiler supplied default ctor
	X x_obj2(x_obj1);	// Compiler supplied Copy ctor
	X x_obj3(std::move(x_obj2));  // Compiler supplied Move ctor
	
	x_obj1 = x_obj3;	//Compiler supplied overloaded operator =()
	//  x_obj1.operator=(x_obj3);  /* operand1 becomes invoking object and operand2 becomes argument

	X x_obj4(1);
	X x_obj5 = 1;   // int (copy initialization is allowed)
	//X x_obj6 = 2.5; // double 
	//X x_obj7 = 2.5F;//float
	//X x_obj8 = 'A';//char
	X x_obj9 = (int)2.5;
	X x_obj10 = static_cast<int>(2.5);
	
	Y y_obj1(10);   //parameterized ctor is called : direct-initialization selects Y::Y(int)
	//Y y_obj2 = 10;  //error: copy-initialization does not consider Y::Y(int)
	Y y_obj2 = (Y)10;   //Explicit conversion is allowed
	Y y_obj3 = static_cast<Y>(10); //Explicit conversion is allowed

	foo(y_obj1);
	//foo(45); //error
	foo(Y(445));
	foo((Y)555);
	foo(static_cast<Y>(10));
}

void delegating_constructors() {
	Product p1;
	p1.print_details();
	
	Product p2("Ball pen"s);
	p2.print_details();
	
	Product p3(150.5F);
	p3.print_details();

	Product p4("Marker"s, 130.0F);
	p4.print_details();
}

void member_initialization_list() {
	Person p1;
	p1.print_details();
	Person p2("Kalia"s, "AB+", 56565656);
	p2.print_details();
	Person p3("Leela", "O+", 6565656);
	p3.print_details();
}

//Person gper("Gagan"s, "AB+",345643453);
int main()
{
	
	//default_ctors();
	//parameterized_ctor();
	//copy_constructor();
	//forcing_compiler_for_default_ctor();
	//restricting_compiler_from_providing_default_ctor();
	//move_ctor();
	//converting_constructor();
	//delegating_constructors();
	member_initialization_list();
	//std::cout << "Returning from main\n";
}
