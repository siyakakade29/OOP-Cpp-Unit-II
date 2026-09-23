//A company employs full-time employees, part-time employees, and interns. 
//All employees share common information, but salary calculations vary by employment type. 
#include <iostream>     // For input and output (cout)
#include <string>       // For using string
using namespace std;    // Avoid writing std::

class Employee
{
protected:
    int empId;          // Stores employee ID
    string name;        // Stores employee name
    string department;  // Stores department

public:
    // Constructor to initialize employee details
    Employee(int id, string n, string dept)
        : empId(id), name(n), department(dept) {}

    // Displays common employee information
    void displayBasicInfo() const
    {
        cout << "ID: " << empId
             << " | Name: " << name
             << " | Department: " << department;
    }

    // Pure virtual function for salary calculation
    virtual double calculateSalary() const = 0;

    // Virtual destructor
    virtual ~Employee() = default;
};


// Class for full-time employees
class FullTimeEmployee : public Employee
{
private:
    double monthlySalary;   // Stores monthly salary

public:
    // Constructor for full-time employee
    FullTimeEmployee(int id, string n, string dept, double salary)
        : Employee(id, n, dept), monthlySalary(salary) {}

    // Returns the monthly salary
    double calculateSalary() const override
    {
        return monthlySalary;
    }

    // Displays full-time employee details
    void display() const
    {
        displayBasicInfo();

        cout << " | Type: Full-Time | Salary: Rs. "
             << calculateSalary() << endl;
    }
};


// Class for part-time employees
class PartTimeEmployee : public Employee
{
private:
    double hourlyRate;     // Stores payment per hour
    int hoursWorked;       // Stores total hours worked

public:
    // Constructor for part-time employee
    PartTimeEmployee(int id, string n, string dept,
                     double rate, int hours)
        : Employee(id, n, dept),
          hourlyRate(rate),
          hoursWorked(hours) {}

    // Calculates salary using rate × hours
    double calculateSalary() const override
    {
        return hourlyRate * hoursWorked;
    }

    // Displays part-time employee details
    void display() const
    {
        displayBasicInfo();

        cout << " | Type: Part-Time | Salary: Rs. "
             << calculateSalary() << endl;
    }
};


// Class for interns
class Intern : public Employee
{
private:
    double stipend;        // Stores intern stipend

public:
    // Constructor for intern
    Intern(int id, string n, string dept,
           double stipendAmount)
        : Employee(id, n, dept),
          stipend(stipendAmount) {}

    // Returns the stipend
    double calculateSalary() const override
    {
        return stipend;
    }

    // Displays intern details
    void display() const
    {
        displayBasicInfo();

        cout << " | Type: Intern | Stipend: Rs. "
             << calculateSalary() << endl;
    }
};


// Main function
int main()
{
    // Create a full-time employee
    FullTimeEmployee f1(101, "Amit", "IT", 65000);

    // Create a part-time employee
    PartTimeEmployee p1(102, "Sneha", "HR", 250, 120);

    // Create an intern
    Intern i1(103, "Rohan", "Marketing", 15000);

    // Print heading
    cout << "=== Employee Payroll ===" << endl;

    // Display all employee details
    f1.display();
    p1.display();
    i1.display();

    return 0;   // End the program
}