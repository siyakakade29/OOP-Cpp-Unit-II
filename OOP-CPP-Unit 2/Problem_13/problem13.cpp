//To demonstrate access to private data using a friend class.
#include <iostream>   // For input and output

// Account class
class Account {
private:
    double balance;   // Private data member

    // Auditor class is declared as a friend
    friend class Auditor;

public:
    // Constructor to initialize balance
    explicit Account(double initialBalance)
        : balance(initialBalance) {}
};

// Auditor class
class Auditor {
public:
    // Function to access Account's private member
    void inspect(const Account& account) const {
        std::cout << "Account Balance: "
                  << account.balance << '\n';
    }
};

int main() {
    // Create Account object
    Account account(5000.0);

    // Create Auditor object
    Auditor auditor;

    // Display account balance
    auditor.inspect(account);

    return 0;   // End of program
}