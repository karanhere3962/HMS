#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iomanip.h>
#include<stdlib.h>

char r[]="room.dat";
char rt[]="rtype.dat";
char da[]="data.dat";

void box1(char a[],int x1,int y1)
{
  int l,m=strlen(a);
  gotoxy(x1,y1);
  cout<<(char)201;
  for(l=0;l<m+2;l++)
  cout<<(char)205;
  cout<<(char)187;
  gotoxy(x1,y1+1);
  cout<<(char)186<<" "<<a<<" "<<(char)186;
  gotoxy(x1,y1+2);
  cout<<(char)200;
  for(l=0;l<m+2;l++)
  cout<<(char)205;
  cout<<(char)188;
}

int sure()
{
  re:
  clrscr();
  char ch;
  cout<<"Are you sure?(y/n)";
  ch=getch();
  if(ch=='y'||ch=='Y')
    return 1;
  else if(ch=='n'||ch=='N')
    return 0;
  else
    goto re;
}

void box(int x1,int y1,int x2,int y2);
void msg();

class dat
{
  public:
  int billno;
  char ophno[40],onm[40],oadd[40];
  double vou;
  dat()
  {
	 billno=0;
	 vou=1000;
	 strcpy(onm,"");
	 strcpy(ophno,"");
	 strcpy(oadd,"");
	 re:
	 fstream x(da,ios::binary|ios::in|ios::out);
	 if(!x)
	 {
		clrscr();
		cout<<"FILE ERROR...";
		getch();
		exit(1);
	 }
	 x.read((char*)&billno,sizeof(billno));
	 x.read((char*)&vou,sizeof(vou));
	 x.read((char*)&onm,sizeof(onm));
	 x.read((char*)&ophno,sizeof(ophno));
	 x.read((char*)&oadd,sizeof(oadd));
	 if(!strlen(onm))
	   strcpy(onm,"KBPA HOTEL MANAGEMENT SYSTEM");
	 x.close();
      }
      ~dat()
      {
	 fstream x(da,ios::binary|ios::out);
	 if(!x)
	 {
	   clrscr();
	   cout<<"FILE ERROR....";
	   getch();
	   return;
	 }
	 x.write((char*)&billno,sizeof(billno));
	 x.write((char*)&vou,sizeof(vou));
	 x.write((char*)&onm,sizeof(onm));
	 x.write((char*)&ophno,sizeof(ophno));
	 x.write((char*)&oadd,sizeof(oadd));
      }
};

int sm(int d,int a,int b,int s) //d=x co-odi,a=min y co-or,b=max y co-or,s=increasing by factor
{
  gotoxy(29,23);
  cout<<"USE UP-DOWN ARROW KEYS TO SELECT";
  gotoxy(d,a);
  cout<<"*";
  int x=a;
  char y,z;
  while(1)
  {
	  re:
	  y=getch();
	  switch(y)
	  {
		 case 0:z=getch();
			switch(z)
			{
			 case 72:x-=s;
				 cout<<"\b ";
				break;
				case 80:x+=s;
				cout<<"\b ";
				break;
			default:gotoxy(30,22);
				cout<<"INVALID INPUT....";
				getch();
				gotoxy(30,22);
				cout<<"                 ";
				gotoxy(d,x);
				cout<<"\b ";
				goto re;
				}
				break;
		 case 13:return x-a;
		 case 27:return -2;
		 default:cout<<"\b ";
			 gotoxy(30,22);
			 cout<<"INVALID INPUT....";
			 getch();
			 gotoxy(30,22);
			 cout<<"                 ";
			 gotoxy(d,x);
			 cout<<"\b ";
			 goto re;
	  }
	  if(x<a)
		 x=b;
	  if(x>b)
		 x=a;
	  gotoxy(d,x);
	  cout<<"*";

  }
}

void rtr1()
{
  clrscr();
  box(17,1,25,3);   		    //1st box 17 to 25
  box(25,1,45,1);
  box(45,1,45,3);
  box(25,3,45,3);           	    //2nd box 25 to 45
  gotoxy(19,2);
  puts("SL.NO");
  gotoxy(31,2);
  puts("ROOM TYPE");
}

