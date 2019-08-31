#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
using namespace std;

void hr(int x){
    cout << "+";
    for(int i=0;i<x;i++){
        cout << "-";
    }
    cout << "\n";
}
void cls(){
    system("cls");
}

class supplier{
    //About Supplier
    char supplier_name[100];
    char supplier_password[20];
    char supplier_sname[100];
    char supplier_username[100];
    //Product
    char product_name[100];
    long int product_cost;
    char product_color[100];
    char product_symbol[100];
    public:
        void supplier_product_input()
        {
            cout << "|| Welcome To Product Selling || \nEnter product name\n";
            cin >> product_name;
            cout  << "Enter Product Cost\n";
            cin >> product_cost;
            cout << "Enter Product Color\n";
            cin >> product_color;
            cout << "Enter Product Color Symbol in [color] form\n";
            cin >> product_symbol;
            cin.get();
            cin.ignore();
        }
        void product_file_input()
        {
            fstream product_file;
            supplier s;
            s.supplier_product_input();
            product_file.open("products.txt", ios::out | ios::app | ios::binary);
            product_file.write((char*)&s, sizeof(s));
            product_file.close();
        }
        void view_product(){
            ifstream product_file;
            supplier s;
            product_file.open("products.txt",ios::in|ios::binary);
            int i = 1;
            cout << "| Sno |   Product    |   Cost   |   Color   |" << endl;
            do
            {
                product_file.read((char*)&s, sizeof(s));
                cout <<"   " << i <<"     "<< s.product_name << "       "<< s.product_cost << "$        " << s.product_color << "\n";
                hr(43);
                i++;
            }
            while(product_file.read((char*)&s, sizeof(s)));
            product_file.close();
            cin.ignore();
            cin.get();
        }

        void view(){
            ifstream product_file;
            supplier s;
            product_file.open("supplier.txt",ios::in|ios::binary);
            int i = 1;
            do
            {
                product_file.read((char*)&s, sizeof(s));
                cout <<"   " << i <<"     "<< s.supplier_username << "       "<< s.supplier_password << "        " <<"\n";
                hr(43);
                i++;
            }
            while(product_file.read((char*)&s, sizeof(s)));
            product_file.close();
            cin.ignore();
            cin.get();
        }

        void supplier_signup()
        {
            cls();
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
            present = 0;
            ifstream supply_file;
            supplier s;
            supply_file.open("supplier.txt", ios::in | ios::binary);
            //Looping and reading all file contents
            while (supply_file.read((char*)&s, sizeof(s)))
            {

                if ((strcmp(s.supplier_username, x.supplier_username) == 0) && (strcmp(s.supplier_password, x.supplier_password) == 0))
                    present = 1;

            }
            supply_file.close();
            if(present == 1){
                product_file_input();
            }
            else{
                cout << "Record Not Found! Try signing up";
                cin.get();
                cin.ignore();
            }
        }

    void supplier_file_input()
    {
        fstream supply_file;
        supplier s;
        s.supplier_signup();
        supply_file.open("supplier.txt", ios::out|ios::app|ios::binary);
        supply_file.write((char*)&s, sizeof(s));
        supply_file.close();
    }

