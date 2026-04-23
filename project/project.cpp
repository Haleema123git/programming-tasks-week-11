#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
    string productNames[50] = {"Shampoo", "Soap", "Toothpaste"};
    int productPrices[50] = {250, 100, 180};
    int productStock[50] = {20, 30, 15};
    int productCount = 3;

    string userNames[20] = {"manager", "employee"};
    string userRoles[20] = {"Manager", "Employee"};
    int userCount = 2;

    string saleProductNames[100];
    int saleQuantities[100];
    int saleTotals[100];
    int saleCount = 0;

    int mainChoice, choice, quantity, total, i;
    string username, password;

    while (1)
    {
        system("cls");
        cout << "==============================\n";
        cout << "      BUSINESS SYSTEM\n";
        cout << "==============================\n";
        cout << "1. Manager\n";
        cout << "2. Employee\n";
        cout << "3. Customer\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        system("cls");

        if (mainChoice == 1)
        {
            cout << "--------- MANAGER LOGIN ---------\n";
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (username == "manager" && password == "123")
            {
                while (1)
                {
                    system("cls");
                    cout << "========== MANAGER MENU ==========\n";
                    cout << "1. View Users\n";
                    cout << "2. Add Users\n";
                    cout << "3. View Products\n";
                    cout << "4. Add Products\n";
                    cout << "5. Add Stock\n";
                    cout << "6. Delete Product\n";
                    cout << "7. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    system("cls");

                    if (choice == 1)
                    {
                        cout << "----------- USERS -----------\n";
                        for (i = 0; i < userCount; i++)
                        {
                            cout << i + 1 << ". " << userNames[i] << " - " << userRoles[i] << endl;
                        }
                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 2)
                    {
                        cout << "Enter new username: ";
                        cin >> userNames[userCount];
                        cout << "Choose role\n";
                        cout << "1. Manager\n";
                        cout << "2. Employee\n";
                        cout << "Enter choice: ";
                        cin >> choice;

                        if (choice == 1)
                            userRoles[userCount] = "Manager";
                        else
                            userRoles[userCount] = "Employee";

                        userCount++;
                        cout << "User added successfully.\n";
                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 3)
                    {
                        cout << "--------- PRODUCTS ---------\n";
                        for (i = 0; i < productCount; i++)
                        {
                            cout << i + 1 << ". " << productNames[i]
                                 << " | Price: " << productPrices[i]
                                 << " | Stock: " << productStock[i] << endl;
                        }
                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 4)
                    {
                        cout << "Enter product name: ";
                        cin >> productNames[productCount];
                        cout << "Enter product price: ";
                        cin >> productPrices[productCount];
                        cout << "Enter product stock: ";
                        cin >> productStock[productCount];
                        productCount++;
                        cout << "Product added successfully.\n";
                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 5)
                    {
                        cout << "--------- PRODUCTS ---------\n";
                        for (i = 0; i < productCount; i++)
                        {
                            cout << i + 1 << ". " << productNames[i]
                                 << " | Price: " << productPrices[i]
                                 << " | Stock: " << productStock[i] << endl;
                        }

                        int stockChoice, addStock;
                        cout << "\nEnter product number: ";
                        cin >> stockChoice;
                        cout << "Enter stock to add: ";
                        cin >> addStock;

                        if (stockChoice >= 1 && stockChoice <= productCount)
                        {
                            productStock[stockChoice - 1] = productStock[stockChoice - 1] + addStock;
                            cout << "Stock added successfully.\n";
                        }
                        else
                        {
                            cout << "Invalid product number.\n";
                        }

                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 6)
                    {
                        cout << "--------- PRODUCTS ---------\n";
                        for (i = 0; i < productCount; i++)
                        {
                            cout << i + 1 << ". " << productNames[i]
                                 << " | Price: " << productPrices[i]
                                 << " | Stock: " << productStock[i] << endl;
                        }

                        int deleteChoice;
                        cout << "\nEnter product number to delete: ";
                        cin >> deleteChoice;

                        if (deleteChoice >= 1 && deleteChoice <= productCount)
                        {
                            for (i = deleteChoice - 1; i < productCount - 1; i++)
                            {
                                productNames[i] = productNames[i + 1];
                                productPrices[i] = productPrices[i + 1];
                                productStock[i] = productStock[i + 1];
                            }
                            productCount--;
                            cout << "Product deleted successfully.\n";
                        }
                        else
                        {
                            cout << "Invalid product number.\n";
                        }

                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 7)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice.\n";
                        cout << "\nPress any key...";
                        getch();
                    }
                }
            }
            else
            {
                cout << "Invalid manager username or password.\n";
                cout << "\nPress any key...";
                getch();
            }
        }
        else if (mainChoice == 2)
        {
            cout << "--------- EMPLOYEE LOGIN ---------\n";
            cout << "Enter username: ";
            cin >> username;
            cout << "Enter password: ";
            cin >> password;

            if (username == "employee" && password == "123")
            {
                while (1)
                {
                    system("cls");
                    cout << "========== EMPLOYEE MENU ==========\n";
                    cout << "1. View Products\n";
                    cout << "2. Add Products\n";
                    cout << "3. Sales History\n";
                    cout << "4. Product Price\n";
                    cout << "5. Logout\n";
                    cout << "Enter your choice: ";
                    cin >> choice;

                    system("cls");

                    if (choice == 1)
                    {
                        cout << "--------- PRODUCTS ---------\n";
                        for (i = 0; i < productCount; i++)
                        {
                            cout << i + 1 << ". " << productNames[i]
                                 << " | Price: " << productPrices[i]
                                 << " | Stock: " << productStock[i] << endl;
                        }
                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 2)
                    {
                        cout << "Enter product name: ";
                        cin >> productNames[productCount];
                        cout << "Enter product price: ";
                        cin >> productPrices[productCount];
                        cout << "Enter product stock: ";
                        cin >> productStock[productCount];
                        productCount++;
                        cout << "Product added successfully.\n";
                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 3)
                    {
                        cout << "--------- SALES HISTORY ---------\n";
                        if (saleCount == 0)
                        {
                            cout << "No sales yet.\n";
                        }
                        else
                        {
                            for (i = 0; i < saleCount; i++)
                            {
                                cout << i + 1 << ". " << saleProductNames[i]
                                     << " | Quantity: " << saleQuantities[i]
                                     << " | Total: " << saleTotals[i] << endl;
                            }
                        }
                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 4)
                    {
                        int priceChoice;
                        cout << "--------- PRODUCTS ---------\n";
                        for (i = 0; i < productCount; i++)
                        {
                            cout << i + 1 << ". " << productNames[i]
                                 << " | Price: " << productPrices[i]
                                 << " | Stock: " << productStock[i] << endl;
                        }

                        cout << "\nEnter product number: ";
                        cin >> priceChoice;

                        if (priceChoice >= 1 && priceChoice <= productCount)
                        {
                            cout << "Product: " << productNames[priceChoice - 1] << endl;
                            cout << "Price: " << productPrices[priceChoice - 1] << endl;
                        }
                        else
                        {
                            cout << "Invalid product number.\n";
                        }

                        cout << "\nPress any key...";
                        getch();
                    }
                    else if (choice == 5)
                    {
                        break;
                    }
                    else
                    {
                        cout << "Invalid choice.\n";
                        cout << "\nPress any key...";
                        getch();
                    }
                }
            }
            else
            {
                cout << "Invalid employee username or password.\n";
                cout << "\nPress any key...";
                getch();
            }
        }
        else if (mainChoice == 3)
        {
            while (1)
            {
                system("cls");
                cout << "========== CUSTOMER MENU ==========\n";
                cout << "1. View Products\n";
                cout << "2. Product Price\n";
                cout << "3. Buy Product\n";
                cout << "4. Logout\n";
                cout << "Enter your choice: ";
                cin >> choice;

                system("cls");

                if (choice == 1)
                {
                    cout << "--------- PRODUCTS ---------\n";
                    for (i = 0; i < productCount; i++)
                    {
                        cout << i + 1 << ". " << productNames[i]
                             << " | Price: " << productPrices[i]
                             << " | Stock: " << productStock[i] << endl;
                    }
                    cout << "\nPress any key...";
                    getch();
                }
                else if (choice == 2)
                {
                    int priceChoice;
                    cout << "--------- PRODUCTS ---------\n";
                    for (i = 0; i < productCount; i++)
                    {
                        cout << i + 1 << ". " << productNames[i]
                             << " | Price: " << productPrices[i]
                             << " | Stock: " << productStock[i] << endl;
                    }

                    cout << "\nEnter product number: ";
                    cin >> priceChoice;

                    if (priceChoice >= 1 && priceChoice <= productCount)
                    {
                        cout << "Product: " << productNames[priceChoice - 1] << endl;
                        cout << "Price: " << productPrices[priceChoice - 1] << endl;
                    }
                    else
                    {
                        cout << "Invalid product number.\n";
                    }

                    cout << "\nPress any key...";
                    getch();
                }
                else if (choice == 3)
                {
                    int buyChoice;
                    cout << "--------- PRODUCTS ---------\n";
                    for (i = 0; i < productCount; i++)
                    {
                        cout << i + 1 << ". " << productNames[i]
                             << " | Price: " << productPrices[i]
                             << " | Stock: " << productStock[i] << endl;
                    }

                    cout << "\nEnter product number: ";
                    cin >> buyChoice;
                    cout << "Enter quantity: ";
                    cin >> quantity;

                    if (buyChoice >= 1 && buyChoice <= productCount && quantity > 0 && quantity <= productStock[buyChoice - 1])
                    {
                        total = quantity * productPrices[buyChoice - 1];
                        productStock[buyChoice - 1] = productStock[buyChoice - 1] - quantity;

                        saleProductNames[saleCount] = productNames[buyChoice - 1];
                        saleQuantities[saleCount] = quantity;
                        saleTotals[saleCount] = total;
                        saleCount++;

                        system("cls");
                        cout << "============= RECEIPT =============\n";
                        cout << "Product  : " << productNames[buyChoice - 1] << endl;
                        cout << "Price    : " << productPrices[buyChoice - 1] << endl;
                        cout << "Quantity : " << quantity << endl;
                        cout << "Total    : " << total << endl;
                        cout << "===================================\n";
                    }
                    else
                    {
                        cout << "Invalid product number or quantity.\n";
                    }

                    cout << "\nPress any key...";
                    getch();
                }
                else if (choice == 4)
                {
                    break;
                }
                else
                {
                    cout << "Invalid choice.\n";
                    cout << "\nPress any key...";
                    getch();
                }
            }
        }
        else if (mainChoice == 4)
        {
            cout << "Thank you for using the system.\n";
            break;
        }
        else
        {
            cout << "Invalid choice.\n";
            cout << "\nPress any key...";
            getch();
        }
    }

    getch();
    return 0;
}