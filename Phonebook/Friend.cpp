
#include "Friend.h"

Friend::Friend(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType) :
Contact(BirthDate, HomeAddress, EmailAddress, Occupation, Age, Gender, FirstName, LastName, PhoneNumber, ContactType)
{}

Friend::Friend(const Friend &fr)
{
	mContactType = fr.mContactType;
	mFirstName = fr.mFirstName;
	mLastName = fr.mLastName;
	mPhoneNumber = fr.mPhoneNumber;
	mGender = fr.mGender;
	mAge = fr.mAge;
	mBirthDate.setDay(fr.mBirthDate.getDay());
	mBirthDate.setMonth(fr.mBirthDate.getMonth());
	mBirthDate.setYear(fr.mBirthDate.getYear());
	mHomeAddress = fr.mHomeAddress;
	mEmailAddress = fr.mEmailAddress;
	mOccupation = fr.mOccupation;
}

Friend::Friend(string *s)
{
	mContactType = s[0];
	mFirstName = s[1];
	mLastName = s[2];
	mPhoneNumber = s[3];
	mGender = s[4];
	stringstream str;
	str.str("");
	str.clear();
	str<<s[5];
	str>>mAge;
	str.str("");
	str.clear();
	int day, month, year;
	day = month = year = 0;
	str<<s[8];
	str>>day;
	str>>month;
	str>>year;
	mBirthDate.setDay(day);
	mBirthDate.setMonth(month);
	mBirthDate.setYear(year);
	mHomeAddress = s[9];
	mEmailAddress = s[6];
	mOccupation = s[7];
}
//
//Friend::Friend() : Contact()
//{}