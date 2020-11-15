/*
================================================================
Title     : Constructor and Destructor
Name      : Someshwar .K. Gaikwad
Class     : SE-10 (H-10)
Roll No.  : 23257
Date of Performance:

Problem Statement:

Create a class named weather report that holds a daily weather report with data members day_of_month, high_temp, low_temp, amount_rain and amount_snow.  Use different types of constructors to initialize the objects. Also include a function that prompts the user and sets values for each field so that you can override the default values.  Write a menu driven program in C++ with options to enter data and generate monthly report that displays average of each attribute.
 ================================================================
 */


#include<iostream>
using namespace std;
class WeatherReport
{
	private:
	float day;
	float high_temp;     //Data Members
	float low_temp;
	float amount_rain;
	float amount_snow;

	public:
	void update(int d);
	void average(int n);  //Member Functions
	void display(int i);

	WeatherReport()     //Default Constructor
	{
	    day=99;
	    high_temp=999;
	    low_temp=-999;
	    amount_rain=0;     //Initializing to Default Values
	    amount_snow=0;
	}
};
void WeatherReport::update(int d)  //Updates the Data Members
{
    day=d;
    float hightemp;
    float lowtemp;
    float amountrain;
    float amountsnow;
    cout<<"Update High Temperature: ";
    cin>>hightemp;
    while(hightemp>50||hightemp<-10) //Checking if entered value lies within the range
    {
    	cout<<"High Temperature Range: -10 to 50\n";
    	cout<<"Update Again\n";
    	cout<<"Update High Temperature: ";
    	cin>>hightemp;
    }

    cout<<"Update Low Temperature: ";
    cin>>lowtemp;
    while(lowtemp>38||lowtemp<-10) //Checking if entered value lies within the range
    {
    	cout<<"Low Temperature Range: -10 to 38\n";
    	cout<<"Update Again\n";
    	cout<<"Update Low Temperature: ";
    	cin>>lowtemp;
    }
    cout<<"Update Amount of Rainfall: ";
    cin>>amountrain;
    while(amountrain>400||amountrain<0) //Checking if entered value lies within the range
    {
    	cout<<"Amount of Rainfall Range: 0 to 400\n";
    	cout<<"Update Again\n";
    	cout<<"Update Amount of Rainfall: ";
    	cin>>amountrain;
    }
    cout<<"Update Amount of Snow: ";
    cin>>amountsnow;
    while(amountsnow>50||amountsnow<0) //Checking if entered value lies within the range
    {
    	cout<<"Amount of Snowfall Range: 0 to 50\n";
    	cout<<"Update Again\n";
    	cout<<"Update Amount of Rainfall: ";
    	cin>>amountsnow;
    }
    high_temp=hightemp;
    low_temp=lowtemp;          //Updating the values
    amount_rain=amountrain;
    amount_snow=amountsnow;
    cout<<"---------------------------------------------------------------\n";
}
void WeatherReport::average(int in)  //Calculates Average
{
    static float sum_ht;
    static float sum_lt;        //Stores the Average Values
    static float sum_rain;
    static float sum_snow;
    static int n;

    if(low_temp!=-999)
    {
        sum_ht=sum_ht+high_temp;
        sum_lt=sum_lt+low_temp;
        sum_rain=sum_rain+amount_rain;
        sum_snow=sum_snow+amount_snow;
        n++;
    }

    if(in==29)
    {
        sum_ht=sum_ht/n;
        sum_lt=sum_lt/n;
        sum_rain=sum_rain/n;
        sum_snow=sum_snow/n;
        //Calculating Average

        cout<<"---------------------------------------------------------------\n";
        cout<<"Average :\t"<<sum_ht<<"\t"<<sum_lt<<"\t"<<sum_rain<<"\t"<<sum_snow<<"\n";
        cout<<"---------------------------------------------------------------\n";
             //Printing the Average

        sum_ht=0;
        sum_lt=0;        //Stores the Average Values
        sum_rain=0;
        sum_snow=0;

        n=0;
    }


}

void WeatherReport::display(int i) //Displays the Weather Report in tabular
{
    cout<<i<<"\t"<<day<<"\t"<<high_temp<<"\t"<<low_temp<<"\t"<<amount_rain<<"\t"<<amount_snow<<"\n";
}

int main()
{
    WeatherReport Wt[30];

    int i;

    cout<<"---------------------------------------------------------------\n";
    cout<<"                Monthly Weather Report\n";
    cout<<"---------------------------------------------------------------\n";

    cout<<"Sr.No. \t Day \t HT \t LT \t AR \t AS \n";

    for(i=0;i<=29;i++)
    {
        Wt[i].display(i+1);    //Displaying default values
    }
    cout<<"---------------------------------------------------------------\n";

    int ch,n,d;

    do
    {
        cout<<"0. Exit\n";
        cout<<"1. Update\n";         //Menu for user
        cout<<"2. Display\n";
        cin>>ch;

        if(ch==0)
        {
        	cout<<"-----------------------END-------------------------------------\n";
        	break;
        }

        else if(ch==1)
        {
        	cout<<"Enter the number of days you wish to update: ";   //Asking for number of days user wants to update
        	cin>>n;

        	cout<<"---------------------------------------------------------------\n";

        	for(i=1;i<=n;i++)
        	{
        		cout<<"Enter the Day Number to update it's Weather Report: ";
        		cin>>d;
       			cout<<"---------------------------------------------------------------\n";

        		if(d>30||d<1)
        		{
        			cout<<"Please enter the Day Number between 1-30\n";
            		i=i-1;
            		continue;
        		}

        		Wt[d-1].update(d);       //Updating Report
        	}
        }

        else if(ch==2)
        {
        	cout<<"---------------------------------------------------------------\n";
        	cout<<"                Monthly Weather Report\n";
            cout<<"---------------------------------------------------------------\n";
        	cout<<"Sr.No. \t Day \t HT \t LT \t AR \t AS \n";

        	for(i=0;i<=29;i++)
        	{
        		Wt[i].display(i+1);     //Displaying the Report
        	}

        	for(i=0;i<=29;i++)
        	{
        	   Wt[i].average(i);  //Displays Average of updated values
        	}
        }

        else
        {
        	cout<<"Please select a correct option\n";
        	continue;
        }
    }
    while(true);

    return 0;
}

