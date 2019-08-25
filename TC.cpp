#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <conio.h>

void clear()
{
    clrscr();
}

class supplier
{
    //About Supplier
    char supplier_name[50];
    char supplier_password[50];
    char supplier_sname[50];
    char supplier_username[50];
    //Product
    char product_name[50];
    long int product_cost;
    char product_color[12];
    char product_symbol[10];

public:
    void supplier_product_input()
    {
        cout << "Welcome To Supply Area. \nEnter Prouct name\n";
        cin >> product_name;
        cout << "Enter Product Cost\n";
        cin >> product_cost;
        cout << "Enter Product Color\n";
        cin >> product_color;
        cout << "Enter Product Color Symbol in [color] form\n";
        cin >> product_symbol;
    }
    void product_file_input()
    {
        fstream product_file;
        supplier s;
        s.supplier_product_input();
        product_file.open("products.txt", ios::app | ios::binary);
        product_file.write((char *)&s, sizeof(s));
        product_file.close();
    }
    // void view()
    // {
    //     ifstream product_file;
    //     supplier s;
    //     product_file.open("products.txt");
    //     product_file.read((char *)&s, sizeof(s));
    //     while (!product_file.eof())
    //     {
    //         cout << s.product_name << " " << s.product_cost;
    //     }
    //     product_file.close();
    // }
    void supplier_signup()
    {
        clear();
        cout << "Enter your Details\n";
        cout << "Enter your first name: ";
        cin >> supplier_name;
        cout << endl;
        cout << "\nEnter your last name: ";
        cin >> supplier_sname;
        cout << endl;
        cout << "\nEnter your Username: ";
        cin >> supplier_username;
        cout << endl;
        cout << "\nEnter your password: ";
        cin >> supplier_password;
        cout << endl;
    }
    void supplier_login()
    {
        int present;
        supplier x;
        cout << "Enter your Username: ";
        cin >> x.supplier_username;

        cout << "\nEnter your password: ";
        cin >> x.supplier_password;
        cout << endl;
        supplier_login_check(x, present);
        if (present == 1)
        {
            product_file_input();
        }
        else
        {
            cout << "Record Not Found! Try signing up";
        }
    }
    // void supplier_login_check(supplier x, int &present)
    // {
    //     //Checking if record is present in file;
    //     present = 0;
    //     fstream supply_file;
    //     supplier s;
    //     supply_file.open("supplier.txt", ios::in | ios::binary);
    //     //Looping and reading all file contents
    //     while (supply_file.read((char *)&s, sizeof(s)))
    //     {
    //         if (s.supplier_username == x.supplier_username && s.supplier_password == x.supplier_password)
    //         {
    //             present = 1;
    //         }
    //     }
    //     supply_file.close();
    // }

    void supplier_file_input()
    {
        fstream supply_file;
        supplier s;
        s.supplier_signup();
        supply_file.open("supplier.txt", ios::app | ios::binary);
        supply_file.write((char *)&s, sizeof(s));
        supply_file.close();
    }

    // void supplier_menu()
    // {
    //     char x;
    //     do
    //     {
    //         cout << "\nWelcome To Supplier Area. \n Do you have an Existing account?\n"
    //              << "[1]Yes [2]No (Press 0 to exit)";
    //         cin >> x;
    //         if (x == '1')
    //         {
    //             clear();
    //             supplier_login();
    //         }
    //         else if (x == '2')
    //         {
    //             clear();
    //             supplier_file_input();
    //         }
    //         else if (x == 'x')
    //         {
    //             clear();
    //             view();
    //         }
    //
    //         else if (x == '0')
    //         {
    //             break;
    //         }
    //
    //         else
    //         {
    //             cout << "Enter valid input";
    //         }
    //
    //     } while (x != '0');
    // }
};

void supplier::view()
{
    ifstream product_file;
    supplier s;
    product_file.open("products.txt");
    product_file.read((char *)&s, sizeof(s));
    while (!product_file.eof())
    {
        cout << s.product_name << " " << s.product_cost;
    }
    product_file.close();
}

void supplier::supplier_login_check(supplier x, int &present)
{
    //Checking if record is present in file;
    present = 0;
    fstream supply_file;
    supplier s;
    supply_file.open("supplier.txt", ios::in | ios::binary);
    //Looping and reading all file contents
    while (supply_file.read((char *)&s, sizeof(s)))
    {
        if (s.supplier_username == x.supplier_username && s.supplier_password == x.supplier_password)
        {
            present = 1;
        }
    }
    supply_file.close();
}

void supplier::supplier_menu()
{
    char x;
    do
    {
        cout << "\nWelcome To Supplier Area. \n Do you have an Existing account?\n"
             << "[1]Yes [2]No (Press 0 to exit)";
        cin >> x;
        if (x == '1')
        {
            clear();
            supplier_login();
        }
        else if (x == '2')
        {
            clear();
            supplier_file_input();
        }
        else if (x == 'x')
        {
            clear();
            view();
        }

        else if (x == '0')
        {
            break;
        }

        else
        {
            cout << "Enter valid input";
        }

    } while (x != '0');
}

void menu()
{
    char a;
    //Do menu starts
    do
    {

        cout << "Welcome to Estore where you can buy or supply Electronic Products!\n"
             << "Are you a [1] Supplier or [2] Customer ? (Enter the character corresponding to the action. Press [0] to Exit)\n";
        cin >> a;
        if (a == '1')
        {
            clear();
            supplier supply_session;
            supply_session.supplier_menu();
        }
        else if (a == '2')
        {
            clear();
            cout << "hi broke";
        }
        else if (a == '0')
        {
            break;
        }

        else
        {
            cout << "Tri dont cri";
        }

    } while (a != '0');
    //Menu 1 ends
}
void main()
{
    clrscr();
    menu();
    getch();
}