void rti(int i)
{
  gotoxy(1,i);
  box(17,i-1,17,i+1);
  box(17,i+1,25,i+1);
  box(25,i-1,25,i+1);
  box(25,i+1,45,i+1);
  box(45,i-1,45,i+1);
}

class room
{
  public:
  int rno,vacant;
  double chrg;
  char rtype[20],spclty[50];
};

class rtyp
{
	public:
	int s;
	char a[30];
};

int checkr(char a[])
{
  rtyp t;
  ifstream x(rt,ios::binary);
  if(!x)
  {
    gotoxy(30,22);
    cout<<"File read error....";
    getch();
    gotoxy(30,22);
    cout<<"                   ";
    return 2;
  }
  while(x.read((char*)&t,sizeof(t)))
  {
    if(strcmp(a,t.a)==0)
     return 1;
  }
   return 0;
}

void edel(int i,room p[],int k,int chk);

double getnum(int xc,int i,int l,int gg=0);

void edelr(int i,rtyp p[],int k,int chk)
{
  int j,ls;
  rtyp t;
  fstream x;
  char ch1,cs[15];
		 prog:
		 if(chk==0)
		 { hs:
		 clrscr();
		 msg();
		 gotoxy(20,23);
		 cout<<"ENTER AN EMPTY FIELD TO GO BACK";
		   gotoxy(1,1);
		   cout<<"ENTER NEW ROOM TYPE:";
		   gets(t.a);
		   if(strlen(t.a)==0)
		    return;
		   if(strlen(t.a)>13)
		{
		 gotoxy(25,22);
		 cout<<"MAXIMUM CHARACTER EXEEDED(13)... TRY AGAIN";
		 getch();
		 gotoxy(25,22);
		 cout<<"                                          ";
		 goto hs;
		}
		if(checkr(t.a)==1)
		{
		  gotoxy(20,22);
		  cout<<"ROOM TYPE ALREADY EXISTS...TRY AGAIN";
		  getch();
		  gotoxy(20,22);
		  cout<<"                                    ";
		  goto hs;
		}
		 }
		 t.s=k;
		 gotoxy(6,24);
		 cout<<"           ENTER=>SAVE       ESC=>EXIT          ";
		 progr:
		 ch1=getch();
		 if(ch1==13)
		 {
		   x.open(rt,ios::binary|ios::out);
		   if(!x)
		   {
		     gotoxy(30,22);
		     cout<<"FILE ERROR....";
		     getch();
		     return;
		   }
		   if(chk==0)
		   {
		   for(j=0;j<i;j++)
		   {
		    if(p[j].s==k)
		    {
		    x.write((char*)&t,sizeof(t));
		    strcpy(cs,p[j].a);
		    }
		    else
		    {
		      x.write((char*)&p[j],sizeof(t));
		    }
		   }
		   x.close();
		   }
		   if(chk==1)
		   {
		   ls=1;
		   for(j=0;j<i;j++)
		   {
		    if(p[j].s!=k)
		    {
		      p[j].s=ls++;
		      x.write((char*)&p[j],sizeof(t));
		    }
		    else
		     strcpy(cs,p[j].a);
		   }
		   x.close();
		   }
		   nd:
		   ls=0;
		   room f,*rs;
		   x.open(r,ios::binary|ios::in|ios::out);
		   while(x.read((char*)&f,sizeof(f)))
		     ls++;
		   rs=new room[ls];
		     x.close();
		   x.open(r,ios::binary|ios::in|ios::out);
		   ls=0;
		   while(x.read((char*)&f,sizeof(f)))
		     rs[ls++]=f;
		   x.close();
		   j=0;
		   if(chk==1)
		   while(j<ls)
		   {
		    if(strcmpi(cs,rs[j].rtype)==0)
		     {
		       edel(ls,rs,rs[j].rno,chk);
		       goto nd;
		     }
		    j++;
		   }
		   if(chk==0)
		   while(j<ls)
		   {
		    if(strcmpi(cs,rs[j].rtype)==0)
		     {
		       strcpy(rs[j].rtype,t.a);
		       edel(ls,rs,rs[j].rno,2);
		       goto nd;
		     }
		    j++;
		   }
		   return;
		 }
		 else if(ch1==27)
		   if(sure())
		    return;
		   else
		    goto progr;
		 else
		 {
		   goto progr;
		 }
}

