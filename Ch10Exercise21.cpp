//
// Created by Javier on 10/19/2024.
//

#include <iostream>
#include <string>
using namespace std;

class bankAccount {
private:
    // Variables
    string accountHolderName;
    int accountNumber;
    string accountType;
    double balance;
    double interestRate;
    static int nextAccountNumber;

public:
    // Default Constructor
    bankAccount() : accountHolderName(""), accountType("Checking"), balance(0.0), interestRate(0.0) {
        accountNumber = nextAccountNumber++;  // Automatically assign account number
    }

    bankAccount(const string& name, const string& type, double initialBalance, double rate)
        : accountHolderName(name), accountType(type), balance(initialBalance), interestRate(rate) {
        accountNumber = nextAccountNumber++;  // Assign and increment account number
    }
    // Getters
    string getAccountHolderName() const { return accountHolderName; }
    int getAccountNumber() const { return accountNumber; }
    string getAccountType() const { return accountType; }
    double getBalance() const { return balance; }
    double getInterestRate() const { return interestRate; }

    // Setters
    void setAccountHolderName(const string &name) { accountHolderName = name; }
    void setAccountType(const string &type) { accountType = type; }
    void setInterestRate(const double rate) { interestRate = rate; }

    // Function to deposit money
    void deposit(const double amount) {
        if (amount > 0) {
            balance += amount;
        }
        else {
            cout << "Invalid deposit amount!" << endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        }
        else {
            cout << "Invalid or insufficient funds for withdrawal!" << endl;
        }
    }

    // Function to display account information
    void displayAccountInfo() const {
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Interest Rate: " << (interestRate * 100) << "%" << endl;
    }
};

// Initialize static member variable for bank account number
int bankAccount::nextAccountNumber = 1; 

int main() {
    // Array to hold up to 10 bank accounts
    bankAccount accounts[10];

    accounts[0] = bankAccount("Alice Johnson", "Checking", 1000.00, 0.02);
    accounts[1] = bankAccount("Bob Smith", "Saving", 2500.00, 0.03);
    accounts[2] = bankAccount("Charlie Brown", "Checking", 1500.00, 0.01);

    // Use functions
    accounts[0].deposit(500);  // Deposit
    accounts[1].withdraw(300); // Withdraw

    // Display account details
    for (int i = 0; i < 3; ++i) {
        cout << "Account " << (i + 1) << " details:" << endl;
        accounts[i].displayAccountInfo();
        cout << endl;
    }

    return 0;
}