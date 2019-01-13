#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdio.h>
#include <iomanip>
using namespace std;
struct suppliers
{
  string name[20];
  string sname[20];
  string pass[20];
  long int gstno[20];
  long int id[20];
};
suppliers supplier[20];
void login()
{
  cout<<"Enter your ID:";
  cin>>supplier[1].id[0];
  cout<<endl<<"Enter your password:";
  cin>>supplier[1].pass[0];
  cout<<endl;
}
void signup()
{
  cout<<"Enter your name:"<<endl;
  cin>>supplier[1].name[0];
  cin>>supplier[1].sname[0];
  cout<<"\nEnter your GST no.:";
  cin>>supplier[1].gstno[0];
  cout<<"\nEnter your ID:";
  cin>>supplier[1].id[0];
  cout<<"\nEnter your password:";
  cin>>supplier[1].pass[0];
  cout<<endl;
}
int main()
{
system ("cls");
supplier[0].name[0]='Virtulya';
supplier[0].sname[0]='Rajput';
supplier[0].gstno[0]=123456789;
supplier.[0].id[0]=987654321;
supplier[0].pass[0]='bestguy100';
char ask[20];
do
{
cout<<"Are you a pre-existing supplier? (Y/N)";
cin>>ask;
switch(ask[0])
{
 case 'Y':
 login();
 break;
 case 'N':
 signup();
 break;
 case 'X':

 default :
 cout<<"Invalid. Try Again\n";
 getch();
 break;
}
}while(ask[0]!='Y' && ask[0] != 'N');

}
