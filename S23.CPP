#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<dos.h>
#include<time.h>
#include<fstream.h>
struct game
{      	        unsigned int srno;
		char mvnm[30];
		char h1[30];
		char h2[30];
		char h3[30];
		char h4[30];
		int sno(){ return srno;}
		void input();
		void show();
		void games();

};
int score=0;
void match();
void admin();
void update();
void display();
void boundary();
void disp();
void menu();
void guest();
int count();
void update()
{    	game p;
	int n,i;
	fstream fo;
	fo.open("game.dat",ios::app|ios::binary);
	cout<<"\n Enter Number of Movies";
	cin>>n;
		for(i=1;i<=n;i++)
		{	p.input();
			fo.write((char*)&p,sizeof(p));
		}
	fo.close();
	admin();
}
int count()
{	game p;
	int c=0;
	fstream fax;
	fax.open("game.dat",ios::in|ios::binary);
	while(fax.read((char*)&p,sizeof(p)))
	{  	c++;
	}
	fax.close();
	return c;
}
char d;
int dust=0,flag=0;
void game::games()
{
	do
	{
	flag++;
	clrscr();
	boundary();
	char y[30]={NULL};
   //	textcolor(5);
	fstream fin;
	game p,a;
	randomize();
	int xx=count();
	int t;
	t=1+random(xx);
	if(flag>1)
	{
		do
		{
			t=1+random(xx);
		}while(dust==t);
	}
	dust=t;
	fin.open("game.dat",ios::binary|ios::in);
	while(fin.read((char*)&a,sizeof(a)))
	{	if(t==a.srno)
		{
			break;
		}
	}
	fin.close();
	clrscr();
	int f,g=0;
	char k,h,q[30];
	gotoxy(30,5);
	cout<<"GUESS THE MOVIE";
//	cout<<"movie name"<<a.mvnm;
	strcpy(q,a.mvnm);
	gotoxy(30,7);
	for(int j=0;q[j]!=NULL;j++)
	{
		cout<<"_ ";
		y[j]='*';
	}
  //	cout<<"alpha"<<j;
	for(int x=10;x>0;)
	{               f=1;
			gotoxy(11,10);
			cout<<"GUESS ALPHABET PRESENT IN MOVIE NAME ";
			gotoxy(11,11);
			cout<<"FOR HINT PRESS '/','@','#'or'&'\t";
			cin>>h;
			gotoxy(10,9);
			if(h=='/'||h=='@'||h=='&'||h=='#')
			{
				if(h=='/')
				{       g++;
					cout<<" HINT : "<<a.h1<<"\t\t";
					x--;
				}
				else if(h=='@')
				{	g++;
					cout<<" HINT : "<<a.h2<<"\t\t";
					x--;
				}
				else if(h=='#')
				{	g++;
					cout<<" HINT : "<<a.h3<<"\t\t";
					x--;
				}
				else if(h=='&')
				{	g++;
					cout<<" HINT : "<<a.h4<<"\t\t";
					x--;
				}
		     //	gotoxy(10,10);
		      //	cout<<"GUESS ALPHABET PRESENT IN MOVIE NAME   \t";
		       //	cin>>k;
			}
			else
			{
			for(j=0;q[j]!=NULL;j++)
			{	if(tolower(h)==q[j]||toupper(h)==q[j])
				{	y[j]=q[j];
					f=0;
				}
			}
			}
    //			cout<<"if part";
			if(strcmpi(q,y)==0)
			{	score=score+x*3;
				gotoxy(19,21);
			      //	textcolor(YELLOW+BLINK);
				cprintf(" YOU WON \nYOUR SCORE:");
				cout<<score;
				gotoxy(36,19);
				cout<<" MOVIE IS: "<<q;
				break;
			}
			if(f!=0)
			{x--;}
				gotoxy(20,15);
				cout<<"YOU HAVE "<<x<<" CHANCES";
					   gotoxy(15,16);
					   cout<<y;
	}
 //	cout<<"fish"<<h;
	if(x==0||x<0)
	{
	  //	textcolor(YELLOW);
		randomize();
		score=score+x*random(6);
		gotoxy(36,18);
		cout<<"\nYOU LOST \n\t MOVIE:"<<q;
	}
	gotoxy(4,18);
	cout<<"\ IF WE WANT TO PLAY ONCE MORE PRESS Y ELSE ANY OTHER KEY\t";
	cin>>d;
	}while(d=='y'||d=='Y');
     //	if(d=='y'||d=='Y')
     //	guest();
     //	else
	menu();

}
void game::input()
{       clrscr();
	cout<<"\n Enter Serial no: ";
	cin>>srno;
	cout<<"\n Enter Movie Name: ";
	gets(mvnm);
	cout<<"\n Enter HINT 1: ";
	gets(h1);
	cout<<"\n Enter HINT 2: ";
	gets(h2);
	cout<<"\n Enter HINT 3: ";
	gets(h3);
	cout<<"\n Enter HINT 4: ";
	gets(h4);
}
void game::show()
{       clrscr();
	cout<<"\n Enter Serial no: ";
	cout<<srno;
	cout<<"\n Enter Movie Name: ";
	cout<<mvnm;
	cout<<"\n Enter HINT 1: ";
	cout<<h1;
	cout<<"\n Enter HINT 2: ";
	cout<<h2;
	cout<<"\n Enter HINT 3: ";
	cout<<h3;
	cout<<"\n Enter HINT 4: ";
	cout<<h4;
}
void display()
{       textcolor(RED);
	clrscr();
		{	for(int i=37;i<45;i++)
			{       delay(100);
				gotoxy(i,8);
				cout<<"*";
			}
			for(i=37;i<45;i++)
			{       delay(100);
				gotoxy(i,12);
				cout<<"*";
			}
			for( i=37;i<45;i++)
			{       delay(100);
				gotoxy(i,16);
				cout<<"*";
			}
			for( i=8;i<19;i++)
			{       delay(100);
				gotoxy(45,i);
				cout<<"*";
			}
		}
	clrscr();
	delay(500);
	{
			for(int i=37;i<45;i++)
			{       delay(100);
				gotoxy(i,8);
				cout<<"*";
			}
			for(i=37;i<45;i++)
			{       delay(100);
				gotoxy(i,12);
				cout<<"*";
			}
			for( i=8;i<12;i++)
			{       delay(100);
				gotoxy(45,i);
				cout<<"*";
			}
			for( i=12;i<16;i++)
			{       delay(100);
				gotoxy(37,i);
				cout<<"*";
			}

			for( i=37;i<45;i++)
			{       delay(100);
				gotoxy(i,16);
				cout<<"*";
			}
		}
	clrscr();
	delay(500);
		{	for(int i=8;i<16;i++)
			{       delay(100);
				gotoxy(40,i);
				cout<<"*";
			}
		}
	getch();
}
char passw[40]={"S23"};
void match()
{	clrscr();
	char a[30];
	cout<<"\n ENTER PASSWORD: ";
	for(int i=0;i<3;i++)
	{	a[i]=getch();
		cout<<"*";
	}
	a[i]=NULL;
	//gets(a);
		if(strcmp(a,passw)==0)
		admin();
		else
		exit(0);
}

