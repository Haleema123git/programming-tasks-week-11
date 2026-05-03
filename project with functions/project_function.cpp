#include <iostream>
using namespace std;

// ===== FUNCTIONS =====
void pause() {
    cout << "\nPress Enter to continue...";
    cin.ignore();
    cin.get();
}

void managerMenu(string pName[], int pPrice[], int pStock[], int &pCount) {
    int choice;

    while (true) {
        system("cls");
        cout << "===== MANAGER MENU =====\n";
        cout << "1. View Products\n2. Add Product\n3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < pCount; i++)
                cout << i+1 << ". " << pName[i] << " | " << pPrice[i] << " | " << pStock[i] << endl;
        }
        else if (choice == 2) {
            cout << "Name: ";
            cin >> pName[pCount];
            cout << "Price: ";
            cin >> pPrice[pCount];
            cout << "Stock: ";
            cin >> pStock[pCount];
            pCount++;
        }
        else if (choice == 3) break;

        pause();
    }
}

void employeeMenu(string pName[], int pPrice[], int pStock[], int &pCount) {
    int choice;

    while (true) {
        system("cls");
        cout << "===== EMPLOYEE MENU =====\n";
        cout << "1. View Products\n2. Add Product\n3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < pCount; i++)
                cout << i+1 << ". " << pName[i] << endl;
        }
        else if (choice == 2) {
            cout << "Name: ";
            cin >> pName[pCount];
            cout << "Price: ";
            cin >> pPrice[pCount];
            cout << "Stock: ";
            cin >> pStock[pCount];
            pCount++;
        }
        else if (choice == 3) break;

        pause();
    }
}

void customerMenu(string pName[], int pPrice[], int pStock[], int &pCount) {
    int choice;

    while (true) {
        system("cls");
        cout << "===== CUSTOMER MENU =====\n";
        cout << "1. View Products\n2. Buy Product\n3. Logout\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            for (int i = 0; i < pCount; i++)
                cout << i+1 << ". " << pName[i]
                     << " | Price: " << pPrice[i]
                     << " | Stock: " << pStock[i] << endl;
        }
        else if (choice == 2) {
            int p, q;
            cout << "Enter product number: ";
            cin >> p;
            cout << "Enter quantity: ";
            cin >> q;

            if (p >= 1 && p <= pCount && q <= pStock[p-1]) {
                int total = q * pPrice[p-1];
                pStock[p-1] -= q;

                cout << "\n=== RECEIPT ===\n";
                cout << "Product: " << pName[p-1] << endl;
                cout << "Total: " << total << endl;
            } else {
                cout << "Invalid input\n";
            }
        }
        else if (choice == 3) break;

        pause();
    }
}

// ===== MAIN =====
int main() {
    string productNames[50] = {"Shampoo", "Soap", "Toothpaste"};
    int productPrices[50] = {250, 100, 180};
    int productStock[50] = {20, 30, 15};
    int productCount = 3;

    int choice;
    string user, pass;

    while (true) {
        system("cls");
        cout << "===== BUSINESS SYSTEM =====\n";
        cout << "1. Manager\n2. Employee\n3. Customer\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;

            if (user == "manager" && pass == "123")
                managerMenu(productNames, productPrices, productStock, productCount);
            else {
                cout << "Wrong login\n";
                pause();
            }
        }
        else if (choice == 2) {
            cout << "Username: ";
            cin >> user;
            cout << "Password: ";
            cin >> pass;

            if (user == "employee" && pass == "123")
                employeeMenu(productNames, productPrices, productStock, productCount);
            else {
                cout << "Wrong login\n";
                pause();
            }
        }
        else if (choice == 3) {
            customerMenu(productNames, productPrices, productStock, productCount);
        }
        else if (choice == 4) break;
    }

    return 0;
}