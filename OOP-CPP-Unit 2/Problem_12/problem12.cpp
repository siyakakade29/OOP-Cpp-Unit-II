//To solve duplicate-base ambiguity in diamond inheritance using a virtual base class.
#include <iostream>   // For input and output
#include <string>     // For string data type
#include <utility>    // For std::move

// Base class Person
class Person {
protected:
    std::string name;   // Stores person's name

public:
    // Constructor to initialize name
    explicit Person(std::string personName)
        : name(std::move(personName)) {}

    // Function to display name
    void displayName() const {
        std::cout << "Name: " << name << '\n';
    }
};

// Student class virtually inherits Person
class Student : virtual public Person {
public:
    // Constructor
    Student() : Person("Unknown") {}
};

// Employee class virtually inherits Person
class Employee : virtual public Person {
public:
    // Constructor
    Employee() : Person("Unknown") {}
};

// TeachingAssistant inherits Student and Employee
class TeachingAssistant : public Student, public Employee {
public:
    // Constructor to initialize Person name
    explicit TeachingAssistant(std::string assistantName)
        : Person(std::move(assistantName)),
          Student(),
          Employee() {}
};

int main() {
    // Create TeachingAssistant object
    TeachingAssistant assistant("Riya");

    // Display name
    assistant.displayName();

    return 0;   // End of program
}