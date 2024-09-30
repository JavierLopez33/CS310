#include <iostream>
using namespace std;

// Function to calculate the billing amount
double calculateBilling(double hourlyRate, int consultingTime, double income) {
    double billingAmount = 0.0;

    if (income <= 25000) {
        // If income is and time <= 30 minutes, no charge
        if (consultingTime > 30) {
            int extraTime = consultingTime - 30;
            billingAmount = hourlyRate * 0.40 * (extraTime / 60.0);
        }
    } else {
        // If not low income and time <= 20 minutes, no charge
        if (consultingTime > 20) {
            int extraTime = consultingTime - 20;
            billingAmount = hourlyRate * 0.70 * (extraTime / 60.0);
        }
    }

    return billingAmount;
}

int main() {
    double hourlyRate;
    int consultingTime;
    double income;

    // Input from the user
    cout << "Enter your income: $";
    cin >> income;

    cout << "Enter the hourly rate: $";
    cin >> hourlyRate;

    cout << "Enter the total consulting time in minutes: ";
    cin >> consultingTime;

    // Calculate billing amount
    double billingAmount = calculateBilling(hourlyRate, consultingTime, income);

    // Output the billing amount
    cout << "The billing amount is: $" << billingAmount << endl;

    return 0;
}