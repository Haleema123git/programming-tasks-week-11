#include <iostream>
#include <string>
using namespace std;

// Function prototype
string checkAlphabetCase(char ch);

int main() {
    char letter;
    
    cout << "Enter a character (A/a): ";
    cin >> letter;
    
    string result = checkAlphabetCase(letter);
    cout << result << endl;
    
    return 0;
}

// Function definition
string checkAlphabetCase(char ch) {
    if (ch == 'A') {
        return "You have entered Capital A";
    } else if (ch == 'a') {
        return "You have entered small a";
    } else {
        return "Invalid input! Please enter A or a only.";
    }
}