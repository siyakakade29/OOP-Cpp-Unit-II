#include <iostream>     // For input and output
#include <memory>       // For smart pointers
#include <string>       // For using string
#include <vector>       // For using vector
using namespace std;


// Base class for all payment methods
class PaymentMethod
{
protected:
    string transactionId;   // Stores transaction ID
    double amount;          // Stores payment amount

public:
    // Constructor to initialize payment details
    PaymentMethod(string tid, double amt)
        : transactionId(tid), amount(amt) {}

    // Pure virtual function for processing payment
    virtual bool processPayment() const = 0;

    // Virtual destructor
    virtual ~PaymentMethod() = default;
};


// Class for credit card payment
class CreditCardPayment : public PaymentMethod
{
private:
    string maskedCardNumber;    // Stores masked card number

public:
    // Constructor for credit card payment
    CreditCardPayment(string tid, double amt, string card)
        : PaymentMethod(tid, amt), maskedCardNumber(card) {}

    // Processes credit card payment
    bool processPayment() const override
    {
        cout << "Credit-card transaction " << transactionId
             << " for Rs. " << amount
             << " using " << maskedCardNumber
             << " completed." << endl;

        return true;    // Payment successful
    }
};


// Class for UPI payment
class UPIPayment : public PaymentMethod
{
private:
    string upiId;       // Stores UPI ID

public:
    // Constructor for UPI payment
    UPIPayment(string tid, double amt, string upi)
        : PaymentMethod(tid, amt), upiId(upi) {}

    // Processes UPI payment
    bool processPayment() const override
    {
        cout << "UPI transaction " << transactionId
             << " for Rs. " << amount
             << " from " << upiId
             << " completed." << endl;

        return true;    // Payment successful
    }
};


// Class for net banking payment
class NetBankingPayment : public PaymentMethod
{
private:
    string bankName;    // Stores bank name

public:
    // Constructor for net banking payment
    NetBankingPayment(string tid, double amt, string bank)
        : PaymentMethod(tid, amt), bankName(bank) {}

    // Processes net banking payment
    bool processPayment() const override
    {
        cout << "Net-banking transaction " << transactionId
             << " for Rs. " << amount
             << " through " << bankName
             << " completed." << endl;

        return true;    // Payment successful
    }
};


// Main function
int main()
{
    // Create a vector to store different payment objects
    vector<unique_ptr<PaymentMethod>> payments;

    // Add credit card payment
    payments.push_back(
        make_unique<CreditCardPayment>(
            "TXN001", 2500, "XXXX-XXXX1234"
        )
    );

    // Add UPI payment
    payments.push_back(
        make_unique<UPIPayment>(
            "TXN002", 1200, "student@upi"
        )
    );

    // Add net banking payment
    payments.push_back(
        make_unique<NetBankingPayment>(
            "TXN003", 5000, "Example Bank"
        )
    );

    // Print heading
    cout << "=== Payment Gateway ===" << endl;

    // Process each payment
    for (const auto& payment : payments)
    {
        payment->processPayment();
    }

    return 0;     // End the program
}