//To create and use a nested class.
#include <iostream>
#include <string>
#include <utility>

// Outer class
class University {
public:

    // Nested class inside University
    class Department {
    private:
        std::string name;   // Stores department name

    public:
        // Constructor to initialize department name
        explicit Department(std::string departmentName)
            : name(std::move(departmentName)) {}

        // Function to display department name
        void display() const {
            std::cout << "Department: " << name << '\n';
        }
    };
};

int main() {
    // Create Department object
    University::Department department(
        "Artificial Intelligence and Data Science"
    );

    // Display department details
    department.display();

    return 0;   // End of program
}//