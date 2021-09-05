
#include <bits/stdc++.h>
using namespace std;


class Hospital {
public:
	string H_name;
	string location;
	int available_beds;
	float rating;
	string contact;
	string doctor_name;
	int price;
};


class Patient : public Hospital {
public:
	string P_name;
	int P_id;
};

// Hospital Data
void PrintHospitalData(
	vector<Hospital>& hospitals)
{
	cout << "PRINT hospitals DATA:"
		<< endl;

	cout << "HospitalName"<<setw(10)
		<< "Location"<<setw(20)
		<< "Beds_Available"<<setw(15)
		<< "Rating	 "<<setw(15)
		<< "Hospital_Contact	 "<<setw(15)
		<< "Doctor_Name	 "<<setw(10)
		<< "Price_Per_Bed	 \n";

	for (int i = 0; i < 4; i++) {
		cout <<setw(2)
		<< hospitals[i].H_name
			<< setw(20)
			
			<< hospitals[i].location
			<<setw(20)
			<< hospitals[i].available_beds
			<< setw(12)
			<< hospitals[i].rating
			<< setw(19)
			<< hospitals[i].contact
			<< setw(21)
			<< hospitals[i].doctor_name
			<< setw(10)
		
			<< hospitals[i].price
			<<setw(10)
			<< endl;
	}

	cout << endl
		<< endl;
}

// Function to print the patient
// data in the hospital
void PrintPatientData(
	vector<Patient>& patients,
	vector<Hospital>& hospitals)
{
	cout << "PRINT patients DATA:"
		<< endl;
	cout << "Patient_Name  "
		<< "Patient_Id  "
		<< "Patient_Contact	 "
		<< "Alloted_Hospital	 "
		<< "Patient_Expenditure	 \n";

	for (int i = 0; i < 4; i++) {
		cout
		<< setw(6)
		 << patients[i].P_name
			<< setw(11)
		
			<< patients[i].P_id
			
			<< setw(21)
			<< patients[i].contact
			<< setw(24)
			<< hospitals[i].H_name
			<< setw(20)
			<< patients[i].price
			
			<< endl;
	}

	cout << endl
		<< endl;
}

// Comparator function to sort the
// hospital data by name
bool name(Hospital& A, Hospital& B)
{
	return A.H_name > B.H_name;
}

// Function to sort the hospital
// data by name
void SortHospitalByName(
	vector<Hospital> hospitals)
{
	// Sort the date
	sort(hospitals.begin(),
		hospitals.end(),
		name);

	cout << "SORT BY NAME:"
		<< endl
		<< endl;
	PrintHospitalData(hospitals);
}

// Comparator function to sort the
// hospital data by rating
bool rating(Hospital& A, Hospital& B)
{
	return A.rating > B.rating;
}

// Function to sort the hospital
// data by namerating
void SortHospitalByRating(vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		rating);

	cout << "SORT BY Rating:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

// Comparator function to sort the
// hospital data by Bed Available
bool beds(Hospital& A, Hospital& B)
{
	return A.available_beds > B.available_beds;
}

// Function to sort the hospital
// data by Bed Available
void SortByBedsAvailable(
	vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		beds);

	cout << "SORT BY Available Beds:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

// Comparator function to sort the
// hospital data by Bed Price
bool beds_price(Hospital& A, Hospital& B)
{
	return A.price < B.price;
}

// Function to sort the hospital
// data by Bed Price
void SortByBedsPrice(
	vector<Hospital> hospitals)
{
	sort(hospitals.begin(),
		hospitals.end(),
		beds_price);

	cout << "SORT BY Available Beds Price:"
		<< endl
		<< endl;

	PrintHospitalData(hospitals);
}

// Comparator function to sort the
// hospital data by City
void PrintHospitalBycity(
	string city, vector<Hospital> hospitals)
{
	cout << "PRINT hospitals by Name :"
		<< city << endl;

	cout << "HospitalName  "
		<< "Location "
		<< "Beds_Available  "
		<< "Rating  "
		<< "Hospital_Contact  "
		<< "Doctor_Name  "
		<< "Price_Per_Bed	 \n";

	for (int i = 0; i < 4; i++) {

		if (hospitals[i].location != city)
			continue;
		cout << setw(7) 
		     <<hospitals[i].H_name
			<< setw(15)
		
			<< hospitals[i].location
			<< setw(10)
			<< hospitals[i].available_beds
			<< setw(11)
			<< hospitals[i].rating
			<< setw(20)
			<< hospitals[i].contact
			<< setw(12)
			<< hospitals[i].doctor_name
			<< setw(8)
		
			<< hospitals[i].price
			<< setw(0)
			<< endl;
	}
	cout << endl
		<< endl;
}

// Function to implement Hospital
// Management System
void HospitalManagement(
	string patient_Name[], int patient_Id[],
	string patient_Contact[], int bookingCost[],
	string hospital_Name[], string locations[], int beds[],
	float ratings[], string hospital_Contact[],
	string doctor_Name[], int prices[])
{
	// Stores the Hospital data
	// and user data
	vector<Hospital> hospitals;

	// Create Objects for hospital   					 patient_Name, patient_Id, patient_Contact,
	//								   				   	bookingCost, hospital_Name, locations, beds,
	//													ratings, hospital_Contact, doctor_Name, prices);
	// and the users
	Hospital h;

	// Initialize the data
	for (int i = 0; i < 4; i++) {
		h.H_name = hospital_Name[i];
		h.location = locations[i];
		h.available_beds = beds[i];
		h.rating = ratings[i];
		h.contact = hospital_Contact[i];
		h.doctor_name = doctor_Name[i];
		h.price = prices[i];
		hospitals.push_back(h);
	}

	// Stores the patient data
	vector<Patient> patients;
	Patient p;

	// Initialize the data
	for (int i = 0; i < 4; i++) {
		p.P_name = patient_Name[i];
		p.P_id = patient_Id[i];
		p.contact = patient_Contact[i];
		p.price = bookingCost[i];
		patients.push_back(p);
	}

	cout << endl;

	// Call the various operations
	PrintHospitalData(hospitals);
	PrintPatientData(patients, hospitals);

	SortHospitalByName(hospitals);
	SortHospitalByRating(hospitals);
	cout<<"enter the hospital to find\n";
	string s;
	cin>>s;
	PrintHospitalBycity(s, hospitals);
	SortByBedsAvailable(hospitals);
	SortByBedsPrice(hospitals);
}

// Driver Code
int main()
{
	
	string patient_Name[] = { "P1", "P2", "P3", "P4" };
	int patient_Id[] = { 2, 3, 4, 1 };
	string patient_Contact[]
		= { "2345342657", "2345764852", "8574655809",
			"5676573980" };
	int bookingCost[] = { 1000, 1200, 1100, 600 };

	string hospital_Name[] = { "H1", "H2", "H4", "H3" };
	string locations[] = { "chennai", "Bangalore",
						"Mumbai", "Selam" };
	int beds[] = { 4, 5, 6, 9 };
	float ratings[] = { 5.2, 4.1, 3.4, 5.9 };
	string hospital_Contact[]
		= { "6575340577", "2987661502", "3245658959",
			"3434562094" };
	string doctor_Name[] = { "D1", "D4", "D3", "D2" };
	int prices[] = { 100, 200, 100, 290 };

	// Function Call
	HospitalManagement(
		patient_Name, patient_Id, patient_Contact,
		bookingCost, hospital_Name, locations, beds,
		ratings, hospital_Contact, doctor_Name, prices);

	return 0;
}
