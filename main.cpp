#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib> // For system() function
#include <conio.h> // For getch() function
using namespace std;

int choicels;
void login();
void signup();
int login_menu();

const int NUM_ROOMS = 15;
const int NUM_FOOD_ITEMS = 15;
const int NUM_DESSERT_ITEMS = 5;

int ch;
int total;
string reservations[NUM_ROOMS][2];
string food_items[NUM_FOOD_ITEMS][2];
string dessert_items[NUM_DESSERT_ITEMS][2];

void initializeRooms()
{
    for (int i = 0; i < NUM_ROOMS; ++i)
    {
        reservations[i][0] = to_string(i + 1);
        reservations[i][1] = "0";
    }
}

void initializeFoodItems()
{
    for (int i = 0; i < NUM_FOOD_ITEMS; ++i)
    {
        food_items[i][0] = to_string(i + 1);
        food_items[i][1] = to_string((i + 1) * 100);
    }
}

void initializeDessertItems()
{
    for (int i = 0; i < NUM_DESSERT_ITEMS; ++i)
    {
        dessert_items[i][0] = to_string(i + 1);
        dessert_items[i][1] = to_string((i + 1) * 200);
    }
}

void displayRooms()
{
    system("cls");
    cout << "LIST OF AVAILABLE ROOMS:" << endl;
    for (int i = 0; i < NUM_ROOMS; ++i)
    {
        cout << "ROOM NUMBER " << i + 1 << ": ";
        if (reservations[i][1] == "0")
            cout << "Available" << endl;
        else
            cout << "Occupied by " << reservations[i][1] << endl;
    }
}

void reserveRoom()
{
    system("cls");
    int room_no;
    cout << "Enter the room number you want to reserve (1-" << NUM_ROOMS << "): ";
    cin >> room_no;

    if (room_no >= 1 && room_no <= NUM_ROOMS)
    {
        if (reservations[room_no - 1][1] == "0")
        {
            cout << "Enter your name: ";
            cin >> reservations[room_no - 1][1];
            cout << "Room reserved successfully!" << endl;
        }
        else
        {
            cout << "Sorry, the room is already occupied." << endl;
        }
    }
    else
    {
        cout << "Invalid room number." << endl;
    }
}

void checkOut()
{
    system("cls");
    int room_no;
    cout << "Enter the room number to check-out (1-" << NUM_ROOMS << "): ";
    cin >> room_no;

    if (room_no >= 1 && room_no <= NUM_ROOMS)
    {
        if (reservations[room_no - 1][1] != "0")
        {
            cout << "Checking out room " << room_no << ". Thank you for staying!" << endl;
            reservations[room_no - 1][1] = "0";
        }
        else
        {
            cout << "This room is not currently occupied." << endl;
        }
    }
    else
    {
        cout << "Invalid room number." << endl;
    }
}

int orderFood()
{
    system("cls");
    char ch_food;
    total = 0; // Reset total
    do
    {
        int f_ch_d;
        int f_ch;
        int d_ch;
        cout << "FOOD MENU" << endl;
        cout << "1. FOOD ITEMS" << endl;
        cout << "2. DESSERT ITEMS" << endl;
        cin >> f_ch_d;

        switch (f_ch_d)
        {
        case 1:
            cout << "-------------------------------" << endl;
            cout << "| Serial |   Food Item   | Price |" << endl;
            cout << "-------------------------------" << endl;

            for (int i = 0; i < NUM_FOOD_ITEMS; ++i)
            {
                cout << "|   " << food_items[i][0] << "   | Food Item " << food_items[i][0] << " | " << food_items[i][1] << " |" << endl;
            }

            cout << "-------------------------------" << endl;

            cout << "Enter Sr of Food Item " << endl;
            cin >> f_ch;
            if (f_ch >= 1 && f_ch <= NUM_FOOD_ITEMS)
            {
                cout << "SUCCESSFULLY ORDERED" << endl;
                total += stoi(food_items[f_ch - 1][1]);
                cout << "Total Amount: " << total << endl;
            }
            else
            {
                cout << "Invalid selection." << endl;
            }
            break;

        case 2:
            cout << "        DESSERT ITEMS         " << endl;
            cout << "-------------------------------" << endl;
            cout << "| ITEM NUMBER |     ITEM       | Price |" << endl;
            cout << "-------------------------------" << endl;

            for (int j = 0; j < NUM_DESSERT_ITEMS; ++j)
            {
                cout << "|    " << dessert_items[j][0] << "      | Dessert Item " << dessert_items[j][0] << " | " << dessert_items[j][1] << endl;
            }

            cout << "-----------------------------" << endl;

            cout << "Enter Sr of Desert Item " << endl;
            cin >> d_ch;
            if (d_ch >= 1 && d_ch <= NUM_DESSERT_ITEMS)
            {
                cout << "SUCCESSFULLY ORDERED" << endl;
                total += stoi(dessert_items[d_ch - 1][1]);
                cout << "Total Amount: " << total << endl;
            }
            else
            {
                cout << "Invalid selection." << endl;
            }
            break;

        default:
            cout << "Invalid choice." << endl;
        }

        cout << "Do you want to continue ordering (Y/N)? ";
        cin >> ch_food;

    } while (ch_food == 'Y' || ch_food == 'y');

    return total;
}

