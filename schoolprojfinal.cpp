#include <iostream.h>
#include <fstream.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>

void hr(int x)
{
  cout << "+";
  for (int i = 0; i < x; i++)
    cout << "-";
  cout << "+ \n";
}

//Cart Class
class cart
{
public:
  int qty;
  char product_no[20];
  char product_name[100];
  long int product_cost;
  char product_color[100];

  int view_cart()
  {
    int empty = 0;
    int length;
    ifstream cart_file;
    cart s;
    //Open File
    cart_file.open("cart.txt", ios::in | ios::binary);
    //Check If file is Empty
    cart_file.seekg(0, ios::end);   // put the "cursor" at the end of the file
    length = cart_file.tellg();     // find the position of the cursor
    cart_file.close();
    if(length == 0)
    {
      empty = 1;
      cout << "Empty Cart";
    }
    else
    {
      ifstream cart_file;
      cart s;
      //Open File
      cart_file.open("cart.txt", ios::in | ios::binary);
      int i = 1;
      cout << "| Sno | Product No.|   Product    |   Cost   | Qty |  Color   |" << endl;
      do
      {
        cart_file.read((char *)&s, sizeof(s));
        cout << "   " << i << "     " << s.product_no << "       " << s.product_name << "         $" << s.product_cost << "      " << s.qty<< "     "<< s.product_color << "\n";
        hr(60);
        i++;
      } while (cart_file.read((char*)&s, sizeof(s)));
      cart_file.close();
    }
    return empty;
    }
};

//Supplier Class Starts
class supplier
{
  //Supplier
  char supplier_name[100];
  char supplier_password[20];
  char supplier_sname[100];
  char supplier_username[100];
  //Product
public:
  char product_no[20];
  char product_name[100];
  float product_cost;
  char product_color[100];

  void supplier_product_input();  // Product input
  void view_product();            //Shows Products supplier by supplier
  void view_supplier();           //Shows Supplier details
  void supplier_signup();         //Supplier Registration
  void supplier_login();          //Supplier Login
  void supplier_menu();           //Supplier Menu
};

void supplier::supplier_product_input()
{
  fstream product_file;
  supplier s;

  //User Input
  clrscr();
  cout << "|| Welcome To Product Selling ||\n";
  cout << "Enter product name\n";
  cin >> s.product_name;
  cout << "Enter Product No\n";
  cin >> s.product_no;
  cout << "Enter Product Cost\n";
  cin >> s.product_cost;
  cout << "Enter Product Color\n";
  cin >> s.product_color;

  //File Input
  product_file.open("products.txt", ios::out | ios::app | ios::binary);
  product_file.write((char *)&s, sizeof(s));
  product_file.close();

  cin.get();
  cin.ignore();
}

void supplier::view_product()
{
  int length;
  ifstream product_file;
  supplier s;
  //Open File
  product_file.open("products.txt", ios::in | ios::binary);
  //Check If file is Empty
  product_file.seekg(0, ios::end);  // put the "cursor" at the end of the file
  length = product_file.tellg();    // find the position of the cursor
  product_file.close();
  if(length == 0)
      cout << "empty";
  else
  {
    ifstream product_file;
    supplier s;
    //Open File
    product_file.open("products.txt", ios::in | ios::binary);
    int i = 1;
    cout << "| Sno | Product No.|   Product    |   Cost   |   Color   |" << endl;
    do
    {
      product_file.read((char *)&s, sizeof(s));
      cout << "   " << i << "     " << s.product_no << "       " << s.product_name << "       " << s.product_cost << "$        " << s.product_color << "\n";
      hr(54);
      i++;
    } while (product_file.read((char*)&s, sizeof(s)));
    product_file.close();
  }
  cin.get();
  cin.ignore();
}

