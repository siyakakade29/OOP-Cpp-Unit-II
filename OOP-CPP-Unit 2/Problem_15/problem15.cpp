#include <iostream>
#include <string>
#include <utility>

// Base class for all vehicles
class Vehicle {
protected:
    std::string registrationNumber; // Vehicle registration number
    double ratePerDay;              // Rent per day

public:
    // Constructor
    Vehicle(std::string registration, double rate)
        : registrationNumber(std::move(registration)),
          ratePerDay(rate) {}

    // Function to calculate rent
    virtual double calculateRent(int days) const {
        return ratePerDay * days;
    }

    // Function to display vehicle details
    virtual void display() const {
        std::cout << "Registration: " << registrationNumber << '\n';
        std::cout << "Rate per day: " << ratePerDay << '\n';
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};

// Derived class Car
class Car : public Vehicle {
private:
    int numberOfDoors; // Number of doors

public:
    // Constructor
    Car(std::string registration, double rate, int doors)
        : Vehicle(std::move(registration), rate),
          numberOfDoors(doors) {}

    // Display car details
    void display() const override {
        Vehicle::display();
        std::cout << "Doors: " << numberOfDoors << '\n';
    }
};

// Derived class Bike
class Bike : public Vehicle {
private:
    int engineCapacity; // Engine capacity in CC

public:
    // Constructor
    Bike(std::string registration, double rate, int capacity)
        : Vehicle(std::move(registration), rate),
          engineCapacity(capacity) {}

    // Calculate rent with 10% discount
    double calculateRent(int days) const override {
        return ratePerDay * days * 0.9;
    }

    // Display bike details
    void display() const override {
        Vehicle::display();
        std::cout << "Engine Capacity: "
                  << engineCapacity << " CC\n";
    }
};

// Derived class Bus
class Bus : public Vehicle {
private:
    int seatingCapacity; // Number of seats

public:
    // Constructor
    Bus(std::string registration, double rate, int seats)
        : Vehicle(std::move(registration), rate),
          seatingCapacity(seats) {}

    // Display bus details
    void display() const override {
        Vehicle::display();
        std::cout << "Seating Capacity: "
                  << seatingCapacity << '\n';
    }
};

int main() {
    // Create objects
    Car car("MH12AB1234", 2000, 4);
    Bike bike("MH14CD5678", 1000, 150);
    Bus bus("MH20EF9012", 5000, 40);

    int days = 5;

    // Display Car details
    std::cout << "\nCar Details\n";
    car.display();
    std::cout << "Rent for " << days
              << " days: " << car.calculateRent(days) << "\n\n";

    // Display Bike details
    std::cout << "Bike Details\n";
    bike.display();
    std::cout << "Rent for " << days
              << " days: " << bike.calculateRent(days) << "\n\n";

    // Display Bus details
    std::cout << "Bus Details\n";
    bus.display();
    std::cout << "Rent for " << days
              << " days: " << bus.calculateRent(days) << "\n";

    return 0;
}