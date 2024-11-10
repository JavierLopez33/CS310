//
// Created by Javier on 11/10/2024.
//
#include <iostream>
#include <random>
#include <vector>

int main() {
    // Set up the random number generator
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(10.0, 100.0); // Setup number range: [10, 100]

    // Generate 25 random real numbers
    int count = 25;
    std::cout << "Random numbers between 10 and 100:" << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout <<  "#" << i + 1  << ": " << dis(gen) << std::endl;
    }

    return 0;
}