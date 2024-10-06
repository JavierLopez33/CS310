#include <iostream>
#include <string>
using namespace std;

// This function will check if a character is a vowel
bool isVowel(char ch) {
    ch = tolower(ch); // covert the char to lowercase
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

// This function will remove vowels from a string
string removeVowels(string str) {
    string result = "";
    for (char ch : str) {
        if (!isVowel(ch)) {
            result += ch; // Add the character if it is not a vowel
        }
    }
    return result;
}

int main() {
    string input;

    // Prompt the user to input a string
    cout << "Enter a word or sentance: ";
    getline(cin, input); // used getLine instead of cin >> input; to allow for sentances not just single words

    // Remove the vowels and output the modified string
    string noVowels = removeVowels(input);
    cout << "Input after removing vowels: " << noVowels << endl;

    return 0;
}