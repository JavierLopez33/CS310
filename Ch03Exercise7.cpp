#include <iostream>
#include <iomanip>  // for formatting output
#include <locale>   // for thousands separator

using namespace std;

int main() {
    // Variables
    double netBalance, payment, interestRate, averageDailyBalance, interest;
    int d1, d2;

    // Input: netBalance, payment, d1 (days in billing cycle), d2 (days before payment), and interest rate per month
    cout << "Enter the net balance: $";
    cin >> netBalance;
    cout << "Enter the payment: $";
    cin >> payment;
    cout << "Enter the number of days in the billing cycle: ";
    cin >> d1;
    cout << "Enter the number of days payment is made before the billing cycle: ";
    cin >> d2;
    cout << "Enter the monthly interest rate (0.0152 for 1.52%): ";
    cin >> interestRate;

    // Calculate the average daily balance
    averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    // Calculate the interest on the unpaid balance
    interest = averageDailyBalance * interestRate;

    // Format and display the output with two decimal places and thousands separator
    cout << fixed << setprecision(2);  // Set precision to 2 decimal places
    locale loc("");                    // Locale for the thousands separator
    cout.imbue(loc);                   // Apply the locale

    cout << "The interest on the unpaid balance is: $" << interest << endl;

    return 0;
}