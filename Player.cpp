#include "Player.h"
#include <iostream>
#include <string>
#include <stdexcept>
#include <cctype>
#include <algorithm>
#include <cstdlib>
bool Player::is_name_valid(std::string name)
{
	int non_alpha_count = std::count_if(name.begin(), name.end(), //range
		[](unsigned char ch) {return not isalpha(ch); }
	);
	return non_alpha_count == 0;
}
bool Player::is_age_valid(size_t age)
{
	return age >= min_age and age <= max_age;
}

bool Player::is_yob_valid(size_t year)
{
	return year >= min_yob and year <= max_yob;
}

//Player::Player()
//{
//	name = "Madan";
//	year_of_debut = 2020;
//	age = 23;
//}

Player::Player(std::string p_name, size_t p_yob, size_t p_age)
{
	if (not is_name_valid(p_name)) {
		std::cerr << "Name not valid\n";
		std::exit(EXIT_FAILURE);
	}
	name = p_name;

	if (not is_yob_valid(p_yob)) {
		std::cerr << "Year of debut has to be in between " << min_yob << " & " << max_yob << "\n";
		std::exit(EXIT_FAILURE);
	}
	year_of_debut = p_yob;

	if (not is_age_valid(p_age)) {
		std::cerr << "Age should be in the range of " << min_age << " to " << max_age << "\n";
		std::exit(EXIT_FAILURE);
	}
	age = p_age;
}


Player::Player( size_t p_yob, size_t p_age, std::string p_name)
{
	if (not is_name_valid(p_name)) {
		std::cerr << "Name not valid\n";
		std::exit(EXIT_FAILURE);
	}
	name = p_name;

	if (not is_yob_valid(p_yob)) {
		std::cerr << "Year of debut has to be in between " << min_yob << " & " << max_yob << "\n";
		std::exit(EXIT_FAILURE);
	}
	year_of_debut = p_yob;

	if (not is_age_valid(p_age)) {
		std::cerr << "Age should be in the range of " << min_age << " to " << max_age << "\n";
		std::exit(EXIT_FAILURE);
	}
	age = p_age;
}
std::string Player::get_name()
{
	return name;
}

Player::Player(const Player& ref_other)
{
	name = ref_other.name;
	year_of_debut = ref_other.year_of_debut;
	age = ref_other.age;
}

size_t Player::get_year_of_debut()
{
	return year_of_debut;
}

size_t Player::get_age()
{
	return age;
}

void Player::set_name(std::string p_name)
{
	if (is_name_valid(p_name)) {
		name = p_name;
	}
	else {
		std::cerr << "Name contains a character that is not an alphabet\n";
	}

}

void Player::set_age(size_t p_age)
{
	if (not is_age_valid(p_age)) {
		std::cerr << "Age should be in the range of " << min_age <<" to " << max_age << "\n";
		//throw std::runtime_error("Invalid age supplied\n");
	}
	else {
		age = p_age;
	}



}

void Player::set_year_of_debut(size_t yob)
{
	if (is_yob_valid(yob)) {
		year_of_debut = yob;
	}
	else {
		std::cerr << "Year of debut has to be in between " << min_yob << " & " << max_yob << "\n";
	}
}

void Player::print_player_details() const
{
	std::cout << "Name          : " << name << '\n';
	std::cout << "Year of debut : " << year_of_debut << '\n';
	std::cout << "Age           : " << age << "\n\n";
}

