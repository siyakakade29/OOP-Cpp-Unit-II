//To demonstrate how a derived class can access a protected base-class member.
#include <iostream>   // For input and output
#include <string>     // For using string data type
#include <utility>    // For std::move

// Base class Employee
class Employee {
protected:
    std::string name;   // Stores employee name

public:
    // Constructor to initialize employee name
    explicit Employee(std::string employeeName)
        : name(std::move(employeeName)) {}
};

// Derived class Developer inherits Employee
class Developer : public Employee {
private:
    std::string language;   // Stores programming language

public:
    // Constructor to initialize name and programming language
    Developer(std::string employeeName, std::string programmingLanguage)
        : Employee(std::move(employeeName)),
          language(std::move(programmingLanguage)) {}

    // Function to display developer details
    void display() const {
        std::cout << "Developer: " << name << '\n';
        std::cout << "Language: " << language << '\n';
    }
};

int main()
 {
    // Create a Developer object
    Developer developer("Neha", "C++");

    // Display developer information
    developer.display();

    return 0;   // End of program
}