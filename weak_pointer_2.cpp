/*
 * File:   weak_ptr_cycle.cpp
 * Author: Hrishikesh Pisal
 *
 * Created on 3 May 2021, 5:01 PM
 */

 // cycle.cpp

#include <iostream>
#include <memory>

//Forward Declaration
struct Son;
struct Daughter;

struct Mother {

    ~Mother() {
        std::cout << "Mother gone" << std::endl;
    }

    Mother() {
        std::cout << "Mother created" << std::endl;
    }

    void setSon(const std::shared_ptr<Son> sp_son) {
        sp_mySon = sp_son;
    }

    void setDaughter(const std::shared_ptr<Daughter> sp_daughter) {
        wp_myDaughter = sp_daughter;
    }
    std::shared_ptr<const Son> sp_mySon; //owing pointer : strong reference
    std::weak_ptr<const Daughter> wp_myDaughter; //non-owing pointer : weak reference
};


struct Son {

    Son(std::shared_ptr<Mother> sp_mother) : myMother(sp_mother) {
        std::cout << "Son created\n";
    }

    ~Son() {
        std::cout << "Son gone" << std::endl;
    }

   
    std::shared_ptr<const Mother> myMother;
};


struct Daughter {

    Daughter(std::shared_ptr<Mother> sp_mother) : myMother(sp_mother) {
        std::cout << "Daughter created\n";
    }

    ~Daughter() {
        std::cout << "Daughter gone" << std::endl;
    }
    std::shared_ptr<const Mother> myMother; //strong reference to Mother
};

int main() {
    std::cout << std::endl;
    //Mother & son
   /* {
        auto sp_mother(std::make_shared<Mother>());
        auto sp_son (std::make_shared<Son>(sp_mother));
        sp_mother->setSon(sp_son);
        
        std::cout << "Mother's refercence count : " << sp_mother.use_count() << "\n";
        std::cout << "Sons refercence count : " << sp_son.use_count() << "\n";
    }*/
    //Mother & Daughter
    {
        auto sp_mother(std::make_shared<Mother>());
        auto sp_daughter(std::make_shared<Daughter>(sp_mother));

        sp_mother->setDaughter(sp_daughter);
        std::cout << "Mother's refercence count : " << sp_mother.use_count() << "\n";
        std::cout << "Daughter's refercence count : " << sp_daughter.use_count() << "\n";
    }

    std::cout << std::endl;
}