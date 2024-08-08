#pragma once
#include <string>

class Player
{
private:
	static constexpr size_t max_age{ 70 };
	static constexpr size_t min_age{ 18 };
	static constexpr size_t min_yob{ 1990 };
	static constexpr size_t max_yob{ 2022 };

	std::string name;
	size_t year_of_debut;
	size_t age;

	bool is_name_valid(std::string);
	bool is_age_valid(size_t age);
	bool is_yob_valid(size_t year);
public:
	/* Default constructor : Parameterless*/
	//Player();

	/* Default Parameterized constructor*/
	Player(std::string p_name ="Priya", size_t yob = min_yob, size_t age = min_age);

	/* Parameterized constructor*/
	Player( size_t yob, size_t age, std::string p_name);

	/* Copy constructor*/
	Player(const Player& ref);

	/* Returns the name of the player*/
	std::string get_name();

	/* Returns the year of debut of the player*/
	size_t get_year_of_debut();

	/* Returns the age of the player*/
	size_t get_age();

	/* Sets the name of the player*/
	void set_name(std::string name);

	/* Sets the Age of the player*/
	void set_age(size_t age);

	/* Sets the Year of Debut of the player*/
	void set_year_of_debut(size_t yob);

	void print_player_details() const;
};

class A {
private:
	int data;
public:
	/*Parameterized constructor*/
	A(int value) {
		data = value;
	}
	/*forces the compiler to provide the default constructor
	Defaulted default constructor: the compiler will define 
	the implicit default constructor even if other constructors are present.*/
	A() = default;
	
};


class B {
private:
	int data;
public:
	/*Deleted default constructor: if it is selected by overload resolution, the program fails to compile.*/
	B() = delete;

	B(int value) {
		data = value;
	}
};