    void supplier_menu()
    {
        char x;
        do
        {   system("cls");
            cout << "|| Welcome To Supplier Area ||\n"
                 << "\n[1]Login\n\n[2]Signup\n\n([0] to exit)\n > ";
            cin >> x;
            if (x == '1')
            {
                cls();
                supplier_login();
            }
            else if (x == '2')
            {
                cls();
                supplier_file_input();
            }
            else if (x == 'x')
            {
                cls();
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
};

class customer{
    //About customer
    char customer_name[100];
    char customer_password[20];
    char customer_sname[100];
    char customer_username[100];
    //Product
    char product_name[100];
    long int product_cost;
    char product_color[100];
    char product_symbol[100];
    public:

        void marketplace_menu()
        {
          cls();
          char choice;
          do{
            cout << "|| Welcome To Marketplace || \n[1] Buy\n[2] Cart\n([0] Exit)";
            cin>>choice;
            if(choice == '1')
            {
              buy();
            }
            else if(choice == '2')
            {
              cart();
            }
            else
            {
              cout<<"Enter valid input";
            }
          }while(choice != '0');
        }

        void buy()
        {
          cls();
          view_product();
          cout<<"\n\nChoose the number of the corresponding product you want to choose:\n";

          // checkout();


        }

        void cart()
        {

        }

        // void checkout();
        // {
        //   //If no of items in cart >= 1, then checkout
        // }

        // void product_file_input()
        // {
        //     fstream product_file;
        //     customer s;
        //     s.customer_product_input();
        //     product_file.open("products.txt", ios::out | ios::app | ios::binary);
        //     product_file.write((char*)&s, sizeof(s));
        //     product_file.close();
        // }

        void view_product(){
            ifstream product_file;
            customer s;
            product_file.open("products.txt",ios::in|ios::binary);
            int i = 1;
            cout << "| Sno |   Product    |   Cost   |   Color   |" << endl;
            do
            {
                product_file.read((char*)&s, sizeof(s));
                cout <<"   " << i <<"     "<< s.product_name << "       "<< s.product_cost << "$        " << s.product_color << "\n";
                hr(43);
                i++;
            }
            while(product_file.read((char*)&s, sizeof(s)));
            product_file.close();
            cin.ignore();
            cin.get();
        }

        void view(){
            ifstream product_file;
            customer s;
            product_file.open("customer.txt",ios::in|ios::binary);
            int i = 1;
            do
            {
                product_file.read((char*)&s, sizeof(s));
                cout <<"   " << i <<"     "<< s.customer_username << "       "<< s.customer_password << "        " <<"\n";
                hr(43);
                i++;
            }
            while(product_file.read((char*)&s, sizeof(s)));
            product_file.close();
            cin.ignore();
            cin.get();
        }

        void customer_signup()
        {
            cls();
            cout << "Enter your Details\n";
            cout << "Enter your first name: ";
            cin >> customer_name;
            cout << endl;
            cout << "\nEnter your last name: ";
            cin >> customer_sname;
            cout << endl;
            cout << "\nEnter your Username: ";
            cin >> customer_username;
            cout << endl;
            cout << "\nEnter your password: ";
            cin >> customer_password;
            cout << endl;
        }
        void customer_login()
        {
            int present;
            customer x;
            cout << "Enter your Username: ";
            cin >> x.customer_username;
            cout << "\nEnter your password: ";
            cin >> x.customer_password;
            cout << endl;
            present = 0;
            ifstream supply_file;
            customer s;
            supply_file.open("customer.txt", ios::in | ios::binary);
            //Looping and reading all file contents
            while (supply_file.read((char*)&s, sizeof(s)))
            {

                if ((strcmp(s.customer_username, x.customer_username) == 0) && (strcmp(s.customer_password, x.customer_password) == 0))
                    present = 1;

            }
            supply_file.close();
            if(present == 1){
                marketplace_menu();
            }
            else{
                cout << "Record Not Found! Try signing up";
                cin.get();
                cin.ignore();
            }
        }

    void customer_file_input()
    {
        fstream customer_file;
        customer s;
        s.customer_signup();
        customer_file.open("customer.txt", ios::out|ios::app|ios::binary);
        customer_file.write((char*)&s, sizeof(s));
        customer_file.close();
    }

    void customer_menu()
    {
        char x;
        do
        {   system("cls");
            cout << "|| Welcome To Customer Menu||\n"
                 << "\n[1]Login\n\n[2]Signup \n\n([0] to exit)\n > ";
            cin >> x;
            if (x == '1')
            {
                cls();
                customer_login();

            }
            else if (x == '2')
            {
                cls();
                customer_file_input();
            }
            else if (x == 'x')
            {
                cls();
                view_product();
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
};


void menu(){
    char a;
    //Do menu starts
    do{
        system("cls");
        cout << "|| Welcome to Estore where you can buy or supply Electronic Products! ||\n"
             << "\n[1] Supplier \n\n[2] Customer \n\n([0] to Exit)\n> ";
        cin >> a;
        if (a == '1')
        {
            cls();
            supplier supply_session;
            supply_session.supplier_menu();

    }
    else if (a == '2')
    {
        cls();
        customer customer_session;
        customer_session.customer_menu();
    }
    else if (a == '0')
    {
        break;
    }

    else{
        cout << "Invalid Input, Try Again.";
    }

    }while(a!='0');
//Menu 1 ends


}

    int main(){
        system("cls");
        menu();
        return 0;
    }
