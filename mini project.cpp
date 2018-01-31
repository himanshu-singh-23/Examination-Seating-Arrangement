#include<iostream>
#include<fstream>
#include<conio.h>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<windows.h>
#include<iomanip>
#include<stdlib.h>
using namespace std;
class student
{
	long int registration_no;
	char course_code[50];
	char subject[50];
	public:
	int status;
	public:
		void getdata()
		{
			cout<<" \n\n\t\t\tRegistration No: ";
			cin>>registration_no;
			cout<<" \n\t\t\tPrograme name : ";
			fflush(stdin);
			gets(course_code);
			cout<<"\n\t\t\t Course Code : ";
			fflush(stdin);
			gets(subject);
			status=0;	
		}
		void display()
		{
			cout<<"\n\n\t\t\t\t\t   "<<registration_no<<"\t\t\t   "<<course_code<<"\t\t   "<<subject<<" \t\t\tstatus "<<status<<" "<<endl;
		}
		void display1()
		{
			cout<<"\n\n\t\t\t\t\t   "<<registration_no<<"\t\t\t   "<<course_code<<"\t\t   "<<subject<<endl;
		}
		int reg()
		{
			return registration_no;
		}
		void display2()
		{
			cout<<"\t"<<registration_no<<" "<<course_code<<" "<<subject<<"   ";
		}
		friend void Sitting_Arrangement();
		friend int check_registration_no(long int );
		friend void update(long int);
}s,s1;
////////////////////////////////////////////////////////////////  C H E C K__R E G I S T R A T I O N__N O  /////////////////////////////////////////////////////////
int check_registration_no(long int x)
{
	ifstream fin("./registration_no.txt");
	fin.read((char*)&s,sizeof(s));
	while(!fin.eof())
	{
		if(x==s.registration_no)
		{
			return 0;
			break;	
		}
		else
		fin.read((char*)&s,sizeof(s));
	}
}
////////////////////////////////////////////////////////////  S I T T I N G  A R R A N G E M E N T  /////////////////////////////////////////////////////////////// 
void Sitting_Arrangement() // friend function to do sitting planning...
{
	student s;
	int count=0,n=0;
	fstream f("./registration_no.txt",ios::in | ios::out);// input file
	fstream f1("./registration_no1.txt",ios::out|ios::in|ios::app);//out put file
		if(!f)
		{
			cout<<"\n\t\t\t\t\t\t REQUIRED DATA IS NOT AVAILABLE  PLEASE MAKE SURE YOU HAVE A INPUT FILE ";
		}
		else
		{
			f.read((char*)&s,sizeof(s));
			while(!f.eof())
			{
				n++;
				f.read((char*)&s,sizeof(s));
			}
			f.clear();
			f.seekg(0,ios::beg);
			f.read((char*)&s,sizeof(s));
			for(int i=0;i<=n;i++)
			{
					if(s.status==0)
					{
						count++;
					}
					if(count==1&&s.status==0)
					{
						f1.write((char*)&s,sizeof(s));
						s1=s;// storing the value of readen data from input file into a same type of class object;
						s1.status=1;
						count++;
						f.seekp(-abs(sizeof(s1)),ios::cur);
						f.write((char*)&s1,sizeof(s1));
					}
					if(f.eof())
					{
						if(count==0)
						{
							Sleep(1000);
							cout<<"\n\t\t\t\t\t\t\t\t Examination Sitting Arrangenemt Is Started Now ....";
							Sleep(4500);
							cout<<"\n\n\n\t\t\t\t\t\t\t\t Examination Sitting  Arrangement Completed :) ";
							Sleep(1250);
							cout<<"\n\n\n\t\t\t\t\t\t\t\t Please See The Output File  ";
							break;	
						}
						else
						{
							f.close();
							f1.close();
							Sitting_Arrangement();
						}
					}	
					else
					{
					
						if(stricmp(s.course_code,s1.course_code)!=0&&stricmp(s.subject,s1.subject)!=0&&s.registration_no!=s1.registration_no&&s.status==0&&count!=0)
						{// condition as per our sitting plan;
							s1=s;
							f1.write((char*)&s1,sizeof(s1));
							s1.status=1;
							f.seekp(-abs(sizeof(s1)),ios::cur);
							f.write((char*)&s1,sizeof(s1));
						}				
					}
					f.read((char*)&s,sizeof(s));	
			}
		}
			f1.close();f.close();
}
/////////////////////////////////////////////////////////////////////  D A T E__C H E C K  /////////////////////////////////////////////////////////////////////////////////
int Date_check(string b)
{
	if(b.size()<10)
	{
		cout<<"\n\n Wrong Formate Of Date Correct Formate is : (dd/mm/yyyy) ";
		return 1;
	}
	if(b[0]>='2'&&b[3]=='0'&&b[4]=='2')
	{
		cout<<"\n\n Its Feb Date Can't Be 29 ";
		return 1;
	}
	else if(b[3]=='1'&&b[4]>'2')
	{
		cout<<"\n\n Wrong Month ";
		return 1;	
	}
	else if(b[0]>='3'&&b[1]>='2')
	{
		cout<<"\n\n Wrong Date ";
		return 1;	
	}
	else
	return 0;
}
///////////////////////////////////////////////////////////////////////  D A T E__C O M P A R E  /////////////////////////////////////////////////////////////////
int Date_compare(string d,string b)
{
	if(d[6]>b[6])
	{
		return 0;
	}
	else if(d[6]==b[6]&&d[7]>b[7])
	{
		return 0;
	}
	else if(d[6]==b[6]&&d[7]==b[7]&&d[8]>b[8])
	{
		return 0;
	}
	else if(d[6]==b[6]&&d[7]==b[7]&&d[8]==b[8]&&d[9]>b[9])
	{
		return 0;
	}
	else if(d[6]==b[6]&&d[7]==b[7]&&d[8]==b[8]&&d[9]==b[9])
	{
		if(d[3]>b[3])
		{
			return 0;
		}
		else if(d[3]==b[3]&&d[4]>b[4])
		{
			return 0;
		}
		else if(d[3]==b[3]&&d[4]==b[4])
		{
			if(d[0]>b[0])
			{
				return 0;
			}
			else if(d[0]==b[0]&&d[1]>b[1])
			{
				return 0;
			}
			else if(d[0]==b[0]&&d[1]<b[1])
			{
				return 1;
			}
			else if(d[0]<b[0])
			{
				return 1;
			}
		}
		else if(d[3]==b[3]&&d[4]<b[4])
		{
			return 1;
		}
		else if(d[3]<b[3])
		{
			return 1;
		}
	}
	else
	return 1;
}
////////////////////////////////////////////  F o r m a t e__o f__S i t t i n g__A r r a n g e m e n t  /////////////////////////////////////////////////////////
void Formate_of_Sitting_Arrangement()
{
	ifstream f("./registration_no1.txt");
	if(!f)
	{
		Sleep(2000);
		cout<<"\n\n\t\t\t\t\t\t\t\t Sorry!!! Students Data Not Found ....";
	}
	else
	{
		Sleep(1000);
		int Room_no,Days,count,flag=0;
		string b,d;
		cout<<"\n\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
		cout<<"\n\n Enter The No. Of Rooms Available : ";
		cin>>Room_no;
		a:cout<<"\n\n Enter The current Date (dd/mm/yyyy) : ";
		cin>>b;
		flag=Date_check(b);
		if(flag!=0)
		{
			goto a;
		}
		else
		{
			flag=0;
			b:cout<<"\n\n Enter The Date Of First Examination (dd/mm/yyyy) : ";
			cin>>d;
			flag=Date_check(d);	
			if(flag!=0)
			{
				goto b;
			}
			else
			{
				flag=0;
				flag=Date_compare(d,b);
				if(flag!=0)
				{
					cout<<"\n\n Sorry!! , We Are Unable To Do Sitting Arrangements For Previous Dates :";
				}
				else
				{
					cout<<"\n\n Enter The No. Of Days Of Examination : ";
					cin>>Days;
					Sleep(3000);
					if(Days>0&&Room_no>0)
					{
						for(int r=0;r<Days;r++)
						{
							count=0;
							ifstream f("./registration_no1.txt");
							if(!f)
							{	
								Sleep(2000);
								cout<<"\n\n\t\t\t\t\t\t\t\t Sorry!!! Students Data Not Found ....";
							}
							else
							{
								cout<<"\n\n\t\t\t\t-----------------------------------S I T T I N G  A R R A N G E M E N T -------------------------------\n";
								cout<<"\n     DATE:-"<<r+9<<"-05-2016 \n\n     Time: 10:00 to 13:00 ";
								for(int i=0;i<Room_no;i++)
								{
									cout<<" \t\t\t\t\t\t\t\t\t\t\t\t\t\t\t Room No. "<<i+1<<"\n\n";
									for(int j=0;j<5;j++)
									{
										for(int k=0;k<6;k++)
										{
											f.read((char*)&s,sizeof(s));
											count++;
											if(f.eof())
											{
												j=5;
												i=Room_no;
												f.close();
												break;
											}
											else
											{
												s.display2();
											}
										}
										cout<<endl<<endl;
									}
								}	
							}
						}
						if(--count<Room_no*60)
						{
							cout<<"\n\n\t\t\t\t Less Number Of Students Are Available Sorry We Are Unable To Fill All The Rooms...";	
						}	
					}
					else if(Days<=0)
					{	
						cout<<"\n\n\t\t\t\t\t Sorry!! Sitting Arrangement Can't Be Done For "<<Days<<" no. Of Days...";
					}	
					else
					{
						cout<<"\n\n\t\t\t\t\t\t\t\t Sorry !! Rooms Are Not Available...";
					}	
				}	
			}
		}
	}
}
////////////////////////////////////////////////////////////////////////////  D E L E T E  //////////////////////////////////////////////////////////////////////////
string Delete()
{
	cout<<"\n\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	cout<<"\n\n\t\t\t\t\t\t\t\t [1]. DELETE INPUT FILE \n\t\t\t\t\t\t\t\t [2]. DELETE OUTPUT FILE   \n\t\t\t\t\t\t\t\t [3]. Select All \n\t\t\t\t\t\t\t\t [4]. Back :  " ;
	int x;
	cin>>x;
	q:switch(x)
	{
		case 1:
		{
			char y;
			cout<<"\n\t\t\t\t\t\t\t\t Are You Really Want To Delete The File ? (y/n) : ";
			cin>>y;
			if(y=='y'||y=='Y')
			{
				remove("./registration_no.txt");
				Sleep(2000);
				cout<<"\n\n\t\t\t\t\t\t\t\t File Is Deleted Successfully\n";
				getch();	
				system("CLS");
				return "0";
			}
			else if(y=='n'||y=='N')
			{
				cout<<"\n\n\t\t\t\t\t\t\t\t File Not Deleted\n";
				return "5";	
			}
			else
			{
				x=1;
				goto q;
			}	
			break;
		}
		case 2:
		{
			char y;
			cout<<"\n\t\t\t\t\t\t\t\t Are You Really Want To Delete The File ? (y/n) : ";
			cin>>y;
			if(y=='y'||y=='Y')
			{
				remove("./registration_no1.txt");
				Sleep(2500);
				cout<<"\n\n\t\t\t\t\t\t\t\t File Is Deleted Successfully\n";
				getch();
				system("CLS");
				return "0";	
			}
			else if(y=='n'||y=='N')
			{
				cout<<"\n\n\t\t\t\t\t\t\t\t File Is Not Deleted ";
				return "5";	
			}
			else
			{
				x=2;
				goto q;
			}	
			break;
		}
		case 3:
		{
			char y;
			cout<<"\n\t\t\t\t\t\t\t\t Are You Really Want To Delete Both The Files ? (y/n) : ";
			cin>>y;
			if(y=='y'||y=='Y')
			{
				remove("./registration_no1.txt");
				remove("./registration_no.txt");
				Sleep(3500);
				cout<<"\n\n\t\t\t\t\t\t\t\t Files Are Deleted Successfully\n";
				getch();
				system("CLS");
				return "0";	
			}
			else if(y=='n'||y=='N')
			{
				cout<<"\n\n\t\t\t\t\t\t\t\t Files Are Not Deleted ";
				return "5";	
			}
			else
			{
				x=3;
				goto q;	
			}	
			break;
		}
		case 4:
		{
			system("CLS");
			return "0";
			break;
		}
		default:
			cout<<" \n\t\t\t\t\t\t\t\t Wrong Choice ";
			return "5";
			break;
	}	
}
//////////////////////////////////////////////////////////////////  R E S T O R E__S T A T U S  //////////////////////////////////////////////////////////////////
void Restore_status()
{
	fstream fin("e:\\my apps\\registration_no.txt",ios::in|ios::out);
	if(!fin)
	{
		cout<<"\n\t\t\t\t\t\t\t\t SOrRy!! File Not Found Which You Want To Restore ";
	}
	else
	{
		fin.read((char*)&s,sizeof(s));
		while(!fin.eof())
		{
			s.status=0;
			fin.seekp(-abs(sizeof(s)),ios::cur);
			fin.write((char*)&s,sizeof(s));
			fin.read((char*)&s,sizeof(s));
		}
			fin.close();
			Sleep(3000);
			cout<<"\n\n\t\t\t\t\t\t\t\t Congratulations Status Restored Successfully \n\t\t\t\t\t\t\t\t\t\t Now Status = 0 ";
			Sleep(1750);
			cout<<"\n\n\t\t\t\t\t\t\t\t !!! Please Delete The OutPut File Important.........";
	}
}
////////////////////////////////////////////////////////////////////////////////// M A I N ////////////////////////////////////////////////////////////////////////
int main()
{
	student s2;
	char g,c;
	int j=0,l=6,count=0;;
	string password,t;
	cout<<"\n\t\t\t\t********    THIS APPLICATION IS ABOUT AUTOMATIC EXAMINATION SITTING ARRANGEMENT   *********";
	cout<<"\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t$ DESIGN BY H!MANSHU S!NGH\n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t  B.Tech CSE (hons.) \n\n";
	cout<<"--------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
	z:cout<<"\n\n\n\t\t\t\t\t\t\t\t      LOG IN\n\n\t\t\t\t\t\t\t\t USER NAME : ADMIN \n\n\t\t\t\t\t\t\t\t PASSWORD  : ";
	c=getch();
	while(c!=13)
	{
		cout<<"*";
		password.push_back(c);
		c=getch();
	}
	if(!password.compare("12345"))
	{
		system("cls");
		Sleep(3000);
		do
		{
			o:cout<<"\n\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
			cout<<"\n------------------------\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\-------------------------------";
			cout<<"\n------------------------------------------------------------------------------------------------------------------------------------------------------------------------";	
			cout<<"\n\n\n\t\t\t\t\t\t\t\t [1]. Add Student Data\n\n\t\t\t\t\t\t\t\t [2]. Display All Saved Data \n\n\t\t\t\t\t\t\t\t [3]. Automatic Sitting Arrangement\n\n\t\t\t\t\t\t\t\t [4]. Formate Of Sitting Arrangement ( How It Looks Like ) \n\n\t\t\t\t\t\t\t\t [5]. Delete All Saved Data \n\n\t\t\t\t\t\t\t\t [6]. Restore Status \n\n\t\t\t\t\t\t\t\t [7]. Exit : ";
			cin>>t;
				p:	if(t=="1")
					{
						system("CLS");
						char y;int x=1;
						ofstream f("./registration_no.txt",ios::app);
						s.getdata();
						cout<<"\n\n\t\t\t\t\t\t\t\t Data Entered By You \n\n ";
						cout<<"\t\t\t\t\t REGISTRATION NO. \t\t PROGRAME NAME \t\t COURSE CODE ";
						s.display1();
						s2=s;
						x=check_registration_no(s.reg());
						if(x==0)
						{			
							cout<<"\n\n\t\t\t\t\t Registration No. Entered By you Is Already Present In The File ";
							Sleep(3000);
							t="1";
							f.close();
							goto p;
						}
						else
						{
							fflush(stdin);
							v:cout<<"\n\n\t\t\t\t\t\t\t\t Is It Correct ? (y/n) : ";
							cin>>y;
							if(y=='y'||y=='Y')
							{
								f.write((char*)&s2,sizeof(s2));	
								f.close();	
								Sleep(4000);
								cout<<"\n\n\t\t\t\t\t\t\t\t Data Recorded Succsessfully !!! ";
								Sleep(1000);
								system("CLS");
								goto o;
							}
						else if(y=='n'||y=='N')
						{
							f.close();
							t="1";
							goto p;
						}
						else
						{
							cout<<"\n\t\t\t\t\t\t\t\t Sorry It Is Not A Correct Choice ";
							goto v;	
						}	
						}	
					}
					else if(t=="2")
					{
						system("CLS");
						int x;
						cout<<"\n\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
						cout<<"\n\n\t\t\t\t\t\t\t\t [1]. Input File \n\t\t\t\t\t\t\t\t [2]. Output File \n\t\t\t\t\t\t\t\t [3]. Back : ";
						cin>>x;
						if(x==1)
						{
							cout<<"\n\n\t\t\t\t\t\t\t\t File is opening Please Wait For a Moment\n\n\n";
							Sleep(5000);
							ifstream fi("./registration_no.txt");
							if(!fi)
							{
								cout<<"\n\t\t\t\t\t\t\t\t SORRY!! File May Be Deleted Or Misssing ";
							}
							else
							{
								cout<<"\t\t\t\t\t REGISTRATION NO. \t\t PROGRAME NAME \t\t COURSE CODE ";
								fi.read((char*)&s,sizeof(s));
								while(!fi.eof())
								{
									s.display();
									fi.read((char*)&s,sizeof(s));
								}
								fi.close(); 
							}	
						}
						else if(x==2)
						{
							cout<<"\n\n\t\t\t\t\t\t\t\t File is opening Please Wait For a Moment\n\n\n";
							Sleep(10000);
							ifstream fi("./registration_no1.txt");
							if(!fi)
							{
								cout<<"\n\t\t\t\t\t\t\t\t SORRY!! File May Be Deleted Or Misssing ";
							}
							else
							{
								cout<<"\t\t\t\t\t REGISTRATION NO. \t\t PROGRAME NAME \t\t COURSE CODE ";
								fi.read((char*)&s,sizeof(s));
								while(!fi.eof())
								{
									s.display1();
									fi.read((char*)&s,sizeof(s));
								}
								fi.close(); 
							}
						}
						else if(x==3)
						{
							system("CLS");
							goto o;	
						}
						else
						{
							cout<<"\n\t\t\t\t\t\t\t\t Sorry It Is Not A Correct Choice ";
							getch();
							system("CLS");
							t="2";
							goto p;
						}
						getch();	
						system("CLS");
					}	
				else if(t=="3")
					{
						system("CLS");
						string k;
						cout<<"\n\n\t\t\t\t\t\t\t\t Press Enter To Start Sitting Arrangement : ";
						fflush(stdin);
						getline(cin,k);
						if(k.size()==0)
						{
							Sitting_Arrangement();// calling the friend function .....	
						}
						else
						{
								cout<<"\n\t\t\t\t\t\t\t\t Sorry You Have To Press Enter ";
								getch();
								t="3";
								goto p; 
						}			
						getch();
						system("ClS");
					}
				else if(t=="4")
					{
						system("CLS");
						Formate_of_Sitting_Arrangement();
						getch();	
						system("CLS");
					}	
				else if(t=="5")
					{
						system("CLS");
						t=Delete();
						if(t=="0")
						{
							goto o;
						}
						else
						{
							getch();
							system("CLS");
							goto p;
						}
					}
				else if(t=="6")
					{
						system("CLS");
						Restore_status();
						getch();
						system("CLS");
					}
				else if(t=="7")
					{
						Sleep(2000);
						cout<<"\n\n\n\t\t\t\t\t\t\t ******* THANKYOU FOR USEING THiS APPLICATION  ******";
					}
				else
				cout<<"\n\n\t\t\t\t\t\t\t WRONG CHOICE PLEASE CHOOSE FROM < 1 - 7 > \n\n";
		}while(t!="7");	
	}
	else
	{
		count++;
		if(count>=3)
		{
			Sleep(1500);
			cout<<"\n\t\t\t\t\t\t\t\t SORRY!! YOU ARE NOT AN AUTHORIZED USER \n\n\n";
			cout<<"\n\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
			t=6;
			goto p;
		}
		else
		{
			cout<<"\n\t\t\t\t\t\t\t\t SORRY!! wrong password \n\n\t\t\t\t\t\t\t\t Plz Try Again \n\n\t\t\t\t\t\t\t\t You Have Only "<<3-count<<" Chance Left\n\n\n";
			cout<<"\n\n--------------------------------------------------------------------------------------------------------------------------------------------------------------------------";
			goto z;	
		}
	}
	getch();
}
