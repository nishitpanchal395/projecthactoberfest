#include<stdio.h>
/*
  Defines types and macros needed for the Standard I/O Package
  defined in Kernighan and Ritchie and extended under UNIX
  System V. Defines the standard I/O predefined streams stdin,
  stdout, stdprn, and stderr, and declares stream-level I/O
  routines.
*/
#include<conio.h>
/*
  Declares various functions used in calling the DOS console
  I/O routines.
*/
#include<stdlib.h>
/*
  Declares several commonly used routines: conversion
  routines, search/sort routines, and other miscellany.
*/
#include<string.h>
/*
  Declares several string- and memory-manipulation routines.
*/
#include<iostream>
/*
  Declares the basic C++ (version 2.0) streams (I/O) routines.
*/
//#include<constrea>
/*
  It allows you to create output streams that write to specified windows on
  the screen, in specified colors, and at specific locations.
*/
#include<time.h>
/*
  Defines a structure filled in by the time-conversion
  routines, and a type used by other time routines; also
  provides prototypes for these routines.
*/
#include<iomanip>
/*
  Declares the C++ streams I/O manipulators and contains
  macros for creating parameterized manipulators.
*/
#include<fstream>
/*
  Declares the C++ stream classes that support file input and
  output.
*/
using namespace std;
char f[10]="f";
char s[10]="s";
int addr,ad,flag,f1,d,m,i,amt;
float tamt;
//class login defined
class login
{
	public:
	char id[100];
	char pass[100];
	char *password;
//function to get User IDs and its passwords.
	void getid()
	{
		cout<<"Enter your id:";
		gets(id);
		password=getpass("Enter the password:");
		strcpy(pass,password);
	}
//function to display id and password when needed.
	void displayid()
	{
		cout<<"Id:";
		puts(id);
		cout<<"Password:";
		puts(pass);
	}
};
//class detail defined
class detail
{
	public:
	int tno;
	char tname[100];
	char bp[100];
	char dest[100];
	int c1,c1fare;
	int c2,c2fare;
	int d,m,y;
//function to get details for reservation of seats
	void getdetail()
	{
		cout<<"Enter the details as follows\n";
		cout<<"Train no:";
		cin>>tno;
		cout<<"Train name:";
		gets(tname);
		cout<<"Boarding point:";
		gets(bp);
		cout<<"Destination pt:";
		gets(dest);
		cout<<"No of seats in first class & fare per ticket:";
		cin>>c1>>c1fare;
		cout<<"No of seats in second class & fare per ticket:";
		cin>>c2>>c2fare;
		cout<<"Date of travel:";
		cin>>d>>m>>y;
	}
//function to display details of th seats reserved by user
	void displaydetail()
	{
		cout<<tno<<" \t"<<tname<<" \t"<<bp<<" \t"<<dest<<"\t";
		cout<<c1<<" \t"<<c1fare<<"\t"<<c2<<" \t"<<c2fare<<"\t";
		cout<<d<<"-"<<m<<"-"<<y<<"\t"<<endl;
	}
};
//class reservation defined
class reser
{
	public:
	int pnr;
	int tno;
	char tname[100];
	char bp[10];
	char dest[100];
	char pname[10][100];
	int age[20];
	char clas[10];
	int nosr;
	int i;
	int d,m,y;
	int con;
	float amc;
//function to get details of train and seats required for reservation.
	void getresdet()
	{
		cout<<"Enter the details as follows\n";
		cout<<"Train no:";
		cin>>tno;
		cout<<"Train name:";
		gets(tname);
		cout<<"Boarding point:";
		gets(bp);
		cout<<"Destination pt:";
		gets(dest);
		cout<<"No of seats required:";
		cin>>nosr;
		for(i=0;i<nosr;i++)
		{
			cout<<"Passenger name:";
			gets(pname[i]);
			cout<<"Passenger age:";
			cin>>age[i];
		}
		cout<<"Enter the class f-first class s-second class:";
		gets(clas);
		cout<<"Date of travel:";
		cin>>d>>m>>y;
		cout<<"Enter the concession category\n";
		cout<<"1.Military\n2.Senior citizen\n3.None\n";
		cin>>con;
		cout<<"............END OF GETTING DETAILS............\n";
	}
//function to display the details of the seats booked by any user when needed.
	void displayresdet()
	{
		cout<<"...............................................\n";
		cout<<"...............................................\n";
		cout<<"Pnr no:"<<pnr;
		cout<<"\nTrain no:"<<tno;
		cout<<"\nTrain name:";
		puts(tname);
		cout<<"Boarding point:";
		puts(bp);
		cout<<"Destination pt:";
		puts(dest);
		cout<<"No of seats reserved:"<<nosr;
		for(i=0;i<nosr;i++)
		{
			cout<<"Passenger name:";
			puts(pname[i]);
			cout<<"Passenger age:"<<age[i];
		}
		cout<<"\nYour class:";puts(clas);
		cout<<"\nDate of reservation:"<<d<<"-"<<m<<"-"<<y;
		cout<<"\nYour concession category:"<<con;
		cout<<"\nYou must pay:"<<amc<<endl;
		cout<<"***********************************************\n";
		cout<<".........END OF RESERVATION.................\n";
		cout<<"***********************************************\n";
	}
//display passengers details when asked in program.
	void displaypass()
	{
		cout<<"\n\nPnr no:"<<pnr;
		cout<<"\nTrain no:"<<tno;
		cout<<"\nTrain name:";
		puts(tname);
		cout<<"Your Seat Class:";
		puts(clas);
		cout<<"Date of Reservation:"<<d<<"-"<<m<<"-"<<y;
		cout<<"\nNo of seats reserved:"<<nosr;
		for(i=0;i<nosr;i++)
		{       cout<<"\nPassenger name:";
			puts(pname[i]);
			cout<<"Passenger age:"<<age[i];
			getch();
		}
		getch();
	}
};
void manage();
void user();
void database();
void res();
void reserve();
void displaypassdetail();
void enquiry();
//Main of the program
void main()
{
	{
		//clrscr();
		constream cout;
		cout<<setclr(2);
		cout<<  "\n\n\n\n\n\n\n\n"
		       "                            ____          _____   _____            ____ \n"
		       "       `                '  |       |     |       |     | |`    '| |     \n"
			       "        `      '`      '   |       |     |       |     | | `  ' | |     \n"
		       "         `    '  `    '    |--     |     |       |     | |  `'  | |--   \n"
		       "          `  '    `  '     |       |     |       |     | |      | |     \n"
		       "           `'      `'      |____   |____ |_____  |_____| |      | |____ \n";
		getch();
	}
	{
		clrscr();
		constream cout;
		cout<<setclr(2);
		cout<< "\n\n\n\n\n\n\n\n"
		       "              _______  _____               _____           _____    \n "
		       "                |    |     |             |     | |     | |     |   \n "
		       "                |    |     |             |     | |     | |     |   \n "
		       "                |    |     |             |     | |     | |_____|   \n"
		       "                 |    |     |             |     | |     | |`       \n "
		       "                |    |     |             |     | |     | | `        \n "
		       "                |    |_____|             |_____| |_____| |  `      \n ";
		getch();
	}
	{
		clrscr();
		constream cout;
		cout<<setclr(2);
		cout<< "\n\n\n\n\n\n\n\n"
		       "          _____   _____   _____   _____      _____   _____              \n "
		       "        |     | |     | |     | |          |     | |     | |`      '|   \n "
		       "        |     | |     | |     | |          |     | |     | | `    ' |   \n "
		       "        |_____| |_____| |     | |    _     |_____| |_____| |  `  '  |   \n "
		       "        |       |`      |     | |   |_|__  |`      |     | |   `'   |  \n "
		       "        |       | `     |     | |     |  | | `     |     | |        |  \n "
		       "        |       |  `    |_____| |_____|  | |  `    |     | |        |  \n ";
		getch();
	}
	{
		clrscr();
		constream cout;
		cout<<setclr(4);
		cout<<"\n\n\n\n\n\n\n\n\n\n\n            THIS PROGRAM IS MADE (CODED) BY :\n\n"
					    "                                             1)                        \n"
					    "                                               NAME:      MANARTH PATEL\n"
					    "                                               ROLL NO:                \n"
					    "                                             2)                        \n"
					    "                                               NAME:      DIVYAM SINGH \n"
					    "                                               ROLL NO:                \n";
		getch();
	}
	{
		constream cout;
		cout<<setclr(7);
	}
	clrscr();
	int ch;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	cout<<".......WELCOME TO RAILWAY RESERVATION SYSTEM..........\n";
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
	do
	{
		cout<<"^^^^^^^^^^^^^^^^^^^^^^MAIN MENU^^^^^^^^^^^^^^^^^^^^\n";
		cout<<"1.Admin mode\n2.User mode\n3.Exit\n";
		cout<<"Enter your choice:";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
				database();
			break;
			case 2:
				user();
			break;
			case 3:
				exit(0);
		}
	}
	while(ch<=3);
	getch();
}
/*
   function that checks admins password if enetered correct than allows to
   use program as by admin mode if entered incorrect than asked to enter correct
   password or ask to use program as user mode if user id and password exists.
*/
void database()
{
	char *password;
	char *pass="password";
	password=getpass("Enter the admininistrator password:");
	detail a;
	fstream f;
	int ch;
	char c;
	if(strcmp(pass,password)!=0)
	{
		cout<<"Enter the password correctly \n";
		cout<<"You are not permitted to logon admin mode\n";
		cout<<"Try to use program as user if user id and password is alloted to you\n";
		cout<<"If you dont have user id too ask admin to add your id and password\n";
		goto h;
	}
	if(strcmp(pass,password)==0)
	{
		char c;
		do
		{
			cout<<"\n...........ADMINISTRATOR MENU...........\n";
			cout<<"1.Create detail data base\n2.Add details\n";
			cout<<"3.Display details\n4.User management\n";
			cout<<"5.Display passenger details\n6.Return to main menu\n";
			cout<<"Enter your choice:";
			cin>>ch;
			cout<<endl;
			switch(ch)
			{
				case 1:
					f.open("t.txt",ios::out|ios::binary);
					do
					{
						a.getdetail();
						f.write((char *) & a,sizeof(a));
						cout<<"Do you want to add one more record?\n";
						cout<<"y-for Yes\nn-for No\n";
						cin>>c;
					}
					while(c=='y');
					f.close();
				break;
				case 2:
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					a.getdetail();
					f.write((char *) & a,sizeof(a));
					f.close();
				break;
				case 3:
					cout<<"T.No\t T.Name\tB.P\tD.P  \tF.C\tCost  \tS.C\tCost  \tD.O.T\n";
					cout<<"______________________________________________________________________________\n\n\n";
					f.open("t.txt",ios::in|ios::out|ios::binary|ios::app);
					f.seekg(0);
					while(f.read((char *) & a,sizeof(a)))
					{
						a.displaydetail();
					}
					f.close();
				break;
				case 4:
					manage();
				break;
				case 5:
					displaypassdetail();
				break;
			}
		}
		while(ch<=5);
		f.close();
	}
	h:
}
/*function to revoke "void res()" when needed to reserve seats but once asks
either to continue booking or leave booking.*/
void reserve()
{
	int ch;
	do
	{
		cout<<"1.Reserve\n2.Return to the main menu\n";
		cout<<"Enter your choice:";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
				res();
			break;
		}
	}
	while(ch==1);
	getch();
}
//function to calculate the final amount to be paid by user and then store all data in a file named "p.txt".
void res()
{
	detail a;
	reser b;
	fstream f1,f2;
	time_t t;
	f1.open("t.txt",ios::in|ios::out|ios::binary);
	f2.open("p.txt",ios::in|ios::out|ios::binary|ios::app);
	int ch;
	b.getresdet();
	while(f1.read((char *) &a,sizeof(a)))
	{
		if(a.tno==b.tno)
		{
			if(strcmp(b.clas,f)==0)
			{
				if(a.c1>=b.nosr)
				{
					amt=a.c1fare;
					addr=f1.tellg();
					ad=sizeof(a.c1);
					f1.seekp(addr-(7*ad));
					a.c1=a.c1-b.nosr;
					f1.write((char *) & a.c1,sizeof(a.c1));
					if(b.con==1)
					{
						cout<<"Concession category:MILITARY PERSONNEL\n";
						b.amc=b.nosr*((amt*50)/100);
					}
					else if(b.con==2)
					{
						cout<<"Concession category:SENIOR CITIZEN\n";
						b.amc=b.nosr*((amt*60)/100);
					}
					else if(b.con==3)
					{
						cout<<"You cannot get any concession\n";
						b.amc=b.nosr*amt;
					}
					srand((unsigned)time(&t));
					b.pnr=rand();
					f2.write((char *) & b,sizeof(b));
					b.displayresdet();
					cout<<"------------------------------------------------------\n";
					cout<<"--------------Your ticket is reserved-----------\n";
					cout<<"-----------------End of reservation menu-------\n";
				}
				else
				{
					cout<<"**********Sorry req seats not available********\n";
				}
			}
			else if(strcmp(b.clas,s)==0)
			{
				if(a.c2>=b.nosr)
				{
					amt=a.c2fare;
					addr=f1.tellg();
					ad=sizeof(a.c2);
					f1.seekp(addr-(5*ad));
					a.c2=a.c2-b.nosr;
					f1.write((char *) & a.c2,sizeof(a.c2));
					if(b.con==1)
					{
						cout<<"Concession category:MILITARY PRESONNEL\n";
						b.amc=b.nosr*((amt*50)/100);
					}
					else if(b.con==2)
					{
						cout<<"Concession category:SENIOR CITIZEN\n";
						b.amc=b.nosr*((amt*60)/100);
					}
					else if(b.con==3)
					{
						cout<<"You cannot get any concession\n";
						b.amc=b.nosr*amt;
					}
					f2.write((char *) & b,sizeof(b));
					b.displayresdet();
					cout<<"---------------------------------------\n";
					cout<<"--------Your ticket is reserved--------\n";
					cout<<"------------End of reservation---------\n";
				}
				else
				{
					cout<<"********Sorry req no of seats not available*******\n";
				}
			}
			getch();
			goto h;
		}
		else
		{
			flag=0;
		}
	}
	if(flag==0)
	{
		cout<<"............Wrong train no......................\n";
	cout<<"......Enter the train no from the data base.....\n";
	}
	f1.close();
	f2.close();
	getch();
	h:
}
//function to display passngers details when needed and provokes object from function - "void displaypass()"
void displaypassdetail()
{
	fstream f;
	reser b;
	f.open("p.txt",ios::in|ios::out|ios::binary);
	f.seekg(0);
	while(f.read((char *) & b,sizeof(b)))
	{
		b.displaypass();
	}
	f.close();
	getch();
}
//function to get the details of trains avalable for booking train seats.
void enquiry()
{
	cout<<"T.No\t T.Name\tB.P\tD.P  \tF.C\tCost  \tS.C\tCost  \tD.O.T\n";
	cout<<"______________________________________________________________________________\n\n\n";
	fstream f;
	f.open("t.txt",ios::in|ios::out|ios::binary);
	detail a;
	while(f.read((char *) & a,sizeof(a)))
	{
		a.displaydetail();
	}
	getch();
}
//function to make user use user mode by entering user id and password provided.
void user()
{
	login a;
	int ch;
	cout<<"*****************************************************\n";
	cout<<"***********WELCOME TO THE USER MENU**\n";
	cout<<"****************************************************\n";
	char *password;
	fstream f;
	f.open("id.txt",ios::in|ios::out|ios::binary);
	char id[100];
	puts("Enter your id:");
	gets(id);
	password=getpass("Enter your password:");
	while(f.read((char *) & a,sizeof(a)))
	{
		if((strcmp(a.id,id)==0)&&(strcmp(a.pass,password)==0))
		{
			do
			{
				cout<<"1.Reserve\n2.Enquiry\n3.Return to the main menu\n";
				cout<<"Enter your choice:";
				cin>>ch;
				cout<<endl;
				switch(ch)
				{
					case 1:
					reserve();
					break;
					case 2:
					enquiry();
					break;
				}
			}
			while(ch<=2);
			goto j;
		}
		else
		{
			d=1;
		}
	}
	if(d==1)
	{
		cout<<"Enter your user id and password correctly\n";
	}
	getch();
	j:
}
//function to manage user ids and password.
void manage()
{
	int ch;
	fstream f;
	char c;
	login a;
	cout<<".........WELCOME TO THE USER MANAGEMENT MENU........\n";
	do
	{
		cout<<"1.Create id data base\n2.Add details\n";
		cout<<"3.Display details\n4.Return to the main menu\n";
		cout<<"Enter your choice:";
		cin>>ch;
		cout<<endl;
		switch(ch)
		{
			case 1:
			f.open("id.txt",ios::out|ios::binary);
			do
			{
				a.getid();
				f.write((char *) & a,sizeof(a));
				cout<<"Do you want to add one more record\n";
				cout<<"y-Yes\nn-No\n";
				cin>>c;
			}
			while(c=='y');
			f.close();
			break;
			case 2:
			f.open("id.txt",ios::in|ios::out|ios::binary|ios::app);
			a.getid();
			f.write((char *) & a,sizeof(a));
			f.close();
			break;
			case 3:
			f.open("id.txt",ios::in|ios::out|ios::binary);
			f.seekg(0);
			while(f.read((char *) & a,sizeof(a)))
			{
				a.displayid();
			}
			f.close();
			break;
		}
	}
	while(ch<=3);
	getch();
}
