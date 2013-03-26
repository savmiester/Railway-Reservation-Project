
		//Project on railway reservation


#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<RESER1.CPP>
#include<LAS.CPP>

int seats[73]={0};
void res(int n);
 int initmouseptr();
 int getmousepos(int *,int *,int *);
 int showmouseptr();
 union REGS i,o;
class train
 {
 int t1;
 int t2;
 int t3;
  public:
  train()
  {
   t1=34;
   t2=44;
   t3=25;
  }
  int ns,csn,av_seat,tn;
  void getinfo(int n);
  void reservation(int n);
  void cancelation();

  };                 //end class

train trn[4];

      //SEATS AVAILABLE IN THE TRAIN
	void train:: getinfo(int n)
	{         if(n==111)
		  trn[1].av_seat=t1;
		  else if(n==112)
		  trn[2].av_seat=t2;
		  else if(n==113)
		  trn[3].av_seat=t3;

		cout<<endl<<"\nAVAILABLE SEATS FOR RESERVATION ARE: " <<av_seat<<endl;
		cout<<endl<<"------------------------------------------------\n";
		reservation(72-av_seat);
	 delay(4000);
	} //end getinfo

      //RESERVATION FUNCTION
void train::reservation(int n)
{
 ns=n;
 fflush(stdin);
 setbkcolor(BLACK);

  for(int i=1;i<=72;i++)
 {
   if(seats[i]==0)
   {
     seats[i]=1;
     ns--;
      if(ns==0)
       break;
   } //end if
 }  //end for

 for(i=1;i<=72;i++)
 {
   cout<<seats[i]<<" ";
   if(i%10==0)
    cout<<"\n";
 }
	    //end for
}               	// end reservation


 //CANCELLATION FUNCTION
void train::cancelation()
{
  int n;
  //fflush(stdin);
  setbkcolor(BLACK);
  cout<<"Enter how many seats you wants to cancel:";
  fflush(stdin);
  cin>>n;
  cout<<"Enter your seat no:";
  for(int k=1;k<=n;k++)
  {
 // fflush(stdin);
  cin>>csn;
  if(seats[csn]==1)
 {  seats[csn]=0;
    cout<<"\nTicket for seat no."<< csn<<" is canceled"<<endl;
   }
  else if (seats[csn]==0)
  {
   cout<<"\n Seat no."<<csn<<" is already canceled\n";
   }
   }


  for(int i=1;i<=72;i++)
  {
    cout<<seats[i]<<" ";
    if(i%10==0)
      cout<<"\n";
  }	//end for
  cout<<"\nPlease wait for the process to complete......\n ";
  delay(3500);
}                //end cancelation




