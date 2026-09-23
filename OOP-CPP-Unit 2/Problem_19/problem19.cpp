//Vehicle Fleet Management 
#include <iostream>     // For input and output
#include <memory>       // For smart pointers
#include <string>       // For using string
#include <vector>       // For using vector
using namespace std;


// Base class for all vehicles
class Vehicle
{
protected:
    string vehicleId;          // Stores vehicle ID
    string registrationNumber;  // Stores registration number
    double fuelLevel;          // Stores fuel level

public:

    // Constructor to initialize vehicle details
    Vehicle(string vid, string reg)
        : vehicleId(vid), registrationNumber(reg), fuelLevel(100.0) {}

    // Starts the vehicle engine
    void startEngine() const
    {
        cout << "Vehicle " << vehicleId
             << " engine started." << endl;
    }

    // Adds fuel to the vehicle
    void refuel(double amount)
    {
        fuelLevel += amount;

        // Fuel cannot be more than 100%
        if (fuelLevel > 100.0)
        {
            fuelLevel = 100.0;
        }
    }

    // Displays basic vehicle information
    virtual void displayInfo() const
    {
        cout << "Vehicle ID: " << vehicleId
             << " | Registration: " << registrationNumber
             << " | Fuel: " << fuelLevel << "%" << endl;
    }

    // Virtual destructor
    virtual ~Vehicle() = default;
};


// Class for truck
class Truck : public Vehicle
{
private:
    double cargoCapacity;       // Stores cargo capacity

public:

    // Constructor for truck
    Truck(string vid, string reg, double capacity)
        : Vehicle(vid, reg), cargoCapacity(capacity) {}

    // Displays truck information
    void displayInfo() const override
    {
        cout << "Truck | ";

        // Call displayInfo() of base class
        Vehicle::displayInfo();

        cout << "Cargo capacity: "
             << cargoCapacity << " tonnes" << endl;
    }
};


// Class for delivery van
class DeliveryVan : public Vehicle
{
private:
    int packageCount;           // Stores number of packages

public:

    // Constructor for delivery van
    DeliveryVan(string vid, string reg, int packages)
        : Vehicle(vid, reg), packageCount(packages) {}

    // Displays delivery van information
    void displayInfo() const override
    {
        cout << "Delivery Van | ";

        // Call displayInfo() of base class
        Vehicle::displayInfo();

        cout << "Packages loaded: "
             << packageCount << endl;
    }
};


// Class for delivery bike
class Bike : public Vehicle
{
private:
    bool hasDeliveryBox;        // Stores whether bike has delivery box

public:

    // Constructor for bike
    Bike(string vid, string reg, bool hasBox)
        : Vehicle(vid, reg), hasDeliveryBox(hasBox) {}

    // Displays bike information
    void displayInfo() const override
    {
        cout << "Delivery Bike | ";

        // Call displayInfo() of base class
        Vehicle::displayInfo();

        // Display box availability
        cout << "Delivery box: "
             << (hasDeliveryBox ? "Available" : "Not available")
             << endl;
    }
};


// Main function
int main()
{
    // Create a vector to store different vehicles
    vector<unique_ptr<Vehicle>> fleet;

    // Add a truck to the fleet
    fleet.push_back(
        make_unique<Truck>(
            "V001", "MH12-AB-1234", 10.5
        )
    );

    // Add a delivery van to the fleet
    fleet.push_back(
        make_unique<DeliveryVan>(
            "V002", "MH12-CD-5678", 50
        )
    );

    // Add a delivery bike to the fleet
    fleet.push_back(
        make_unique<Bike>(
            "V003", "MH12-EF-9012", true
        )
    );

    // Print heading
    cout << "=== Fleet Status ===" << endl;

    // Process each vehicle in the fleet
    for (const auto& vehicle : fleet)
    {
        // Start the engine
        vehicle->startEngine();

        // Display vehicle details
        vehicle->displayInfo();

        // Print a blank line
        cout << endl;
    }

    return 0;       // End the program
}