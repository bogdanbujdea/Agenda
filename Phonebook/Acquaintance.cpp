#include "Acquaintance.h"

Acquaintance::Acquaintance(string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType) : Contact(Gender, FirstName, LastName, PhoneNumber, ContactType)
{}

Acquaintance::Acquaintance(Date BirthDate, string HomeAddress, string EmailAddress, string Occupation, int Age, string Gender, string FirstName, string LastName, string PhoneNumber, string ContactType)
: Contact(Gender, FirstName, LastName, PhoneNumber, ContactType)
{}

Acquaintance::Acquaintance(string *s)
{
	mContactType = s[0];
	mFirstName = s[1];
	mLastName = s[2];
	mPhoneNumber = s[3];
	mGender = s[4];
}

//
Acquaintance::Acquaintance(const Acquaintance &acq)
{
	mContactType = acq.mContactType;
	mGender = acq.mGender;
	mFirstName = acq.mFirstName;
	mLastName = acq.mLastName;
	mPhoneNumber = acq.mPhoneNumber;
}
//
//Acquaintance& Acquaintance::operator= (const Acquaintance &acq)
//{
//	mAge = acq.mAge;
//	mBirthDate = acq.mBirthDate;
//	mContactType = acq.mContactType;
//	mEmailAddress = acq.mEmailAddress;
//	mGender = acq.mGender;
//	mHomeAddress = acq.mHomeAddress;
//	mName = acq.mName;
//	mOccupation = acq.mOccupation;
//	mPhoneNumber = acq.mPhoneNumber;
//	return *this;
//}

Acquaintance::~Acquaintance()
{
}