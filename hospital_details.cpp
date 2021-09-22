#include "hospital_details.h"
#include <bits/stdc++.h>
#include<fstream>
using namespace std;
hospital_details::hospital_details()
{
	password="admin";
	avr=5;
}
hospital_details::verify(string create)
{
if(create!=password)
	{
		cout<<"\n\nYOU NOT AN ADMIN\n\n";
		return 0;
		
	}
	else
	{
		cout<<"-------------------------------------------------verified-------------------------------------------------\n";
	}
	return 1;
}
void hospital_details::hget_details()
{
	
		
	
	cout<<"enter hospital name :";
	cin>>name;
	cout<<"\nenter location: ";
	cin>>location;
	cout<<"enter hosptial contact number\n";
	cin>>contact;
	cout<<"\nenter bed availability : ";
	cin>>bed_avail;
	cout<<"\nenter rating : ";
	cin>>rating;

	ofstream hdata;
	hdata.open("h_details.txt",ios::app);
	hdata<<name<<endl<<location<<endl<<contact<<endl<<bed_avail<<endl<<rating<<endl<<endl;
	cout<<"successfully inserted\n";
	hdata.close();

}

void hospital_details::hput_details()
{
//	string H_string;
	ifstream Hospital;
	cout<<"-------------------------------------------------HOSPITAL DETAILS-------------------------------------------------\n";
		cout<<setw(20)<<setiosflags(ios::left) << "HospitalName"<<setw(20)<<setiosflags(ios::left)
		<<"Location"<<setw(20)<<setiosflags(ios::left)
		<<"contact"<<setw(20)<<setiosflags(ios::left)
		<<"bed_avail"<<setw(20)<<setiosflags(ios::left)
		<<"rating"<<endl<<endl;
		
	Hospital.open("h_details.txt");
	Hospital>>name;
	Hospital>>location;
	Hospital>>contact;
	Hospital>>bed_avail;
	Hospital>>rating;
	while(!Hospital.eof())
	{
		cout<<setw(20)<<setiosflags(ios::left) << name
		<<setw(20)<<setiosflags(ios::left)<< location
		<<setw(20)<<setiosflags(ios::left)<< contact
		<<setw(20)<<setiosflags(ios::left)<<bed_avail
		<<setw(20)<<setiosflags(ios::left)<<rating<<endl;
		
		
		Hospital>>name;
	    Hospital>>location;
	    Hospital>>contact;
	    Hospital>>bed_avail;
	    Hospital>>rating;
	}
	cout<<endl<<endl;
	Hospital.close();
	
}
void hospital_details::delete_detail()
{
	ifstream d;
	d.open("h_details.txt");
	ofstream n;
	n.open("new.txt");
	cout<<"enter hospital name :";
	string dname;
	cin>>dname;
	d>>name;
	d>>location;
	d>>contact;
	d>>bed_avail;
	d>>rating;
	while(!d.eof())
	{
		if(name!=dname)
		{
		n<<name<<endl<<location<<endl<<contact<<endl<<bed_avail<<endl<<rating<<endl<<endl;	
		}
		
		
	d>>name;
	d>>location;
	d>>contact;
	d>>bed_avail;
	d>>rating;
	}
	n.close();
	d.close();
	if(remove("h_details.txt")!=0)
	cout<<"file does not remove\n";
	else
	cout<<"file removed successfully\n";
	
	if(rename("new.txt","h_details.txt")!=0)
	cout<<"file does not rename\n";
	else
	cout<<"file renamed successfully\n";
		
}
void hospital_details::modify_rating()
{

	ifstream d;
	d.open("h_details.txt");
	ofstream n;
	n.open("new.txt");
	cout<<"enter the hospital name: ";
		string dname;
	cin>>dname;
	d>>name;
	d>>location;
	d>>contact;
	d>>bed_avail;
	d>>rating;
	
	while(!d.eof())
	{
		if(name!=dname)
		{
		n<<name<<endl<<location<<endl<<contact<<endl<<bed_avail<<endl<<rating<<endl<<endl;	
		}
		if(name==dname)
		{
			int nr;
			cout<<"enter new rating (below 100):";
			cin>>nr;
			if(nr>100)
			cout<<"not valid\n";
			else
			{
				avr++;
				nr=(nr/avr+rating);
				n<<name<<endl<<location<<endl<<contact<<endl<<bed_avail<<endl<<nr<<endl<<endl;
			}
		
		}
		
		
	d>>name;
	d>>location;
	d>>contact;
	d>>bed_avail;
	d>>rating;
	}
	
	d.close();
	n.close();
	if(remove("h_details.txt")!=0)
	{
		cout<<"error\n";
		
		
	}
	else
	cout<<"successfully recreated\n";
	if(rename("new.txt","h_details.txt"))
	{
		cout<<"not modify\n";
	}
	else
	cout<<"modified successfully\n";
	
	
}
void hospital_details::location_details()
{
	ifstream d;
	d.open("h_details.txt");

	cout<<"enter location  :";
	string dname;
	cin>>dname;
	d>>name;
	d>>location;
	d>>contact;
	d>>bed_avail;
	d>>rating;
	cout<<setw(50)<<setiosflags(ios::left)<<"hospital name"<<setw(50)<<setiosflags(ios::left)<<"location"<<endl;
	while(!d.eof())
	{
		if(location==dname)
		{
		cout<<setw(50)<<setiosflags(ios::left)<<name<<setw(50)<<setiosflags(ios::left)<<location<<endl;	
		}
		
		
	d>>name;
	d>>location;
	d>>contact;
	d>>bed_avail;
	d>>rating;
	}
	d.close();

cout<<endl<<endl<<endl;
		
}

