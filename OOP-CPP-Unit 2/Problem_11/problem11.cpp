//To create an abstract base class using a pure virtual function.
#include <iostream>   // For input and output

// Abstract base class Shape
class Shape {
public:
    // Pure virtual function to calculate area
    virtual double area() const = 0;

    // Virtual destructor
    virtual ~Shape() = default;
};

// Rectangle class inherits Shape
class Rectangle : public Shape {
private:
    double length;   // Stores length
    double width;    // Stores width

public:
    // Constructor to initialize length and width
    Rectangle(double givenLength, double givenWidth)
        : length(givenLength), width(givenWidth) {}

    // Override area() function
    double area() const override {
        return length * width;
    }
};

// Circle class inherits Shape
class Circle : public Shape {
private:
    double radius;   // Stores radius

public:
    // Constructor to initialize radius
    explicit Circle(double givenRadius) : radius(givenRadius) {}

    // Override area() function
    double area() const override {
        return 3.141592653589793 * radius * radius;
    }
};

int main() {
    // Create Rectangle object
    Rectangle rectangle(5.0, 3.0);

    // Create Circle object
    Circle circle(2.0);

    // Display rectangle area
    std::cout << "Rectangle Area: " << rectangle.area() << '\n';

    // Display circle area
    std::cout << "Circle Area: " << circle.area() << '\n';

    return 0;   // End of program
}