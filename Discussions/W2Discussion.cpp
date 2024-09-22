#include <iostream>
using namespace std;

int main() {
    //variables
    double num1, num;
    char operation;

    // Input two numbers
    cout << "Enter a number: "
    cin >> num1;
    cout << "Enter a second number: ";
    cin >> num2;

    // Ask the user if they want to add or subtract
    cout << "Enter '+' to add or '-' to subtract: ";
    cin >> operation;

    // Perform the chosen operation
    if (operation == '+') {
        cout << "The result of addition is: " << (num1 + num2) << endl;
    } else if (operation == '-') {
        cout << "The result of subtraction is: " << (num1 - num2) << endl;
    } else {
        cout << "Invalid operation." << endl;
    }

    return 0;
}