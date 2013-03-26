#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<fstream.h>

class info
{
  private:

  public:
   void getinfo()
   {
    cout<<"\nEnter the train no: ";
    cin>>train;
    cout<<"\nDate : ";
    cin>>date;
   }
   void display();
};

class ticket
{
 public:
  void getinfo();
  void window();
  void display();
};
 void ticket::getinfo()
{
 int no,age;
 char sex,name[30];
 cout<<"How many tickets do you want to reserve ?....";
 cin>>no;
 cout<<"Enter name: ";
 cin>>name;
 cout<<"Enter age: ";
 cin>>age;
 cout<<"Enter sex: m or f :   ";
 cin>>sex;

