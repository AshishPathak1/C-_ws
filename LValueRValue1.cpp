// LvalueRvalue_3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>

/*
*  The strdup() function returns a pointer to a new string which is
*  a duplicate of the string s.  Memory for the new string is
*  obtained with malloc(), and can be freed with free().
*/
struct Data
{
    char* text{nullptr};
    void init(char const* txt) { // initialize text from txt (C-style Strnig : const char *
        text = _strdup(txt);
        std::cout << "Memory Allocated! Calling strdup\n";
    }

    void init(Data const& other) //Lvalue
    {
        text = _strdup(other.text);
        std::cout << "Memory Allocated! Calling strdup\n";
    }
    //No-Arg ctor
    Data() {
        std::cout << "Data Object Created\n";
    }
    //copy ctor
    Data(const Data& other) { //copy constructor
        std::cout << "Data object copy Created\n";
        this->text = other.text;
    }
    ~Data() {
        std::cout << "Data object destroyed\n";
    }
  
};


/*
* move-aware and implements move semantics, removing the (extra copy) drawback of the
  previous approach, and instead of making an extra copy of the temporary object's NTBS
  the pointer value is simply transferred to its new owner.
*/
struct BetterData
{
    char* text{nullptr};
    void init(char const* txt) { // initialize text from txt
        text = _strdup(txt);
        std::cout << "Memory Allocated! Calling strdup\n";
    }

    /* tmp object ceases to exist after executing the statement in which it is used*/
    void init(BetterData&& tmp) //Rvalue
    {
        // grabs the temporary object's text value
        text = std::move(tmp.text);    //tmp.text : xvalue
        // assigns 0 to other.text so that the temporary object's free(text) action does no harm.
        tmp.text = nullptr;
    }
    BetterData() {
        std::cout << "BetterData Object Created\n";
    }
    ~BetterData() {
        std::cout << "BetterData Object Created\n";
    }
};


Data dataFactory(char const* text);
BetterData betterDataFactory(char const* text);
void move_semantics_intro();

int main()
{
    Data d1{};
    /*
    Here the init function duplicates the NTBS stored in the temporary object.
    Immediately thereafter the temporary object ceases to exist.
    If you think about it, then you realize that that's a bit over the top:
        � the dataFactory function uses init to initialize the text variable of its
          temporary Data  object. for that it uses strdup;
        � the d1.init function then also uses strdup to initialize d1.text;
        � the statement ends, and the temporary object ceases to exist.
    */
    d1.init(dataFactory("first_string"));

    //std::cout << "Using R-Value Reference\n";
    BetterData d2{};
    /*
    * betterDataFactory returns a (temporary) object, and because of that it uses the init(Data &&tmp) function.
    */
    d2.init(betterDataFactory("Second_string"));

}

void move_semantics_intro() {

}

/*
* it returns a (temporary) Data object initialized with text.
* Such temporary objects cease to exist once the statement in which they are created ends.
*/
Data dataFactory(char const* text) {
    Data data{};  //temporary/Local object
    data.init(text);
    return data;
}

BetterData betterDataFactory(char const* text) {
    BetterData data{};  //temporary object
    data.init(text);
    return data;
}