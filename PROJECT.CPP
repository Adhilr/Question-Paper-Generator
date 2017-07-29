#include<iostream.h>
#include<fstream.h>
#include<stdio.h>
#include<conio.h>
static int te=2;
int qa[5],qb;
struct question
{
 int cr; char quest[200];
}a[10],b[5];
class teacher
{ public:
	int password,credit;
	teacher()
	{
     }
	teacher(int x, int y)
	{
	password=x;
	credit=y;
	}
}t[100];
void add()
{
 int pa, cred;
 cout<<"\nGenrated teachers code is:"<<te;
 cout<<"\nEnter a password(only numbers): ";
 cin>>pa;
 cout<<"\nEnter credits(0 to 5): ";
 cin>>cred;
 if(cred<0 || cred>5)
 {
  cout<<"Invalid credits. Try again";
  cout<<"\nEnter credits(0 to 5): ";
  cin>>cred;
 }
 clrscr();
 cout<<"\n\n\t\t\t\tGiven Details\nId      :"<<te<<"\nPassword:"<<pa<<"\nCredit  :"<<cred;
 cout<<"\nPress 'y' to save:";
 if(getchar()=='y')
   {
     t[te]=teacher(pa,cred);
     cout<<"Saved Successfully";
     te++;
     getch();
   }
 else
   {
    cout<<"Cancelled\n\nPress 'a' to TRY AGAIN :" ;
    if(getchar()=='a') add();
    getch();
   }
}
void change()
{
 int u1,c1;
 cout<<"\n\n\t\t\t\tChange of CREDITS";
 cout<<"\n\n\nEnter the TEACHER'S ID:"; cin>>u1;
 cout<<"\n\nEnter the CREDITS"; cin>>c1;
 cout<<"Press 'y' to save the change";
 if(getchar()=='y') t[u1].credit=c1;
 else
  {
   cout<<"\n Cancelled\nPress 'a' to TRY AGAIN :";
   if(getchar()=='a') change();
  }
}
void prepare(int i)
{
 int d, w;
 cout<<"\n\n\t\t\tQuestion list for PART A\nCODE : Question \n";
 for(w=0;w<10;w++)
  cout<<w<<" : "<<a[w].quest<<'\n';
 cout<<"\nEnter Codes for any 5 Questions:";
 for(w=0;w<5;w++)
   {
    cout<<w+1<<" : "; cin>>d;
    a[d].cr+=i;
    }

 clrscr();
 cout<<"\n\n\t\t\tQuestion list for PART B\nCODE : Question\n";
 for(w=0;w<5;w++)
  cout<<w<<" : "<<b[w].quest<<'\n';
 cout<<"Enter code of any 1 PART B question:"; cin>>d;
 b[d].cr+=i;
 clrscr();
}
void make()
{
 int w;
 cout<<"\t\t\t\tQUESTION MAKER";
 cout<<"\n\t\tEnter 10 PART A question\n(Note:Use underscore(_)instead of space)";
 for(w=0;w<10;w++)
 {
  cout<<"\nCode : "<<w<<"\nEnter Question:";
  cin>>a[w].quest;
  cout<<"\n\n";
 }
 clrscr();
 cout<<"\t\tEnter 5 PART B questions\n";
 for(w=0;w<5;w++)
 {
  cout<<"\nCode : "<<w<<"\nEnter Question:";
  cin>>b[w].quest;
 }
 clrscr();
}
int same(int aw,int am)
{
 int ab=1;
 for(int i=0;i<am;i++)
  if(aw==qa[i])
   ab=0;
 return ab;
}
void show()
{
 int w=0,m,g=0,f;
 f=5*(te+1);
 for(m=0;m<5;m++)
 {for(w=0;w<10;w++)
  if(a[w].cr>=g && same(w,m))
   {
    qa[m]=w; g=a[w].cr;
   }
  }
  g=0;

  for(w=0;w<5;w++)
    if(b[w].cr>=g)
    {
     qb=w;
     g=b[w].cr;
    }
 clrscr();
 ofstream outf("QUESTION_PAPER");
 outf<<"\n\n\n\t\t\t\tQuestion Paper\n\n\t\t\t\tPart - A\n";
 for(m=0;m<5;m++)
  outf<<m+1<<") "<<a[qa[m]].quest<<'\n';
 outf<<"\n\n\t\t\t\tPart - B\n";
  outf<<"1) "<<b[qb].quest<<'\n';
 outf.close();
 cout<<"\n\n\n\t\t\t\tQuestion Paper\n\n\t\t\t\tPart - A\n";
 for(m=0;m<5;m++)
  cout<<m+1<<") "<<a[qa[m]].quest<<'\n';
 cout<<"\n\n\t\t\t\tPart - B\n";
  cout<<"1) "<<b[qb].quest<<'\n';
 cout<<"\n\n\n\n\nThe QUESTION PAPER is stored in a text file 'QUESTION_PAPER.TXT' in the current directory.\n\t\t\t\t\t\tTHANK YOU";
 getch();
}
void main()
{
int u,p,ch,l=1,log;
t[1]=teacher(1001,10);
while(l==1)
{
 cout<<"\t\t\t\tWelcome to Qustion Paper Controller\nLogin ID : ";
 cin>>u;
 cout<<"\nPassword : ";
 cin>>p;
 if(t[u].password==p)
  {
   log=1;
   if(u==1)
   {
    while(log)
    {
     cout<<"\n\n\t\t\tWelcome HOD Sir_/\_";
     cout<<"\n\n\t\t\tMENU";
     cout<<"\n1.Add teacher\n2.Change credits of a teacher\n3.Make question\n4.Generate Question Paper\n5.Logout\n6.Quit\nEnter your choice : ";
     cin>>ch;
     clrscr();
     switch(ch)
     {
      case 1: add();
	      break;
      case 2: change();
	      break;
      case 3: make();
	      break;
      case 4: show();
	      break;
      case 5: log=0;
	      break;
      case 6: l=0;log=0;
	      break;
      default: cout<<"Wrong choice. Try again.";
     }
    clrscr();
    }
   }
    else
	while(log==1)
	{ clrscr();
	 cout<<"\n\n\n\t\t\tWelcome Teacher\n\n\t\t\t\tMenu\n1.Submit Q.P.\n2.Log out\n3.Quit\n\nEnter Your Choice : ";
	 cin>>ch;
	 switch(ch)
	 {
	  case 1: prepare(t[u].credit);
		  break;
	  case 2: log=0;clrscr();
		  break;
	  case 3: l=0;log=0;clrscr();
		  break;
	  default: cout<<"\n\nWrong choice. Try again.";
	 }	}
   }
 getch();
} }
