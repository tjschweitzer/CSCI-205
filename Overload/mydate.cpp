#include "mydate.h"




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

Date::Date(int m, int d, int y){
	this->month = m;
	this->day = d;
	year= y;
}

// set the date
void Date::setDate(int mm, int dd, int yy){
	this->month = mm;
	this->day = dd;
	this->year= yy;
}

  
Date& Date::operator++(){  // preincrement operator
	Date temp;

	this->day = this->day + 1;

	if (this->day > numberOfDays(this->month,this->year)){
		this->day = 1;
		if (this->month == 11){
			this->month=0;
		}else{
			this->month = this->month + 1;
		}
	
	}
	return *this;
}
  
  
Date Date::operator++(int){ //postincrement operator
	
	Date temp = *this;
	++*this;
	return temp;
	
  }
  
  
Date &Date::operator+=(int additionalDays){ // add days, modify object
	Date temp;

	this->day = this->day + additionalDays;
	
	while (this->day > numberOfDays(this->month,this->year)){
		this->day = this->day - numberOfDays(this->month,this->year);
		if (this->month == 11){
			this->month=0;
		}else{
			this->month = this->month + 1;
		}
	
	}
	return *this;

}
 
bool Date::leapYear(int y) const{ // is this a leap year?
	return (y % 400 == 0 ||(y % 4 == 0 && y % 100 != 0)); 
}
  
bool Date::endOfMonth(int d) const{ // is this end of month?
	return (numberOfDays(this->month,this->year)==d);
}