#include <iostream>   // For input and output
#include <string>     // For using string data type
#include <utility>    // For std::move

// Base class Person
class Person {
protected:
    std::string name;   // Stores person's name

public:
    // Constructor to initialize name
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Function to display person's name
    void showPerson() const {
        std::cout << "Name: " << name << '\n';
    }
};

// Employee class inherits Person
class Employee : public Person {
protected:
    int employeeId;   // Stores employee ID

public:
    // Constructor to initialize name and employee ID
    Employee(std::string employeeName, int id)
        : Person(std::move(employeeName)), employeeId(id) {}

    // Function to display employee ID
    void showEmployee() const {
        std::cout << "Employee ID: " << employeeId << '\n';
    }
};

// Manager class inherits Employee
class Manager : public Employee {
private:
    int teamSize;   // Stores team size

public:
    // Constructor to initialize name, ID and team size
    Manager(std::string managerName, int id, int size)
        : Employee(std::move(managerName), id), teamSize(size) {}

    // Function to display manager details
    void showManager() const {
        showPerson();      // Display name
        showEmployee();    // Display employee ID
        std::cout << "Team Size: " << teamSize << '\n';
    }
};


int main()
 {
    // Create Manager object
    Manager manager("Ravi", 501, 8);

    // Display manager information
    manager.showManager();

    return 0;   // End of program
}