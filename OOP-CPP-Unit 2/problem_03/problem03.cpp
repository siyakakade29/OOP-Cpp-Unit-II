//To observe the effect of public and private inheritance on accessibility.
#include <iostream>   // For input and output

// Base class
class Base {
public:
    // Function to display a message
    void show() const {
        std::cout << "Base public function\n";
    }
};

// Public inheritance
class PublicDerived : public Base {
    // show() remains public in this class
};

// Private inheritance
class PrivateDerived : private Base {
public:
    // Public function that calls Base class function
    void callBaseShow() const {
        show();   // Allowed inside the class
    }
};

int main() {
    // Object of PublicDerived class
    PublicDerived publicObject;
    publicObject.show();   // Accessible because of public inheritance

    // Object of PrivateDerived class
    PrivateDerived privateObject;
    privateObject.callBaseShow();   // Calls Base class function indirectly

    // privateObject.show();
    // Error: show() becomes private due to private inheritance

    return 0;   // End of program
}