 #include<iostream.h>
 #include<conio.h>
 #include<graphics.h>
 #include<fstream.h>
 #include<stdlib.h>
 #include<dos.h>
 int initmouseptr();
 int getmousepos(int *,int *,int *);
 //textwidth(char far *textstring);
 //textheight(char far *textstring);
 //outtextxy(int , int , char *);
 int showmouseptr();
 union REGS i,o;
int main()
{
 int gd=DETECT,gm,ch,button,x,y;
 initgraph(&gd,&gm,"c:\\tc\\bgi");

  while(1)
  {                       //start while
	 cleardevice();
	 outtextxy(100,80,"1:Create");
	 outtextxy(100,80+1*(textheight("Create")+5),"2:Deposit");
	 outtextxy(100,80+2*(textheight("Create")+5),"3:Withdraw");
	 outtextxy(100,80+3*(textheight("Create")+5),"4:Search");
	 outtextxy(100,80+4*(textheight("Create")+5),"5:Exit");
	 outtextxy(200,100,"Enter Your Choice:");

	 initmouseptr();
	 showmouseptr();
	  gotoxy(220,100);
	  while(1)               //start while
	  { getmousepos(&button,&x,&y);
		   if(x>=100&&x<=100+textwidth("1:Creation")&&y>=80&&y<=140)
			 {
			   while((button&1)==1)
					{  getmousepos(&button,&x,&y);
						if(x>=100&&x<=100+textwidth("1:Create")&&y>=80&&y<=80+textheight("1:Create"))
							{cout<<"yes1";break;}
							if(x>=100&&x<=100+textwidth("2:Deposit")&&y>=93&&y<=101)
						  {cout<<"yes 2	";break;}
						if(x>=100&&x<=100+textwidth("3:Withdraw")&&y>=106&&y<=114)
						{cout<<"yes 3";break;}
						if(x>=100&&x<=100+textwidth("4:Search")&&y>=119&&y<=127)
							 {cout<<"yes 4";break;}
						if(x>=100&&x<=100+textwidth("5:Exit")&&y>=132&&y<=140)
							{exit(1);break;}


					 }

			 }

	  }

 } //end while
 return 0;
}

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

