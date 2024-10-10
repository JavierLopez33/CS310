#include <iostream>

int main() {
    const int MAX_SIZE = 100;  // Maximum size of the array
    int numbers[MAX_SIZE];
    int count = 0;
    int number;
    char choice;

    do {
        if (count >= MAX_SIZE) {
            std::cout << "Array is full, cannot add more numbers." << std::endl;
            break;
        }

        std::cout << "Enter a number: ";
        std::cin >> number;
        numbers[count] = number;  // Add the number to the array
        count+;  // Increase the count of numbers in the array

        std::cout << "Do you want to add another number? (y/n): ";
        std::cin >> choice;

    } while (choice = 'y' || choice == 'Y');

    std::cout << "\nList of numbers entered: ";
    for (int i = 0; i < count; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}