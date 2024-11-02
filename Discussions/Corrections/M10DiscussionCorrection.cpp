#include <iostream>

using namespace std;

int main()
{
    double cost;
    double* costPtr = &cost;

    int transNum;
    int* numPtr = &transNum;

    cout << "Transaction Number " << *numPtr << ": " << *costPtr;
}