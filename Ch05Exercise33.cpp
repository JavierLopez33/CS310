//
// Created by Javier Lopez
//
#include <iostream>
using namespace std;

// Function to calculate the number of dishes that can be done in time t
int calculate_dishes(int a, int b, int t) {
    int time_spent = 0;  // variable to track how much time has been spent
    int num_dishes = 0;  // variable to track how many dishes can be prepared

    // Loop to check how many dishes can be made within time 't'
    while (time_spent + a <= t) {
        time_spent += a;  // adds 'a' to the time spent every loop iteration
        num_dishes++;  // 1 gets added to num_dishes every loop iteration
        a += b;  // Increase the time for the next dish
    }

    return num_dishes;
}

int main() {
    int a, b, t;

    // Prompting the user time for first dish, additional time for other dishes, and total time available
    cout << "Enter the time for the first dish (in minutes): ";
    cin >> a;
    cout << "Enter the additional time for each subsequent dish (in minutes): ";
    cin >> b;
    cout << "Enter the total available time (in minutes): ";
    cin >> t;

    // Calculate and output using the method and provide the users inputs set it to the result variable
    int total_dishes = calculate_dishes(a, b, t);
    cout << "Bianca can prepare " << total_dishes << " dishes." << endl;

    return 0;
}