void cust(int a)
{
  clrscr();
  int i=0,j,k,m,row,rctr=0,chk;
  char ch,ch1;
  rtyp ret,*p,s;
  ifstream rea;
  back:
  ret.s=0;
  rea.open(rt,ios::binary);
  while(rea.read((char*)&s,sizeof(s)))
    ret.s=s.s;
  rea.close();
  ret.s++;
  if(a==0)
  {
	  int flg=0,i;
	  st:
	  i=4;
	  rtr1();
	  fstream x;
		while(1)
		{
		msg();
		gotoxy(20,23);
		cout<<"ENTER AN EMPTY FIELD TO GO BACK";
		gotoxy(10,24);
		cout<<"                                                          ";
		flg=0;
		x.open(rt,ios::in|ios::out|ios::ate|ios::binary);
		if(!x)
		{
		 gotoxy(30,22);
		 cout<<"FILE ERROR...";
		 getch();
		 gotoxy(30,22);
		 cout<<"             ";
		 return;
		}
		flg=0;
		rti(i);
		gotoxy(19,i);
		cout<<ret.s;
		hs:
		gotoxy(27,i);
		gets(ret.a);
		if(strlen(ret.a)==0)
		  return;
		if(strlen(ret.a)>13)
		{
		 gotoxy(25,22);
		 cout<<"MAXIMUM CHARACTER EXEEDED... TRY AGAIN";
		 getch();
		 gotoxy(25,22);
		 cout<<"                                      ";
		 gotoxy(27,i);
		 cout<<"                                      ";
		 rti(i);
		 goto hs;
		}
		if(checkr(ret.a)==1)
		{
		  gotoxy(20,22);
		  cout<<"ROOM TYPE ALREADY EXISTS...TRY AGAIN";
		  getch();
		  gotoxy(20,22);
		  cout<<"                                    ";
		  gotoxy(27,i);
		  cout<<"              ";
		  goto hs;
		}
		re:
		gotoxy(10,24);
		cout<<"CTRL+S=>SAVE         ENTER=>ENTER NEXT           ESC=>EXIT";
		gotoxy(10,22);
		cout<<"                                                     ";
		ch=getch();
		switch(ch)
		{
	case 13:
		if(flg==0)
		{
		  x.write((char*)&ret,sizeof(ret));
		  x.close();
		}
		ret.s++;
		i+=2;
		break;
	case 27:if(sure()==1)
		  return;
		  else
		  clrscr();
		  i=4;
		  rtr1();
		  x.close();
		  break;
	case 19:if(flg==0)
		{
		  if(!x)
			 {
			  gotoxy(30,22);
			  cout<<"FILE ERROR...";
			  getch();
			  gotoxy(30,22);
			  cout<<"             ";
			  return;
			 }
		  x.write((char*)&ret,sizeof(ret));
		  x.close();
		  flg=1;
		}
		  gotoxy(30,22);
		  cout<<"SAVE SUCCESS";
		  getch();
		goto re;
	default:gotoxy(30,22);
		cout<<"INVALID INPUT.....";
		getch();
		goto re;

      }
      if(i==18)
      {
       i=4;
       goto st;
      }
    }
  }
  else
   hh:
   row=rctr;
   fstream x(rt,ios::binary|ios::in);
   if(!x)
   {
     gotoxy(30,22);
     cout<<"FILE ERROR....";
     getch();
     return;
   }
   msg();
   while(x.read((char*)&ret,sizeof(ret)))
   {
      i++;
   }
   x.close();
   if(i==0)
   {
     gotoxy(20,22);
     cout<<"NO DATA TO EDIT... INPUT SOME DATA FIRST...";
     getch();
     gotoxy(20,22);
     cout<<"                                           ";
     return;
   }
   p=new rtyp[i];
   i=0;
   x.open(rt,ios::binary|ios::in);
   while(x.read((char*)&ret,sizeof(ret)))
   {
      p[i++]=ret;
   }
   x.close();
   for(j=0;j<i;j++)
   {
      k=j;
      for(m=j+1;m<i;m++)
       if(p[m].s<p[k].s)
	 k=m;
      if(j!=k)
      {
	ret=p[j];
	p[j]=p[k];
	p[k]=ret;
      }
   }
   j=4;
   rtr1();
   while(1)
   {
      if(row>=i)
      {
	row=rctr=0;
	rtr1();
	j=4;
      }
      if(j==4)
      {
       rtr1();
       msg();
      }
      rti(j);
      gotoxy(19,j);
      cout<<setw(5)<<p[row].s;
      gotoxy(27,j);
      puts(p[row].a);
      j+=2;
      row++;
      if(j==18||row==i)
       {
	rex:
	gotoxy(6,24);
	cout<<"CTRL+E=>EDIT        ENTER=>NEXT       ESC=>EXIT       "<<(char)24<<"=>PREV";
	ch=getch();
	switch(ch)
	{
	  case 0:ch1=getch();
		 switch(ch1)
		 {
		   case 72:xp:
			   if(row==7)
			   row=i-7;
			   else if((row-7)<0)
			   row=0;
			   else
			   {
			    row=row-7-(row%7);
			   }
			   j=4;
			   rctr=row;
			   break;
		   default:goto rex;
		 }
		 break;
	  case 5:clrscr();
		 cout<<"What do you want to do?\n   EDIT ROOM TYPE\n   DELETE ROOM TYPE";
		 chk=sm(2,2,3,1);
		 if(chk==-2)
		  goto hh;
		 prog:
		 clrscr();
		 if(chk==0)
		 cout<<"Enter the sl.no of the room type you want to edit: ";
		 if(chk==1)
		 {
		  ba:
		    clrscr();
		   cout<<"This will delete all the room details of the selected room type.\nDo you still wish to continue?(y/n)";
		   ch=getch();
		   if(ch=='y'||ch=='Y')
		     goto rx;
		   else if(ch=='n'||ch=='N')
		     goto prog;
		   else
		   {
		     cout<<"\n\n\nINVALID INPUT.....";
		     getch();
		     clrscr();
		     goto ba;
		   }
		   rx:
		   clrscr();
		   cout<<"Enter the sl.no room type you want to delete: ";
		 }
		 k=getnum(1,2,5);
		 msg();
		 if(k==-1)
		  goto hh;
		 if(k>i)
		 {
		   gotoxy(25,22);
		   cout<<"Sl.no not found...";
		   getch();
		   goto prog;
		 }
		   edelr(i,p,k,chk);
		 goto hh;
	  case 13:rctr=row;
		  j=4;
		  break;
	  case 27:if(sure()==1)
		  return;
		  else
		   goto xp;
	  default : gotoxy(30,22);
		cout<<"INVALID INPUT....";
		getch();
		gotoxy(30,22);
		cout<<"                 ";
		goto rex;
    }
       }
   }
}

