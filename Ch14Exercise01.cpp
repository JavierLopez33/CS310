#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
// Created by Javier on 11/15/2024.

// Exception class for negative numbers
class NegativeNumber : public std::exception {
public:
    const char* what() const noexcept override {
        return "Input cannot be negative.";
    }
};

// Exception class for non-digit input
class NonNumber : public std::exception {
public:
    const char* what() const noexcept override {
        return "Input must be a number.";
    }
};

// Function to validate
double getValidNumber(const std::string& prompt) {
    while (true) {
        try {
            std::cout << prompt;
            std::string input;
            std::getline(std::cin, input);

            // Check for non-numeric input
            for (char c : input) {
                if (!std::isdigit(c) && c != '.' && c != '-') {
                    throw NonNumber();
                }
            }

            double value = std::stod(input);

            // Check for negative number
            if (value < 0) {
                throw NegativeNumber();
            }

            return value;
        } catch (const NegativeNumber& e) {
            std::cerr << "Error: " << e.what() << " Please try again.\n";
        } catch (const NonNumber& e) {
            std::cerr << "Error: " << e.what() << " Please try again.\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: Invalid input. Please try again.\n";
        }
    }
}

int main() {
    std::cout << "Feet and Inches to Centimeters Converter:\n";

    // Input for length in feet
    double feet = getValidNumber("Enter length in feet: ");

    // Input for length in inches
    double inches = getValidNumber("Enter length in inches: ");

    // Conversion: 1 foot = 30.48 cm, 1 inch = 2.54 cm
    double totalCentimeters = (feet * 30.48) + (inches * 2.54);

    // Output the result
    std::cout << "The equivalent length in centimeters is: " << totalCentimeters << " cm\n";

    return 0;
}
