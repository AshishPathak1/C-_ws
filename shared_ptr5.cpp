#include <iostream>
#include <string>
#include <utility>
#include <xutility>

struct Part { // like processor
	std::string part_name;
	Part() {};
	Part(std::string name) :part_name(name) { 
		std::cout << "Part " << part_name << " is created\n"; 
	}
	~Part() { 
		std::cout << "Part " << part_name << " is destroyed\n"; 
	}
};

struct Whole { //laptop
	Part part;
	std::string whole_name;

	Whole(std::string part_name, std::string whole_name) :whole_name(whole_name), part(part_name) {
		std::cout << "Whole " << whole_name << " is created\n";
	}

	~Whole() { 
		std::cout << "Whole " << whole_name << " is destroyed\n";
		
	}
};

class Car {};
class Truck {};

std::shared_ptr<Car> demo() {
	auto truck_ptr = std::make_shared<Truck>();
	auto car_ptr = std::shared_ptr<Car>(truck_ptr, new Car());
	return car_ptr;
}

std::shared_ptr<Part> safe_way() {
	//referece wp is created on Stack
	//Shared resouce is created on Heap
	auto wp = std::make_shared<Whole>("Component", "Container");
	//Return std::shared_ptr<Part> using aliasing
	//Owning the Whole but pointing to part
	return std::shared_ptr<Part>(wp, &(wp->part) ); //alising ctor
	//The Whole object is not deleted on return
	
}

std::shared_ptr<Part> risky_way() {
	auto wp = std::make_shared<Whole>("Componant", "Container");
	//Return std::shared_ptr<Part> using without using aliasing
	return std::shared_ptr<Part>(&wp->part);
	//The Whole object is deleted on return
}

void need_for_alising_constructor() {
	//failure
	//{
	//	auto pp1 = risky_way(); //dangling shared pointers
	//	std::cout << "using part : " << pp1->part_name << "\n";
	//}
	//Safe
	{
		/*pp2 is a shared_ptr<Part> but manages a Whole object*/
		auto pp2 = safe_way();
		std::cout << "using part : " << pp2->part_name << "\n";
		//'Whole' object is disposed of when this block ends
	}
}

int main() {
	need_for_alising_constructor();
}