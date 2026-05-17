#include <iostream>
#include <fstream>
#include <windows.h>
#include <conio.h>

using namespace std;

void loadPerfumes(string name[], int price[],
                  int stock[], int sold[],
                  int &count)
{
    fstream file;

    file.open("perfumes.txt", ios::in);

    count = 0;

    while (count < 50 &&
           file >> name[count]
                >> price[count]
                >> stock[count]
                >> sold[count])
    {
        count = count + 1;
    }

    file.close();
}

void savePerfumes(string name[], int price[],
                  int stock[], int sold[],
                  int count)
{
    fstream file;

    file.open("perfumes.txt", ios::out);

    for (int i = 0; i < count; i = i + 1)
    {
        file << name[i] << " ";
        file << price[i] << " ";
        file << stock[i] << " ";
        file << sold[i] << endl;
    }

    file.close();
}

void addDefaultPerfumes(string name[],
                        int price[],
                        int stock[],
                        int sold[],
                        int &count)
{
    count = 8;

    name[0] = "Jasmine";
    price[0] = 1500;
    stock[0] = 20;
    sold[0] = 0;

    name[1] = "Rose";
    price[1] = 1200;
    stock[1] = 25;
    sold[1] = 0;

    name[2] = "Oud";
    price[2] = 2500;
    stock[2] = 15;
    sold[2] = 0;

    name[3] = "Musk";
    price[3] = 1800;
    stock[3] = 18;
    sold[3] = 0;

    name[4] = "Vanilla";
    price[4] = 1300;
    stock[4] = 30;
    sold[4] = 0;

    name[5] = "Sandalwood";
    price[5] = 2200;
    stock[5] = 12;
    sold[5] = 0;

    name[6] = "Amber";
    price[6] = 2000;
    stock[6] = 10;
    sold[6] = 0;

    name[7] = "Lavender";
    price[7] = 1600;
    stock[7] = 22;
    sold[7] = 0;

    savePerfumes(name, price, stock, sold, count);
}

void viewPerfumes(string name[],
                  int price[],
                  int stock[],
                  int count)
{
    cout << "\n===== PERFUME LIST =====\n";

    for (int i = 0; i < count; i = i + 1)
    {
        cout << i + 1 << ". ";
        cout << name[i];
        cout << " | Price: ";
        cout << price[i];
        cout << " | Stock: ";
        cout << stock[i];
        cout << endl;
    }
}

void managerMenu(string name[],
                 int price[],
                 int stock[],
                 int sold[],
                 int &count)
{
    int choice;

    while (true)
    {
        system("cls");

        cout << "===== MANAGER MENU =====\n";
        cout << "1. View Perfumes\n";
        cout << "2. Add Perfume\n";
        cout << "3. Delete Perfume\n";
        cout << "4. Sales Report\n";
        cout << "5. Logout\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            viewPerfumes(name, price, stock, count);
        }

        else if (choice == 2)
        {
            cout << "\nEnter Perfume Name: ";
            cin >> name[count];

            cout << "Enter Perfume Price: ";
            cin >> price[count];

            cout << "Enter Perfume Stock: ";
            cin >> stock[count];

            sold[count] = 0;

            count = count + 1;

            savePerfumes(name, price, stock, sold, count);

            cout << "\nPerfume Added Successfully!";
        }

        else if (choice == 3)
        {
            int number;

            viewPerfumes(name, price, stock, count);

            cout << "\nEnter Perfume Number To Delete: ";
            cin >> number;

            if (number >= 1 && number <= count)
            {
                int index;

                index = number - 1;

                for (int i = index;
                     i < count - 1;
                     i = i + 1)
                {
                    name[i] = name[i + 1];
                    price[i] = price[i + 1];
                    stock[i] = stock[i + 1];
                    sold[i] = sold[i + 1];
                }

                count = count - 1;

                savePerfumes(name, price, stock, sold, count);

                cout << "\nPerfume Deleted Successfully!";
            }

            else
            {
                cout << "\nInvalid Perfume Number!";
            }
        }

        else if (choice == 4)
        {
            cout << "\n===== SALES REPORT =====\n";

            for (int i = 0; i < count; i = i + 1)
            {
                cout << i + 1 << ". ";
                cout << name[i];
                cout << " | Sold: ";
                cout << sold[i];
                cout << " | Remaining Stock: ";
                cout << stock[i];
                cout << endl;
            }
        }

        else if (choice == 5)
        {
            break;
        }

        else
        {
            cout << "\nInvalid Choice!";
        }

        cout << "\n\nPress Any Key To Continue...";
        getch();
    }
}

