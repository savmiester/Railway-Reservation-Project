     #include<iostream.h>
     #include<conio.h>
     #include<graphics.h>
     #include<dos.h>

     void last()
     {
      clrscr();
      int gdriver = DETECT, gmode, errorcode;

      /* initialize graphics mode */
      initgraph(&gdriver, &gmode, "c:\\TC\\BGI");
      setbkcolor(BROWN);
      rectangle(15,15,620,460);
     settextstyle(TRIPLEX_FONT,HORIZ_DIR,1);
     setcolor(GREEN);
     outtextxy(85,35,"RAILWAYS RESERVATION SYSTEM");
     setcolor(WHITE);
     settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
     outtextxy(25,300,"Project done by:-");

     outtextxy(35,320," \n Savio D'souza  \n Mayur Desai \n Sudarshan Devardekar ");
     outtextxy(25,350,"Under guidance of : \n Mr.A M Patravale");

     outtextxy(35,400,"Department of Computer Science & Engineering");
     outtextxy(25,450,"Bharati Vidyapeeth's College Of Engineering ,Kolhapur");



	delay(5000);
	exit(0);

 }
