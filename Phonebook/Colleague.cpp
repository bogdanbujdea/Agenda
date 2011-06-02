
#include "Colleague.h"


Colleague::Colleague(string EmailAddress, string Occupation, int Age,string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID) : 
Contact(EmailAddress, Occupation, Age, Gender, FirstName, LastName, PhoneNumber, ContactType, ID)
{}

Colleague::Colleague(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType, int ID):
Contact(EmailAddress, Occupation, Age, Gender, FirstName, LastName, PhoneNumber, ContactType, ID)
{}

Colleague::Colleague(const Colleague &col)
{
	mContactType = col.mContactType;
	mFirstName = col.mFirstName;
	mLastName = col.mLastName;
	mPhoneNumber = col.mPhoneNumber;
	mGender = col.mGender;
	mAge = col.mAge;
	mEmailAddress = col.mEmailAddress;
	mOccupation = col.mOccupation;
}


Colleague::Colleague(string *s)
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
}

//Colleague::Colleague() : Contact()
//{}