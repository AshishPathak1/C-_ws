// shared_pointer3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std::literals;

class Thing {
private:
    std::string somedata;
public:
    Thing(std::string whats_this_thing): somedata (whats_this_thing) {
        std::cout << "Thing " << somedata << " is created\n";
    }
    /*Overloading operator() makes object callable*/
    void operator()() {
        std::cout << "Thing " << somedata << " is called\n";
    }

    ~Thing() {
        std::cout << "Thing " << somedata << " is destroyed\n";
    }
};

void callable_object_basics() {
    //Define object of class Thing
    Thing athing{ "Bat" };
    //Using object as function; callable object: Functors
    athing();
}

/*Custom deleter to close and delete a file*/
class TempFileDeleter {
private:
    std::string filename;
public:
    
    TempFileDeleter(std::string f_name) {
        filename = f_name;
    }

    void operator()(std::ofstream *fp) {
        fp->close(); // (*fp).close()
        
        std::cout << "Closing and deleting the file " << filename << "\n";
        std::remove(filename.c_str());

    }
};


class AutoFileClose {
private:
    std::string filename;
public:

    AutoFileClose(std::string f_name) {
        filename = f_name;
    }

    void operator()(std::ofstream* fp) {
        fp->close(); // (*fp).close()

        std::cout << "Closing the file " << filename << "\n";
    

    }
};

void file_handling_basics() {
    std::string filename_with_path = "d:/temp/abc.txt"s;

    //open the file for writing
    std::ofstream file_writer{ filename_with_path }; 

    //carry out operatio on file
    file_writer << "First_line\n"s;
    file_writer << "Second_line\n"s;

    //close
    file_writer.close();
}

void write_data_to_file(std::shared_ptr<std::ofstream> fptr) {
    *fptr << "First_line\n";
    *fptr << "Second_line\n";
   fptr->flush();
}

void shared_ptr_to_file_object() {
   
    /* Deleter for the shared_pointer can be function object*/
    {
        std::string file_path = "d:/temp/lmn.txt"s;
        
        TempFileDeleter temp_file_deleter{ file_path }; //callable object implementing overriding operator() 
        std::shared_ptr<std::ofstream> fptr{ new std::ofstream(file_path), temp_file_deleter };
        
        //alternatively
       // std::shared_ptr<std::ofstream> fptr{ new std::ofstream(file_path), TempFileDeleter(file_path)};
        
        *fptr << "First_line\n";
        *fptr << "Second_line\n";
        fptr->flush();
    }

    {
        std::string filename = "d:/temp/xyz.txt"s;
        std::shared_ptr<std::ofstream> fptr{ new std::ofstream{filename},AutoFileClose(filename) };
        write_data_to_file(fptr);
    }
    std::cout << "Finished Writing\n";
}



int main()
{
   // callable_object_basics();
   // file_handling_basics();
    shared_ptr_to_file_object();

    return 0;

}