struct st
{
  char a[30];
};

int sts(int x,int s,int max,char r[][30])
{
  int i=0;
  gotoxy(29,23);
  cout<<"USE UP-DOWN ARROW KEYS TO SELECT";
  gotoxy(s,x);
  cout<<r[0];
  char ch,ch1;
  while(1)
  {
    re:
    ch=getch();
    switch(ch)
    {
      case 0:ch1=getch();
	     switch(ch1)
	     {
	       case 72:i--;
		       break;
	       case 80:i++;
		       break;
	       default :gotoxy(30,22);
			cout<<"INVALID INPUT....";
			getch();
			gotoxy(30,22);
			cout<<"                         ";
			goto re;
	     }
	     break;
      case 13:gotoxy(29,23);
	      cout<<"                                ";
	      return i;
      case 27:return -10;
      default : gotoxy(30,22);
		cout<<"INVALID INPUT....";
		getch();
		gotoxy(30,22);
		cout<<"                 ";
		goto re;
    }
    if(i==-1)
      i=max-1;
    if(i==max)
      i=0;
    gotoxy(s,x);
    cout<<"                  ";
    gotoxy(s,x);
    cout<<r[i];
  }
}

int ts(int x,int s,int max,st r[])
{
  int i=0;
  gotoxy(29,23);
  cout<<"USE UP-DOWN ARROW KEYS TO SELECT";
  gotoxy(s,x);
  cout<<r[0].a;
  char ch,ch1;
  while(1)
  {
    re:
    ch=getch();
    switch(ch)
    {
      case 0:ch1=getch();
	     switch(ch1)
	     {
	       case 72:i--;
		       break;
	       case 80:i++;
		       break;
	       default :gotoxy(30,22);
			cout<<"INVALID INPUT....";
			getch();
			gotoxy(30,22);
			cout<<"                         ";
			goto re;
	     }
	     break;
      case 13:gotoxy(29,23);
	      cout<<"                                ";
	      return i;
      case 27:return -10;
      default : gotoxy(30,22);
		cout<<"INVALID INPUT....";
		getch();
		gotoxy(30,22);
		cout<<"                 ";
		goto re;
    }
    if(i==-1)
      i=max-1;
    if(i==max)
      i=0;
    gotoxy(s,x);
    cout<<"              ";
    gotoxy(s,x);
    cout<<r[i].a;
  }
}

