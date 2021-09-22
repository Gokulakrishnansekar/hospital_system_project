#ifndef HOSPITAL_DETAILS_H
#define HOSPITAL_DETAILS_H
#include <bits/stdc++.h>
using namespace std;
class hospital_details
{
	public:
		int verify(string);
		hospital_details();
		void hget_details();
		void hput_details();
		void delete_detail();
		void modify_rating();
		void location_details();
	protected:
		string name;
		string location;
		string password;
		string bed_avail;
		int rating;
		string contact;
		int avr;
		
};

#endif
