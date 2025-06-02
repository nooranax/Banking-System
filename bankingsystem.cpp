#include<iostream>
#include<fstream>
using namespace std;

int main()
{
	
	system("color fc");
	cout<<"\t\t\t\t\tWELCOME TO NURPUR BANK LIMITED!!"<<endl;
	cout<<"\t\t\t\t\t--------------------------------"<<endl<<endl;
	
	int bal, nom, damn, totaldamn=0, wdraw, totalwdraw=0;
	float annualint, mint, intam, totalintam=0;
	

	cout<<"Enter Annual Interest Rate (in %)    :";
	cin>>annualint;
	mint=annualint/12;
	cout<<"Enter the Starting Balance           :$";
	cin>>bal;
	cout<<"Number of months account beeen active:";
	cin>>nom;
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl;
	
	
	cout<<"DEPOSIT & WITHDRAWL INFO!!"<<endl;
	cout<<endl;
	for(int i=0; i<nom; i++)
	{
		cout<<"MONTH "<<i+1<<endl;
		cout<<"Deposited Amount :$";
		cin>>damn;
		while(damn<0)
		{
			cout<<"INVALID. Should be higher than 0."<<endl;
			cout<<"Deposited Amount :$";
			cin>>damn;
		}
		totaldamn+=damn;
		bal+=damn;
		cout<<"Withdraw Amount  :$";
		cin>>wdraw;
		while(wdraw<0)
		{
			cout<<"INVALID. Should be higher than 0."<<endl;
			cout<<"Withdraw Amount  :$";
			cin>>wdraw;
		}
		totalwdraw+=wdraw;
		bal-=wdraw;
		
		cout<<"Monthly Interest Rate: "<<mint<<"%"<<endl;
		intam=bal*mint;
		totalintam+=intam;
		cout<<"Interest will be $"<<intam<<endl;
		bal+=intam;
		cout<<endl;
	}
	cout<<"------------------------------------------------------------------------------------------------------------------------"<<endl<<endl;
	cout<<"FINAL REPORT:"<<endl;
	cout<<"Total Account Balance   :$"<<bal<<endl;
	cout<<"Total Amount Deposited  :$"<<totaldamn<<endl;
	cout<<"Total Interest Amount   :$"<<totalintam<<endl; 

	ofstream nurpuracc;
	nurpuracc.open("nurpurbanklim.txt");
	if(nurpuracc.is_open())
	{
		nurpuracc<<bal<<endl;
		nurpuracc<<totaldamn<<endl;
		nurpuracc<<totalintam<<endl;
	}
	nurpuracc.close();

}
