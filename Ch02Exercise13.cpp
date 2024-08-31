#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    // Declared the variables needed
    double originalPrice, markupPercentage, salesTaxRate;
    double sellingPrice, salesTax, finalPrice;

    // Input to read original price, markup percentage, and sales tax rate
    cout << "Enter the original price of the item: $";
    cin >> originalPrice;
    cout << "Enter the percentage of markup (without % sign): ";
    cin >> markupPercentage;
    cout << "Enter the sales tax rate (without % sign): ";
    cin >> salesTaxRate;

    // Calculate the selling price, sales tax, and final price
    sellingPrice = originalPrice + (originalPrice * (markupPercentage / 100));
    salesTax = sellingPrice * (salesTaxRate / 100);
    finalPrice = sellingPrice + salesTax;

    // Set some output formatting so currency could have 2 decimal points
    cout << fixed << setprecision(2);

    // Output the results
    cout << "\nOriginal price: $" << originalPrice << endl;
    cout << "Markup percentage: " << markupPercentage << "%" << endl;
    cout << "Selling price: $" << sellingPrice << endl;
    cout << "Sales tax rate: " << salesTaxRate << "%" << endl;
    cout << "Sales tax: $" << salesTax << endl;
    cout << "Final price of the item: $" << finalPrice << endl;

    return 0;
}