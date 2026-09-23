//To override a virtual member function in a derived class.
#include <iostream>   // For input and output

// Base class Vehicle
class Vehicle {
public:
    // Virtual function
    virtual void move() const {
        std::cout << "Vehicle is moving\n";
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};

// Car class inherits Vehicle
class Car : public Vehicle {
public:
    // Override move() function
    void move() const override {
        std::cout << "Car moves on roads\n";
    }
};

// Boat class inherits Vehicle
class Boat : public Vehicle {
public:
    // Override move() function
    void move() const override {
        std::cout << "Boat moves on water\n";
    }
};

int main() {
    // Create Car object
    Car car;

    // Create Boat object
    Boat boat;

    // Call move() of Car
    car.move();

    // Call move() of Boat
    boat.move();

    return 0;   // End of program
}