void generateReceipt(int roomNumber)
{
    const int roomRent = 5000;
    const int serviceCharge = 2000;

    cout << "------------RECEIPT--------------" << endl;
    cout << "Room Charges: " << roomRent << endl;
    cout << "Service Charges: " << serviceCharge << endl;
    cout << "Food Charges: " << total << endl;
    int totalBill = roomRent + serviceCharge + total;
    cout << "Total Bill: " << totalBill << endl;
}

void displayMenu()
{
    system("cls");
    cout << "--------------- WELCOME TO THE HOTEL MANAGEMENT SYSTEM ---------------" << endl;
    cout << "1. DISPLAY AVAILABLE ROOMS" << endl;
    cout << "2. RESERVE A ROOM" << endl;
    cout << "3. CHECK-OUT FROM ROOM" << endl;
    cout << "4. ORDER FOOD" << endl;
    cout << "5. Exit" << endl;
}

void menu()
{
    initializeRooms();
    initializeFoodItems();
    initializeDessertItems();

    do
    {
        displayMenu();
        cout << "Enter your choice (1-5): ";
        cin >> ch;

        switch (ch)
        {
        case 1:
            displayRooms();
            break;
        case 2:
            reserveRoom();
            break;
        case 3:
            checkOut();
            break;
        case 4:
            total = orderFood();
            break;
        case 5:
            cout << "Exiting the Hotel Management System. Thank you!" << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }

    } while (ch != 5);
}

void login()
{
    system("cls");
    int flag = 0;
    string name, name1, password, password1;
    cout << "ENTER YOUR DETAILS :" << endl;
    cout << "username: ";
    cin >> name;
    cout << "password: ";
    cin >> password;

    ifstream fin("details.txt"); // Open file for reading
    while (fin >> name1 >> password1)
    {
        if (name == name1 && password == password1)
        {
            flag = 1;
            break;
        }
    }
    fin.close(); // Close the file

    if (flag == 1)
    {
        cout << "LOGIN SUCCESSFUL!" << endl;
        getch();
        menu(); // Call menu() instead of main()
    }
    else
    {
        cout << "YOUR DETAILS ARE NOT CORRECT! " << endl;
        getch();
        login_menu(); // Go back to login menu
    }
}

void signup()
{
    system("cls");
    string name, password;
    cout << "ENTER YOUR DETAILS :" << endl;
    cout << "username: ";
    cin >> name;
    cout << "password: ";
    cin >> password;

    ofstream fout("details.txt", ios::app); // Open file for writing (append mode)
    fout << name << ' ' << password << endl;
    fout.close(); // Close the file

    cout << "SIGNUP SUCCESSFUL!" << endl;
    getch();
    login_menu(); // Go back to login menu
}

int login_menu()
{
    cout << "WELCOME TO HOTEL MANAGEMENT SYSTEM" << endl;
    cout << "1- SIGNUP" << endl;
    cout << "2- LOGIN" << endl;

    cout << "ENTER CHOICE : ";
    cin >> choicels;

    if (choicels == 2)
    {
        login();
        return 1;
    }
    else if (choicels == 1)
    {
        signup();
    }
    else
    {
        cout << "ERROR! PLEASE TRY AGAIN" << endl;
    }
    return 1;
}

int main()
{
    login_menu(); // Start with login menu
    return 0;
}
