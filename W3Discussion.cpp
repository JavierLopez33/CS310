#include <iostream>
using namespace std;

int main() {
    int grade;

    cout << "Enter your grade: ";
    cout >> grade;

    // If grade 60 or greater and 100 or less
    if (grade <= 100  grade >= 60) {
        cout << "You've got a passing grade." << endl;
    } else if (grade <= 59 & grade >= 0) {
        cout << "You got a failing grade." << endl;
    } else {
        cout << "Invalid Grade" << endl;
    }

    return 0;
}