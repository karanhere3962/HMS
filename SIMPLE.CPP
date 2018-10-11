#include<gst.h>
#include<time.h>

//delay loop. delays 1second for default or for no. of secs specified
void delay(double k=1)
{
   int i;
   clock_t a,b;
   a=clock();
   b=clock();
   while((b-a)/(CLK_TCK*1.0)<=k)
   {
     b=clock();
   }
}


//introduction screen
void intro()
{
  clrscr();
  int i,j=77,k;
  i=1;
  while(i<77&&!kbhit())
  {
    delay(0.0001);
    gotoxy(3,1);//upper and left lines
    cout<<" ";
    if(i<=44)
    {
     if((i%2)==0)
     {
      if(i%2<26)
      {
      gotoxy(3,(i/2)+3);
     cout<<(char)179;
     }
      gotoxy(5,i/2);
       cout<<(char)179;
     }
    }
    gotoxy(i+4,3);
    cout<<(char)196;
    gotoxy(i-4,4);
    cout<<(char)196;
    if(j>=29)            //lower and right lines
    {
     if((j%2)==0)
     {
      gotoxy(74,(j/2)-14);
     cout<<(char)179;
      gotoxy(76,(j/2)-11);
       cout<<(char)179;
     }
    i++;
    }
    gotoxy(j-3,23);
    cout<<(char)196;
    gotoxy(j+4,24);
    cout<<(char)196;
    j--;
    gotoxy(75,23);
    cout<<" ";
    switch(i)
    {
       case 1 :gotoxy(22,8);
	       cout<<"HOTEL";
	       break;
       case 5 :gotoxy(28,8);
	       cout<<"MANAGEMENT";
	       break;
       case 10:gotoxy(39,8);
	       cout<<"SYSTEM";
	       break;
       case 15:gotoxy(46,8);
	       cout<<"(HMS)";
	       break;
       case 20:gotoxy(13,10);
	       cout<<"MADE";
	       break;
       case 25:gotoxy(18,10);
	       cout<<"BY";
	       break;
       case 30:gotoxy(21,10);
	       cout<<":-";
	       break;
       case 35:gotoxy(20,12);
	       cout<<"BHAWNA";
	       break;
       case 40:gotoxy(27,12);
	       cout<<"CHHETRI";
	       break;
       case 45:gotoxy(25,14);
	       cout<<"KARAN";
	       break;
       case 50:gotoxy(31,14);
	       cout<<"CHETTRI";
	       break;
       case 55:gotoxy(32,16);
	       cout<<"PRITAM";
	       break;
       case 60:gotoxy(39,16);
	       cout<<"CHHETRI";
	       break;
       case 65:gotoxy(39,18);
	       cout<<"AVNISH";
	       break;
       case 70:gotoxy(46,18);
	       cout<<"SHARMA";
	       break;
    }
    gotoxy(72,23);
  }
  getch();
}
//menu for hotel management system selected in the main menu
void hms()
{
  clrscr();
  int i=0,j=0,k,l;
  re:
  clrscr();
  box1("  MENU  ",32,3);
  gotoxy(10,11);
  cout<<"ROOM DETAILS";
  gotoxy(50,11);
  cout<<"GUEST DETAILS";
  msg();
  gotoxy(26,23);
  cout<<"USE ARROW KEYS TO SELECT";
  gotoxy(30,24);
  cout<<"PRESS ESC TO EXIT";
  switch(i)                //for selection box
  {
     case 0:switch(j)      //vertical selection
	    {
	      case 0:box1("ROOM DETAILS",9,10);              //horizontal selection
		     k=0;
		     gotoxy(1,21);
		     break;
	      case 1:k=1;
		     box1("GUEST DETAILS",49,10);
		     gotoxy(1,21);
		     break;
	    }
	    break;
  }
  char a,b,c;
  a=getch();
    switch(a)           //for moving the selection box
  {
     case 27:return;
     case 0:break;
     case 13:switch(k)
	     {
		case 0:mainr();
		       break;
		case 1:maing();
		       break;
	     }
	     break;
     default:msg();
	     gotoxy(30,22);
	     cout<<"INVALID INPUT....";
	     c=getch();
	     if(c==0)
	       b=getch();
  }
  if(a==0)
  {
  b=getch();
  switch(b)
  {
     case 75:j--;
	      break;
     case 77:j++;
	      break;
     default:msg();
	     gotoxy(30,22);
	     cout<<"INVALID INPUT....";
	     c=getch();
	     if(c==0)
	      b=getch();
  }
  }
  if(j==-1)
    j=0;
  if(j==2)
    j=1;
  goto re;
}

