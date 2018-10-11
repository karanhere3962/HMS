#include<iostream.h>
#include<conio.h>
#include<stdio.h>

void box(int x1,int y1,int x2,int y2)
{
  int l,i;
  gotoxy(x1,y1);
  cout<<" ";
  for(l=x1;l<x2-1;l++)
  cout<<"-";
  for(i=++y1;i<y2;i++)
  {
    gotoxy(x1,i);
    cout<<"|";
    gotoxy(x2,i);
    cout<<"|";
  }
  gotoxy(x1,y2);
  cout<<" ";
  for(l=x1;l<x2-1;l++)
  cout<<"-";
}

void increase(int i)
{
  gotoxy(1,i);
  box(1,i-1,1,i+1);
  box(1,i+1,9,i+1);
  box(9,i-1,9,i+1);
  box(9,i+1,25,i+1);
  box(25,i-1,25,i+1);
  box(25,i+1,45,i+1);
  box(45,i-1,45,i+1);                   //3rd box 25 to 45
  box(45,i+1,54,i+1);
  box(54,i-1,54,i+1);
  box(54,i+1,80,i+1);                   //4th box 45 to 54
  box(80,i-1,80,i+1);
}

void main()
{
  clrscr();
  box(1,1,9,3);   		    //1st box 1 to 9
  box(9,1,25,1);
  box(25,1,25,3);
  box(9,3,25,3);           	    //2nd box 9 to 25
  box(25,1,45,1);
  box(45,1,45,3);
  box(25,3,45,3);                   //3rd box 25 to 45
  box(45,1,54,1);
  box(54,1,54,3);
  box(45,3,54,3);                   //4th box 45 to 54
  box(54,1,80,1);
  box(80,1,80,3);
  box(54,3,80,3);                   //5th box 54 to 80
  gotoxy(3,2);
  puts("RM NO");
  gotoxy(13,2);
  puts("ROOM TYPE");
  gotoxy(30,2);
  puts("ROOM STATUS");
  gotoxy(47,2);
  puts("CHARGE");
  gotoxy(62,2);
  puts("SPECIALTY");
  increase(4);
  increase(6);
  increase(8);
  getch();
}