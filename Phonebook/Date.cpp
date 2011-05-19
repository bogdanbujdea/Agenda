#include "../stdafx.h"
#include "Date.h"

Date::Date()
{
	GetLocalTime(&mDate);
	mDate.wYear = -1;
}

Date::Date(const Date& date)
{
	mDate.wDay			= date.mDate.wDay;
	mDate.wDayOfWeek	= date.mDate.wDayOfWeek;
	mDate.wHour			= date.mDate.wHour;
	mDate.wMilliseconds	= date.mDate.wMilliseconds;
	mDate.wMinute		= date.mDate.wMinute;
	mDate.wMonth		= date.mDate.wMonth;
	mDate.wSecond		= date.mDate.wSecond;
	mDate.wYear			= date.mDate.wYear;
}

Date& Date::operator=(const Date& date)
{
	mDate.wDay			= date.mDate.wDay;
	mDate.wDayOfWeek	= date.mDate.wDayOfWeek;
	mDate.wHour			= date.mDate.wHour;
	mDate.wMilliseconds	= date.mDate.wMilliseconds;
	mDate.wMinute		= date.mDate.wMinute;
	mDate.wMonth		= date.mDate.wMonth;
	mDate.wSecond		= date.mDate.wSecond;
	mDate.wYear			= date.mDate.wYear;
	return *this;
}

int Date::getYear() const { return mDate.wYear; }

int Date::getMonth() const { return mDate.wMonth; }

int Date::getDay() const { return mDate.wDay; }

void Date::setYear(int Year) { mDate.wYear = Year; }

void Date::setMonth(int Month) { mDate.wMonth = Month; }

void Date::setDay(int Day) { mDate.wDay = Day; }

string Date::toString()
{
	stringstream str;
	string tmp,date;
	str<<mDate.wDay<<" "<<mDate.wMonth<<" "<<mDate.wYear;
	str>>tmp;
	date = tmp;
	str>>tmp;
	date += " ";
	date += tmp;
	str>>tmp;
	date += " ";
	date += tmp;
	if(mDate.wYear == 0)
		return "0";
	return date;
}