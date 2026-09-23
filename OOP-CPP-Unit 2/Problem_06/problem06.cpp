//To demonstrate multiple inheritance using academic and sports records.
#include <iostream>   // For input and output

// Base class Academic
class Academic {
protected:
    int academicMarks;   // Stores academic marks

public:
    // Constructor to initialize academic marks
    explicit Academic(int marks) : academicMarks(marks) {}

    // Function to display academic marks
    void showAcademic() const {
        std::cout << "Academic Marks: " << academicMarks << '\n';
    }
};

// Base class Sports
class Sports {
protected:
    int sportsMarks;   // Stores sports marks

public:
    // Constructor to initialize sports marks
    explicit Sports(int marks) : sportsMarks(marks) {}

    // Function to display sports marks
    void showSports() const {
        std::cout << "Sports Marks: " << sportsMarks << '\n';
    }
};

// Student class inherits Academic and Sports
class Student : public Academic, public Sports {
public:
    // Constructor to initialize both base classes
    Student(int academic, int sports)
        : Academic(academic), Sports(sports) {}

    // Function to display total marks
    void showTotal() const {
        std::cout << "Total Marks: "
                  << academicMarks + sportsMarks << '\n';
    }
};

int main() {
    // Create Student object
    Student student(80, 15);

    // Display academic marks
    student.showAcademic();

    // Display sports marks
    student.showSports();

    // Display total marks
    student.showTotal();

    return 0;   // End of program
}