void instruct()
{	clrscr();
		for(int i=0;i<=79;i++)
		{       gotoxy(i,1);
			cout<<"*";
		}
		for(i=0;i<22;i++)
		{       textcolor(BLUE+BLINK);
			delay(100);
			gotoxy(i,2);
			cprintf(" *--* WELCOME TO BOLLYWOOD GAME *---*");
		}
		for(i=1;i<=79;i++)
		{	gotoxy(i,23);
			cout<<"*";
		}
	randomize();
	textcolor(GREEN);
	gotoxy(8,6);
	cprintf(" \n   INSTRUCTIONS");
	cout<<"\n * You have to guess the movie name by giving input of charcters there in name."<<"\n * You have got 10 chances.";
	cout<<"\n * Your chances will be reduced if you take hint & input character not in the\n name of movie.";
	cout<<"\n * Number of blanks represent number of charcters in movie name."<<"\n * There are 4 hints.";
	cout<<"\n\n\n\t ENTER ANY KEY TO GO BACK";
	char t;
	cin>>t;
	if(t!=NULL)
	menu();
	getch();
}
void boundary()
{       randomize();
	textcolor(4);
		for(int i=0;i<78;i++)
		{	gotoxy(i,0);
			cprintf("Î");
		}
		for(i=0;i<23;i++)
		{	gotoxy(79,i);
			cprintf("Î");
		}
		for( i=0;i<79;i++)
		{	gotoxy(i,0);
			cprintf("Î");
		}
		for( i=0;i<23;i++)
		{	gotoxy(1,i);
			cprintf("Î");
		}
}
void disp()
{	game p;
	fstream fo;
	fo.open("game.dat",ios::in|ios::binary);
	while(fo.read((char*)&p,sizeof(p)))
	{	p.show();
		delay(3000);
	}
	fo.close();
	admin();
}
void admin()
{       clrscr();
	boundary();
	textcolor(RED);
	char ch;
		gotoxy(25,10);
		cout<<"   Enter Choice : ";
		gotoxy(25,11);
		cout<<"   1. SEE MOVIES : ";
		gotoxy(25,12);
 /*		cout<<"   2. CHANGE PASSWORD : ";
		gotoxy(25,13); */
		cout<<"   2. ADD MOVIES : ";
		gotoxy(20,13);
		cout<<"   ENTER ANY KEY TO GO BACK";
		cin>>ch;
		switch(ch)
		{	case '1' :	disp();
					break;
		       /*	case '2' :	pass();
					break; */
			case '2' :      update();
					break;
			default :       menu();

		}
}
void guest()
{   		clrscr();
		game p;
		char ch;
		boundary();
		textcolor(RED);
		gotoxy(25,10);
		cout<<"   Enter Choice : ";
		gotoxy(25,11);
		cout<<"   1. PLAY : ";
		gotoxy(25,12);
		cout<<"   2. INSTRUCTIONS : ";
		gotoxy(20,13);
		cout<<"   ENTER ANY KEY TO GO BACK : ";
		cin>>ch;
		switch(ch)
		{	case '1' :	p.games();
					break;
			case '2' :	instruct();
					break;
			default :       menu();
					break;
		}
}
void menu()
{       clrscr();
	boundary();
	textcolor(RED);
	gotoxy(25,10);
	cout<<"   Enter Choice :" ;
	gotoxy(25,11);
	cout<<"   1. ADMIN " ;
	gotoxy(25,12);
	cout<<"   2. PLAYER " ;
	gotoxy(20,13);
	cout<<"   PRESS ANY KEY TO EXIT THE GAME ";
	char ch;
	cin>>ch;
	switch(ch)

		{	case '1' :      match();
					break;
			case '2' :	guest();
					break;
			default:        exit(0);
					break;
		}
}
void main()
{       textbackground(BLACK);
	clrscr();
	 display();
	 menu();
      //admin();
	textcolor(BLUE+BLINK);
	getch();
}




























