//To implement hierarchical inheritance using Vehicle as a common base class.
#include <iostream>   // For input and output
#include <string>     // For string data type
#include <utility>    // For std::move

// Base class Vehicle
class Vehicle {
protected:
    std::string registrationNumber;   // Stores vehicle number

public:
    // Constructor to initialize registration number
    explicit Vehicle(std::string registration)
        : registrationNumber(std::move(registration)) {}

    // Function to start vehicle
    void start() const {
        std::cout << "Vehicle " << registrationNumber << " started\n";
    }
};

// Car class inherits Vehicle
class Car : public Vehicle {
public:
    // Constructor
    explicit Car(std::string registration)
        : Vehicle(std::move(registration)) {}

    // Function to open car boot
    void openBoot() const {
        std::cout << "Car boot opened\n";
    }
};

// Bike class inherits Vehicle
class Bike : public Vehicle {
public:
    // Constructor
    explicit Bike(std::string registration)
        : Vehicle(std::move(registration)) {}

    // Function to show helmet reminder
    void helmetReminder() const {
        std::cout << "Please wear a helmet\n";
    }
};

int main() {
    // Create Car object
    Car car("MH12AB1234");

    // Create Bike object
    Bike bike("MH12CD5678");

    // Call Car functions
    car.start();
    car.openBoot();

    // Call Bike functions
    bike.start();
    bike.helmetReminder();

    return 0;   // End of program
}