void supplier::view_supplier()
{
  int length;
  ifstream supply_file;
  supplier s;
  //Open File
  supply_file.open("supplier.txt", ios::in | ios::binary);
  //Check If file is Empty
  supply_file.seekg(0, ios::end);   // put the "cursor" at the end of the file
  length = supply_file.tellg();     // find the position of the cursor
  supply_file.close();
  if(length == 0)
      cout << "empty";
  else
  {
    ifstream supply_file;
    supplier s;
    //Open File
    supply_file.open("supplier.txt", ios::in | ios::binary);
    int i = 1;
    do
    {
      supply_file.read((char *)&s, sizeof(s));
      cout << "   " << i << "     " << s.supplier_username << "       " << s.supplier_password << "        "
           << "\n";
      hr(43);
      i++;
    } while (supply_file.read((char *)&s, sizeof(s)));
    supply_file.close();
  }
  cin.ignore();
  cin.get();
}

void supplier::supplier_signup()
{
  clrscr();
  fstream supply_file;
  supplier s;

  //User Input
  cout << "Enter your Details\n";
  cout << "Enter your first name: ";
  cin >> s.supplier_name;
  cout << endl;
  cout << "\nEnter your last name: ";
  cin >> s.supplier_sname;
  cout << endl;
  cout << "\nEnter your Username: ";
  cin >> s.supplier_username;
  cout << endl;
  cout << "\nEnter your password: ";
  cin >> s.supplier_password;
  cout << endl;

  //File Input
  supply_file.open("supplier.txt", ios::out | ios::app | ios::binary);
  supply_file.write((char *)&s, sizeof(s));
  supply_file.close();
}

void supplier::supplier_login()
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
  while (supply_file.read((char *)&s, sizeof(s)))
  {
    if ((strcmp(s.supplier_username, x.supplier_username) == 0) && (strcmp(s.supplier_password, x.supplier_password) == 0))
          present = 1;
  }
  supply_file.close();
  if (present == 1)
    supplier_product_input();
  else
  {
    cout << "Record Not Found! Try signing up";
    cin.get();
    cin.ignore();
  }
}

void supplier::supplier_menu()
{
  char x;
  do
  {
    clrscr();
    cout << "|| Welcome To Supplier Area ||\n"<< "\n[1]Login\n\n[2]Signup\n\n([0] to exit)\n > ";
    cin >> x;
    if (x == '1')
    {
      clrscr();
      supplier_login();
    }
    else if (x == '2')
    {
      clrscr();
      supplier_signup();
    }
    else if (x == 'x')
    {
      clrscr();
      view_supplier();
    }
    else if (x == 'y')
    {
      clrscr();
      view_product();
    }
    else
    {
      cout << "Enter valid input";
    }
  } while (x != '0');
}
//Supplier Funtions End

//Customer Class starts
class customer
{
  //About customer
  char customer_name[100];
  char customer_password[20];
  char customer_sname[100];
  char customer_username[100];
  char customer_address[100];
  long int customer_mobile;

  //Product
  long int product_no;
  char product_name;
  float product_cost;
  char product_color[100];

public:
  void view_product();            //Shows Products
  void marketplace_menu();        //Shows Marketplace
  void buy();                     //Buying Products
  void customer_cart();           //Cart
  void checkout();                //Checkout
  void view_customer();           //Shows customer details
  void customer_signup();         //customer Registration
  void customer_login();          //customer Login
  void customer_menu();           //customer Menu

};

void customer::view_product()
{
  supplier s;
  s.view_product();
}

void customer::marketplace_menu()
{
  clrscr();
  char choice;
  do
  {
    clrscr();
    cout << "|| Welcome To Marketplace ||\n\n[1] Buy\n\n[2] Cart\n\n[3] Checkout\n\n([0] Exit)";
    cin >> choice;
    if (choice == '1')
    {
      buy();
    }
    else if (choice == '2')
    {
      customer_cart();
    }
    else if (choice == '3')
    {
      checkout();
    }
    else
    {
      cout << "Enter valid input";
    }
  } while (choice != '0');
}

