#include<iostream> //for input/output process
#include<cstring> //for string
#include<stdlib.h> //for pause and go to the next page
#include<fstream> //for using in file

using namespace std;

    const int SIZE=3; //for number of patient
    //decleration for used in the function process and displaydata
	int male=0 ;
	int female=0;
	int old = 0;
	int young = 100;
	string genderold;
	string genderyoung;
	int longest = 0;
	string namepatient;
	string genderpatient;
	int agepatient;
	int hightemp;
	int days = 0;
	
	struct covid19{ //decleration elements for struct covid19
		string patientGender;
		string patientName;
		int patientAge;
		int num_ward;
		double temp[100];	
	};
    covid19 patientInfo[SIZE]; //variable decleration for struct covid19
	
	void process(ifstream&, int& ,int& , int& , int& , string& , string& , int& , string& , string& , int& , int&);//process find total male and female patient, youngest and oldest patient and also to find patient that longest stay in ward and total days that temperature higher than 40
	void displaydata (ofstream&  , int& , int& , int& , int& , string& , string& , int& , string& , string& , int& , int&);////display all the result that have done from the function process

	
int main()
{
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t Welcome to the Hospital Sg Buloh \t\t\t";
	cout<<endl<<endl<<endl<<endl<<endl;
	
	system("pause");
	system("CLS");

		ofstream inputfile;//open to input data to file
	    inputfile.open("covid.txt");//create a file
	    
	    cout<<endl;
	    cout<<"\t\t\t ADD PATIENT INFORMATION \t\t\t"<<endl;
	    cout<<endl;
        cout<<"***********************************************************************************************************************************************"<<endl;
        cout<<endl;
		for(int i=0 ; i<SIZE ; i++)
	{
		cout<<"Patient "<<i+1<<" :"<<endl;
		cout<<endl;
		cout<<"Patient name: ";
		cin>> patientInfo[i].patientName;//input patient name
		cout<<"Patient gender: ";
		cin>> patientInfo[i].patientGender;//input patient gender
		cout<<"Patient age: ";
		cin>> patientInfo[i].patientAge;//input patient age
		cout<<"Patient days in ward: ";
		cin>> patientInfo[i].num_ward;//input patient days stay in ward
		for(int j=0 ; j<patientInfo[i].num_ward ; j++)
	{
		cout<<"Temperature days "<<j+1<<": ";
		cin >>patientInfo[i].temp[j];//input patient temperature during days in ward
    } 
    cout<<endl;
    }
    cout<<endl;
    cout<<"***********************************************************************************************************************************************"<<endl;
    cout<<endl;
    
	inputfile<<endl;
	inputfile<<"\t\t\t ADD PATIENT INFORMATION \t\t\t"<<endl;
	inputfile<<endl;
	inputfile<<"***********************************************************************************************************************************************"<<endl;
    inputfile<<endl;
	
for(int i=0 ; i<SIZE ; i++)//input data to file covid
{
	inputfile<<"Patient "<<i+1<<" :"<<endl;
	inputfile<<endl;
	inputfile<<"Patient name :"<<patientInfo[i].patientName<<endl;//input patient name tu file
	inputfile<<"Patient gender : "<<patientInfo[i].patientGender<<endl;//input patient gender to file
	inputfile<<"Patient age : "<<patientInfo[i].patientAge<<endl;//input patient age to file
	inputfile<<"Patient days in ward : "<<patientInfo[i].num_ward<<endl;//input patient days in ward to file
	for(int j=0 ; j<patientInfo[i].num_ward ; j++)
	inputfile<<"Temperature days "<<j+1<<" : "<<patientInfo[i].temp[j]<<endl;//input patient temperature during in ward to file
}
    inputfile<<endl;
    inputfile<<"***********************************************************************************************************************************************"<<endl;
    inputfile<<endl;
    
   ifstream outfile;//to open to reading file

 
	process(outfile , male , female , young , old , genderyoung , genderold , longest , namepatient , genderpatient , agepatient, days);//to do process find total male and female patient, youngest and oldest patient and also to find patient that longest stay in ward and total days that temperature higher than 40
	
	system("Pause");
	system("CLS");
	
	ofstream myfile;//to open and writting summary to file
	displaydata(myfile , male , female , young , old , genderyoung , genderold , longest , namepatient , genderpatient , agepatient, days);//display all the result  that have done from the function process
	
	system("Pause");
	system("CLS");
	
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"\t\t\t Thank you for using this system \t\t\t";
	cout<<endl<<endl;
	cout<<"\t\t\t\t\tCreated by : Azza Fizatiaina Binti Azahari"<<endl;
	cout<<"\t\t\t\t\t\t\t  From CS2512A"<<endl;

	return 0 ;

}
void process(ifstream& outfile , int &male , int &female , int &young , int &old , string &genderyoung , string &genderold , int &longest , string &namepatient,
string &genderpatient , int &agepatient , int&days)//to do process find total male and female patient, youngest and oldest patient and also to find patient that longest stay in ward and total days that temperature higher than 40
{
	//to find total male and female patient
		for(int i=0 ; i<SIZE ; i++)
	{
	    if (patientInfo[i].patientGender =="male")
	    {
		male = male+1;
	    }
		else if( patientInfo[i].patientGender == "female")
		{
		female=female+1;
	    }
    }
  
   //to find the youngest and oldest patient 
    for(int i=0; i<SIZE ; i++)
   {
   	if(patientInfo[i].patientAge < young)
	{
	young = patientInfo[i].patientAge;
	genderyoung = patientInfo[i].patientGender;	
    } 
	else if(patientInfo[i].patientAge > old)
	{
	old=patientInfo[i].patientAge;
	genderold=patientInfo[i].patientGender;
    }

    }

  //to find the patient that stay longest in ward and the total number of days that temperature over than 40
   for(int i=0; i<SIZE ; i++)
   {
	if(patientInfo[i].num_ward>longest)
	{
	longest=patientInfo[i].num_ward;
	namepatient=patientInfo[i].patientName;
	genderpatient = patientInfo[i].patientGender;
	agepatient = patientInfo[i].patientAge;
	{
	for(int j=0 ; j<patientInfo[i].num_ward ; j++)
	{
		if(patientInfo[i].temp[j] > 40)
		{
		  days++;
     	}
     }

   }    
   }
}
   
   cout<<endl;
}

