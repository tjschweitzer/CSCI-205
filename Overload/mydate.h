#ifndef MYDATE_H
#define MYDATE_H

#include <iostream>

using namespace std;

class Date {
	friend ostream &operator<<(ostream &output, const Date &d);

	public:
		Date(int m=1, int d=1, int y=1900); // constructor
		void setDate(int mm, int dd, int yy); // set the date
		Date &operator++();  // preincrement operator
		Date operator++(int);  //postincrement operator
		Date &operator+=(int additionalDays); // add days, modify object
		bool leapYear(int y) const; // is this a leap year?
		bool endOfMonth(int d) const; // is this end of month?

		friend ostream &operator<<( ostream &output, const Date &D ) { 
			string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"}; 
					
			output << months[D.month-1] << " " << D.day << ", "<<D.year;
			return output;
		}
	private:
		int month;
		int day; 
		int year;

		static const int days[];  // array of days per month
		void helpIncrement();  //utility functionj
};

#endif

