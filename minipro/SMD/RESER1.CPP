#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>
#include<graphics.h>


void show();

class first
{
 private :
  int refno,seatno,age;
  char name[50],sex,srtstn[25],desstn[25];
 // float fare,totfare;

 public :
  void display1();
  void gin();
  void gout();
 // void table();
};

void first::display1()
{
 cout<<"\n\n\n\t\t----------------------------------------";
 cout<<"\n\t\t\t****INDIAN RAILWAYS****";
 cout<<"\n\t\t------------------------------------------";
 cout<<"\n\t\tCHATRAPATI SHAHU TERMINUS,KOLHAPUR\n";
}

void first::gin()
{
 cleardevice();
 cout<<"\nEnter your name :";
 fflush(stdin);
 gets(name);

 cout<<"Enter your age :";
 fflush(stdin);
 cin>>age;


 cout<<"Enter your sex :";
 fflush(stdin);
 cin>>sex;
/* if ('m'||sex!='M'||sex!='f'||sex!='F')
   {
     cout<<"\nEnter a valid sex!!";
     cout<<"Enter your sex :";
     fflush(stdin);
     cin>>sex;
   }
  */
 cout<<"Enter starting station :";
 fflush(stdin);
 gets(srtstn);

 cout<<"Enter destination station :";
 fflush(stdin);
 gets(desstn);
  cout<<"\n\n\n\nPlease press ENTER..........\n";
 getch();
}

void first::gout()
{
 cleardevice();
 display1();
 cout<<"\n\n";
 cout<<"\nName :"<<name<<"\t\tAge :"<<age<<"\t\tSex :"<<sex;
 cout<<"\n\nStarting Station :"<<srtstn<<"\t\tDestination station :"<<desstn<<"\n\n";
 cout<<"\n\n\n\nPlease press ENTER..........\n";

 getch();
 }



void enter()
{
 fstream file,temp;
 first f1;
// file.open("trains.txt",ios::app);
 temp.open("ticket.txt",ios::out);

 char x;

  f1.gin();
//  file.write((char*)&f1,sizeof f1);
  temp.write((char*)&f1,sizeof f1);
//  file.close();
  temp.close();
}

void showtrain()
{
 fstream fs;
 first f1;
 fs.open("trains.txt",ios::in);
 while(fs.read((char*)&f1,sizeof f1))
 {
   f1.gout();
 }
 fs.close();
 }


void showticket()
{
 fstream fs;
 first f1;
 fs.open("ticket.txt",ios::in);
 while(fs.read((char*)&f1,sizeof f1))
 {
   f1.gout();
 }
 fs.close();
 cout<<"\n\n\nPlease press ENTER..............";
 }


void res(int n)
{
 clrscr();
 first r;
 int ch;
 while(n!=0)
  {
     enter();
     showticket();
     n--;
   }


}


