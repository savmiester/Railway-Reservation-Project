#include <graphics.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

int main(void)
{
   /* request auto detection */
   int gdriver = DETECT, gmode, errorcode;
   int midx, midy;

   /* initialize graphics and local variables */
   initgraph(&gdriver, &gmode, "c:\\tc\\bgi");

   /* read result of initialization */
   errorcode = graphresult();
   if (errorcode != grOk)  /* an error occurred */
   {
      printf("Graphics error: %s\n", grapherrormsg(errorcode));
      printf("Press any key to halt:");
      getch();
      exit(1); /* terminate with an error code */
   }

 //  midx = getmaxx() / 2;
 //  midy = getmaxy() / 2;

   /* output text at the center of the screen */
   /* Note: the C.P. doesn't get changed.     */
   settextstyle(GOTHIC_FONT, HORIZ_DIR,1.5);
   outtextxy(200,19, "Railway Reservation & Enquiry System");
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR,1.5);
   outtextxy(10,100, "Software Developed By :-");
   outtextxy(10,125, "Savio D'souza           Roll No.:10");
   outtextxy(10,140, "Mayur Desai             Roll No.:12");
   outtextxy(10,155, "Sudharshan Devardekar   Roll No.:09");
   outtextxy(10,170, "Under the guidance of Mr.Amol Patravale.");
   outtextxy(150,350, "Department of Computer Science");
   line(6,20,633,20);
   line(8,22,631,22);
   line(8,45,631,45);
   line(6,47,633,47);
   line(8,22,8,45);
   line(6,20,6,47);
   line(631,22,631,45);
   line(633,20,633,47);
   rectangle(3,3,635,470);

   setbkcolor(BROWN);
   /* clean up */
   getch();
   closegraph();
   return 0;
}