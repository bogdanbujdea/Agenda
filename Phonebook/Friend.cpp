
#include "Friend.h"

Friend::Friend(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID) :
Contact(BirthDate, HomeAddress, EmailAddress, Occupation, Age, Gender, FirstName, LastName, PhoneNumber, ContactType, ID)
{}

Friend::Friend(const Friend &fr)
{
	mContactType = fr.mContactType;
	mFirstName = fr.mFirstName;
	mLastName = fr.mLastName;
	mPhoneNumber = fr.mPhoneNumber;
	mGender = fr.mGender;
	mAge = fr.mAge;
	mID = fr.mID;
	mBirthDate.setDay(fr.mBirthDate.getDay());
	mBirthDate.setMonth(fr.mBirthDate.getMonth());
	mBirthDate.setYear(fr.mBirthDate.getYear());
	mHomeAddress = fr.mHomeAddress;
	mEmailAddress = fr.mEmailAddress;
	mOccupation = fr.mOccupation;
}

Friend::Friend(string *s)
{
	stringstream str;
	str<<s[0];
	str>>mID;
	str.str("");
	str.clear();
	mContactType = s[1];
	mFirstName = s[2];
	mLastName = s[3];
	mPhoneNumber = s[4];
	mGender = s[5];
	str<<s[6];
	str>>mAge;
	mEmailAddress = s[7];
	mOccupation = s[8];
	str.str("");
	str.clear();
	int day, month, year;
	day = month = year = 0;
	str<<s[9];
	str>>day;
	str>>month;
	str>>year;
	mBirthDate.setDay(day);
	mBirthDate.setMonth(month);
	mBirthDate.setYear(year);
	mHomeAddress = s[10];

}
//
//Friend::Friend() : Contact()
//{}