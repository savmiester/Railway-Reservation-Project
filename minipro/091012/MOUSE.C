#include<stdio.h>
#include<stdlib.h>
#include<dos.h>
#include<graphics.h>
#include<conio.h>
union REGS i,o;
main()
{
 int gd=DETECT,gm,maxx,maxy,x,y,button;

 initgraph(&gd,&gm,"c:\\tc\\bgi");

 maxx=getmaxx();
 maxy=getmaxy();

 rectangle(0,56,maxx,maxy);
 setviewport(1,57,maxx-1,maxy-1,1);
 gotoxy(26,1);
 printf("Mouse Demonstration Program");

 if(initmouse()==0)
 {
 closegraph();
 restorecrtmode();
 printf("\nMouse driver not loaded");
 exit(1);
 }

 restrictmouseptr(1,57,maxx-1,maxy-1);
 showmouseptr();
 gotoxy(1,2);
 printf("left button");
 gotoxy(15,2);
 printf("right button");
 gotoxy(55,3);
 printf("press any key to exit");

 while(!kbhit())
 {
  getmousepos(&button,&x,&y);

  gotoxy(5,3);
  (button &1)==1 ? printf("DOWN"):printf("UP");

  gotoxy(20,3);
  (button &2)==2 ? printf("DOWN"):printf("UP");
  gotoxy(65,2);
  printf("X=%03d y=%03d",x,y);
   }
   return 0;
  }
  initmouse()
  {
  i.x.ax=0;
  int86(0x33,&i,&o);
  return(o.x.ax);
  }
  showmouseptr()
  {
  i.x.ax=1;
  int86(0x33,&i,&o);
  return 0;
  }
  restrictmouseptr(int x1,int y1,int x2,int y2)
  {
  i.x.ax=7;
  i.x.cx=x1;
  i.x.dx=x2;

  i.x.ax=8;
  i.x.cx=y1;
  i.x.dx=y2;
  int86(0x33,&i,&o);
  return 0;
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