void customer::buy()
{
  clrscr();
  char serial_no[10];
  cout << "\n\t\t\t || Buy || \t \t \n\n";
  view_product();
  cout << "\nTo choose product, type its Product No. Below:\n";
  cin >> serial_no;
  ifstream product_file;
  supplier s;
  //Open File
  product_file.open("products.txt", ios::in | ios::binary);
  do
  {
    product_file.read((char*)&s, sizeof(s));
    if ((strcmp(s.product_no, serial_no) == 0))   //If present add into cart
    {
      cart c;
      cout << "\n Enter Quantity :\n";
      int qnt;
      cin>>qnt;
      //Putting Values Into Cart
      strcpy(c.product_name,s.product_name);
      c.qty = qnt;
      strcpy(c.product_no,serial_no);
      c.product_cost = s.product_cost;
      strcpy(c.product_color,s.product_color);
      fstream cart_file;
      cart_file.open("cart.txt",ios::out|ios::app|ios::binary);
      cart_file.write((char*)&c, sizeof(c));
      cart_file.close();
    }
  } while (product_file.read((char*)&s, sizeof(s)));
  product_file.close();
}

void customer::customer_cart()
{
  cart cc;
  clrscr();
  cout << " \t \t || Your Cart || \t \t \n\n";
  cc.view_cart();
  cin.get();
  cin.ignore();
}

void customer::checkout()
{
  clrscr();
  ifstream cart_file;
  cart s;
  int sum = 0;
  //Open File
  cart_file.open("cart.txt", ios::in | ios::binary);
  do
  {
    cart_file.read((char *)&s, sizeof(s));
    sum = sum + (s.product_cost*s.qty);
  } while (cart_file.read((char*)&s, sizeof(s)));
  cart_file.close();
  cart x;
  char pchoice[20];
  do
  {
    clrscr();
    cout << "\n|| Checkout ||\n" << endl << "Items in cart: \n\n";
    int empty = x.view_cart();
    if(empty== 1)
    {
      cout << "\n Sorry Your cart is empty, please buy something..\n";
      cin.get();
      cin.ignore();
      break;
    }
    else
    {
      cout << " Choose your payment method: " << endl << "\nMENU\n" << "\n 1]Credit/Debit card \n 2]Paytm \n 3]Back \nEnter Response: \n";
      cin>> pchoice;

      switch (pchoice[0])
      {
        case '1':
          int one,two,three,four,cvv;
          char pur;
          cout  << "Outstanding Amt. to be payed = $" << sum << "\n Enter Card Number: \n";
          cin >> one >> two >> three >> four;
          cout << "Enter CVV\n";
          cin >> cvv;
          cout << "Are you sure to purchase(Y/N): \n";
          cin >> pur;
          if(pur == 'Y' || pur == 'y')
          {
            cout << "Transaction completed\n";
            fstream d;
            fstream f;
            d.open("cart.txt",ios::out|ios::in|ios::binary);
            f.open("temp.txt",ios::out|ios::binary);
            remove("cart.txt");
            rename("temp.txt","cart.txt");
            d.close();
            f.close();
            cin.get();
            cin.ignore();
            marketplace_menu();
          }
          break;

        case '2':
          int phone,otp;
          char purch;
          cout  << "Outstanding Amt. to be payed = $" << sum << "\n Enter Phone Number: \n";
          cin >> phone;
          cout << "Enter OTP (Use anything as default)\n";
          cin >> otp;
          cout << "Are you sure to purchase(Y/N): ";
          cin >> purch;
          if(purch == 'Y' || purch == 'y')
          {
            cout << "Transaction completed\n";
            fstream d,f;
            d.open("cart.txt",ios::out|ios::in|ios::binary);
            f.open("temp.txt",ios::out|ios::binary);
            remove("cart.txt");
            rename("temp.txt","cart.txt");
            d.close();
            f.close();
            marketplace_menu();
          }
          break;

        case 3:
          break;
        default:
          cout << "Invalid input try again" << '\n';
          cin.ignore();
          cin.get();
          break;
    //If no of items in cart >= 1, then checkout
      }
  }
  }while(pchoice[0]!='3');
      }