void htl()
{
   clrscr();
   box1("KBPA HOTEL MANAGEMENT SYSTEM",27,3);
   cout<<"\n\n  THIS PROGRAM IS CREATED AS A SCHOOL PROJECT AND TOOK ALMOST 85";
   cout<<"\n  DAYS TO COMPLETE. EFFORT HAS BEEN MADE TO BUILD EVERY EVERY ASPECT";
   cout<<"\n  OF THE PROJECT. HOWEVER DUE TO LIMITED TIME AND KNOWLEDGE, THERE";
   cout<<"\n  MAY BE SOMETHING LEFT FROM US. THEREFORE FOR ANY SUGGESTION PLEASE";
   cout<<"\n  CONTACT US. OUR e-MAIL ID: kbpahms@gmail.com .";
   getch();
}

void htl1()
{
   clrscr();
   box1(" WELCOME ",30,2);
   cout<<"\n\n    WELCOME TO OUR HOTEL. ENJOY HOLIDAYS WITH OUR WORLD CLASS SERVICES";
   cout<<"\n    AND RELAX. FEEL FREE TO CALL THE ROOM SERVICE FOR ANYTHING.";
   cout<<"\n    WE WILL BE MORE THAN HAPPY TO HELP YOU IN MANNER.\n\n";
   box1(" OUR BELIEF ",28,11);
   cout<<"\n\n\tGUEST ARE GOD. SERV THEM SO WELL THAT THEY VISIT REGULARLY.";
   getch();
}

//main menu
void menu()
{
  clrscr();
  int i=0,j=0,k,s=0,l;
  re:
  clrscr();
  if(s==0)
  {
    delay(0.001);
    s++;
  }
  box1("  MENU  ",32,3);
  if(s==1)
  {
    delay(0.4);
    s++;
  }
  gotoxy(10,9);
  cout<<"HOTEL MANAGEMENT SYSTEM (HMS)";
  if(s==2)
  {
    delay(0.4);
    s++;
  }
  gotoxy(50,9);
  cout<<"ABOUT HOTEL";
  if(s==3)
  {
    delay(0.4);
    s++;
  }
  gotoxy(10,15);
  cout<<"ABOUT HMS";
  if(s==4)
  {
    delay(0.4);
    s++;
  }
  gotoxy(50,15);
  cout<<"EXIT";
  if(s==5)
  {
    delay(0.4);
    s++;
  }
  msg();
  gotoxy(26,23);
  cout<<"USE ARROW KEYS TO SELECT";
  gotoxy(30,24);
  cout<<"PRESS ESC TO EXIT";
  if(s==6)
  {
    delay(0.4);
    s++;
  }
  switch(i)                //for selection box
  {
     case 0:switch(j)      //vertical selection
	    {
	      case 0:box1("HOTEL MANAGEMENT SYSTEM (HMS)",9,8);              //horizontal selection
		     k=0;
		     gotoxy(1,21);
		     break;
	      case 1:k=1;
		     box1("ABOUT HOTEL",49,8);
		     gotoxy(1,21);
		     break;
	    }
	    break;
     case 1:switch(j)   //vertical selection
	    {
	      case 0:box1("ABOUT HMS",9,14);         //horizontal selection
		     gotoxy(1,21);
		     k=2;
		     break;
	      case 1:box1("EXIT",49,14);
		     gotoxy(1,21);
		     k=3;
		     break;
	    }
  }
  char a,b,c;
  a=getch();
    switch(a)           //for moving the selection box
  {
     case 27:return;
     case 0:break;
     case 13:switch(k)
	     {
		case 0:hms();
		       break;
		case 1:htl1();
		       break;
		case 2:clrscr();
		       htl();
		       break;
		case 3:return;
	     }
	     break;
     default:msg();
	     gotoxy(30,22);
	     cout<<"INVALID INPUT....";
	     c=getch();
	     if(c==0)
	       b=getch();
  }
  if(a==0)
  {
  b=getch();
  switch(b)
  {
     case 72:i--;
	      break;
     case 80:i++;
	      break;
     case 75:j--;
	      break;
     case 77:j++;
	      break;
     default:msg();
	     gotoxy(30,22);
	     cout<<"INVALID INPUT....";
	     c=getch();
	     if(c==0)
	      b=getch();
  }
  }
  if(i==-1)
    i=0;
  if(i==2)
    i=1;
  if(j==-1)
    j=0;
  if(j==2)
    j=1;
  goto re;
}
void main()
{
  intro();
  menu();
}