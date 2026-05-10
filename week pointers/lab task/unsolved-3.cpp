#include <iostream>
using namespace std;

// Function to reverse array using pointers
void reverseArray(int *arr, int size) {
    int *start = arr;
    int *end = arr + size - 1;

    while (start < end) {
        int temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}

int main() {
    int n;

    cout << "Enter size of array: ";
    cin >> n;
    int *arr = new int[n];

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> *(arr + i);
    }

    reverseArray(arr, n);

    cout << "Reversed array:\n";
    for (int i = 0; i < n; i++) {
        cout << *(arr + i) << " ";
    }

    delete[] arr;

    return 0;
}