void employeeMenu(string name[],
                  int price[],
                  int stock[],
                  int sold[],
                  int &count)
{
    int choice;

    while (true)
    {
        system("cls");

        cout << "===== EMPLOYEE MENU =====\n";
        cout << "1. View Perfumes\n";
        cout << "2. Add Perfume\n";
        cout << "3. Logout\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            viewPerfumes(name, price, stock, count);
        }

        else if (choice == 2)
        {
            cout << "\nEnter Perfume Name: ";
            cin >> name[count];

            cout << "Enter Perfume Price: ";
            cin >> price[count];

            cout << "Enter Perfume Stock: ";
            cin >> stock[count];

            sold[count] = 0;

            count = count + 1;

            savePerfumes(name, price, stock, sold, count);

            cout << "\nPerfume Added Successfully!";
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            cout << "\nInvalid Choice!";
        }

        cout << "\n\nPress Any Key To Continue...";
        getch();
    }
}

void customerMenu(string name[],
                  int price[],
                  int stock[],
                  int sold[],
                  int &count)
{
    int choice;

    while (true)
    {
        system("cls");

        cout << "===== CUSTOMER MENU =====\n";
        cout << "1. View Perfumes\n";
        cout << "2. Buy Perfume\n";
        cout << "3. Logout\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            viewPerfumes(name, price, stock, count);
        }

        else if (choice == 2)
        {
            int perfumeNumber;
            int quantity;

            viewPerfumes(name, price, stock, count);

            cout << "\nEnter Perfume Number: ";
            cin >> perfumeNumber;

            cout << "Enter Quantity: ";
            cin >> quantity;

            if (perfumeNumber >= 1 &&
                perfumeNumber <= count)
            {
                int index;

                index = perfumeNumber - 1;

                if (quantity > 0 &&
                    quantity <= stock[index])
                {
                    int totalBill;

                    totalBill =
                    quantity * price[index];

                    stock[index] =
                    stock[index] - quantity;

                    sold[index] =
                    sold[index] + quantity;

                    savePerfumes(name,
                                 price,
                                 stock,
                                 sold,
                                 count);

                    cout << "\n===== RECEIPT =====\n";

                    cout << "Perfume Name: ";
                    cout << name[index] << endl;

                    cout << "Price: ";
                    cout << price[index] << endl;

                    cout << "Quantity: ";
                    cout << quantity << endl;

                    cout << "Total Bill: ";
                    cout << totalBill << endl;

                    cout << "Remaining Stock: ";
                    cout << stock[index] << endl;
                }

                else
                {
                    cout << "\nNot Enough Stock!";
                }
            }

            else
            {
                cout << "\nInvalid Perfume Number!";
            }
        }

        else if (choice == 3)
        {
            break;
        }

        else
        {
            cout << "\nInvalid Choice!";
        }

        cout << "\n\nPress Any Key To Continue...";
        getch();
    }
}

main()
{
    string perfumeName[50];

    int perfumePrice[50];
    int perfumeStock[50];
    int perfumeSold[50];

    int perfumeCount = 0;

    int choice;

    string username;
    string password;

    loadPerfumes(perfumeName,
                 perfumePrice,
                 perfumeStock,
                 perfumeSold,
                 perfumeCount);

    if (perfumeCount == 0)
    {
        addDefaultPerfumes(perfumeName,
                           perfumePrice,
                           perfumeStock,
                           perfumeSold,
                           perfumeCount);
    }

    while (true)
    {
        system("cls");

        cout << "===== PERFUME SHOP MANAGEMENT SYSTEM =====\n";

        cout << "1. Manager Login\n";
        cout << "2. Employee Login\n";
        cout << "3. Customer\n";
        cout << "4. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "\nEnter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            if (username == "manager" &&
                password == "123")
            {
                managerMenu(perfumeName,
                            perfumePrice,
                            perfumeStock,
                            perfumeSold,
                            perfumeCount);
            }

            else
            {
                cout << "\nWrong Manager Login!";
                getch();
            }
        }

        else if (choice == 2)
        {
            cout << "\nEnter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

            if (username == "employee" &&
                password == "123")
            {
                employeeMenu(perfumeName,
                             perfumePrice,
                             perfumeStock,
                             perfumeSold,
                             perfumeCount);
            }

            else
            {
                cout << "\nWrong Employee Login!";
                getch();
            }
        }

        else if (choice == 3)
        {
            customerMenu(perfumeName,
                         perfumePrice,
                         perfumeStock,
                         perfumeSold,
                         perfumeCount);
        }

        else if (choice == 4)
        {
            cout << "\nThank You For Using System!";
            break;
        }

        else
        {
            cout << "\nInvalid Choice!";
            getch();
        }
    }
}