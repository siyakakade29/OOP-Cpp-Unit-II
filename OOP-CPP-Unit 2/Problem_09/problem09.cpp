//To initialize a parameterized base class from a derived-class constructor.
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
};

// Student class inherits Person
class Student : public Person {
private:
    int rollNumber;   // Stores roll number

public:
    // Constructor to initialize name and roll number
    Student(std::string studentName, int roll)
        : Person(std::move(studentName)), rollNumber(roll) {}

    // Function to display student details
    void display() const {
        std::cout << "Name: " << name << '\n';
        std::cout << "Roll Number: " << rollNumber << '\n';
    }
};

int main() {
    // Create Student object
    Student student("Kiran", 24);

    // Display student information
    student.display();

    return 0;   // End of program
}