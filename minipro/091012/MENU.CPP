#include<stdio.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#include<alloc.h>

char *menu[]={"Reservation","Train Enquiry","Search","Reservation Status","Cancellation","Exit"};
union REGS i,o;

void main()
{
  int gd=DETECT,gm,choice=1,bill=0,width=0,i,count;
  char **buffer;

  initgraph(&gd,&gm,"c:\\tc\\bgi");

  if(initmouse()==0)
    {
      printf("\nUnable to intialize Mouse......");
      exit();
     }
  count=sizeof(menu)/sizeof(char*) ;
  settextstyle(TRIPLEX_FONT,0,3);
  displaymenu(menu,count,100,100);

  for(i=0;i<count;i++)
     {
       if (textwidth(menu[i])>width)
	   width=textwidth(menu[i]);
      }

   buffer=malloc(sizeof(menu));
   savemenu(menu,buffer,width,count,100,100);

   while(choice!=6)
     {
	choice=getrresponse(menu,buffer,width,count,100,100);
	gotoxy(50,15);
	printf("You have selected %s",menu[choice-1]);
      }
   }

    displaymenu(char **menu,int count,int x1,int y1)
    {
      int i,h;
      h=textheight(menu[0]) ;

      for(i=0;i<count;i++)
	  outtextxy(x1,y1+i*(h+5),menu[i]);
     }

     savemenu(char **menu,char **buffer,int width, int count,int x1,int y1)
     {
       int i,x2,yy1,yy2,area,h;
       h=textheight(menu[0]);

       for(i=0;i<count;i++)
       {
	 x2=x1+width;
	 yy1=y1+i*(h+5);
	 yy2=y1+(i+1)*(h+5);

	 area=imagesize(x1,yy1,x2,yy2);
	 buffer[i]=malloc(area);
	 getimage(x1,yy1,x2,yy2,buffer[i]);
	}
     }

     getresponse(char **menu,char **buffer,int width,int count,int x1,int y1)
     {
       int choice=1,prevchoice=0,x,y,x2,y2,button;
       int in,i,h;

       h=textheight(menu[0]);
       y2=y1+count*(h+5);
       x2=x1+width;
       rectangle(x1-5,y1-5,x2+5,y2+5);

       while(1)
	{
	  getmousepos(&button,&x,&y);

	  if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
	  {
	     in=1;

	     for(i=1;i<=count;i++)
	     {
		if(y<=y1+i*(h+5))
		{
		  choice=i;
		  break;
		}
	      }

	     if(prevchoice!=choice)
	     {
	       hidemouseptr();
	       highlight(buffer,choice,h,x1,y1);

	       if(prevchoice)
		  dehighlight(buffer,prevchoice,h,x1,y1);

		  prevchoice=choice;
		  showmouseptr();
		}

	       if((button & 1)==1)
	       {
		 while((button & 1)==1)
		   getmousepos(&button,&x,&y);

		 if(x>=x1&&x<=x2&&y>=y1&&y<=y2)
		  return(choice);
		}
	      }
	    else
	    {
	    if(in==1)
		  {
		  in=0;
		  prevchoice=0;
		  hidemouseptr();
		  dehighlight(buffer,choice,h,x1,y1);
		  showmouseptr();
		 }
	       }
	     }
	   }

	  highlight(char **buffer,int ch,int h,int x1,int y1)
	  {
	   putimage(x1,y1+(ch-1)*(h+5),buffer[ch-1],NOT_PUT);
	  }

	  dehighlight(char**buffer,int ch,int h,int x1,int y1)
	  {
	   putimage(x1,y1+(ch-1)*(h+5),buffer[ch-1],COPY_PUT);
	  }

	  initmouse()
	  {
	   i.x.ax=1;
	   int86(0x33,&i,&o);
	   return(o.x.ax);
	  }

	  showmouseptr()
	  {
	    i.x.ax=1;
	    int86(0x33,&i,&o);
	   }
	  hidemouseptr()
	  {
	    i.x.ax=2;
	    int86(0x33,&i,&o);
	   }

	getmouseptr(int*button,int*x,int*y )
	  {
	    i.x.ax=3;
	    int86(0x33,&i,&o);
	    *button=o.x.bx;
	    *x=o.x.cx;
	    *y=o.x.dx;
	  }