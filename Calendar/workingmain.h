
#include <iostream>
#include <string>
#include<bits/stdc++.h> 
#include <iomanip>
using namespace std; 


/*  returns the name of the month  */
string getMonthName(int monthNumber) { 
	string months[] = {"January", "February", "March", 
					"April", "May", "June", 
					"July", "August", "September", 
					"October", "November", "December"
					}; 

	return (months[monthNumber-1]); 
} 

/*  return the number of days in a month  */
int numberOfDays (int monthNumber, int year) { 
	switch(monthNumber){
		
		// January 
		case 1: 
		// March 
		case 3:
		// May 
		case 5:
		// July 
		case 7: 
		// August 
		case 8: 
		// October 
		case 10:
		// December 
		case 12 :
			return (31); 
		break;
		
		
		// February 
		case 2:
			if (year % 400 == 0 ||(year % 4 == 0 && year % 100 != 0)) 
				return (29); 
			else
				return (28); 
		
		break;

		// April 
		case 4:
		// June 
		case 6:
		// September 
		case 9:
		// November 
		case 11:
			return (30); 
		break;
		}
		return 0;
} 


/*  return the day the month starts on  */
int findFirstDate(int m, int y){
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    y -= m < 3;
    return (y + y/4 - y/100 + y/400 + t[m-1] + 1) % 7;

}

/*  prints the calendar  */
void printCalendar(int m, int y){
	
	string monthString = getMonthName(m);
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	cout<<setw(12 + (.5 * monthString.length()))<<monthString<<" "<<y<<endl;
	cout<<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
	
	cout<<" Sun Mon Tue Wed Thu Fri Sat"<<endl;
	
	if(findFirstDate(m,y)!=0){
		cout<<setw(findFirstDate(m,y)*4)<<" ";
		}
	
	for (int i=1;i<=numberOfDays(m,y);i++){
		
		cout<<setw(3)<<i<<" ";
		if ((i+findFirstDate(m,y))%7==0){
			cout<<endl;
		}
	}
	cout<<endl;

}


/*  main program  */
int main() { 
	int month = 13;
	int year = 1799;

		cout<<"What Month (1-12)"<<endl;
		cin>>month;
	
	

		cout<<"What Year"<<endl;
		cin>>year;

	
	printCalendar(month,year);
	
	return (0); 
} 
