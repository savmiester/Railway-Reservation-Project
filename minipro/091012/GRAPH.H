/* Graphics Programs */
/*Probable front page of our mini projext*/
#include<graphics.h>
#include<conio.h>
#include<stdio.h>
#include<dos.h>

void graph()
{
   int gd=DETECT,gm;
   initgraph(&gd,&gm,"c:\\tc\\bgi");
   setcolor(YELLOW);
   line(220,30,338,30);
   rectangle(10,10,625,470);
   setcolor(WHITE);
   rectangle(5,5,630,475);
   outtextxy(220,20,"****WELCOME****");
   setcolor(GREEN);
   settextstyle(GOTHIC_FONT,HORIZ_DIR,0);
   outtextxy(100,40,"RAILWAY RESERVATION");
   setcolor(WHITE);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,0);
   outtextxy(40,100,"Software Developed By:-");
   outtextxy(40,120,"SAVIO D'SOUZA           Roll.No: 10");
   outtextxy(40,140,"MAYUR DESAI             Roll.No: 12");
   outtextxy(40,160,"SUDARSHAN DEVARDEKAR    Roll.No: 09");
   outtextxy(40,200,"Under Guidance Of:-");
   outtextxy(40,220,"Mr. A M PATRAVALE");
   outtextxy(200,300,"Department Of,");
   outtextxy(130,320,"COMPUTER SCIENCE & ENGINEERING");
   outtextxy(200,400,"BHRATI VIDYAPEETH'S");
   outtextxy(130,420,"COLLEGE OF ENGINEERING , KOLHAPUR.");
   setbkcolor(BROWN);
   getch();
}


int t(void)
{
   struct  time t;

   gettime(&t);
   printf("The current time is: %2d:%02d:%02d.%02d\n",
	  t.ti_hour, t.ti_min, t.ti_sec, t.ti_hund);
   return 0;
}

void info()
{
 printf("we are getting display on screen");
}