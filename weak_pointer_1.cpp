
/* Comparison of std::shared_ptr and std::weak_ptr as
returned values from functions. Also, demo
of testing for expired object.
*/

#include <iostream>
#include <memory>


class Thing {
public:
	Thing() : id(++object_counter) {
		std::cout << "Thing " << id << " created" << std::endl;
	}
	~Thing() {
		std::cout << "Thing " << id << " destroyed" << std::endl;
	}
	int get_thing() const {
		return id;
	}
private:
	int id;	//instance data
	static int object_counter;   //class data
};

int Thing::object_counter{ 0 };


// create a Thing, but return a std::weak_ptr to it - gets destructed
std::weak_ptr<Thing> weak()
{
	auto sp = std::make_shared<Thing>();

	std::cout << "in weak(): Thing " << sp->get_thing() << std::endl;

	std::weak_ptr<Thing> wp(sp);
	return wp; //but sp goes out of scope; resulting in destroying the Thing
}


// check the std::weak_ptr to see if the Thing is still there,
// in two different ways
void is_it_there(std::weak_ptr<Thing> wp)
{
	//	checks whether the referenced object was already deleted
	if (wp.expired()) {
		std::cout << "it is expired" << std::endl;
	}
	else {
		std::cout << "it is not expired" << std::endl;
	}

	std::shared_ptr<Thing> p = wp.lock(); //creates a shared_ptr that manages the referenced object
	if (!p) {
		std::cout << "it is gone!" << std::endl;
	}
	else {
		std::cout << "it is Thing " << p->get_thing() << std::endl;
	}
}


// create a Thing, but return a std::shared_ptr to it
std::shared_ptr<Thing> shared()
{
	auto sp = std::make_shared<Thing>();

	std::cout << "in shared(): Thing " << sp->get_thing() << std::endl;

	return sp;
}


void weak_ptr_basic_concept() {
	auto sp = std::make_shared<Thing>();

	std::cout << "in main: Thing used " << sp->get_thing() << std::endl;

	std::weak_ptr<Thing> wp1 = weak();
	is_it_there(wp1);

	sp = shared();
	std::weak_ptr<Thing> wp2(sp);
	is_it_there(wp2);
}


/*Weak_ptr with primitive data*/
void weak_ptr_operations_primitive_type() {

	std::cout << std::boolalpha << std::endl;
	//Create a shared ptr
	auto sharedPtr1 = std::make_shared<int>(2021);

	//std::weak_ptr which borrows the resource from the std::shared_ptr
	std::weak_ptr<int> weakPtr{ sharedPtr1 };
	//returns the number of shared_ptr objects that manage the object
	std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;

	//returns the number of shared_ptr objects that manage the object
	std::cout << "sharedPtr.use_count(): " << sharedPtr1.use_count() << std::endl;

	//checks whether the referenced object was already deleted
	std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;

	//lock() :	creates a shared_ptr that manages the referenced object
	//use weakPtr.lock() to create a std::shared_ptr out of it.
	if (std::shared_ptr<int> sharedPtr2 = weakPtr.lock()) {
		std::cout << "*sharedPtr2: " << *sharedPtr2 << std::endl;
		std::cout << "sharedPtr2.use_count(): " << sharedPtr2.use_count() << std::endl;
	}
	else {
		std::cout << "Don't get the resource!" << std::endl;
	}

	//Releases the reference to the managed object
	weakPtr.reset();
	//checks whether the referenced object was already deleted; weak reference is reset
	std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;

	if (std::shared_ptr<int> sharedPtr1 = weakPtr.lock()) {
		std::cout << "*sharedPtr1: " << *sharedPtr1 << std::endl;
		std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
	}
	else {
		std::cout << "Don't get the resource!" << std::endl;
	}
	std::cout << "*sharedPtr1: " << *sharedPtr1 << std::endl;
	std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
	sharedPtr1.reset();//Releases the managed object
	std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
	std::cout << std::endl;

}


void weak_ptr_operations_class_type() {

	std::cout << std::boolalpha << std::endl;
	//Create a shared ptr
	auto sharedPtr1 = std::make_shared<Thing>();

	//std::weak_ptr which borrows the resource from the std::shared_ptr
	std::weak_ptr<Thing> weakPtr{ sharedPtr1 };
	//returns the number of shared_ptr objects that manage the object
	std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;

	//returns the number of shared_ptr objects that manage the object
	std::cout << "sharedPtr.use_count(): " << sharedPtr1.use_count() << std::endl;

	//checks whether the referenced object was already deleted
	std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;

	//lock() :	creates a shared_ptr that manages the referenced object
	//use weakPtr.lock() to create a std::shared_ptr out of it.
	if (std::shared_ptr<Thing> sharedPtr2 = weakPtr.lock()) {
		std::cout << "*sharedPtr2: " << sharedPtr2->get_thing() << std::endl;
		std::cout << "sharedPtr2.use_count(): " << sharedPtr2.use_count() << std::endl;
	}
	else {
		std::cout << "Don't get the resource!" << std::endl;
	}

	// releases the weak reference of the managed object
	weakPtr.reset();
	//checks whether the weak reference has expired not the managed object
	std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;

	if (std::shared_ptr<Thing> sharedPtr3 = weakPtr.lock()) {
		std::cout << "*sharedPtr: " << sharedPtr3->get_thing() << std::endl;
		std::cout << "sharedPtr1.use_count(): " << sharedPtr3.use_count() << std::endl;
	}
	else {
		std::cout << "Don't get the resource!" << std::endl;
	}
	std::cout << "sharedPtr.use_count(): " << sharedPtr1.use_count() << std::endl;
	std::cout << std::endl;

}

int main()
{
	//weak_ptr_basic_concept();
	//weak_ptr_operations_primitive_type();
	weak_ptr_operations_class_type();
	return 0;
}

/* output:
Thing 1 creation
in main: Thing 1
Thing 2 creation
in return_std::weak: Thing 2
Thing 2 destruction
it is expired
it is gone!
Thing 3 creation
in return_std::shared: Thing 3
Thing 1 destruction
it is not expired
it is Thing 3
Thing 3 destruction
*/

