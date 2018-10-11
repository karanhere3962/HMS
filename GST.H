#include<serv.h>

char gu[]={"guest.dat"};

class guest
{
  public:
  char nm[30];
  int rno,vou,gstno,dd,mm,y,cdd,cmm,cy;
  char ph[12],add[50];
  double swim,gym,gmplr,spa,pho,pool;

  guest()
  {
    swim=gym=gmplr=spa=pho=pool=vou=0;
  }
};

int checkg(int a)
{
  guest t;
  ifstream x(gu,ios::binary);
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
    if(a==t.gstno)
     return 1;
  }
   return 0;
}

void gstr1()
{
  clrscr();
  box(1,1,7,3);   		    //1st box 1 to 7
  box(7,1,15,1);
  box(15,1,15,3);
  box(7,3,15,3);           	    //2nd box 7 to 15
  box(15,1,30,1);
  box(30,1,30,3);
  box(15,3,30,3);                   //3rd box 15 to 30
  box(30,1,42,1);
  box(42,1,42,3);
  box(30,3,42,3);                   //4th box 30 to 42
  box(42,1,47,1);
  box(47,1,47,3);
  box(42,3,47,3);                   //5th box 42 to 47
  box(47,1,67,1);
  box(67,1,67,3);
  box(47,3,67,3);		    //6th box 47 to 67
  box(67,1,80,1);
  box(80,1,80,3);
  box(67,3,80,3);		    //6th box 67 to 80
  gotoxy(2,2);
  puts("GST#");
  gotoxy(9,2);
  puts("ROOM#");
  gotoxy(16,2);
  puts("NAME OF GUEST");
  gotoxy(32,2);
  puts("PHONE NO");
  gotoxy(43,2);
  puts("VOU#");
  gotoxy(53,2);
  puts("ADDRESS");
  gotoxy(69,2);
  puts("CHK IN DT");
}

void increaseg(int i)
{
  gotoxy(1,i);
  box(1,i-1,1,i+1);
  box(1,i+1,7,i+1);
  box(7,i-1,7,i+1);
  box(7,i+1,15,i+1);
  box(15,i-1,15,i+1);
  box(15,i+1,30,i+1);
  box(30,i-1,30,i+1);                   //3rd box 25 to 45
  box(30,i+1,42,i+1);
  box(42,i-1,42,i+1);
  box(42,i+1,47,i+1);                   //4th box 45 to 54
  box(47,i-1,47,i+1);
  box(47,i+1,67,i+1);                   //4th box 45 to 54
  box(67,i-1,67,i+1);
  box(67,i+1,80,i+1);                   //4th box 45 to 54
  box(80,i-1,80,i+1);
}

