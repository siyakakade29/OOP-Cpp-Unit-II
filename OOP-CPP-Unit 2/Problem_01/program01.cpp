#include <iostream>   // For input and output
#include <string>     // For using string data type
using namespace std;

// Base class Person
class Person {
protected:
    string name;   // Stores the person's name

public:
    // Constructor to initialize the name
    explicit Person(string personName) : name(std::move(personName)) {}

    // Function to display the name
    void displayName() const {
        cout << "Name: " << name << '\n';
    }
};

// Derived class Student inherits from Person
class Student : public Person {
private:
    int rollNumber;   // Stores student's roll number

public:
    // Constructor to initialize name and roll number
    Student(string studentName, int roll)
        : Person(move(studentName)), rollNumber(roll) {}

    // Function to display student details
    void displayStudent() const {
        displayName();   // Calls Person class function
        cout << "Roll Number: " << rollNumber << '\n';
    }
};

int main() {
    // Create a Student object
    Student student("Amit", 101);

    // Display student information
    student.displayStudent();

    return 0;   // End of program
}