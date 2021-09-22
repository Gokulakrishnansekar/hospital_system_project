#include <bits/stdc++.h>
#include "patient_details.h"
#include "hospital_details.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
		hospital_details d;
		patient_details patient;
		 while(1){
    cout<<"-------------------------------------------------log in-------------------------------------------------\n";
   
	
    cout<<setw(50)<<" "<<"1.admin\n"<<setw(50)<<" "<<"2.user\n\n\n\n\n\n";
	
    cout<<"enter your option...\n";
    int log;
    cin>>log;
    switch(log)
    {
    	case 1:
    		{
    			string pass;
    			
    			cout<<"enter your password :";
    			cin>>pass;
    			system("cls");
    		 
			  
			   if(d.verify(pass))
    		    {
				cout<<setw(50)<<" "<<"1.view\n"<<setw(50)<<" "<<"2.delete hospital\n"<<setw(50)<<""
				<<"3.insert patient details\n"<<setw(50)<<" "
				<<"4.delete patient details\n"<<setw(50)<<" "<<"5.insert hospital\n";
			
    			cout<<"enter your operation: ";
    		
    			int temp;
    		    cin>>temp;
				switch(temp)
				{  
					
    		    case 1:patient.p_viewall();
    		    break;
    		    case 2:d.delete_detail();
    		    break;
    		    case 3:patient.pget_details();
    		    break;
    		    case 4:patient.p_remove();
					break;
				case 5:{
					d.hget_details();
					break;
				}
				
    		    default:cout<<"option is not valid\n";
    				break;
				}
				
			}
    			break;
			}
		case 2:
			{
				
				cout<<setw(50)<<" "<<"1.hospital detail\n"<<setw(50)<<" "<<"2.paient details\n"<<
				setw(50)<<" "<<"3.give rating hospital\n"<<setw(50)
				<<" "<<"4.find hospital from location\n";
				int p_opt;
				cout<<"enter the no what you want to know:  \n";
				cin>>p_opt;
				switch(p_opt)
				{
					case 1:
						{
							d.hput_details();
							break;
						}
					case 2:{
						patient.pput_details();
						break;
					}
					case 3:
						{
							d.modify_rating();
							break;
						} 
					case 4:
						{
							d.location_details();
							break;
						}
						default :{
							cout<<"option is not valid\n";
							break;
						}
				}
					break;
			}
			break;
		}
	cout<<"do you want to continue[yes/no]\n";
	string opt;
	cin>>opt;
	if(opt=="no")
	break;
	else
	system("cls");

}
    return 0;
}
