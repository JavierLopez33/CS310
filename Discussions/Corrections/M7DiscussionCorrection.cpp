//Max Jankowski
//Week 7 Discussion
//Example of chapter 8 programming exercise 2

#include <iostream>
using namespace std;

// Function to find the index of the first occurrence of the smallest element
int smallIndex(int arr[], int size) {

    if (size == 0) {  //Check to see if array is empty

        return -1; //If empty
    }

    int minIndex = 1;  //Init and declaring minIndex

    for (int i = 1; i < size; i++) { //Loop to compare elements in the array
        if (arr[i] < arr[minIndex]) {
            minIndex = i; // Update minIndex when a smaller element is found
        }
    }

    return minIndex; //Returns smallest element of array to minIndex variable
}

int main() {
    // Test array
    int arr[] = {10, 20, 5, 8, 5, 3, 6, 3};
    //calculating the size of the array
    int size = sizeof(arr) / sizeof(arr[0]);

    // Find and print the index of the smallest element
    int index = smallIndex(arr, size);

    if (index != -1) {
        cout << "The index of the first occurrence of the smallest element is:  " << index << endl;
        cout << "The smallest element is:  " << arr[index] << endl;
    } else {
        cout << "The array is empty. " << endl;
    }

    return 0;
}