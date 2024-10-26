//
// Created by Javier on 10/26/2024.
//
#include <iostream>
#include <iomanip>
using namespace std;

// BankAccount class
class bankAccount {
protected:
    int accountNumber;
    double balance;

public:
    // Constructor
    bankAccount(int acctNum = 0, double bal = 0.0) : accountNumber(acctNum), balance(bal) {}

    // Set account number
    void setAccountNumber(int acctNum) {
        accountNumber = acctNum;
    }

    // Get account number
    int getAccountNumber() const {
        return accountNumber;
    }

    // Get balance
    double getBalance() const {
        return balance;
    }

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
        } else {
            cout << "Invalid deposit amount.\n";
        }
    }

    // Withdraw money
    virtual void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Invalid or insufficient funds for withdrawal.\n";
        }
    }

    // Print account information
    virtual void printAccountInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

// checkingAccount class
class checkingAccount : public bankAccount {
private:
    double interestRate;
    double minBalance;
    double serviceCharges;

public:
    // Constructors
    checkingAccount(int acctNum = 0, double bal = 0.0, double intRate = 0.0, double minBal = 0.0, double charges = 0.0)
        : bankAccount(acctNum, bal), interestRate(intRate), minBalance(minBal), serviceCharges(charges) {}

    // Set and get interest rate
    void setInterestRate(double intRate) {
        interestRate = intRate;
    }
    double getInterestRate() const {
        return interestRate;
    }

    // Set and get minimum balance
    void setMinBalance(double minBal) {
        minBalance = minBal;
    }
    double getMinBalance() const {
        return minBalance;
    }

    // Set and get service charges
    void setServiceCharges(double charges) {
        serviceCharges = charges;
    }
    double getServiceCharges() const {
        return serviceCharges;
    }

    // Post interest to the balance
    void postInterest() {
        balance += balance * (interestRate / 100);
    }

    // Check if balance is below minimum balance
    bool belowMinBalance() const {
        return balance < minBalance;
    }

    // Withdraw money
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            if (belowMinBalance()) {
                balance -= serviceCharges;
                cout << "Service charge of $" << serviceCharges << " applied for falling below minimum balance.\n";
            }
        } else {
            cout << "Invalid or insufficient funds for withdrawal.\n";
        }
    }

    // Print account information
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
        cout << "Minimum Balance: $" << minBalance << endl;
        cout << "Service Charges: $" << serviceCharges << endl;
    }
};

// savingsAccount class
class savingsAccount : public bankAccount {
private:
    double interestRate;

public:
    // Constructors
    savingsAccount(int acctNum = 0, double bal = 0.0, double intRate = 0.0)
        : bankAccount(acctNum, bal), interestRate(intRate) {}

    // Set and get interest rate
    void setInterestRate(double intRate) {
        interestRate = intRate;
    }
    double getInterestRate() const {
        return interestRate;
    }

    // Post interest to the balance
    void postInterest() {
        balance += balance * (interestRate / 100);
    }

    // Withdraw money
    void withdraw(double amount) override {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
        } else {
            cout << "Invalid or insufficient funds for withdrawal.\n";
        }
    }

    // Print account information
    void printAccountInfo() const override {
        bankAccount::printAccountInfo();
        cout << "Interest Rate: " << interestRate << "%" << endl;
    }
};

// Function to test classes
void testAccounts() {
    // Test checkingAccount
    checkingAccount checkAcct(12345, 500.0, 1.5, 200.0, 15.0);
    cout << "\nChecking Account Info:\n";
    checkAcct.printAccountInfo();
    checkAcct.deposit(100.0);
    checkAcct.withdraw(400.0);
    checkAcct.postInterest();
    checkAcct.printAccountInfo();

    // Test savingsAccount
    savingsAccount saveAcct(67890, 1000.0, 2.0);
    cout << "\nSavings Account Info:\n";
    saveAcct.printAccountInfo();
    saveAcct.deposit(500.0);
    saveAcct.withdraw(300.0);
    saveAcct.postInterest();
    saveAcct.printAccountInfo();
}

int main() {
    testAccounts();
    return 0;
}