#ifndef DATE_H
#define DATE_H
#include <Windows.h>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

class Date
{
private:
	SYSTEMTIME mDate;
public:
	Date();
	Date(const Date &date);
	Date &operator=(const Date &date);
	int getYear() const;
	int getMonth() const;
	int getDay() const;

	string toString();
	void setYear(int Year);
	void setMonth(int Month);
	void setDay(int Day);
};

#endif
