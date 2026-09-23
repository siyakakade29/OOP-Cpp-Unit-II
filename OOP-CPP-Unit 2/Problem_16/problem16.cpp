//To develop a salary system using an abstract class and derived classes.
#include <iostream>
#include <string>
#include <utility>

// Abstract base class Employee
class Employee {
protected:
    int employeeId;      // Employee ID
    std::string name;    // Employee name

public:
    // Constructor
    Employee(int id, std::string employeeName)
        : employeeId(id), name(std::move(employeeName)) {}

    // Pure virtual function to calculate salary
    virtual double calculateSalary() const = 0;

    // Display employee details
    void displayBasicDetails() const {
        std::cout << "Employee ID: " << employeeId << '\n';
        std::cout << "Name: " << name << '\n';
    }

    // Virtual destructor
    virtual ~Employee() = default;
};

// Derived class PermanentEmployee
class PermanentEmployee : public Employee {
private:
    double basicSalary; // Basic salary
    double allowance;   // Allowance

public:
    // Constructor
    PermanentEmployee(int id, std::string employeeName,
                      double basic, double extra)
        : Employee(id, std::move(employeeName)),
          basicSalary(basic),
          allowance(extra) {}

    // Calculate salary
    double calculateSalary() const override {
        return basicSalary + allowance;
    }
};

// Derived class ContractEmployee
class ContractEmployee : public Employee {
private:
    double hourlyRate; // Hourly rate
    int hoursWorked;   // Total hours worked

public:
    // Constructor
    ContractEmployee(int id, std::string employeeName,
                     double rate, int hours)
        : Employee(id, std::move(employeeName)),
          hourlyRate(rate),
          hoursWorked(hours) {}

    // Calculate salary
    double calculateSalary() const override {
        return hourlyRate * hoursWorked;
    }
};

// Function to display pay slip
void displayPaySlip(const Employee& employee) {
    employee.displayBasicDetails();
    std::cout << "Salary: "
              << employee.calculateSalary()
              << "\n\n";
}

int main() {
    // Create Permanent Employee object
    PermanentEmployee permanentEmployee(
        101, "Asha", 40000.0, 8000.0
    );

    // Create Contract Employee object
    ContractEmployee contractEmployee(
        102, "Vikas", 500.0, 80
    );

    // Display pay slips
    displayPaySlip(permanentEmployee);
    displayPaySlip(contractEmployee);

    return 0;
}