double getnum(int xc,int i,int l,int gg)
{
   char *a,ch;
   int j=0,y,k,x1=0;
   double x=0;
   a=new char[20];
   while(1)
   {
       msg();
       gotoxy(29,24);
       cout<<"PRESS ESC FOR EXIT";
       re:
       gotoxy(xc+j,i);
       ch=getche();
       if(j==l-1)
       {
	 if(ch!=8&&ch!=27&&ch!=13)
	 {
	  cout<<"\b ";
	 gotoxy(30,22);
	 cout<<"MAXIMUM CHARACTERS REACHED...";
	 getch();
	 gotoxy(30,22);
	 cout<<"                             ";
	 goto re;
	 }
       }
       if(ch=='0'&&j==0&&gg==0)
       {
	  gotoxy(30,22);
	  cout<<"FIRST NUMBER CAN'T BE 0";
	  getch();
	  gotoxy(30,22);
	  cout<<"                       ";
	  goto re;
       }
       else if(ch>='0'&&ch<='9')
	 {
	    a[j++]=ch;
	    goto re;
	 }
       else if(ch==13)
	{
	   if(j==0)
	   {
	    gotoxy(30,22);
	    cout<<"THIS FIELD CAN'T BE EMPTY";
	    getch();
	    gotoxy(xc,i);
	    cout<<" ";
	    gotoxy(30,22);
	    cout<<"                         ";
	    goto re;
	   }
	   if(l>=6)
	   {
	     for(k=0;k<j;k++)
	     {
	       y=(int)(a[k]-48);
	       x=x*10+y;
	     }
	     gotoxy(29,24);
	     cout<<"                                ";
	     return x;
	   }
	   if(l<=5)
	   {
	     for(k=0;k<j;k++)
	     {
	       y=(int)(a[k]-48);
	       x1=x1*10+y;
	     }
	     gotoxy(29,24);
	     cout<<"                                  ";
	     return x1;
	   }
	}
	else if(ch==27)
	{
	  gotoxy(29,24);
	  cout<<"                                      ";
	  return -1;
	}
	else if(ch==8)
	{
	  if(j!=0)
	  {j--;
	  cout<<" \b ";
	  gotoxy(30,22);
	  cout<<"                                        ";
	  goto re;}
	}
	else
	{
	   gotoxy(30,22);
	   cout<<"INVALID INPUT";
	   getch();
	   gotoxy(xc+j,i);
	   cout<<" ";
	   gotoxy(30,22);
	   cout<<"             ";
	   goto re;
	}
   }
}

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

void msg()
{
  int l;
  gotoxy(3,20);
  for(l=3;l<36;l++)
  cout<<(char)177;
  cout<<"MESSAGE";
  for(l=45;l<80;l++)
  cout<<(char)177;
  for(l=21;l<25;l++)
  {
    gotoxy(3,l);
    cout<<(char)221;
    gotoxy(77,l);
    cout<<(char)222;
  }
  gotoxy(3,25);
  for(l=3;l<78;l++)
  cout<<(char)177;
}


