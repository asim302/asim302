#include <iostream>
#include<iomanip>
using namespace std;
int main()
{ 

	//Declare Variables
	
	string name;
	int rollno;
	float totalmarks,obtainedmarks,percentage;
	//Input Details from user 
	
	cout<<"Enter student name: ";
		getline(cin,name)
	cout<<"Enter Roll no: "; 
	cin>>rollno;
	cout<<"Enter obtained Marks out of 1100:";
	cin>>obtainedmarks;
		percentage=(static_cast<float>(obtainedmarks)/totalmarks*100);
	//print result card or Display Details
	cout<<"\n================Result Card===============\n";
	cout<<"Name:"<<name<<endl;
	cout<<"Total Marks:"<<totalmarks<<endl;
	cout<<"Obtained Marks:"<<obtainedmarks<<endl;
	
	cout<<"rollno: \t 217\n"<<endl;
	cout<<"Total Marks:"<<totalmarks<<endl;
	cout<<"Obtained Marks:"<<obtainedmarks<<endl;
	cout<<"Roll no:"<<rollno<<"\n"<<endl;
	cout<<"Percentage: "<<percentage<<"%"<<endl;
	return 0;
	
	
/*	int age=25;
	float height=5.9;
	char grade='A';
	bool isStudent=true;
	double largedecimal;
	return 0; */
}
