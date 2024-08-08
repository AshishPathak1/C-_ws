// EnumType.cpp : unscoped enum
//

#include <iostream>
#include <thread>
#include <chrono>
#include <string_view>
#include <string>
using namespace std::literals;

void enumBasic() {

	enum TrafficLight
	{
		green,
		yellow,
		red,
	};

	TrafficLight trafficlight{ red };

	// Checking some stuff
	if (trafficlight == TrafficLight::green)
		std::cout << "Traffic light is green! You may proceed" << std::endl;
	if (trafficlight == TrafficLight::yellow)
		std::cout << "Traffic light is yellow! Go slow" << std::endl;
	if (trafficlight == TrafficLight::red)
		std::cout << "Traffic light is red! Please Stop" << std::endl;
	// not recommended. Always prefix the enumerator with the enumeration type
	if (trafficlight == red)
		std::cout << "Traffic light is red! Please Stop" << std::endl;

	constexpr int PINK{ 5 };
	//trafficlight = PINK;
}




void enumNeed()
{
	std::cout << "Std Code of my city : " << 84 << std::endl;
	constexpr unsigned int HYDERABAD_STD_CODE{ 84 };
	//HYDERABAD_STD_CODE = 48;
	std::cout << "Std Code of my city : " << HYDERABAD_STD_CODE << std::endl;
	static constexpr unsigned AKURDI{ 411035 };
	static constexpr unsigned CHINCHWAD{ 411018 };
	static constexpr unsigned PUNE{ 411004 };
	//static constexpr unsigned PUNE{ 22 };
	unsigned pincode = AKURDI;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = CHINCHWAD;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = PUNE;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = 888565656;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
	pincode = HYDERABAD_STD_CODE;
	std::cout << "Pincode Code of my city : " << pincode << std::endl;
}

void enumDeclaration() {
	/*Create a type that can be assigned values only in the specified range*/
	enum Pincode {  //Declaration of enum type
		akurdi		= 411035,
		nigdi		= 411044,
		bhosari		= 411027,
		chinchwad	= 411018,
	};

	enum Pincode my_city_pincode {akurdi};

	Pincode citycode; //defining a variable of enum type
	std::cout << "Size of enum type PINCODE :" << sizeof(citycode) << " bytes " << std::endl;
	citycode = akurdi;
	std::cout << "Pincode Code : " << citycode << std::endl;
	citycode = bhosari;
	std::cout << "Pincode Code : " << citycode << std::endl;
	/* CityCode can be assigned values specified in the enumeration only*/
	//constexpr unsigned HYDERABAD_STD_CODE{ 84 };
	//citycode = HYDERABAD_STD_CODE;
	//citycode = 411035;
	//citycode = static_cast<Pincode>(4110350);
	return;
}



int main()
{
	//enumNeed();
	//enumDeclaration();
	//enumBasic();

	std::this_thread::sleep_for(std::chrono::seconds(5));
}
