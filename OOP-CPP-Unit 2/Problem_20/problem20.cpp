#include <iostream>     // For input and output
#include <memory>       // For smart pointers
#include <string>       // For using string
#include <vector>       // For using vector
using namespace std;


// Base class for all bank accounts
class Account
{
protected:
    string accountNumber;   // Stores account number
    string holderName;      // Stores account holder name
    double balance;         // Stores account balance

public:

    // Constructor to initialize account details
    Account(string accNo, string name, double bal)
        : accountNumber(accNo), holderName(name), balance(bal) {}

    // Deposit money into the account
    void deposit(double amount)
    {
        balance += amount;
        cout << "Deposited: Rs. " << amount << endl;
    }

    // Withdraw money from the account
    virtual void withdraw(double amount)
    {
        if (amount <= balance)
        {
            balance -= amount;
            cout << "Withdrawn: Rs. " << amount << endl;
        }
        else
        {
            cout << "Insufficient balance." << endl;
        }
    }

    // Pure virtual function for interest calculation
    virtual double calculateInterest() const = 0;

    // Displays basic account information
    virtual void displayInfo() const
    {
        cout << "Account No: " << accountNumber
             << " | Holder: " << holderName
             << " | Balance: Rs. " << balance << endl;
    }

    // Virtual destructor
    virtual ~Account() = default;
};


// Savings Account class
class SavingsAccount : public Account
{
private:
    double interestRate;    // Stores interest rate

public:

    // Constructor for savings account
    SavingsAccount(string accNo, string name,
                   double bal, double rate)
        : Account(accNo, name, bal), interestRate(rate) {}

    // Calculate savings account interest
    double calculateInterest() const override
    {
        return balance * interestRate / 100;
    }

    // Display savings account details
    void displayInfo() const override
    {
        cout << "Savings Account | ";
        Account::displayInfo();

        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Current Account class
class CurrentAccount : public Account
{
private:
    double minimumBalance;  // Stores minimum required balance

public:

    // Constructor for current account
    CurrentAccount(string accNo, string name,
                   double bal, double minBal)
        : Account(accNo, name, bal),
          minimumBalance(minBal) {}

    // Current account usually has no interest
    double calculateInterest() const override
    {
        return 0;
    }

    // Withdraw money from current account
    void withdraw(double amount) override
    {
        if (balance - amount >= minimumBalance)
        {
            balance -= amount;
            cout << "Withdrawn: Rs. " << amount << endl;
        }
        else
        {
            cout << "Withdrawal denied: Minimum balance required."
                 << endl;
        }
    }

    // Display current account details
    void displayInfo() const override
    {
        cout << "Current Account | ";
        Account::displayInfo();

        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Fixed Deposit Account class
class FixedDepositAccount : public Account
{
private:
    double interestRate;    // Stores interest rate
    int years;              // Stores deposit period

public:

    // Constructor for fixed deposit account
    FixedDepositAccount(string accNo, string name,
                        double bal, double rate, int y)
        : Account(accNo, name, bal),
          interestRate(rate),
          years(y) {}

    // Calculate fixed deposit interest
    double calculateInterest() const override
    {
        return balance * interestRate * years / 100;
    }

    // Display fixed deposit details
    void displayInfo() const override
    {
        cout << "Fixed Deposit Account | ";
        Account::displayInfo();

        cout << "Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Main function
int main()
{
    // Create a vector to store different account objects
    vector<unique_ptr<Account>> accounts;

    // Add a savings account
    accounts.push_back(
        make_unique<SavingsAccount>(
            "A001", "Amit", 50000, 4.0
        )
    );

    // Add a current account
    accounts.push_back(
        make_unique<CurrentAccount>(
            "A002", "Sneha", 80000, 10000
        )
    );

    // Add a fixed deposit account
    accounts.push_back(
        make_unique<FixedDepositAccount>(
            "A003", "Rohan", 100000, 7.0, 2
        )
    );


    // Print heading
    cout << "=== Banking System ===" << endl;

    // Display all account details
    for (const auto& account : accounts)
    {
        account->displayInfo();
        cout << endl;
    }


    // Deposit money into savings account
    cout << "=== Deposit ===" << endl;
    accounts[0]->deposit(5000);
    accounts[0]->displayInfo();

    cout << endl;


    // Withdraw money from current account
    cout << "=== Withdrawal ===" << endl;
    accounts[1]->withdraw(20000);
    accounts[1]->displayInfo();

    return 0;       // End the program
}