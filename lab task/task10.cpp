#include <iostream>
#include <string>
using namespace std;

// Function prototype
string numberToWords(int number);

int main()
{
    int num;

    cout << "Enter a number (1-99): ";
    cin >> num;

    // Input validation
    if (num < 1 || num > 99)
    {
        cout << "Please enter a number between 1 and 99!" << endl;
        return 1;
    }

    string result = numberToWords(num);
    cout << result << endl;

    return 0;
}

// Function definition
string numberToWords(int number)
{
    // Arrays for words
    string ones[] = {"", "One", "Two", "Three", "Four", "Five",
                     "Six", "Seven", "Eight", "Nine"};

    string teens[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen",
                      "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

    string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty",
                     "Sixty", "Seventy", "Eighty", "Ninety"};

    // Case 1: Number 1–9 (single digit)
    if (number < 10)
    {
        return ones[number];
    }

    // Case 2: Number 10–19 (teens - special case)
    else if (number < 20)
    {
        return teens[number - 10];
    }

    // Case 3: Number 20–99 (two digits)
    else
    {
        int tensDigit = number / 10; // Tens place
        int onesDigit = number % 10; // Ones place

        if (onesDigit == 0)
        {
            // Multiple of ten: 20, 30, 40...
            return tens[tensDigit];
        }
        else
        {
            // Example: 25 → "Twenty" + "Five" = "TwentyFive"
            return tens[tensDigit] + ones[onesDigit];
        }
    }
}