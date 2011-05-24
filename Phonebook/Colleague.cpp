
#include "Colleague.h"


Colleague::Colleague(string EmailAddress, string Occupation, int Age,string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType) : 
Contact(EmailAddress, Occupation, Age, Gender, FirstName, LastName, PhoneNumber, ContactType)
{}

Colleague::Colleague(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType):
Contact(EmailAddress, Occupation, Age, Gender, FirstName, LastName, PhoneNumber, ContactType)
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
	mContactType = s[0];
	mFirstName = s[1];
	mLastName = s[2];
	mPhoneNumber = s[3];
	mGender = s[4];
	stringstream str;
	str<<s[5];
	str>>mAge;
	mEmailAddress = s[6];
	mOccupation = s[7];
}

//Colleague::Colleague() : Contact()
//{}