void main()
{
 int gd=DETECT,gm,x,y,j,p,q,button;
 int n;
 char s[10],ch;
 clrscr();
 initgraph(&gd,&gm,"C:\\tc\\bgi");
 train t;
 int no;
	setbkcolor(BLACK);
	cout<<"\n\n\n\n\n*******************************************************************************";
	settextstyle(TRIPLEX_FONT,HORIZ_DIR,2);
	outtextxy(120,100,"       INDIAN RAILWAYS ");
	outtextxy(120,120," AUTOMATED RESERVATION SYSTEM");
	cout<<"\n\n\n\n\n*******************************************************************************";

	settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
	//delay(4000);
	cleardevice();
	cout<<"\n\n\n\n\t\t\t\tLOADING....";
       //	delay(1000);
	cleardevice();

    xyz:do
	{
	cleardevice();
	fflush(stdin);
	cout<<endl<<"\t\t"<<"WEL-COME";
	cout<<endl<<"-----------------------------------------------------------------------";
	cout<<endl<<"\t"<<"TRAIN NO"<<"\t"<<"TRAIN NAME"<<"\t"<<"FROM"<<"\t\t"<<"TO";
	cout<<endl<<"-----------------------------------------------------------------------";
	cout<<endl<<"\t"<<"111"<<"\t\t"<<"MAHALAXMI EXP  "<<"\t"<<"KOLHAPUR"<<"\t"<<"MUMBAI";
	cout<<endl<<endl<<"\t"<<"112"<<"\t\t"<<"SAHYADRI EXP  "<<"\t"<<"KOLHAPUR"<<"\t"<<"MUMBAI";
	cout<<endl<<endl<<"\t"<<"113"<<"\t\t"<<"RANI CHANNAMA EXP"<<"\t"<<"KOLHAPUR"<<"\t"<<"BANGLORE";
	cout<<endl<<"-----------------------------------------------------------------------";

		cout<<endl<<"\nENTER TRAIN NO: ";
		 fflush(stdin);
		cin>>no;
		cout<<"\nAre you sure(Y/N): ";
		fflush(stdin);
		cin>>ch;

	}while(ch=='N'||ch=='n');                //end do while
		switch(no)
		{
		case 111:
			cleardevice();
			cout<<endl<<endl<<"TRAIN NAME:"<<"MAHALAXMI EXP";
			cout<<endl<<"------------------------------------------------";
			cout<<endl<<endl<<"\t"<<"FROM"<<"\t\t"<<"TO";
			cout<<endl<<"------------------------------------------------";
			cout<<endl<<endl<<"\t"<<"KOLHAPUR"<<"\t"<<"MUMBAI";
			cout<<endl<<"\t"<<"(8:00 PM)"<<"\t"<<"(6:00 AM)";
			trn[1].getinfo(no);
			break;

		case 112:
			cleardevice();
			cout<<endl<<endl<<"TRAIN NAME:"<<"SAHYADRI EXP";
			cout<<endl<<"------------------------------------------------";
			cout<<endl<<endl<<"\t"<<"FROM"<<"\t\t"<<"TO";
			cout<<endl<<"------------------------------------------------";
			cout<<endl<<"\t"<<"KOLHAPUR"<<"\t"<<"MUMBAI";
			cout<<endl<<"\t"<<"(11:30 PM)"<<"\t"<<"(11:00 AM)";
			trn[2].getinfo(no);
			break;

		case 113:
			cleardevice();
			cout<<endl<<endl<<"TRAIN NAME:"<<"RANI CHANNAMA EXP";
			cout<<endl<<"------------------------------------------------";
			cout<<endl<<endl<<"\t"<<"FROM"<<"\t\t"<<"TO";
			cout<<endl<<"------------------------------------------------";
			cout<<endl<<"\t"<<"KOLHAPUR"<<"\t"<<"BANGLORE";
			cout<<endl<<"\t"<<"(2:30 PM)"<<"\t"<<"(1:00 PM)";
			trn[3].getinfo(no);
			break;

		default:
		       cout<<"YOU ENTER WRONG TRAIN NO";
		       delay(1500);
		       goto xyz;



		}//end switch
smd:
while(1)
  {                  //start while
    cleardevice();
    //fflush(stdin);
    outtextxy(250,380,"1:Reserve");
    outtextxy(250,380+1*(textheight("Reserve")+5),"2:Cancel");
    outtextxy(250,380+2*(textheight("Reserve")+5),"3:Display");
    outtextxy(250,380+3*(textheight("Reserve")+5),"4:Exit");
   // outtextxy(250,380+4*(textheight("Reserve")+5),"5:Exit");
    outtextxy(250,360,"Select ur option:");

    initmouseptr();
    showmouseptr();
    gotoxy(220,100);
    while(1)               //start while
    { getmousepos(&button,&x,&y);
      if(x>=250&&x<=250+textwidth("1:Reserve")&&y>=380&&y<=440)
      {
       while((button&1)==1)
       {
	getmousepos(&button,&x,&y);
	if(x>=250&&x<=250+textwidth("1:Reserve")&&y>=380&&y<=380+textheight("1:Reserve"))
	{
	 cleardevice();
	 fflush(stdin);
	 cout<<"Enter how many seats u want to reserve:";
	 cin>>n;
	 t.reservation(n);
	 res(n);
	 goto smd;

	}
	if(x>=250&&x<=250+textwidth("2:Cancel")&&y>=393&&y<=401)
	{
	 cleardevice();
	 t.cancelation();
	 goto smd;
	}
	if(x>=250&&x<=250+textwidth("3:Display")&&y>=406&&y<=414)
	{
	  goto abc;
	 }
	if(x>=250&&x<=250+textwidth("4:Exit")&&y>=419&&y<=427)
	{
	 last();
	}
      /*	if(x>=250&&x<=250+textwidth("5:Exit")&&y>=432&&y<=440)
	{ last();}*/
       }
      }
    }
 }   //end while
 abc:
   cleardevice();

  x=70;
  y=10;
 rectangle(10,10,566,200);
 for(int i=1;i<=9;i++)
 {
   line(x,y,x,200);
    if(i!=9)
      line(x+2,y,x+2,200);
  line(x-40,y,x-40,y+114);
  line(x-60,y+114,x-40,y+114);
  line(x-60,y+38,x-40,y+38);
  line(x-60,y+76,x-40,y+76);
  line(x-20,y,x-20,y+114);
  line(x-20,y+114,x,y+114);
  line(x-20,y+38,x,y+38);
  line(x-20,y+76,x,y+76);
  line(x-60,y+152,x-40,y+152);
  line(x-40,y+152,x-40,y+190);
  line(x-20,y+152,x,y+152);
  line(x-20,y+152,x-20,y+190);
  x=x+62;
 }       //end for
 x=70;
 y=10;
 settextstyle(2,HORIZ_DIR,4);
 for(j=1;j<=72;)
 {
    if(seats[j]==0)
      setcolor(WHITE);
    else
      setcolor(RED);
    itoa(j,s,10);
    outtextxy(x-50,y+170,s);

    if(seats[j+1]==0)
      setcolor(WHITE);
    else
      setcolor(RED);
    itoa(j+1,s,10);
    outtextxy(x-10,y+170,s);

    if(seats[j+2]==0)
      setcolor(WHITE);
    else
      setcolor(RED);
    itoa(j+2,s,10);
    outtextxy(x-50,y+95,s);

    if(seats[j+3]==0)
      setcolor(WHITE);
    else
      setcolor(RED);
    itoa(j+3,s,10);
    outtextxy(x-50,y+57,s);

    if(seats[j+4]==0)
      setcolor(WHITE);
    else
      setcolor(RED);
    itoa(j+4,s,10);
    outtextxy(x-50,y+19,s);

    if(seats[j+5]==0)
      setcolor(WHITE);
    else
      setcolor(RED);
    itoa(j+5,s,10);
    outtextxy(x-10,y+95,s);

    if(seats[j+6]==0)
      setcolor(WHITE);
    else
      setcolor(RED);
    itoa(j+6,s,10);
    outtextxy(x-10,y+57,s);

    if(seats[j+7]==0)
      setcolor(WHITE);
    else
      setcolor(RED);
    itoa(j+7,s,10);
    outtextxy(x-10,y+19,s);

    j=j+8;
    x=x+61;
    outtextxy(100,400,"Please press ENTER..........\n");

 }
 getch();
 goto smd;
}        //end for


  //end main


 initmouseptr()
  {
   i.x.ax=0;
   int86(0x33,&i,&o);
   return(o.x.ax);
  }
  getmousepos(int *button,int *x,int *y)
  {
   i.x.ax=3;
   int86(0x33,&i,&o);
   *button=o.x.bx;
   *x=o.x.cx;
   *y=o.x.dx;
   return 0;
  }

	showmouseptr()
	{
	 i.x.ax=1;
	 int86(0x33,&i,&o);
	 return 0;
	}