void increaser(int i)
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

void rmrow1()
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
}

int check(int a,int y=0)
{
  room t;
  ifstream x(r,ios::binary);
  if(!x)
  {
    gotoxy(30,22);
    cout<<"File read error....";
    getch();
    gotoxy(30,22);
    cout<<"                   ";
    return 2;
  }
  while(x.read((char*)&t,sizeof(t)))
  {
    if(a==t.rno&&y==0)
     return 1;
    else if(a==t.rno&&y!=0)
    {
      if(t.vacant==0)
       return 3;
      else
       return 4;
    }
  }
   return 0;
}

int vac(int i,int x)
{
    if(i==2)
    {
      gotoxy(47,x);
      cout<<"-----";
      gotoxy(60,x);
      cout<<"-------------";
      return 1;
    }
    return 2;
}

void rm(int tst,room &p)
{
    int i=0,flg,ctr=0,bs;
    char ch,ch1;
    room rm;
    st *sss;
    rtyp rty;
    clrscr();
    msg();
    ifstream fin(rt,ios::binary);
     while(fin.read((char*)&rty,sizeof(rty)))
	ctr++;
     fin.close();
     if(ctr==0)
       {
	 gotoxy(30,22);
	 cout<<"ENTER THE ROOM TYPES FIRST....";
	 getch();
	 return;
       }
     sss=new st[ctr];
     ctr=0;
     fin.open(rt,ios::binary);
    while(fin.read((char*)&rty,sizeof(rty)))
	strcpy(sss[ctr++].a,rty.a);
     fin.close();
    while(1)
    {
     gotoxy(10,24);
       cout<<"                                                          ";
    flg=0;
    ofstream x(r,ios::binary|ios::ate);
    if(!x)
    {
	 gotoxy(30,22);
	 cout<<"FILE WRITE ERROR.. CHECK THE FILE PATH";
	 getch();
	 return;
    }
      if(i==0)
      {
	clrscr();
	rmrow1();
	i=4;
      }
      msg();
      increaser(i);
      tre:
      rm.rno=getnum(3,i,5);
      gotoxy(3,i);
      cout<<"     ";
      gotoxy(3,i);
      cout<<setw(5)<<rm.rno;
      if(rm.rno==tst)
	goto mo;
      if(rm.rno==-1)
	 return;
      if(check(rm.rno)==1)
      {
	 gotoxy(20,22);
	 cout<<"THE ROOM NO. ALREADY ENTERED...TRY ANOTHER NO...";
	 getch();
	 gotoxy(3,i);
	 gotoxy(20,22);
	 cout<<"                                                ";
	 gotoxy(3,i);
	 cout<<"      |        ";
	 goto tre;
      }
      else if(check(rm.rno)==2)
      {
	gotoxy(24,22);
	cout<<"FILE ERROR... THE PROGRAM WILL EXIT....";
	getch();
	return;
      }
      gotoxy(9,i);
      cout<<"|           ";
      increaser(i);
      mo:
      gotoxy(11,i);
      bs=ts(i,11,ctr,sss);
      if(bs==-10)
	return;
      strcpy(rm.rtype,sss[bs].a);
      gotoxy(27,i);
      char t[][30]={"VACANT","OCCUPIED","OUT OF ORDER"};
      rm.vacant=sts(i,27,3,t);
      if(rm.vacant==-10)
	return;
      if(vac(rm.vacant,i)==1&&tst==0)
       goto re;
      if(vac(rm.vacant,i)==1&&tst!=0)
      {
       p=rm;
       return;
      }
      gotoxy(30,24);
       cout<<"PER DAY";
      rm.chrg=getnum(47,i,8);
      if(rm.chrg==-1)
	return;
      gotoxy(54,i);
      cout<<"|            ";
      gotoxy(30,24);
       cout<<"       ";
      gotoxy(56,i);
      gets(rm.spclty);
      if(tst!=0)
       {
	  p=rm;
	  return;
       }
      re:
      gotoxy(10,24);
       cout<<"CTRL+S=>SAVE         ENTER=>ENTER NEXT           ESC=>EXIT";
      gotoxy(10,22);
      cout<<"                                                         ";
      ch=getch();
      switch(ch)
      {
	case 13:if(flg==0)
		{
		  x.write((char*)&rm,sizeof(rm));
		  x.close();
		  flg=0;
		}
		i+=2;
		break;
	case 27:if(sure())
		    return;
		   else
		    i=0;
		    break;
	case 19:if(flg==0)
		{
		  x.write((char*)&rm,sizeof(rm));
		  x.close();
		  flg=1;
		}
		  gotoxy(30,22);
		  cout<<"SAVE SUCCESS";
		  getch();
		goto re;
	default:gotoxy(30,22);
		cout<<"INVALID INPUT.....";
		getch();
		goto re;

      }
      if(i==18)
       i=0;
    }
}
void edel(int i,room p[],int k,int chk)
{
  int j;
  room t;
  fstream x;
  char ch1;
		 if(chk==0)
		 rm(k,t);
		 gotoxy(6,24);
		 cout<<"           ENTER=>SAVE       ESC=>EXIT          ";
		 progr:
		 ch1=getch();
		 if(ch1==13)
		 {
		   x.open(r,ios::binary|ios::out);
		   if(!x)
		   {
		     gotoxy(30,22);
		     cout<<"FILE ERROR....";
		     getch();
		     return;
		   }
		   if(chk==0)
		   for(j=0;j<i;j++)
		   {
		    if(p[j].rno==k)
		    x.write((char*)&t,sizeof(t));
		    else
		    {
		      x.write((char*)&p[j],sizeof(t));
		    }
		   }
		   if(chk==2)
		   for(j=0;j<i;j++)
		   {
		     x.write((char*)&p[j],sizeof(t));
		   }
		   if(chk==1)
		   for(j=0;j<i;j++)
		   {
		    if(p[j].rno!=k)
		      x.write((char*)&p[j],sizeof(t));
		   }
		   x.close();
		   return;
		 }
		 else if(ch1==27)
		   if(sure())
		    return;
		   else
		    goto progr;
		 else
		 {
		   gotoxy(30,22);
		   cout<<"INVALID INPUT....";
		   getch();
		   gotoxy(30,22);
		   cout<<"                 ";
		   goto progr;
		 }
}
void modirm(room *p,int it=0,int chk=-1)
{
   room t,s;
   int i=0,j,m,row,rctr=0,k;
   char ch,ch1;
   hh:
   row=rctr;
   fstream x(r,ios::binary|ios::in);
   if(!x)
   {
     gotoxy(30,22);
     cout<<"FILE ERROR....";
     getch();
     return;
   }
   msg();
   if(it==0)
   {
   while(x.read((char*)&t,sizeof(t)))
   {
      i++;
   }
   x.close();
   if(i==0)
   {
     gotoxy(20,22);
     cout<<"NO DATA TO EDIT... INPUT SOME DATA FIRST...";
     getch();
     gotoxy(20,22);
     cout<<"                                           ";
     return;
   }
   p=new room[i];
   i=0;
   x.open(r,ios::binary|ios::in);
   while(x.read((char*)&t,sizeof(t)))
   {
      p[i++]=t;
   }
   x.close();
   }
   for(j=0;j<i;j++)
   {
      k=j;
      for(m=j+1;m<i;m++)
       if(p[m].rno<p[k].rno)
	 k=m;
      if(j!=k)
      {
	t=p[j];
	p[j]=p[k];
	p[k]=t;
      }
   }
   j=4;
   rmrow1();
   while(1)
   {
      if(row>=i)
      {
	row=rctr=0;
	rmrow1();
	j=4;
      }
      if(j==4)
      {
       rmrow1();
       msg();
      }
      increaser(j);
      gotoxy(3,j);
      cout<<setw(5)<<p[row].rno;
      gotoxy(11,j);
      cout<<p[row].rtype;
      gotoxy(27,j);
      if(p[row].vacant==0)
	cout<<"VACANT";
      else if(p[row].vacant==1)
	cout<<"OCCUPIED";
      else
       {
	cout<<"OUT OF ORDER";
	gotoxy(47,j);
	cout<<"------";
	gotoxy(56,j);
	cout<<"      --------------";
	goto pre;
       }
      gotoxy(47,j);
      cout<<p[row].chrg;
      gotoxy(57,j);
      cout<<p[row].spclty;
      pre:
      j+=2;
      row++;
      if(j==18||row==i)
       {
	re:
	gotoxy(6,24);
	cout<<"CTRL+E=>EDIT        ENTER=>NEXT       ESC=>EXIT       "<<(char)24<<"=>PREV";
	ch=getch();
	switch(ch)
	{
	  case 0:ch1=getch();
		 switch(ch1)
		 {
		   case 72:xp:
			   if(row==7)
			   row=i-7;
			   else if((row-7)<0)
			   row=0;
			   else
			   {
			    row=row-7-(row%7);
			   }
			   j=4;
			   rctr=row;
			   break;
		   default:goto re;
		 }
		 break;
	  case 5:clrscr();
		 cout<<"What do you want to do?\n   EDIT ROOM DETAILS\n   DELETE ROOM";
		 chk=sm(2,2,3,1);
		 prog:
		 clrscr();
		 if(chk==0)
		 cout<<"Enter the room no. you want to edit: ";
		 if(chk==1)
		 cout<<"Enter the room no. you want to delete: ";
		 k=getnum(1,2,5,1);
		 msg();
		 if(k==-1)
		 {
		  if(sure())
		   goto hh;
		  else
		   goto prog;
		  }
		 if(check(k)==0)
		 {
		   gotoxy(25,22);
		   cout<<"Room number not found...";
		   getch();
		   goto prog;
		 }
		 ten:
		 edel(i,p,k,chk);
		 chk=-1;
		 goto hh;
	  case 13:rctr=row;
		  j=4;
		  break;
	  case 27:if(sure()==1)
		  return;
		  else
		  goto xp;
	  default : gotoxy(30,22);
		cout<<"INVALID INPUT....";
		getch();
		gotoxy(30,22);
		cout<<"                 ";
		goto re;
    }
       }
   }
}


