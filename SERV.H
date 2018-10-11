#include<rm.h>

char se[]="serv.dat";

class serv
{
    public:
    double swim,spa,gmplr,pool,pho,gym;
    serv()
    {
       swim=spa=gmplr=pool=pho=gym=0;
    }
};

void srvr1()
{
  clrscr();
  box(20,1,40,3);   		    //1st box 1 to 9
  box(40,1,54,1);
  box(54,1,54,3);
  box(40,3,54,3);           	    //2nd box 9 to 25
  box(54,1,65,1);
  box(65,1,65,3);
  box(54,3,65,3);                   //3rd box 25 to 45
  gotoxy(27,2);
  puts("SERVICE");
  gotoxy(45,2);
  puts("CHARGE");
  gotoxy(58,2);
  puts("UNIT");
}

void increases(int i)
{
  gotoxy(1,i);
  box(20,i-1,20,i+1);
  box(20,i+1,40,i+1);
  box(40,i-1,40,i+1);
  box(20,i+1,54,i+1);
  box(54,i-1,54,i+1);
  box(54,i+1,65,i+1);
  box(65,i-1,65,i+1);                   //3rd box 25 to 45
}

void sewri(serv t)
{
  fstream x(se,ios::binary|ios::out);
  if(!x)
  {
   gotoxy(30,22);
   cout<<"FILE ERROR...";
   getch();
   gotoxy(30,22);
   cout<<"             ";
   return;
  }
  x.write((char*)&t,sizeof(t));
}
void seread(char s[],char un[],double &b,int &c,int x=0)
{
  double m;
  increases(c);
  gotoxy(22,c);
  cout<<s;
  gotoxy(56,c);
  puts(un);
  if(x==0)
  {
  m=getnum(42,c,8,1);
  if(m!=-1)
   b=m;
  gotoxy(42,c);
  cout<<"           ";
  }
  gotoxy(42,c);
  cout<<setw(10)<<b;
  c+=2;
}

void mains()
{
  serv a;
  ifstream x(se,ios::binary);
  x.read((char*)&a,sizeof(a));
  int c;
  msg();
  c=4;
  srvr1();
  seread("SWIMMING","PER HOUR",a.swim,c);
  sewri(a);
  seread("SPA","PER HOUR",a.spa,c);
  sewri(a);
  seread("GAME PARLOUR","PER HOUR",a.gmplr,c);
  sewri(a);
  seread("POOL","PER HOUR",a.pool,c);
  sewri(a);
  seread("PHONE","PER MIN",a.pho,c);
  sewri(a);
  seread("GYM","PER HOUR",a.pho,c);
  sewri(a);
}
void shows()
{
  serv a;
  ifstream x(se,ios::binary);
  dat o;
  x.read((char*)&a,sizeof(a));
  int c;
  msg();
  c=4;
  srvr1();
  seread("VOUCHER","PER VOU",o.vou,c,1);
  seread("SWIMMING","PER HOUR",a.swim,c,1);
  seread("SPA","PER HOUR",a.spa,c,1);
  seread("GAME PARLOUR","PER HOUR",a.gmplr,c,1);
  seread("POOL","PER HOUR",a.pool,c,1);
  seread("PHONE","PER MIN",a.pho,c,1);
  seread("GYM","PER HOUR",a.pho,c,1);
  getch();
}