void customer::view_customer()
{
  ifstream customer_file;
  customer s;
  customer_file.open("customer.txt", ios::in | ios::binary);
  int i = 1;
  do
  {
    customer_file.read((char *)&s, sizeof(s));
    cout << "   " << i << "     " << s.customer_username << "       " << s.customer_password << "        " << "\n";
    hr(43);
    i++;
  } while (customer_file.read((char *)&s, sizeof(s)));
  customer_file.close();
  cin.ignore();
  cin.get();
}

void customer::customer_signup()
{
  clrscr();
  fstream customer_file;
  customer s;
  cout << "Enter your Details\n";
  cout << "Enter your first name: ";
  cin >> s.customer_name;
  cout << endl;
  cout << "\nEnter your last name: ";
  cin >> s.customer_sname;
  cout << endl;
  cout << "\nEnter your Username: ";
  cin >> s.customer_username;
  cout << endl;
  cout << "\nEnter your password: ";
  cin >> s.customer_password;
  cout << endl;
  cout << "\nEnter Shipping Address: ";
  cin >> s.customer_address;
  cout << endl;
  cout << "\nEnter Mobile Number: ";
  cin >> s.customer_mobile;
  cout << endl;
  customer_file.open("customer.txt", ios::out | ios::app | ios::binary);
  customer_file.write((char *)&s, sizeof(s));
  customer_file.close();
}

void customer::customer_login()
{
  int present;
  customer x;
  cout << "Enter your Username: ";
  cin >> x.customer_username;
  cout << "\nEnter your password: ";
  cin >> x.customer_password;
  cout << endl;
  present = 0;
  ifstream customer_file;
  customer s;
  customer_file.open("customer.txt", ios::in | ios::binary);
  //Looping and reading all file contents
  while (customer_file.read((char *)&s, sizeof(s)))
  {
    if ((strcmp(s.customer_username, x.customer_username) == 0) && (strcmp(s.customer_password, x.customer_password) == 0))
              present = 1;
  }
  customer_file.close();
  if (present == 1)
  {
    marketplace_menu();
    // cout << "Successfully Logged in!\n";
  }
  else
  {
    cout << "Record Not Found! Try signing up";
    cin.get();
    cin.ignore();
  }
}

void customer::customer_menu()
{
  char x;
  do
  {
    clrscr();
    cout << "|| Welcome To Customer Menu||\n" << "[1]Login\n[2]Signup \n([0] to exit)\n > ";
    cin >> x;
    if (x == '1')
    {
      clrscr();
      customer_login();
    }
    else if (x == '2')
    {
      clrscr();
      customer_signup();
    }
    else if (x == 'x')
    {
      clrscr();
      view_customer();
    }
    else if (x == 'y')
    {
      clrscr();
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
//Customer Funtions End

//Home Menu Starts
void menu()
{
  char a;
  //Do menu starts
  do
  {
    clrscr();
    cout << "|| Welcome to Estore where you can buy or supply Electronic Products! ||\n" << "\n[1] Supplier \n\n[2] Customer \n\n([0] to Exit)\n> ";
    cin >> a;
    if (a == '1')
    {
      clrscr();
      supplier supply_session;
      supply_session.supplier_menu();
    }
   else if (a == '2')
    {
      clrscr();
      customer customer_session;
      customer_session.customer_menu();
    }
    else if (a == '0')
    {
      break;
    }
    else
    {
      cout << "Enter Valid Character";
    }
  } while (a != '0');
}

int main()
{
  clrscr();
  menu();
  return 0;
  getch();
}
