// shared_pointer4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

class Thing {
private:
    std::string somedata;
public:
    Thing(std::string whats_this_thing) :somedata(whats_this_thing) {
        std::cout << "Thing " << somedata << " is created\n";
    }

    /*Overloading operator() makes object callable*/
    void operator()() {
        std::cout << "Thing " << somedata << " is called\n";
    }

    std::string get_data() const{
        return somedata;
    }

    ~Thing() {
        std::cout << "Thing " << somedata << " is destroyed\n";
    }
};


class SomeOtherThing {
private:
    int number;
public:
    SomeOtherThing(int whats_this_thing) {
        number = whats_this_thing;
        std::cout << "SomeOtherThing " << number << " is created\n";
    }
   
    int get_data() const {
        return number;
    }

    ~SomeOtherThing() {
        std::cout << "SomeOtherThing " << number << " is destroyed\n";
    }
};



void get_resource_owned_by_shared_pointer() {
    /*sp1 is owner of Thing MAT */
    std::shared_ptr<Thing> sp1{new Thing("MAT")};
    std::cout << "Reference counter : " << sp1.use_count() << "\n";
    std::cout << "Entering code block\n";
    {
        /*returns the stored raw pointer pointing to the shared resource*/
        Thing* raw_ptr = sp1.get();
        std::cout << "Getting data :";    (*raw_ptr)(); 
        std::cout << "Getting data :" << raw_ptr->get_data() << "\n";
        std::shared_ptr<Thing> sp2{ sp1 };
        std::cout << "is sp1 & sp2 sharing the same resource ? : " 
            << std::boolalpha << (sp1.get() == sp2.get()) << "\n";
        std::cout << "Reference counter : " << sp1.use_count() << "\n";
    }
    std::cout << "Exiting code block\n";
}

void alising_constructor1() {

    const std::shared_ptr<Thing> sp1{ new Thing("Jupiter") }; //owning shared_ptr sp1 shares Jupiter
    Thing* raw_ptr = new Thing("Venus");  //non-owning raw_ptr points to Venus

    {
        std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
        /*sp2 is shared owner of jupiter and points to Venus 
         
          Life time of Thing:Jupiter is controlled by sp1 & sp2; ie when both the
          shared pointers get destroyed the Thing(Jupiter) will also get destroyed
        */
        std::shared_ptr<Thing> sp2(sp1, raw_ptr); //alising constructor
        std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
        std::cout << "Reference counter sp2 : " << sp2.use_count() << "\n";

        std::cout << "sp1 owns " << sp1.get()->get_data() << "\n";
        std::cout << "sp2 referes to " << sp2.get()->get_data() << "\n";
        std::cout << "sp1 owns (shares) " << sp1->get_data() << "\n";
        std::cout << "sp2 referes to " << sp2->get_data() << "\n";
        std::cout << "sp1 owns (shares) "; (*sp1)(); std::cout << "\n";
        std::cout << "sp2 referes to "; (*sp2)(); std::cout << "\n";
       // delete raw_ptr;
        std::cout << "sp2 referes to " << sp2->get_data(); std::cout << "\n";
    }

    std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
    std::cout << "sp1 owns " << sp1.get()->get_data() << "\n";
    delete raw_ptr;
}

void alising_constructor2() {

    const std::shared_ptr<Thing> sp1{ new Thing("Jupiter") }; //sp1 shares Jupiter
    SomeOtherThing* sot_ptr = new SomeOtherThing(999);            //sot_ptr points to Venus

    {
        std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
        
        /*sp2 is shared owner of jupiter and points to Venus */
        //shared pointer sharing "Thing" but pointing to "SomeOtherThing"
        std::shared_ptr<SomeOtherThing> sp2(sp1, sot_ptr); 
       
        std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
        std::cout << "Reference counter sp2 : " << sp2.use_count() << "\n";

        std::cout << "sp1 owns " << sp1.get()->get_data() << "\n";
        std::cout << "sp2 referes to " << sp2.get()->get_data() << "\n";
        std::cout << "sp1 owns (shares) " << sp1->get_data() << "\n";
        std::cout << "sp2 referes to " << sp2->get_data() << "\n";
    }

    std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
    std::cout << "sp1 owns " << sp1.get()->get_data() << "\n";
    delete sot_ptr;
}


void  shared_ptr_deleter_calling() {
    std::shared_ptr<Thing> sp1{ };
    std::shared_ptr<Thing> sp2{ sp1 };
    std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
    std::cout << "Reference counter sp2 : " << sp2.use_count() << "\n";
    sp1.reset();
    std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
    std::cout << "Reference counter sp2 : " << sp2.use_count() << "\n";
    sp2.reset();
    std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
    std::cout << "Reference counter sp2 : " << sp2.use_count() << "\n";

    sp1 = std::make_shared<Thing>("Sun") ;
    sp2 = sp1;
    {
        std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
        std::cout << "Reference counter sp2 : " << sp2.use_count() << "\n";
        Thing* ptr = new Thing("Moon");
        sp2.reset(ptr); //Gives away the ownership of Sun and now owns Moon
        std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
        std::cout << "Reference counter sp2 : " << sp2.use_count() << "\n";
    }
    sp2 = sp1; // Deletes Moon before sharing the ownership of Sun
    std::cout << "Reference counter sp1 : " << sp1.use_count() << "\n";
    std::cout << "Reference counter sp2 : " << sp2.use_count() << "\n";
    sp2.reset(); //Gives away the ownership of Sun
    sp1.reset(); //Gives away the ownership of Sun
    return;
}

int main()
{
    //  get_resource_owned_by_shared_pointer();
    //  alising_constructor1();
    //  alising_constructor2();
      shared_ptr_deleter_calling();
 }
