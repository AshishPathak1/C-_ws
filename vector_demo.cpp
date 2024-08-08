// 27. Vector.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>

void print(const std::vector<int>& v) {
    for (auto element : v) {
        std::cout << element << ", ";
    }
    std::cout << "\n";
}

void print_meta_data(std::vector<double>& v) {
    std::cout << "Size of Vector     : " << v.size() << '\n';
    std::cout << "Capacity of Vector : " << v.capacity() << '\n';
}

//since C++20
void print_data(double element) {
    std::cout << element << ", ";
}

void vector_basics() {
    std::vector<char> grades;
    std::vector<int> marks;
    std::cout << "Size of Marks : " << marks.size() << '\n';
    std::cout << "Capacity of Marks : " << marks.capacity() << '\n';
    marks.push_back(10); //adds an element to the end
    marks.push_back(20);
    marks.push_back(30);
    std::cout << "Size of Marks : " << marks.size() << '\n';
    print(marks);
    marks.push_back(40);
    marks.push_back(50);
    marks.push_back(60);
    marks.push_back(70);
    std::cout << "Size of Marks : " << marks.size() << '\n';
    std::cout << "Capacity of Marks : " << marks.capacity() << '\n';

    //Extra memory can be returned to the system via a call to shrink_to_fit()
    marks.shrink_to_fit(); //reduces memory usage by freeing unused memory
    std::cout << "Size of Marks : " << marks.size() << '\n';
    std::cout << "Capacity of Marks : " << marks.capacity() << '\n';
}

void vector_memory() {
    std::vector<double> v1;
    print_meta_data(v1);
    
    std::cout << "After reserving the memory\n";
    v1.reserve(10); //memory allocated to hold 10 double values
    print_meta_data(v1);

    std::cout << "After Storing 10 values\n";
    for (int i{ 1 }; i <= 10; ++i) {
        v1.push_back(std::sqrt(i * 10));
    }
    print_meta_data(v1);

    std::cout << "After resizing vector\n";
    v1.resize(6);
    print_meta_data(v1);
    
    std::cout << "After shrinking  vector\n";
    v1.shrink_to_fit();
    print_meta_data(v1);

    std::cout << "Increasing the size with default values:\n";
    v1.resize(12); //fills the additional elements with default value of the type
    print_meta_data(v1);
    for (auto element : v1) {
        std::cout << element << ", ";
    }
    std::cout << "\n";

    std::cout << "Increasing the size with fill value:\n";
    v1.resize(15, 99);
    print_meta_data(v1);
    for (auto element : v1) {
        std::cout << element << ", ";
    }
    std::cout << "\n";
}

void vector_creation() {
    std::vector<std::string> names(5);
    std::cout << "Size of names : " << names.size() << '\n';
    std::cout << "Capacity of names : " << names.capacity() << '\n';
    
    std::vector<std::string> friends{"Jay","Ram","Tom","Sam","Chi"};
    std::cout << "Size of friends : " << friends.size() << '\n';
    std::cout << "Capacity of friends : " << friends.capacity() << '\n';
    for (auto dost : friends) {
        std::cout << dost << ", ";
    }
    std::cout << "\n";

    //Automatic template type argument deduction
    std::vector marks{66,77,88,99,77, 56,77};   //Since C++17
    std::cout << "Marks are as follows:\n";
    print(marks);

    std::vector percentage{ 66.6,77.7,88.8,99.9 };//Since C++17
    std::cout << "Percentages are as follows:\n";
    std::for_each(percentage.cbegin(), percentage.cend(), [](auto i) {std::cout << i << ", "; });
    auto print_lambda = [](auto i) {std::cout << i << ", "; };
    std::for_each(percentage.cbegin(), percentage.cend(), print_lambda);
    std::cout << "\n";
    std::cout << "Percentages are as follows:\n";
    std::for_each(percentage.begin(), percentage.end(), print_data);
    std::cout << "\n";

    std::cout << "Last value  : " << percentage.back() << "\n";
    std::cout << "First value : " << percentage.front() << "\n";

   // std::vector scores(5);
   
   // std::vector scores{ 56.5f, 'a', 3, 56.0F };
}

bool predicate(int element) {
    return( element%2 ==0 );
}

void  vector_deletion() {
    std::vector marks{ 66,77,88,99,77, 56,77 };   //Since C++17
    std::cout << "Marks are as follows:\n";
    print(marks);
    std::cout << "After deleting first 3 elements: \n";
    marks.erase(marks.begin(),marks.begin()+3); //member function : method
    print(marks);

    std::vector scores{ 66,77,88,99,77, 56,77 };
    print(scores);
    std::erase(scores, 77); //non-member function; global function
    print(scores);
    
    auto dele_condition = [](auto ele) {return (ele % 7 == 0); };
    std::erase_if(marks, dele_condition); //non-member function
    print(marks);
  
    std::vector data{1,2,3,4,5,6,7,8,9,10};  
    std::erase_if(data, predicate);
    print(data);
}

void vector_operations() {
    //Search and delete
    std::vector v1{10, 20, 30, 40, 50, 60, 70, 80, 90};
    std::cout << "Original Vector : \n";
    print(v1);
    auto pos = std::find(v1.begin(), v1.end(), 70);

    if (pos != v1.end()) {
        std::cout << *pos << " is being deleted\n";
        v1.erase(pos);
    }
    std::cout << "After deleting 70 : \n";
    print(v1);

    pos = std::find(v1.begin(), v1.end(), 80);
    //Inserts a copy of elem before iterator position pos
    v1.insert(pos, 70);
    std::cout << "After inserting 70 : \n";
    print(v1);

    //Inserts n copies of elem before iterator position pos
    pos = std::find(v1.begin(), v1.end(), 80);
    v1.insert(pos,5,99);
    std::cout << "After inserting 99; 5 times : \n";
    print(v1);

    std::cout << std::boolalpha;
    //evaluates to a Boolean value of true ifand only if the container is empty
    std::cout << "Is vector empty ? " << v1.empty() << "\n";
    //std::cout << "Original Vector : \n";
    v1.clear(); 
    std::cout << "Is vector empty ? " << v1.empty() << "\n";
}

int main()
{
 //   vector_basics();
 //   vector_memory();
 //   vector_creation();
 //   vector_deletion();
    vector_operations();
}
