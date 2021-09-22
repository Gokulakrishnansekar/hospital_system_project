#ifndef PATIENT_DETAILS_H
#define PATIENT_DETAILS_H

#include "hospital_details.h"

class patient_details : public hospital_details
{
	public:
		
		void pget_details();
		void pput_details();
		void p_remove();
		void p_viewall();
	protected:
		string p_name;
		string contact;
		string room_id;
		string doctor_id;
		string admit_date;
		string hos;
		bool ans;
		
	
};

#endif
