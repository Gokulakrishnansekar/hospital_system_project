#include "patient_details.h"
#include<bits/stdc++.h>

void patient_details::pget_details()
{
//	string s=pa_details();



	
	ans=false;
    hput_details();
	ifstream H;
	H.open("h_details.txt");
	cout<<"enter the hospital name: ";
	string dname;
	cin>>dname;
	H>>name;
	H>>location;
	H>>contact;
	H>>bed_avail;
	H>>rating;	
	while(!H.eof())
	{	
		if(name==dname)
		{
		
		
			
			ofstream get;
			get.open("p_details.txt",ios::app);
			get<<name<<endl;
				cout<<"enter patient name\n";
				cin>>p_name;
			get<<p_name<<endl;	
				cout<<"enter patient contact number\n";
				cin>>contact;
			get<<contact<<endl;	
				cout<<"enter patient's room name\n";
				cin>>room_id;
			get<<room_id<<endl;	
			//	cout<<"enter doctor name\n"	;
			//	cin>>doctor_id;
			//get<<doctor_id<<endl;
		   
				cout<<"enter admit date\n";
				cin>>admit_date;
			get<<admit_date<<endl<<endl;
			
			
			
			
			
		
			ans=true;
		}
				
		H>>name;
	    H>>location;
	    H>>contact;
	    H>>bed_avail;
	    H>>rating;
}
	cout<<endl<<endl;
	H.close();	
	if(ans==false)
	{
		cout<<"there is no hospital in that name\n";				
	}
	else
	cout<<"successfully\n";


}

void patient_details::pput_details()
{
	ans=false;
	ifstream patient;
	patient.open("p_details.txt");
	string ctr_name;
	string ctr_hname;
	cout<<"enter patient name\n";
	cin>>ctr_name;
	cout<<"enter hospital name\n";
	cin>>ctr_hname;
		patient>>name;
		patient>>p_name;
		patient>>contact;
		patient>>room_id;
	//	patient>>doctor_id;
		patient>>admit_date;
		while(!patient.eof())
		{
			if(name==ctr_hname && p_name==ctr_name)
			{		
		cout<<"-------------------------------------------------PATIENT DETAILS-------------------------------------------------\n";
		cout<<setw(20)<<setiosflags(ios::left) << "HospitalName"<<setw(20)<<setiosflags(ios::left)
		<<"paitent_name"<<setw(20)<<setiosflags(ios::left)
		<<"contact"<<setw(20)<<setiosflags(ios::left)
		<<"room no"<<setw(20)<<setiosflags(ios::left)
		<<"admit data"<<endl<<endl;
		
		cout<<setw(20)<<setiosflags(ios::left)<<name<<
		setw(20)<<setiosflags(ios::left)<<p_name<<
		setw(20)<<setiosflags(ios::left)<<contact<<
		setw(20)<<setiosflags(ios::left)<<room_id<<
	
		setw(20)<<setiosflags(ios::left)<<admit_date<<endl;				
		ans=true;
		}
			patient>>name;
		patient>>p_name;
		patient>>contact;
		patient>>room_id;
	//	patient>>doctor_id;
		patient>>admit_date;
			
		}
		patient.close();
		cout<<endl;
		if(ans==false)
		{
			cout<<"you enter wrong details! please enter correctly\n";
		}	
}
void patient_details::p_remove()
{
	ifstream patient;
	patient.open("p_details.txt");
	ofstream in;
	in.open("new.txt");
	cout<<"enter hospital name\n";
	string h_name;
	cin>>h_name;
	cout<<"enter patient name\n";
	string pname;
	cin>>pname;
	
	patient>>name;
	patient>>p_name;
	patient>>contact;
	patient>>room_id;
//	patient>>doctor_id;
	patient>>admit_date;
	while(!patient.eof())
	{
		if(!(h_name==name && p_name==pname))
		{
		    in<<name<<endl<<p_name<<endl<<contact<<endl<<room_id<<endl<<admit_date<<endl<<endl;	
		}
		patient>>name;
		patient>>p_name;
		patient>>contact;
		patient>>room_id;
	//	patient>>doctor_id;		
		patient>>admit_date;
	}
	in.close();
	patient.close();
	if(remove("p_details.txt")!=0)
	cout<<"not deleted\n";
	if(rename("new.txt","p_details.txt")!=0)
	cout<<"not renamed\n";
	else
	cout<<"changes are made successfully\n";
}
void patient_details::p_viewall()
{
	hput_details();
	cout<<endl<<endl;
	ifstream patient;
	patient.open("p_details.txt");
	
		patient>>name;
		patient>>p_name;
		patient>>contact;
		patient>>room_id;
	//	patient>>doctor_id;
		patient>>admit_date;
			cout<<"-------------------------------------------------PATIENT DETAILS-------------------------------------------------\n";
		cout<<setw(20)<<setiosflags(ios::left) << "HospitalName"<<setw(20)<<setiosflags(ios::left)
		<<"paitent_name"<<setw(20)<<setiosflags(ios::left)
		<<"contact"<<setw(20)<<setiosflags(ios::left)
		<<"room no"<<setw(20)<<setiosflags(ios::left)
		<<"admit date"<<endl<<endl;
		while(!patient.eof())
		{
					
	
		
		cout<<setw(20)<<setiosflags(ios::left)<<name<<
		setw(20)<<setiosflags(ios::left)<<p_name<<
		setw(20)<<setiosflags(ios::left)<<contact<<
		setw(20)<<setiosflags(ios::left)<<room_id<<
		setw(20)<<setiosflags(ios::left)<<admit_date<<endl<<endl;
		//setw(20)<<setiosflags(ios::left)<<admit_date<<endl;				
		
			patient>>name;
		patient>>p_name;
		patient>>contact;
		patient>>room_id;
		//patient>>doctor_id;
		patient>>admit_date;
			
		}
		patient.close();
		cout<<endl;
	
}