void displaydata (ofstream& myfile , int &male , int &female , int &young , int &old , string &genderyoung ,string &genderold , int &longest , string &namepatient ,
 string &genderpatient , int &agepatient , int &days)//display all the result  that have done from the function process
 {
 	cout<<endl;
 	cout<<"\t\t\t Summary of covid 19 patient \t\t\t"<<endl;
 	cout<<endl;
 	cout<<"***********************************************************************************************************************************************"<<endl;
    cout<<endl;
 	//output that get from the process calculate total of male and female
 	cout<<"Total number of male patients : "<<male<<endl;
    cout<<"Total number of female patients : "<<female<<endl;
    cout<<endl;
    //outptut that get from the process find the oldest and youngest patient
    cout<<"The youngest patient age : "<<young<<" "<<"("<<genderyoung<<")"<<endl;
	cout<<"The oldest patient age : "<<old<<" "<<"("<<genderold<<")"<<endl;
   
	cout<<endl;	
	//output thet get from the process find the patient that stay longest in ward and calculate total days that temperature over than 40
    cout<<endl<<"The longest length of stay in ward is "<<longest<<" days with "<<days<<" above 40'C "<<endl;
    cout<<"The patient's name is "<<namepatient<<"( "<<genderpatient<<" , "<<agepatient<<" years old )"<<endl;
    cout<<endl;
    cout<<"***********************************************************************************************************************************************"<<endl;
    cout<<endl;
    
    myfile.open("Summary.txt");// read all the record output to the file Summary
    myfile<<"\t\t\t Summary of covid19 patient \t\t\t"<<endl;
    myfile<<endl;
    myfile<<"***********************************************************************************************************************************************"<<endl;
    myfile<<endl;
    myfile<<"Total number of male patients : "<<male<<endl;
    myfile<<"Total number of female patients : "<<female<<endl;
    myfile<<endl;
	myfile<<"The youngest patient age : "<<young<<" "<<"("<<genderyoung<<")"<<endl;
	myfile<<"The oldest pastient age : "<<old<<" "<<"("<<genderold<<")"<<endl;
	myfile<<endl;	
    myfile<<endl<<"The longest length of stay in ward is "<<longest<<" days with "<<days<<" above 40"<<endl;
    myfile<<"The patient's name is "<<namepatient<<"( "<<genderpatient<<" , "<<agepatient<<" years old )"<<endl;
    myfile<<endl;
    myfile<<"***********************************************************************************************************************************************"<<endl;
    myfile<<endl;
    
    
}


