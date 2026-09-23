//To observe the construction and destruction order of a derived object.
#include <iostream>   // For input and output

// Base class
class Base {
public:
    // Constructor of Base class
    Base() {
        std::cout << "Base constructor\n";
    }

    // Destructor of Base class
    ~Base() {
        std::cout << "Base destructor\n";
    }
};

// Derived class inherits Base
class Derived : public Base {
public:
    // Constructor of Derived class
    Derived() {
        std::cout << "Derived constructor\n";
    }

    // Destructor of Derived class
    ~Derived() {
        std::cout << "Derived destructor\n";
    }
};

int main() {
    // Create object of Derived class
    Derived object;

    return 0;   // End of program
}