void gst(int tst, guest &p)
{
    int i=4,flg,bs;
    char ch,ch1;
    guest g;
    room mmm;
    hll:
    gstr1();
    while(1)
    {
     gotoxy(5,24);
       cout<<"                                                                    ";
    flg=0;
    fstream x(gu,ios::binary|ios::ate|ios::out),y(r,ios::binary|ios::in|ios::out);
    if(!x||!y)
    {
	 gotoxy(30,22);
	 cout<<"FILE WRITE ERROR.. CHECK THE FILE PATH";
	 getch();
	 return;
    }
    if(i==0)
    {
      clrscr();
      gstr1();
      i=4;
    }
      msg();
      increaseg(i);
      tre:
      g.gstno=getnum(2,i,5,1);
      gotoxy(2,i);
      cout<<"     ";
      gotoxy(2,i);
      cout<<setw(5)<<g.gstno;
      if(g.gstno==tst)
	goto mo;
      if(g.gstno==-1)
	 return;
      if((bs=checkg(g.gstno))==1)
      {
	 gotoxy(20,22);
	 cout<<"THE GUEST NO. ALREADY ENTERED...TRY ANOTHER NO...";
	 getch();
	 gotoxy(20,22);
	 cout<<"                                                  ";
	 gotoxy(2,i);
	 cout<<"               ";
	 increaseg(i);
	 goto tre;
      }
      else if(bs==2)
      {
	gotoxy(24,22);
	cout<<"FILE ERROR... THE PROGRAM WILL EXIT....";
	getch();
	return;
      }
      mo:
      g.rno=getnum(8,i,4);
      gotoxy(8,i);
      cout<<"     ";
      gotoxy(8,i);
      cout<<setw(5)<<g.rno;
      if(g.rno==-1)
	 return;
      if((bs=check(g.rno,2))==0)
      {
	 gotoxy(20,22);
	 cout<<"ROOM NO DOES NOT EXIST..... TRY AGAIN.....";
	 getch();
	 gotoxy(20,22);
	 cout<<"                                          ";
	 gotoxy(8,i);
	 cout<<"                  ";
	 increaseg(i);
	 goto mo;
      }
      else if(mmm.rno==g.rno)
	 goto hs;
      else if(bs==4)
      {
	 gotoxy(20,22);
	 cout<<"THE ROOM IS NOT VACANT... TRY ANOTHER ROOM NO...";
	 getch();
	 gotoxy(20,22);
	 cout<<"                                                ";
	 gotoxy(8,i);
	 cout<<"               ";
	 increaseg(i);
	 goto mo;
      }
      else if(bs==2)
      {
	gotoxy(24,22);
	cout<<"FILE ERROR... THE PROGRAM WILL EXIT....";
	getch();
	return;
      }
      hs:
      gotoxy(16,i);
      cout<<"                         ";
      increaseg(i);
      gotoxy(16,i);
      gets(g.nm);
      if(strlen(g.nm)>15)
      {
       gotoxy(25,22);
       cout<<"MAXIMUM CHARACTER EXEEDED(15)... TRY AGAIN";
       getch();
       gotoxy(25,22);
       cout<<"                                          ";
       goto hs;
      }
      mm:
      gotoxy(31,i);
      cout<<"                                            ";
      increaseg(i);
      gotoxy(31,i);
      gets(g.ph);
      if(strlen(g.ph)>12)
      {
       gotoxy(25,22);
       cout<<"MAXIMUM CHARACTER EXEEDED(12)... TRY AGAIN";
       getch();
       gotoxy(25,22);
       cout<<"                                      ";
       goto mm;
      }
      g.vou=getnum(43,i,4);
      if(g.vou==-1)
	return;
      gotoxy(43,i);
       cout<<"   ";
      gotoxy(43,i);
       cout<<setw(3)<<g.vou;
      hp:
      gotoxy(48,i);
      cout<<"                                ";
      increaseg(i);
      gotoxy(48,i);
      gets(g.add);
      if(strlen(g.add)>15)
      {
       gotoxy(25,22);
       cout<<"MAXIMUM CHARACTER EXEEDED(15)... TRY AGAIN";
       getch();
       gotoxy(25,22);
       cout<<"                                          ";
       goto hp;
      }
      da:
      gotoxy(69,i);
       cout<<"DD:MM:YYYY";
      g.dd=getnum(69,i,3,1);
      if(g.dd>31)
      {
       gotoxy(25,22);
       cout<<"PLEASE ENTER A VALID DATE...";
       getch();
       gotoxy(25,22);
       cout<<"                            ";
       goto da;
      }
      mt:
      gotoxy(71,i);
       cout<<":MM:YYYY";
      if(g.dd==-1)
	return;
      g.mm=getnum(72,i,3,1);
      if(g.mm==-1)
	return;
      if(g.mm>12)
      {
       gotoxy(25,22);
       cout<<"PLEASE ENTER A VALID DATE...";
       getch();
       gotoxy(25,22);
       cout<<"                            ";
       goto mt;
      }
      gotoxy(74,i);
       cout<<":YYYY";
      g.y=getnum(75,i,5);
      if(g.y==-1)
	return;
      if(tst!=0)
       {
	  p=g;
	  return;
       }
      re:
      gotoxy(5,24);
       cout<<"CTRL+S=>SAVE   ENTER=>ENTER NEXT   ESC=>EXIT   CTRL+V=>ROOM DETAILS";
      gotoxy(5,22);
      cout<<"                                                                     ";
      ch=getch();
      switch(ch)
      {
	case 13:if(flg==0)
		{
		  room z;
		  while(y.read((char*)&z,sizeof(z)))
		   if(z.rno==g.rno)
		     break;
		  z.vacant=1;
		  y.seekg(y.tellg()-sizeof(z));
		  y.write((char*)&z,sizeof(z));
		  y.close();
		  x.write((char*)&g,sizeof(g));
		  x.close();
		}
		i+=2;
		break;
	case 22:room *z;
		modirm(z);
		i=0;
		goto hll;
	case 27:if(sure())
		    return;
		   else
		    i=0;
		    break;
	case 19:if(flg==0)
		{
		  room z;
		  while(y.read((char*)&z,sizeof(z)))
		   if(z.rno==g.rno)
		     break;
		  z.vacant=1;
		  y.seekp(y.tellg()-sizeof(z));
		  y.write((char*)&z,sizeof(z));
		  y.close();
		  x.write((char*)&g,sizeof(g));
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
void edelg(int i,guest p[],int k,int chk)
{
  int j;
  guest t;
  fstream x;
  char ch1;
		 if(chk==0)
		 gst(k,t);
		 gotoxy(6,24);
		 cout<<"           ENTER=>SAVE       ESC=>EXIT          ";
		 progr:
		 ch1=getch();
		 if(ch1==13)
		 {
		   x.open(gu,ios::binary|ios::out);
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
		    if(p[j].gstno==k)
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
		    if(p[j].gstno!=k)
		      x.write((char*)&p[j],sizeof(t));
		   }
		   x.close();
		   return;
		 }
		 else if(ch1==27)
		   return;
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
void modig(guest zz,int it=-1)
{
   guest t,s,*p;
   int i=0,j,k,m,row,rctr=0,chk;
   char ch,ch1;
   hh:
   row=rctr;
   fstream x(gu,ios::binary|ios::in),y(r,ios::binary|ios::in|ios::out);
   if(!x)
   {
     gotoxy(30,22);
     cout<<"FILE ERROR....";
     getch();
     return;
   }
   msg();
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
   p=new guest[i];
   i=0;
   x.open(gu,ios::binary|ios::in);
   if(it!=-1)
   {
     while(x.read((char*)&t,sizeof(t)))
      {
	if(t.gstno==zz.gstno)
	  p[i++]=zz;
	else
	  p[i++]=t;
      }
   }
   else
    while(x.read((char*)&t,sizeof(t)))
      {
	  p[i++]=t;
      }
   x.close();
   if(it!=-1)
   {
     x.open(gu,ios::binary|ios::out);
     j=0;
     while(j<i)
     {
       x.write((char*)&p[j],sizeof(t));
       j++;
     }
     return;
   }
   for(j=0;j<i;j++)
   {
      k=j;
      for(m=j+1;m<i;m++)
      {
       if(p[m].y<p[k].y)
	 k=m;
       else if(p[m].mm<p[k].mm)
	 k=m;
       else if(p[m].dd<p[k].dd)
	 k=m;
      }
      if(j!=k)
      {
	t=p[j];
	p[j]=p[k];
	p[k]=t;
      }
   }
   j=4;
   gstr1();
   while(1)
   {
      if(row>=i)
      {
	row=rctr=0;
	j=4;
      }
      if(j==4)
      {
       gstr1();
       msg();
      }
      increaseg(j);
      gotoxy(2,j);
      cout<<setw(5)<<p[row].gstno;
      gotoxy(8,j);
      cout<<setw(5)<<p[row].rno;
      gotoxy(16,j);
      puts(p[row].nm);
      gotoxy(31,j);
      puts(p[row].ph);
      gotoxy(43,j);
      cout<<setw(3)<<p[row].vou;
      gotoxy(48,j);
      puts(p[row].add);
      gotoxy(69,j);
      cout<<p[row].dd<<":"<<p[row].mm<<":"<<p[row].y;
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
		   case 72:if(row==7)
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
		 if(chk!=0)
		   cout<<"What do you want to do?\n   EDIT GUEST DETAILS\n   DELETE GUEST DETAILS";
		 chk=sm(2,2,3,1);
		 if(chk==-2)
		 {
		  x.close();
		  goto hh;
		 }
		 prog:
		 clrscr();
		 cout<<"Enter the guest no.: ";
		 k=getnum(1,2,5,1);
		 msg();
		 if(k==-1)
		 {
		  if(sure())
		   goto hh;
		  else
		   goto prog;
		  }
		 if(checkg(k)==0)
		 {
		   gotoxy(25,22);
		   cout<<"Guest number not found...";
		   getch();
		   goto prog;
		 }
		 msg();
		 room z;
		 edelg(i,p,k,chk);
		 while(y.read((char*)&z,sizeof(z)))
		   if(z.rno==k)
		     break;
		  z.vacant=1;
		  y.seekg(y.tellg()-sizeof(z));
		  y.write((char*)&z,sizeof(z));
		  y.close();
		  x.close();
		  goto hh;
	  case 13:rctr=row;
		  j=4;
		  break;
	  case 27:if(sure()==1)
		  return;
		  else
		  if(row==7)
		    row=i-7;
		  else if((row-7)<0)
		    row=0;
		  else
		  {
		    row=row-7-(row%7);
		  }
		  j=4;
		   break;
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

void svs(int k=-3);

void services()
{
      int k;
      fstream x(se,ios::binary|ios::in);
      guest a,z;
      serv m;
      x.read((char*)&m,sizeof(m));
      x.close();
      nn:
      clrscr();
      cout<<"Enter the guest number: ";
      k=getnum(1,2,5,1);
      if(k==-1)
      {
	if(sure)
	  return;
	else
	  goto nn;
      }
      if(checkg(k)==0)
      {
	gotoxy(25,22);
	cout<<"Guest number not found...";
	getch();
	goto nn;
      }
      x.open(gu,ios::binary|ios::in);
      while(x.read((char*)&z,sizeof(z)))
      {
	if(z.gstno==k)
	 break;
      }
      clrscr();
      cout<<"No. of voucher purchased: ";
      a.vou=getnum(1,2,9,1);
      if(a.vou==-1)
       {
	 a.vou=0;
	 goto tr;
       }
      z.vou+=a.vou;
      modig(z,1);
      tr:
      clrscr();
      cout<<"Enter number of hour of: "<<endl;
      cout<<"Swimming: ";
      a.swim=getnum(11,2,9,1);
      if(a.swim==-1)
       {
	 a.swim=0;
	 gotoxy(10,2);
	 cout<<"     ";
	 gotoxy(10,2);
	 cout<<a.swim;
	 goto sp;
       }
       z.swim=z.swim+(a.swim*m.swim);
       modig(z,1);
       sp:
       clrscr();
      cout<<"Enter number of hour of: \nSpa: ";
      a.spa=getnum(6,2,9,1);
      if(a.spa==-1)
       {
	 a.spa=0;
	 gotoxy(10,2);
	 cout<<"     ";
	 gotoxy(10,2);
	 cout<<a.spa;
	 goto gy;
       }
       z.spa=z.spa+(a.spa*m.spa);
       modig(z,1);
       gy:
       clrscr();
      cout<<"Enter number of hour of: \nGym: ";
      a.gym=getnum(6,2,9,1);
      if(a.gym==-1)
       {
	 a.gym=0;
	 gotoxy(10,2);
	 cout<<"     ";
	 gotoxy(10,2);
	 cout<<a.gym;
	 goto gmplr;
       }
       z.gym=z.gym+(a.gym*m.gym);
       modig(z,1);
       gmplr:
       clrscr();
      cout<<"Enter number of hour of: \nGame parlour: ";
      a.gmplr=getnum(15,2,9,1);
      if(a.gmplr==-1)
       {
	 a.gmplr=0;
	 gotoxy(10,2);
	 cout<<"     ";
	 gotoxy(10,2);
	 cout<<a.gmplr;
	 goto ph;
       }
       z.gmplr=z.gmplr+(a.gmplr*m.gmplr);
       modig(z,1);
       ph:
       clrscr();
      cout<<"Enter number of minutes of: \nPhone: ";
      a.pho=getnum(8,2,9,1);
      if(a.pho==-1)
       {
	 a.pho=0;
	 gotoxy(10,2);
	 cout<<"     ";
	 gotoxy(10,2);
	 cout<<a.pho;
	 goto po;
       }
       z.pho=z.pho+(a.pho*m.pho);
       modig(z,1);
       po:
       clrscr();
      cout<<"Enter number of hour of: \nPool: ";
      a.pool=getnum(7,2,9,1);
      if(a.pool==-1)
       {
	 a.pool=0;
	 return;
       }
       z.pool=z.pool+(a.pool*m.pool);
       modig(z,1);
      svs(k);
}
void svs(int k)
{
  guest z;
  fstream x;
  nn:
  clrscr();
  if(k==-3)
  {
    cout<<"Enter the guest number: ";
      k=getnum(1,2,5,1);
  }
      if(k==-1)
      {
	if(sure)
	  return;
	else
	  goto nn;
      }
      if(checkg(k)==0)
      {
	gotoxy(25,22);
	cout<<"Guest number not found...";
	getch();
	return;
      }
      x.open(gu,ios::binary|ios::in);
      while(x.read((char*)&z,sizeof(z)))
      {
	if(z.gstno==k)
	 break;
      }
  clrscr();
  cout<<"No. of voucher(s): "<<z.vou<<endl;
  cout<<"Amount charged for:";
  cout<<"\nSwimming: "<<z.swim<<endl;
  cout<<"Spa: "<<z.spa<<endl;
  cout<<"Gym: "<<z.gym<<endl;
  cout<<"Phone: "<<z.pho<<endl;
  cout<<"Pool: "<<z.pool<<endl;
  x.close();
  getch();
  if(k!=-3)
   return;
  goto nn;
}

int day(int d,int m,int y,int d1,int m1,int y1)
{
  int flg=0,nd=0,dm[]={31,28,31,30,31,30,31,31,30,31,30,31},dt=d,mn=m,yr=y;
  if(y>y1)
  {
    return -1;
  }
  else if(y==y1)
  {
    flg=1;
  }
  if(flg==1&&m>m1)
  {
    return -1;
  }
  else if(m==m1)
    flg=1;
  else
    flg=0;
  if(flg==1&&d>d1)
    return -1;
  for(;d<d1;d++)
  {
    nd++;
  }
  for(;m<m1;m++)
  {
    if(m==2)
      if(y1%400==0||(y1%100!=0&&y1%4==0))
	nd+=dm[1]+1;
      else
      {
	nd+=dm[1];
      }
    else
      nd+=dm[m-1];
    if(mn==m)
     nd-=dt;
  }
  for(;y<y1;y++)
  {
    if(y%400==0||(y%100!=0&&y%4==0))
    {
     if(y==yr)
      nd+=366-nd;
     else
      nd+=366;
    }
    else
     if(y==yr)
      nd+=365-nd;
     else
      nd+=365;
  }
  return ++nd;
}

void bill()
{
  int k,chk,td;
  nn:
  dat dt;
  clrscr();
  cout<<"Enter guest no.: ";
  msg();
  k=getnum(1,2,5,1);
  if(k==-1)
      {
	if(sure)
	  return;
	else
	  goto nn;
      }
  if((chk=checkg(k))==0)
      {
	gotoxy(25,22);
	cout<<"Guest number not found...";
	getch();
	goto nn;
      }
  if(chk==2)
    return;
  guest a;
  char s[30],cid[]={"CHECK-IN DATE: "},cod[]={"\t\tCHECK-OUT DATE: "},nm[]={"NAME OF GUEST: "};
  char bn[]={"BILL NO: "},ph[]={"PHONE NO: "},add[]={"ADDRESS: "},rno[]={"ROOM NO: "};
  char amtr[]={"ROOM CHARGES: "},amts[]={"SERVICE CHARGES: "},ttl[]={"TOTAL AMOUNT: "};
  char gno[]={"GUEST NO: "},thnx[]={"THANK YOU FOR VISITING US. PLEASE VISIT AGAIN."};
  char oph[]={"OUR PHONE NO: "},oadd[]={"ADDRESS: "},ttld[]="TOTAL NO. OF DAYS STAYED: ";
  char sign[]="NAME OF STAFF:______________________________\n\nSIGNATURE:";
  ls:
  clrscr();
  msg();
  gotoxy(5,21);
  cout<<"DO NOT GIVE FILE EXTENTION. TO SAVE THE FILE IN A DESIRED DESTINATION";
  gotoxy(5,22);
  cout<<"GIVE ADDRESS. GIVE JUST NAME TO SAVE FILE IN THE CURRENT DESTINATION.";
  gotoxy(1,1);
  cout<<"Enter the address or just name of the file: ";
  gets(s);
  if(strlen(s)==0)
    goto ls;
  strcat(s,".txt");
  fstream y(gu,ios::binary|ios::in);
  fstream rf(r,ios::binary|ios::in|ios::out);
  if(!y||!rf)
  {
    cout<<"File error...";
    getch();
    return;
  }
  while(y.read((char*)&a,sizeof(a)))
  {
    if(a.gstno==k)
      break;
  }
  room bs;
  while(rf.read((char*)&bs,sizeof(bs)))
  {
    if(a.rno==bs.rno)
      break;
  }
  lll:
  clrscr();
  msg();
  gotoxy(1,1);
  puts("Enter the check out date: ");
  da:
      gotoxy(1,2);
      cout<<"DD:MM:YYYY";
      a.cdd=getnum(1,2,3,1);
      if(a.cdd>31||a.cdd==0)
      {
       gotoxy(25,22);
       cout<<"PLEASE ENTER A VALID DATE...";
       getch();
       gotoxy(25,22);
       cout<<"                            ";
       goto da;
      }
      mt:
      gotoxy(3,2);
       cout<<":MM:YYYY";
      if(a.cdd==-1)
	return;
      a.cmm=getnum(4,2,3,1);
      if(a.cmm==-1)
	return;
      if(a.cmm>12||a.cmm==0)
      {
       gotoxy(25,22);
       cout<<"PLEASE ENTER A VALID DATE...";
       getch();
       gotoxy(25,22);
       cout<<"                            ";
       goto mt;
      }
      gotoxy(6,2);
       cout<<":YYYY";
      a.cy=getnum(7,2,5);
      if(a.cy==-1)
	return;
      clrscr();
  double ttls,ttlr,ttla;
  td=day(a.dd,a.mm,a.y,a.cdd,a.cmm,a.cy);
  if(td==-1||td>30000)
  {
    gotoxy(22,22);
    cout<<"Invalid date... Please enter a valid date....";
    getch();
    goto lll;
  }
  cout<<"\t\t"<<dt.onm<<endl;
  cout<<bn<<++dt.billno<<"\t\t"<<gno<<k<<endl;
  cout<<nm<<a.nm<<"\t"<<rno<<a.rno<<endl;
  cout<<cid<<a.dd<<":"<<a.mm<<":"<<a.y<<"\t"<<cod<<a.cdd<<":"<<a.cmm<<":"<<a.cy<<endl;
  cout<<ph<<a.ph<<"\t   "<<add<<a.add<<endl;
  cout<<ttld<<td<<endl;
  ttlr=td*bs.chrg;
  ttls=(a.vou*dt.vou)+a.swim+a.gym+a.gmplr+a.spa+a.pho+a.pool;
  ttla=(ttlr+ttls);
  cout<<amtr<<ttlr<<"\t\t"<<amts<<ttls<<endl;
  cout<<ttl<<ttla<<"\n"<<sign<<endl;
  cout<<oph<<dt.ophno<<endl<<oadd<<dt.oadd<<endl<<thnx;
  xs:
  cout<<"\n\nWould you like to proceed with the billing?(y/n)";
  char gt;
  cin>>gt;
  if(gt=='y'||gt=='Y')
    goto ms;
  else if(gt=='n'||gt=='N')
    goto nn;
  else
  {
    gotoxy(30,22);
    cout<<"INVALID INPUT....";
    getch();
    gotoxy(30,22);
    cout<<"                 ";
    goto xs;
  }
  ms:
  int c;
  cout<<"\n\nDo you want to change room status to vacant?(y/n)";
  cin>>gt;
  if(gt=='y'||gt=='Y')
    c=1;
  else if(gt=='n'||gt=='N')
    c=0;
  else
  {
    gotoxy(30,22);
    cout<<"INVALID INPUT....";
    getch();
    gotoxy(30,22);
    cout<<"                 ";
    goto ms;
  }
  fstream x(s,ios::out);
  x<<"\t\t"<<dt.onm<<endl<<endl;
  x<<bn<<dt.billno<<"\t\t"<<gno<<k<<endl<<endl;
  x<<nm<<a.nm<<"\t\t"<<rno<<a.rno<<endl<<endl;
  x<<cid<<a.dd<<":"<<a.mm<<":"<<a.y<<"\t"<<cod<<a.cdd<<":"<<a.cmm<<":"<<a.cy<<endl<<endl;
  x<<ph<<a.ph<<"\t   "<<add<<a.add<<endl<<endl;
  x<<ttld<<td<<endl<<endl;
  x<<amtr<<ttlr<<"\t    "<<amts<<ttls<<endl<<endl;
  x<<ttl<<ttla<<"\n"<<sign<<endl;
  x<<oph<<dt.ophno<<endl<<endl<<oadd<<dt.oadd<<endl<<endl<<thnx;
  if(c==1)
  {
  room z;
  while(rf.read((char*)&z,sizeof(z)))
  if(z.rno==a.rno)
     break;
  z.vacant=0;
  rf.seekg(y.tellg()-sizeof(z));
  rf.write((char*)&z,sizeof(z));
  rf.close();
  }
}
void ss()
{
   mm:
   clrscr();
   int k;
   cout<<"  ENTER SERVICE RATES\n";
   cout<<"  VIEW CURRENT RATES\n";
   cout<<"  ENTER SERVICE DETAILS USED BY GUEST\n";
   cout<<"  VIEW SERVICE DETAILS USED BY GUEST";
   k=sm(2,1,4,1);
   if(k==0)
   {
     double dk;
     clrscr();
     dat ob;
     cout<<"Enter the cost of one voucher: ";
     dk=getnum(1,2,8);
     if(dk==-1)
      goto mm;
     else
      ob.vou=dk;
     mains();
   }
   else if(k==1)
    shows();
   else if(k==2)
     services();
   else if(k==3)
     svs();
   else
     return;
   goto mm;
}
void maing()
{
  int i=0,j=0,k,l;
  re:
  clrscr();
  box1("  MENU  ",32,3);
  gotoxy(10,9);
  cout<<"ENTER GUEST DETAILS";
  gotoxy(50,9);
  cout<<"VIEW GUEST DETAILS";
  gotoxy(10,15);
  cout<<"SERVICES";
  gotoxy(50,15);
  cout<<"BILLING";
  msg();
  gotoxy(26,23);
  cout<<"USE ARROW KEYS TO SELECT";
  gotoxy(30,24);
  cout<<"PRESS ESC TO EXIT";
  switch(i)                //for selection box
  {
     case 0:switch(j)      //vertical selection
	    {
	      case 0:box1("ENTER GUEST DETAILS",9,8);              //horizontal selection
		     k=0;
		     gotoxy(1,21);
		     break;
	      case 1:k=1;
		     box1("VIEW GUEST DETAILS",49,8);
		     gotoxy(1,21);
		     break;
	    }
	    break;
     case 1:switch(j)   //vertical selection
	    {
	      case 0:box1("SERVICES",9,14);         //horizontal selection
		     gotoxy(1,21);
		     k=2;
		     break;
	      case 1:box1("BILLING",49,14);
		     gotoxy(1,21);
		     k=3;
		     break;
	    }
  }
  char a,b,c;
  a=getch();
  guest zz;
    switch(a)           //for moving the selection box
  {
     case 27:return;
     case 0:break;
     case 13:switch(k)
	     {
		case 0:gst(0,zz);
		       break;
		case 1:modig(zz);
		       break;
		case 2:ss();
		       break;
		case 3:bill();
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