void mainr()
{
  clrscr();
  int i=0,j=0,k,l;
  re:
  clrscr();
  box1("  MENU  ",32,3);
  gotoxy(10,9);
  cout<<"ENTER ROOM DETAILS";
  gotoxy(43,9);
  cout<<"VIEW AND EDIT ROOM DETAILS";
  gotoxy(10,15);
  cout<<"ENTER ROOM TYPES";
  gotoxy(43,15);
  cout<<"VIEW AND EDIT ROOM TYPES";
  msg();
  gotoxy(26,23);
  cout<<"USE ARROW KEYS TO SELECT";
  gotoxy(30,24);
  cout<<"PRESS ESC TO EXIT";
  switch(i)                //for selection box
  {
     case 0:switch(j)      //vertical selection
	    {
	      case 0:box1("ENTER ROOM DETAILS",9,8);              //horizontal selection
		     k=0;
		     gotoxy(1,21);
		     break;
	      case 1:k=1;
		     box1("VIEW AND EDIT ROOM DETAILS",42,8);
		     gotoxy(1,21);
		     break;
	    }
	    break;
     case 1:switch(j)   //vertical selection
	    {
	      case 0:box1("ENTER ROOM TYPES",9,14);         //horizontal selection
		     gotoxy(1,21);
		     k=2;
		     break;
	      case 1:box1("VIEW AND EDIT ROOM TYPES",42,14);
		     gotoxy(1,21);
		     k=3;
		     break;
	    }
  }
  char a,b,c;
  a=getch();
  room rr,*rk;
    switch(a)           //for moving the selection box
  {
     case 27:return;
     case 0:break;
     case 13:switch(k)
	     {
		case 0:rm(0,rr);
		       break;
		case 1:modirm(rk);
		       break;
		case 2:cust(0);
		       break;
		case 3:cust(1);
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