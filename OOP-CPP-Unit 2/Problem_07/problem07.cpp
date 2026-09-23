//To resolve ambiguity when two base classes contain methods with the same name.
#include <iostream>   // For input and output

// Base class Academic
class Academic {
public:
    // Function to display academic information
    void display() const {
        std::cout << "Academic information\n";
    }
};

// Base class Sports
class Sports {
public:
    // Function to display sports information
    void display() const {
        std::cout << "Sports information\n";
    }
};

// Student class inherits Academic and Sports
class Student : public Academic, public Sports {
public:
    // Function to display both Academic and Sports information
    void displayAll() const {
        Academic::display();   // Call Academic display()
        Sports::display();     // Call Sports display()
    }
};

int main() {
    // Create Student object
    Student student;

    // Call Academic class display function
    student.Academic::display();

    // Call Sports class display function
    student.Sports::display();

    // Call function to display both
    student.displayAll();

    return 0;   // End of program
}